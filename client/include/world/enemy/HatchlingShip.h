//
// Created by cedric on 1/6/23.
//

#pragma once

#include "EnemyShip.h"
#include "world/crop/Crop.h"
#include "world/enemy/TractorBeam.h"

class HatchlingShip : public EnemyShip {
protected:
    sf::Vector2f velocityNormalized = {0.f, 1.f};
    
    Asteroid* targetAsteroid = nullptr;
    sf::Vector2f targetPlant;

    TractorBeam* tractorBeam = nullptr;
    
public:
    explicit HatchlingShip(Space& space, sf::Vector2f location);
    
    void tick(float delta) override;
    
    float getZOrder() const override;
};
