//
// Created by cedric on 1/6/23.
//

#pragma once

#include "EnemyShip.h"
#include "../crop/Crop.h"

class HatchlingShip : public EnemyShip {
    sf::Vector2f velocity;
    Crop* targetCrop;
public:
    explicit HatchlingShip(Space& space, sf::Vector2f location);
    void tick(float delta) override;
    float getZOrder() const override;
};
