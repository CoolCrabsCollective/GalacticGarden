//
// Created by cedric on 1/6/23.
//

#include "world/weapon/SmallLaser.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "world/Space.h"
#include "GameAssets.h"

SmallLaser::SmallLaser(Space& space, sf::Vector2f location, sf::Vector2f direction) 
    : Lazer(space, location), direction(direction) {
    sprite.setTexture(* space.getAssets().get(GameAssets::TEXTURE_SMALL_LAZER));
    sprite.setOrigin({ sprite.getTexture()->getSize().x / 2.0f, sprite.getTexture()->getSize().y / 2.0f });
}

void SmallLaser::tick(float delta) {
    if(shouldBeRemoved())
        return;
    
    float good_delta = delta / 1000.f;
    lifetime -= good_delta;
    location += good_delta * direction * speed;
}

void SmallLaser::draw(sf::RenderTarget &target, const sf::RenderStates &states) const {
    if(shouldBeRemoved())
        return;
    
    sprite.setPosition(location);
    sprite.setScale({ 1.0f / 8.0f / sprite.getTexture()->getSize().x, 0.5f / sprite.getTexture()->getSize().y });
    sprite.setRotation(sf::degrees(direction.angle().asDegrees() + 90.0f));
    target.draw(sprite);
}

float SmallLaser::getZOrder() const {
    return 5.f;
}

float SmallLaser::getDamage() {
    return 1.0f;
}

void SmallLaser::consume() {
    lifetime = 0.0f;
}

bool SmallLaser::shouldBeRemoved() const {
    return lifetime <= 0.0f;
}
