//
// Created by Alexander Winter on 2023-01-06.
//

#include <algorithm>
#include "world/Space.h"
#include "world/Asteroid.h"
#include "world/crop/FalloutFlower.h"
#include "world/enemy/HatchlingShip.h"

Space::Space(wiz::AssetLoader& assets) 
	: assets(assets), entities(), ship(*this, { 0.0f, 0.0f }) {
	entities.push_back(&ship);
	entities.push_back(new Asteroid(*this, { 0.0f, 3.0f }, 0.0f, { 0.0f, 0.0f }, 10.0f ));
    entities.push_back(new FalloutFlower(*this, { 1.0, 3.f}));
    entities.push_back(new HatchlingShip(*this, {-1.0f, -1.0f}));
	entities.push_back(new Asteroid(*this, { 0.0f, -3.0f }, 0.0f, { 0.0f, 0.0f }, -1.0f));

}

void Space::tick(float delta) {
	for(Entity* entity : entities)
		entity->tick(delta);
}

void Space::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
	sf::Vector2f viewSize = VIEW_SIZE;
	sf::Vector2f start = this->getShip().getLocation() - viewSize / 2.0f;
	sf::Vector2f end = this->getShip().getLocation() + viewSize / 2.0f;

    entities_draw_list.clear();

    for(Entity* obj : entities) {
        entities_draw_list.push_back(obj);
    }

    std::sort(entities_draw_list.begin(), entities_draw_list.end(), [&](Entity* a, Entity* b){
        return a->getZOrder() < b->getZOrder();
    });

	for(Entity* entity : entities_draw_list)
    {
        if(entity->getLocation().x >= start.x
           && entity->getLocation().y >= start.y
           && entity->getLocation().x <= end.x
           && entity->getLocation().y <= end.y)
            target.draw(*entity);
    }
}

Ship& Space::getShip() const {
	return ship;
}

wiz::AssetLoader& Space::getAssets() const {
	return assets;
}

std::vector<Entity *> &Space::getEntities() {
    return entities;
}
