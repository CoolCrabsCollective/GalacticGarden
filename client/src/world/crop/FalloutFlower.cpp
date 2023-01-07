//
// Created by cedric on 1/6/23.
//

#include "world/crop/Crop.h"
#include "world/crop/FalloutFlower.h"
#include "world/Space.h"
#include "GameAssets.h"

float FalloutFlower::getTimeToMaturity() const {
    return 5.f;
}

FalloutFlower::FalloutFlower(Asteroid& asteroid, sf::Vector2f relLocation) 
    : Crop(asteroid, relLocation) {
    sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_FALLOUT_FLOWER), true);
    health = 10;
}

float FalloutFlower::getZOrder() const {
    return 1.f;
}
