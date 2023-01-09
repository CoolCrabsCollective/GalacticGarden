//
// Created by cedric on 1/8/23.
//
#include "world/enemy/TheNest.h"
#include "world/enemy/CrowCraft.h"
#include "util/SpriteUtil.h"

TheNest::TheNest(Space &space, const sf::Vector2f &location) : EnemyShip(space, location) {
    health = 100.f;
    fire_delay = 10.f;
    sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_NEST));
    SpriteUtil::setSpriteSize(sprite, { 2.0f, 2.0f });
    sprite.setOrigin({ sprite.getTexture()->getSize().x / 2.0f, sprite.getTexture()->getSize().y / 2.0f });
    speed = 0.01f;
}

void TheNest::tick(float delta) {
    EnemyShip::tick(delta);
    if (time_since_last_fire >= fire_delay) {
        space.addEntity(
                new CrowCraft(space, location + sf::Vector2f{0.5f, 0.5f}));
        space.addEntity(
                new HatchlingShip(space, location + sf::Vector2f{-0.5f, 0.5f}));
        space.addEntity(
                new HatchlingShip(space, location + sf::Vector2f{0.5f, -0.5f}));
        space.addEntity(
                new HatchlingShip(space, location + sf::Vector2f{-0.5f, -0.5f}));

        time_since_last_fire = 0.f;
    }
}

void TheNest::fire() {

}

void TheNest::pushAwayFrom(sf::Vector2f location, float delta) {

}

