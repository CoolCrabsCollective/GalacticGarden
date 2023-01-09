//
// Created by Alexander Winter on 2023-01-08.
//

#include "world/crop/RadioActiveCorn.h"
#include "GameAssets.h"
#include "SFML/System/Vector2.hpp"
#include "world/Asteroid.h"
#include "world/Space.h"

RadioActiveCorn::RadioActiveCorn(Asteroid& asteroid, sf::Vector2f relLocation)
        : Crop(asteroid,
               relLocation,
               asteroid.getSpace().getAssets().get(GameAssets::TEXTURE_CORN_YOUNG),
               asteroid.getSpace().getAssets().get(GameAssets::TEXTURE_CORN)) {
    health = 5.0f;
}

float RadioActiveCorn::getTimeToMaturity() const {
    return 60.0f;
}

float RadioActiveCorn::getZOrder() const {
    return 1.0f;
}

float RadioActiveCorn::getEnergyGain() const {
    return 50.0f;
}