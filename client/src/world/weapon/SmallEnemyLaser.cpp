//
// Created by william on 07/01/23.
//

#include "world/weapon/SmallEnemyLaser.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "world/Space.h"
#include "GameAssets.h"

SmallEnemyLaser::SmallEnemyLaser(Space &space, const sf::Vector2f &location, const sf::Vector2f &direction)
        : Lazer(space, location), direction(direction) {
    sprite.setTexture(* space.getAssets().get(GameAssets::TEXTURE_SMALL_ENEMY_LAZER));
    sprite.setOrigin({ sprite.getTexture()->getSize().x / 2.0f, sprite.getTexture()->getSize().y / 2.0f });
}

void SmallEnemyLaser::tick(float delta) {
    if(shouldBeRemoved())
        return;

    float good_delta = delta / 1000.0f;
    lifetime -= good_delta;
    location += good_delta * direction * speed;
}

void SmallEnemyLaser::draw(sf::RenderTarget &target, const sf::RenderStates &states) const {
    if(shouldBeRemoved())
        return;

    sprite.setPosition(location);
    sprite.setScale({ 1.0f / 8.0f / sprite.getTexture()->getSize().x, 0.5f / sprite.getTexture()->getSize().y });
    sprite.setRotation(sf::degrees(direction.angle().asDegrees() + 90.0f));
    target.draw(sprite);
}

float SmallEnemyLaser::getZOrder() const {
    return 1.0f;
}

float SmallEnemyLaser::getDamage() {
    return 1.0f;
}

void SmallEnemyLaser::consume() {
    lifetime = 0.0f;
}

bool SmallEnemyLaser::shouldBeRemoved() const {
    return lifetime <= 0.0f;
}