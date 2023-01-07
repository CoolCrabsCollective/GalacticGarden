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

	void tick(float delta) override;
	
	void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

  void moveInDirOfVec(const sf::Vector2f& moveVec);

  void updatePos(sf::Vector2f& moveVec);

private:
    float moveSpeed = 5.0;
    sf::Vector2f moveDir = {0.0, 0.0};

    void processInput();
};
