//
// Created by Alexander Winter on 2023-01-06.
//

#include <algorithm>
#include "world/Space.h"
#include "world/Asteroid.h"
#include "world/enemy/HatchlingShip.h"
#include "world/station/GayStation.h"
#include <iostream>
#include "util/MathUtil.h"

using namespace MathUtil;

Space::Space(wiz::AssetLoader& assets) 
    : assets(assets), entities(), ship(*this, { 0.0f, 0.0f }), spacialMap() {
    entities.push_back(&ship);

    entities.push_back(new GayStation(*this, {10.0f, .0f}));

    spawnAsteroidBelt();
    spawnAsteroids();
    
	initSpacialMap();
}

void Space::spawnAsteroidBelt() {
    
}

void Space::spawnAsteroids() {
    std::vector<Asteroid*> asteroids;

    do {
        float x = static_cast<float>(rand() / (RAND_MAX + 1.0) * 2.0 - 1.0) * Space::MAP_RADIUS;
        float y = static_cast<float>(rand() / (RAND_MAX + 1.0) * 2.0 - 1.0) * Space::MAP_RADIUS;
        float radius = static_cast<float>(rand() / (RAND_MAX + 1.0)) * 2.0 + 0.5f;
        int countPlant = round(pow2(radius));
        
        if(pow2(x) + pow2(y) > pow2(Space::MAP_RADIUS))
            continue;
        
        bool overlap = false;
        for(Asteroid* other : asteroids) {
            if(pow2(x - other->getLocation().x) + pow2(y - other->getLocation().y) > pow2(other->getVisualSize().x / 2.0f + radius)) {
                overlap = true;
                break;
            }
        }
        
        float velX = static_cast<float>(rand() / (RAND_MAX + 1.0) * 2.0 - 1.0) * 1.0f;
        float velY = static_cast<float>(rand() / (RAND_MAX + 1.0) * 2.0 - 1.0) * 1.0f;
        float angVel = static_cast<float>(rand() / (RAND_MAX + 1.0) * 2.0 - 1.0) * 100.0f;
        
        asteroids.push_back(new Asteroid(*this, { x, y }, 0.0f, radius * 2.0f, { velX, velY }, angVel, countPlant));
        
    } while(asteroids.size() < 500);
    
    for(Asteroid* ass : asteroids)
        entities.push_back(ass);
}


void Space::initSpacialMap() {

    spacialMap.clear();

    for(Entity* entity : entities) {
        uint64_t key = spacialKey(entity->getLocation());

        if(!spacialMap.contains(key))
            spacialMap[key] = { entity };
        else
            spacialMap[key].insert(spacialMap[key].begin(), entity);
    }
}

void Space::removeFromMap(Entity* entity) {
    uint64_t key = spacialKey(entity->getLocation());

    if(!spacialMap.contains(key))
        throw std::runtime_error("Error entity was not properly in spacial map (DID YOU UPDATE POSITION OUTSIDE OF TICK?)");

    auto& list = spacialMap[key];

    auto last = list.end();
    auto pos = std::find(list.begin(), last, entity);

    if(pos == last)
        throw std::runtime_error("Error entity was not properly in spacial map (DID YOU UPDATE POSITION OUTSIDE OF TICK?)");

    list.erase(pos);

    if(list.empty())
        spacialMap.erase(key);
}

uint64_t Space::spacialKey(sf::Vector2f location) const {
    uint32_t chunkX = round(location.x / CHUNK_SIZE);
    uint32_t chunkY = round(location.y / CHUNK_SIZE);

    return *reinterpret_cast<const uint32_t*>(&chunkX)
           | static_cast<uint64_t>(*reinterpret_cast<const uint32_t*>(&chunkY)) << 32;
}

void Space::tick(float delta) {

    for(Entity* entity : entities) {

        // protip : don't fuck with this unless you know what you are doing
        // and never update position outside of tick

        uint64_t oldKey = spacialKey(entity->getLocation());

        entity->tick(delta);

        uint64_t newKey = spacialKey(entity->getLocation());

        if(oldKey == newKey)
            continue;

        if(!spacialMap.contains(oldKey))
            throw std::runtime_error("Error entity was not properly in spacial map (DID YOU UPDATE POSITION OUTSIDE OF TICK?)");

        auto& list = spacialMap[oldKey];

        auto last = list.end();
        auto pos = std::find(list.begin(), last, entity);

        if(pos == last)
            throw std::runtime_error("Error entity was not properly in spacial map (DID YOU UPDATE POSITION OUTSIDE OF TICK?)");

        list.erase(pos);

        if(list.empty())
            spacialMap.erase(oldKey);

		if(!spacialMap.contains(newKey))
			spacialMap[newKey] = { entity };
		else
			spacialMap[newKey].insert(spacialMap[newKey].begin(), entity);
	}

    manageEnemies();

    removeEntities();

    time_since_last_spawn += delta;
}

