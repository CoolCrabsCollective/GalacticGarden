//
// Created by cedric on 1/6/23.
//

#include "world/weapon/SmallLaser.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "world/Space.h"
#include "GameAssets.h"


SmallLaser::SmallLaser(Space &space, const sf::Vector2f &location, const sf::Vector2f &direction) : Entity(space, location), direction(direction) {
    sprite.setTexture(* space.getAssets().get(GameAssets::TEXTURE_SMALL_LAZER));
}

void SmallLaser::tick(float delta) {
    float good_delta = delta / 1000.f;
    lifetime -= good_delta;
    location += good_delta * direction * speed;
}

void SmallLaser::draw(sf::RenderTarget &target, const sf::RenderStates &states) const {
    sprite.setOrigin({0.5f * sprite.getTexture()->getSize().x, 0.5f * sprite.getTexture()->getSize().y});
    sprite.setPosition({location.x, location.y});
    sprite.setScale({ 1.0f / sprite.getTexture()->getSize().x, 1.0f / sprite.getTexture()->getSize().y });
    target.draw(sprite);
}