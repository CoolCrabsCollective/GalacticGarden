//
// Created by cedric on 1/6/23.
//

#pragma once

#include "EnemyShip.h"
#include "../crop/Crop.h"

class HatchlingShip : public EnemyShip {
protected:
    void draw(sf::RenderTarget &target, const sf::RenderStates &states) const override;
    sf::Vector2f velocityNormalized = {0.f, 1.f};
    Crop* targetCrop = nullptr;
    float rotation = 0.f;
public:
    explicit HatchlingShip(Space& space, sf::Vector2f location);
    void tick(float delta) override;
    float getZOrder() const override;


};
