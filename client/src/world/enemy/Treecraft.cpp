//
// Created by cedric on 1/8/23.
//
#include "world/enemy/TheNest.h"
#include "world/enemy/CrowCraft.h"
#include "world/enemy/TreeCraft.h"
#include "util/SpriteUtil.h"

TreeCraft::TreeCraft(Space &space, const sf::Vector2f &location) : EnemyShip(space, location) {
    health = 200.f;
    fire_delay = 7.5f;
    sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_TREE));
    sprite.setOrigin({ sprite.getTexture()->getSize().x / 2.0f, sprite.getTexture()->getSize().y / 2.0f });

    SpriteUtil::setSpriteSize(sprite, { 8.0f, 8.0f });
    speed = 0.2f;
    time_since_last_fire = fire_delay;
}

void TreeCraft::tick(float delta) {
    EnemyShip::tick(delta);
    if (time_since_last_fire >= fire_delay) {
        space.addEntity(
                new TheNest(space, location + sf::Vector2f{0.5f, 0.5f}));
        space.addEntity(
                new TheNest(space, location + sf::Vector2f{-0.5f, 0.5f}));
        space.addEntity(
                new TheNest(space, location + sf::Vector2f{0.5f, -0.5f}));
        space.addEntity(
                new TheNest(space, location + sf::Vector2f{-0.5f, -0.5f}));

        time_since_last_fire = 0.0f;
    }
}

void TreeCraft::fire() {

}

void TreeCraft::pushAwayFrom(sf::Vector2f location, float delta) {

}

void TreeCraft::damage(float amount) {
    EnemyShip::damage(amount);

    if (health == 0.0f)
        space.lordCrowHasFallen = true;
}

