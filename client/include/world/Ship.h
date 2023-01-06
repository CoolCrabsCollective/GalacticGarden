//
// Created by cedric on 1/6/23.
//

#pragma once

#include "Entity.h"
#include "SFML/Graphics/RenderTarget.hpp"

class Ship : public Entity {

public:
	Ship(Space& space, const sf::Vector2f& location);

public:
	void tick(float delta) override;
	
	void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
};
