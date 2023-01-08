//
// Created by Alexander Winter on 2023-01-06.
//

#include <iostream>
#include "world/Asteroid.h"
#include "GameAssets.h"
#include "world/Space.h"
#include "world/crop/Crop.h"
#include "world/crop/CropType.h"
#include "world/crop/FalloutFlower.h"
#include "util/MathUtil.h"
#include "world/crop/RadioActiveCorn.h"

Asteroid::Asteroid(Space& space, 
				   const sf::Vector2f& location, 
				   float rotation,
				   float size,
				   const sf::Vector2f& startVelocity,
				   float startAngVelocity,
                   int plantingZoneCount) 
	: Entity(space, location) {
	
	sprite.setTexture(*space.getAssets().get(size < 3.0f ? GameAssets::TEXTURE_ASTEROID : GameAssets::TEXTURE_LARGE_ASTEROID), true);
	sprite.setOrigin({ sprite.getTexture()->getSize().x / 2.0f, sprite.getTexture()->getSize().y / 2.0f });

    zoneSprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_SOIL), true);
    zoneSprite.setOrigin({ zoneSprite.getTexture()->getSize().x / 2.0f, zoneSprite.getTexture()->getSize().y / 2.0f });
	
	this->rotation = rotation;
	
	this->size = size;
	this->velocity = startVelocity;
	this->angularVelocity = startAngVelocity;

    generatePlantingZones(plantingZoneCount);
}

void Asteroid::tick(float delta) {
	
	sf::Vector2 extent = { size + MAX_SIZE, size + MAX_SIZE };
	
	std::vector<Entity*> close = space.getAllEntitiesInRect(location, extent);
	
    if(location.lengthSq() > MathUtil::pow2(Space::MAP_RADIUS)) {
        sf::Vector2f normal = -location;
        velocity = velocity - 2.0f * velocity.dot(normal) * normal / normal.lengthSq();
        angularVelocity = -angularVelocity;
    } else {
        for(Entity* entity : close) {
            Asteroid* other = dynamic_cast<Asteroid*>(entity);

            if(other) {
                sf::Vector2f normal = other->getLocation() - location;
                float dst2 = normal.lengthSq();
                float normalDst = size / 2.0f + other->size / 2.0f;
                if(dst2 < normalDst * normalDst * 7.0f / 8.0f && velocity.dot(normal) > 0.0f) {
                    velocity = velocity - 2.0f * velocity.dot(normal) * normal / normal.lengthSq();
                    angularVelocity = -angularVelocity;
                }
            }
        }   
    }
	
	this->location += this->velocity * delta / 1000.0f;
	this->rotation += this->angularVelocity * delta / 1000.0f;
}

float Asteroid::getZOrder() const {
	return 0;
}

void Asteroid::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
	sprite.setPosition(location);
	sprite.setScale({ size / sprite.getTexture()->getSize().x, size / sprite.getTexture()->getSize().y });
	sprite.setRotation(sf::degrees(rotation));
	target.draw(sprite);
	
	for(auto &[key, value] : plantingZones) {
        zoneSprite.setPosition(location + key.rotatedBy(sf::degrees(rotation)));
        zoneSprite.setScale({ 1.f / (zoneSprite.getTexture()->getSize().x * 4.f), 1.f / (zoneSprite.getTexture()->getSize().y * 4.f)});
        if(value == nullptr)
            target.draw(zoneSprite);
	}
}

void Asteroid::generatePlantingZones(int count) {
	float minRadius = size / 4.0f;
	float maxRadius = size / 2.0f * 6.0f / 8.0f;

    for(int i = 0; i < count; i++) {
		float dir = i / static_cast<float>(count) * 360.0f;
		float randDes = static_cast<float>(rand() / (RAND_MAX + 1.0)) * (maxRadius - minRadius) + minRadius;

		plantingZones.insert(std::pair<sf::Vector2f, Crop*> {{ randDes * cosf(dir), randDes * sinf(dir)}, nullptr});
    }
}

std::vector<sf::Vector2f> Asteroid::getPlantingLocations() const {
    std::vector<sf::Vector2f> locations;
    for(auto &[key, value] : plantingZones)
        locations.push_back(key);
    return locations;
}

void Asteroid::plant(CropType cropType, sf::Vector2f relLocation) {
    if(!plantingZones.contains(relLocation))
        throw std::runtime_error("Invalid relative location");
    
    if(plantingZones[relLocation] != nullptr)
        throw std::runtime_error("Already a crop there bruh");
    
    Crop* newCrop;
    switch(cropType)
    {
        case FLOWER:
            newCrop = plantingZones[relLocation] = new FalloutFlower(*this, relLocation);
            break;
            
        case CORN:
            newCrop = plantingZones[relLocation] = new RadioActiveCorn(*this, relLocation);
            break;
            
        default:
            throw std::runtime_error("Unknown crop type");
    }
    
    space.addEntity(newCrop);
}

void Asteroid::removeCrop(sf::Vector2f relLocation) {

    if(!plantingZones.contains(relLocation))
        throw std::runtime_error("Invalid relative location");

    if(plantingZones[relLocation] == nullptr)
        throw std::runtime_error("No crop there");

    plantingZones[relLocation] = nullptr;
}

float Asteroid::getRotation() const {
    return rotation;
}

const sf::Vector2f& Asteroid::getVelocity() const {
    return velocity;
}

float Asteroid::getAngularVelocity() const {
    return angularVelocity;
}

bool Asteroid::isPlanted(sf::Vector2f plant) const {
    if(!plantingZones.contains(plant))
        throw std::runtime_error("Invalid location");
    
    return plantingZones.at(plant) != nullptr;
}

Crop* Asteroid::getCrop(sf::Vector2f plant) {

    if(!plantingZones.contains(plant))
        throw std::runtime_error("Invalid location");
    return plantingZones[plant];
}
