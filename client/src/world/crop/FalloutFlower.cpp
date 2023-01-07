//
// Created by cedric on 1/6/23.
//

#include "world/crop/FalloutFlower.h"
#include "world/Space.h"
#include "GameAssets.h"

float FalloutFlower::get_time_to_maturity() const {
    return 5.f;
}

FalloutFlower::FalloutFlower(Space &space, sf::Vector2f location) : Crop(space, location) {
    sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_FALLOUT_FLOWER));
    health = 500.0f;
}

float FalloutFlower::getZOrder() const {
    return 1.f;
}
