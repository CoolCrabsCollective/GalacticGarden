//
// Created by cedric on 1/6/23.
//

#include "world/weapon/SmallLaser.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "world/Space.h"
#include "GameAssets.h"


SmallLaser::SmallLaser(Space &space, const sf::Vector2f &location, const sf::Vector2f &direction) : Entity(space, location), direction(direction) {
    sprite.setTexture(* space.getAssets().get(GameAssets::TEXTURE_SMALL_LAZER));
    sprite.setOrigin({ sprite.getTexture()->getSize().x / 2.0f, sprite.getTexture()->getSize().y / 2.0f });
}

void SmallLaser::tick(float delta) {
    float good_delta = delta / 1000.f;
    lifetime -= good_delta;
    location += good_delta * direction * speed;
}

void SmallLaser::draw(sf::RenderTarget &target, const sf::RenderStates &states) const {
    sprite.setPosition({location.x, location.y});
    sprite.setScale({ 1.0f / sprite.getTexture()->getSize().x, 1.0f / sprite.getTexture()->getSize().y });
    sprite.setRotation(sf::degrees(direction.angle().asDegrees() + 180.0f));
    target.draw(sprite);
}

float SmallLaser::getZOrder() const {
    return 5.f;
}
