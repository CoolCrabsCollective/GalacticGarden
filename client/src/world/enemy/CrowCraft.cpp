//
// Created by cedric on 1/8/23.
//

#include "world/enemy/HatchlingShip.h"
#include "world/enemy/CrowCraft.h"
#include "world/weapon/SmallEnemyLaser.h"
#include "util/SpriteUtil.h"

CrowCraft::CrowCraft(Space &space, const sf::Vector2f &location) : HatchlingShip(space, location) {

    sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_CROWCRAFT));
    sprite.setOrigin({ sprite.getTexture()->getSize().x / 2.0f, sprite.getTexture()->getSize().y / 2.0f });
    SpriteUtil::setSpriteSize(sprite, { 1.0f, 1.0f });
    targetAsteroid = nullptr;
    speed = 0.02f;
    damageAmount = 5.0f;
    fire_delay = 0.35f;
    health = 5.0f;
}

void CrowCraft::fire() {
    if (time_since_last_fire >= fire_delay) {
        space.addEntity(
                new SmallEnemyLaser(space, location, sf::Vector2f(0.0f, -1.0f).rotatedBy(sf::degrees(rotation))));
        space.addEntity(
                new SmallEnemyLaser(space, location, sf::Vector2f(0.5f, -1.0f).rotatedBy(sf::degrees(rotation))));
        space.addEntity(
                new SmallEnemyLaser(space, location, sf::Vector2f(-0.5f, -1.0f).rotatedBy(sf::degrees(rotation))));

        time_since_last_fire = 0.0f;
    }
}
