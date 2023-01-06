//
// Created by cedric on 1/6/23.
//

#pragma once

#include "Entity.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Sprite.hpp"

class Ship : public Entity {
	mutable sf::Sprite sprite;

public:
	Ship(Space& space, const sf::Vector2f& location);

public:
	void tick(float delta) override;
	
	void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
};
