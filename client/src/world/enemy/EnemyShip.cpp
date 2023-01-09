//
// Created by cedric on 1/6/23.
//

#include "world/Space.h"
#include "world/enemy/EnemyShip.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "GameAssets.h"
#include "world/weapon/SmallEnemyLaser.h"
#include "world/FloatingText.h"
#include "util/SpriteUtil.h"
#include "util/MathUtil.h"

EnemyShip::EnemyShip(Space &space, sf::Vector2f location) 
    : Entity(space, location) {
    damageShader = space.getAssets().get(GameAssets::DAMAGE_SHADER);
}

void EnemyShip::draw(sf::RenderTarget &target, const sf::RenderStates &states) const {
    if(shouldBeRemoved())
        return;

    SpriteUtil::setSpriteOrigin(sprite, { 0.5f, 0.5f });
    sprite.setPosition(location);
    sprite.setRotation(sf::degrees(rotation));

    damageShader->setUniform("hit_multiplier", redness);
    if (redness > 0.0f)
        target.draw(sprite, damageShader);
    else
        target.draw(sprite);
}

void EnemyShip::tick(float delta) {
    if(shouldBeRemoved())
        return;
    
    for(Entity* entity : space.getAllEntitiesInRect(location, sf::Vector2f { 1.0f, 1.0f })) {
        if(entity->shouldBeRemoved())
            continue;
        
        if(Lazer* lazer = dynamic_cast<Lazer*>(entity)) {
            if (lazer->getFaction() != faction && (lazer->getLocation() - location).lengthSq() < MathUtil::pow2(1.0f)) {
                damage(lazer->getDamage());
                space.addEntity(new FloatingText(space, location, "-" + std::to_string((int)round(lazer->getDamage())), sf::Color::Magenta, 0.5f));
                lazer->consume();
                if(health <= 0.0f)
                    return;
            }
        }
        
        if(EnemyShip* other = dynamic_cast<EnemyShip*>(entity)) {
            if(other == this)
                continue;
            
            if((other->getLocation() - location).lengthSq() < MathUtil::pow2(1.0f)) {
                pushAwayFrom(other->getLocation(), delta);
            }
        }
    }

    if(redness > 0.0f)
        redness -= delta / 1000;

    time_since_last_fire += delta / 1000.0f;
}

void EnemyShip::fire() {
    if (time_since_last_fire >= fire_delay) {
        space.addEntity(
                new SmallEnemyLaser(space, location, sf::Vector2f(0.0f, -1.0f).rotatedBy(sf::degrees(rotation))));

        time_since_last_fire = 0.0f;
    }
}

bool EnemyShip::shouldBeRemoved() const {
    return health == 0.0f;
}

void EnemyShip::damage(float amount) {
    redness = 1.0f;
    health -= amount;
    
    if(health <= 0.0f)
        health = 0.0f;
}

float EnemyShip::getZOrder() const {
    return 2.0f;
}
