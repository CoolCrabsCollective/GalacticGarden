//
// Created by william on 07/01/23.
//

#include "world/Space.h"
#include "world/station/GayStation.h"
#include "GameAssets.h"
#include "util/SpriteUtil.h"
#include "world/FloatingText.h"

GayStation::GayStation(Space &space, sf::Vector2f location) : Entity(space, location) {
    sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_GAY_STATION));
    SpriteUtil::setSpriteOrigin(sprite, sf::Vector2f { 0.5f, 0.5f });

    shieldSprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_SHIELD_STATION));
    SpriteUtil::setSpriteOrigin(shieldSprite, sf::Vector2f { 0.5f, 0.5f });

    bob_starting_pos = location.y;

    damageShader = space.getAssets().get(GameAssets::DAMAGE_SHADER);
}

void GayStation::tick(float delta) {
    if (abs(bobbingDisplacement-bob_starting_pos) >= bob_max_displacement) {
        bobbingDirection = !bobbingDirection;
    }

    bobbingDisplacement += (delta / 1000)*(bobbingDirection ? bob_speed : -bob_speed);

    for(Entity* entity : space.getAllEntitiesInRect(location, { 5.0f, 2.0f })) {
        if(entity->shouldBeRemoved())
            continue;

        if(Lazer* lazer = dynamic_cast<Lazer*>(entity)) {
            if (lazer->getFraction() != fraction) {
                redness = 1.0f;
                space.getShip().buyShit(lazer->getDamage());
                space.addEntity(new FloatingText(space, location, "-" + std::to_string((int)round(lazer->getDamage())), sf::Color::Red, 0.5f));
                lazer->consume();
                space.getShip().hurtSound.play();
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

    sprite.setPosition({location.x, bob_starting_pos + bobbingDisplacement});
    SpriteUtil::setSpriteSize(sprite, { 10.0f, 10.0f });

    SpriteUtil::setSpriteOpacity(shieldSprite, redness + 0.2f);
    shieldSprite.setPosition({ location.x, bob_starting_pos + bobbingDisplacement });
    SpriteUtil::setSpriteSize(shieldSprite, { 15.0f, 15.0f });
    
    target.draw(sprite);
    
    target.draw(shieldSprite);
}

bool GayStation::shouldBeRemoved() const {
    return false;
}

float GayStation::getZOrder() const {
    return 1.0f;
}
