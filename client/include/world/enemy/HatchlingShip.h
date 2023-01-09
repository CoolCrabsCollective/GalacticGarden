//
// Created by cedric on 1/6/23.
//

#pragma once

#include "EnemyShip.h"
#include "world/crop/Crop.h"
#include "world/enemy/TractorBeam.h"

class HatchlingShip : public EnemyShip {
protected:
    sf::Vector2f velocityNormalized = {0.0f, 1.0f};
    
    Asteroid* targetAsteroid = nullptr;
    sf::Vector2f targetPlant;

    TractorBeam* tractorBeam = nullptr;

    float plant_search_range = 20.0f;

    float min_friendly_target_range = 20.0f;
    bool targetingFriendly = false;

public:
    explicit HatchlingShip(Space& space, sf::Vector2f location);
    void draw(sf::RenderTarget &target, const sf::RenderStates &states) const override;
    void tick(float delta) override;
    
    float getZOrder() const override;

    void attackFriendly(sf::Vector2f distanceToFriendly);
};
