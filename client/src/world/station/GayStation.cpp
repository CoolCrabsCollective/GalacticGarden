//
// Created by william on 07/01/23.
//

#include "world/Space.h"
#include "world/station/GayStation.h"
#include "GameAssets.h"

GayStation::GayStation(Space &space, sf::Vector2f location) : Entity(space, location){
    sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_GAY_STATION));
    sprite.setOrigin({ sprite.getTexture()->getSize().x / 2.0f, sprite.getTexture()->getSize().y / 2.0f });

    bob_starting_pos = location.y;
}

void GayStation::tick(float delta) {
    if (abs(bobbingDisplacement-bob_starting_pos) >= bob_max_displacement) {
        bobbingDirection = !bobbingDirection;
    }

    bobbingDisplacement += (delta / 1000)*(bobbingDirection ? bob_speed : -bob_speed);
}

void GayStation::draw(sf::RenderTarget &target, const sf::RenderStates &states) const {
    if(shouldBeRemoved())
        return;

    sprite.setOrigin({0.5f * sprite.getTexture()->getSize().x, 0.5f * sprite.getTexture()->getSize().y});
    sprite.setPosition({location.x, bob_starting_pos + bobbingDisplacement});
    sprite.setScale({ 10.0f / sprite.getTexture()->getSize().x, 10.0f / sprite.getTexture()->getSize().y });

    target.draw(sprite);
}

bool GayStation::shouldBeRemoved() const {
    return false;
}

float GayStation::getZOrder() const {
    return 1.0f;
}
