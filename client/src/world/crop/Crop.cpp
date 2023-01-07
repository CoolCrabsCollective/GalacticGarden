//
// Created by cedric on 1/6/23.
//

#include "world/crop/Crop.h"
#include "SFML/Graphics/Sprite.hpp"
#include "GameAssets.h"
#include "world/Space.h"

Crop::Crop(Asteroid& asteroid, sf::Vector2f relLocation)
	: Entity(asteroid.getSpace(), 
             asteroid.getLocation() + relLocation.rotatedBy(sf::degrees(asteroid.getRotation()))), 
             asteroid(asteroid),
             relLocation(relLocation), timeSincePlanted(0.f), health(0) {

    sprite.setTexture(*getSpace().getAssets().get(GameAssets::WHITE_PIXEL), true);
}

void Crop::tick(float delta) {
    if(shouldBeRemoved())
        return;
    
    timeSincePlanted += delta;
    location = asteroid.getLocation() + relLocation.rotatedBy(sf::degrees(asteroid.getRotation()));
}

bool Crop::isReady() const {
    return timeSincePlanted >= getTimeToMaturity();
}

void Crop::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
    if(shouldBeRemoved())
        return;
    
    sprite.setOrigin({0.5f * sprite.getTexture()->getSize().x, 1.0f * sprite.getTexture()->getSize().y});
    sprite.setPosition(location);
    sprite.setScale({ 0.5f / sprite.getTexture()->getSize().x, 0.5f / sprite.getTexture()->getSize().y });
    target.draw(sprite);
}

void Crop::damage(float value) {
    if(shouldBeRemoved())
        return;
    
    this->health -= value;
    if(health <= 0) {
        asteroid.removeCrop(relLocation);
        dead = true;
    }
}

void Crop::harvest() {
    dead = true;
    asteroid.removeCrop(relLocation);
}

bool Crop::shouldBeRemoved() const {
    return dead;
}

Asteroid& Crop::getAsteroid() const {
    return asteroid;
}

sf::Vector2f Crop::getLocationOnAsteroid() const {
    return relLocation;
}