std::vector<Entity*> Space::getAllEntitiesInRect(sf::Vector2f center,
                                                 sf::Vector2f size) const {
    std::vector<Entity*> output;

    sf::Vector2f start = center - size / 2.0f;
    sf::Vector2f end = center + size / 2.0f;

    int32_t startChunkX = static_cast<int32_t>(floor(start.x / CHUNK_SIZE));
    int32_t startChunkY = static_cast<int32_t>(floor(start.y / CHUNK_SIZE));

    int32_t endChunkX = static_cast<int32_t>(ceil(end.x / CHUNK_SIZE));
    int32_t endChunkY = static_cast<int32_t>(ceil(end.y / CHUNK_SIZE));

    for(int32_t x = startChunkX; x <= endChunkX; x++) {
        for(int32_t y = startChunkY; y <= endChunkY; y++) {
            uint64_t key = static_cast<uint32_t>(x) | static_cast<uint64_t>(y) << 32;

            if(!spacialMap.contains(key))
                continue;

            for(Entity* entity : spacialMap.at(key)) {

                if(entity->getLocation().x < start.x
                || entity->getLocation().x > end.x
                || entity->getLocation().y < start.y
                || entity->getLocation().y > end.y)
                    continue;
                output.push_back(entity);
            }
        }
    }

    return output;
}

void Space::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
    sf::Vector2f viewSize = target.getView().getSize();
    sf::Vector2f start = target.getView().getCenter() - viewSize / 2.0f;
    sf::Vector2f end = target.getView().getCenter() + viewSize / 2.0f;

    entities_draw_list.clear();

    for(Entity* obj : entities)
        entities_draw_list.push_back(obj);

    std::sort(entities_draw_list.begin(), entities_draw_list.end(), [&](Entity* a, Entity* b){
        return a->getZOrder() < b->getZOrder();
    });

    for(Entity* entity : entities_draw_list) {
        if(entity->getLocation().x + entity->getVisualSize().x / 2.0f >= start.x
           && entity->getLocation().y + entity->getVisualSize().y / 2.0f >= start.y
           && entity->getLocation().x - entity->getVisualSize().x / 2.0f <= end.x
           && entity->getLocation().y - entity->getVisualSize().y / 2.0f <= end.y)
            target.draw(*entity);
    }
}

void Space::removeEntities() {
    size_t i = 0;
    while (i < this->entities.size()) {
        Entity* entity = this->entities.at(i);
        if (entity->shouldBeRemoved()) {
            entities.erase(entities.begin() + i);
            removeFromMap(entity);

            EnemyShip* enemy = dynamic_cast<EnemyShip*>(entity);
            if (enemy != nullptr)
                enemy_count--;

            delete entity;
        } else {
            i++;
        }
    }
}

void Space::addEntity(Entity *entity) {
    entities.push_back(entity);

    uint64_t key = spacialKey(entity->getLocation());

    if(!spacialMap.contains(key))
        spacialMap[key] = { entity };
    else
        spacialMap[key].insert(spacialMap[key].begin(), entity);
}

void Space::manageEnemies() {
    if (enemy_count < max_enemy_count && time_since_last_spawn > spawn_delay) {
        float minDst = 9.0f;
        float maxDst = 20.0f;

        float randDir = static_cast<float>(rand() / (RAND_MAX + 1.0)) * 360.0;
        float randDes = static_cast<float>(rand() / (RAND_MAX + 1.0)) * (maxDst - minDst) + minDst;

        spawnEnemy({randDes * cosf(randDir) + ship.getLocation().x, randDes * sinf(randDir) + ship.getLocation().y});
    }
}

void Space::spawnEnemy(sf::Vector2f pos) {
    addEntity(new HatchlingShip(*this, pos));
    enemy_count++;
    time_since_last_spawn = 0.0f;
}

Ship& Space::getShip() {
    return ship;
}

const Ship& Space::getShip() const {
    return ship;
}

wiz::AssetLoader& Space::getAssets() const {
    return assets;
}

const std::vector<Entity*> &Space::getEntities() const {
    return entities;
}
