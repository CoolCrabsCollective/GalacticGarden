//
// Created by cedric on 1/6/23.
//

#pragma once

#include "Entity.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Sprite.hpp"

class Ship : public Entity {
protected:
	mutable sf::Sprite sprite;
    float fire_delay = 0.4f;
    float time_since_last_fire = 0.f;
    float plant_delay = 0.2f;
    float time_since_last_plant = 0.f;
    float rotation = 0.0f;
    float angularVelocity = M_PI; // rotate PI per second
    sf::Vector2f moveDirection = {0.f, 0.f};
    bool rotateLeft = false, rotateRight = false;
    
    int harvestedCount = 0;

public:
	Ship(Space& space, const sf::Vector2f& location);

    float getZOrder() const override;

	void tick(float delta) override;
	
    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

    void fire();

    void moveInDirOfVec(const sf::Vector2f& moveVec);

    void setRotateLeft(bool rotateLeft);

    void PlantOnAsteroid(Space& space);

    void setRotateRight(bool rotateRight);

    float getRotation() const;

private:
    float moveSpeed = 3.f;
};
