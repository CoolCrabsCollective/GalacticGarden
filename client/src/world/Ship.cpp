//
// Created by cedric on 1/6/23.
//

#include "world/Space.h"
#include "world/Ship.h"
#include "GameAssets.h"

Ship::Ship(Space& space, const sf::Vector2f& location) 
	: Entity(space, location) {
	
	this->sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_SHIP), true);
}

void Ship::tick(float delta) {

}


void Ship::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
	sprite.setPosition(location - sf::Vector2f {0.5f, 0.5f});
	sprite.setScale({ 1.0f / sprite.getTexture()->getSize().x, 1.0f / sprite.getTexture()->getSize().y });
	target.draw(sprite);
}
