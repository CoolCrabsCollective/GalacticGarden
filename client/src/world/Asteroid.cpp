//
// Created by Alexander Winter on 2023-01-06.
//

#include "world/Asteroid.h"
#include "GameAssets.h"
#include "world/Space.h"

Asteroid::Asteroid(Space& space, 
				   const sf::Vector2f& location, 
				   float rotation,
				   const sf::Vector2f& startVelocity,
				   float startAngVelocity) 
	: Entity(space, location) {
	
    sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_ASTEROID), true);
	sprite.setOrigin({ sprite.getTexture()->getSize().x / 2.0f, sprite.getTexture()->getSize().y / 2.0f });
	
	
	this->rotation = rotation;
    this->velocity = startVelocity;
	this->angularVelocity = startAngVelocity;
}

void Asteroid::tick(float delta) {
    this->location += this->velocity * (delta / 1000);
	this->rotation += this->angularVelocity * (delta / 1000);
}

void Asteroid::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
	sprite.setPosition(location);
	sprite.setScale({ 5.0f / sprite.getTexture()->getSize().x, 5.0f / sprite.getTexture()->getSize().y });
	sprite.setRotation(sf::degrees(rotation));
	target.draw(sprite);
}


