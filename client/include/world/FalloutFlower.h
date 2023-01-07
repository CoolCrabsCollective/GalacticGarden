//
// Created by cedric on 1/6/23.
//

#pragma once

#include "Crop.h"
#include "WIZ/asset/AssetLoader.h"
#include "GameAssets.h"

class FalloutFlower : public Crop {
public:
    explicit FalloutFlower(Space& space, sf::Vector2f location);
    float get_time_to_maturity() const override;
};
