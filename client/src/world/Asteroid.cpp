//
// Created by Alexander Winter on 2023-01-06.
//

#include "world/Asteroid.h"
#include "GameAssets.h"
#include "world/Space.h"

Asteroid::Asteroid(Space& space, const sf::Vector2f& location) 
	: Entity(space, location) {

	this->sprite.setTexture(*space.getAssets().get(GameAssets::ASTEROID), true);
	
}

void Asteroid::tick(float delta) {

}

void Asteroid::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {

	sprite.setPosition(location);
	sprite.setScale({ 1.0f / sprite.getTexture()->getSize().x, 1.0f / sprite.getTexture()->getSize().y });
	target.draw(sprite);
}


