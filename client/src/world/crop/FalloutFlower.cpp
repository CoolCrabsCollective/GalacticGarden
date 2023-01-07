//
// Created by cedric on 1/6/23.
//

#include "world/crop/Crop.h"
#include "world/crop/FalloutFlower.h"
#include "world/Space.h"
#include "GameAssets.h"

float FalloutFlower::getTimeToMaturity() const {
    return 15.f;
}

FalloutFlower::FalloutFlower(Asteroid& asteroid, sf::Vector2f relLocation) 
    : Crop(asteroid, 
           relLocation, 
           asteroid.getSpace().getAssets().get(GameAssets::TEXTURE_PLANT_GROWING), 
           asteroid.getSpace().getAssets().get(GameAssets::TEXTURE_FALLOUT_FLOWER)) {
    health = 5.0f;
}

float FalloutFlower::getZOrder() const {
    return 1.f;
}
