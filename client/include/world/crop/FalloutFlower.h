//
// Created by cedric on 1/6/23.
//

#pragma once

#include "Crop.h"
#include "WIZ/asset/AssetLoader.h"
#include "GameAssets.h"

class FalloutFlower : public Crop {
public:
    explicit FalloutFlower(Asteroid& asteroid, sf::Vector2f relLocation);
    
    float getTimeToMaturity() const override;

    float getZOrder() const override;

    float getEnergyGain() const override;
};
