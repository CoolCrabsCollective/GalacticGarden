//
// Created by william on 07/01/23.
//

#include "world/Space.h"
#include "world/station/GayStation.h"
#include "GameAssets.h"

GayStation::GayStation(Space &space, sf::Vector2f location) : Entity(space, location) {
    sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_GAY_STATION));
    sprite.setOrigin({ sprite.getTexture()->getSize().x / 2.0f, sprite.getTexture()->getSize().y / 2.0f });

    bob_starting_pos = location.y;

    damageShader = space.getAssets().get(GameAssets::DAMAGE_SHADER);
}

void GayStation::tick(float delta) {
    if (abs(bobbingDisplacement-bob_starting_pos) >= bob_max_displacement) {
        bobbingDirection = !bobbingDirection;
    }

    bobbingDisplacement += (delta / 1000)*(bobbingDirection ? bob_speed : -bob_speed);

    for(Entity* entity : space.getAllEntitiesInRect(location, { 1.0f, 1.0f })) {
        if(entity->shouldBeRemoved())
            continue;

        if(Lazer* lazer = dynamic_cast<Lazer*>(entity)) {
            if (lazer->getFraction() != fraction) {
                redness = 1.0f;
                health -= lazer->getDamage();
                lazer->consume();
                if (health <= 0.0f) {
                    health = 0.0f;
                    return;
                }
            }
        }
    }

    if (redness > 0.0f) {
        redness -= delta / 1000;
    }
}

void GayStation::draw(sf::RenderTarget &target, const sf::RenderStates &states) const {
    if(shouldBeRemoved())
        return;

    sprite.setOrigin({0.5f * sprite.getTexture()->getSize().x, 0.5f * sprite.getTexture()->getSize().y});
    sprite.setPosition({location.x, bob_starting_pos + bobbingDisplacement});
    sprite.setScale({ 10.0f / sprite.getTexture()->getSize().x, 10.0f / sprite.getTexture()->getSize().y });

    damageShader->setUniform("hit_multiplier", redness);
    if (redness > 0.0f)
        target.draw(sprite, damageShader);
    else
        target.draw(sprite);
}

bool GayStation::shouldBeRemoved() const {
    return false;
}

float GayStation::getZOrder() const {
    return 1.0f;
}
