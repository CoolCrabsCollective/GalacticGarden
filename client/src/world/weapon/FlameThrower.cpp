//
// Created by william on 08/01/23.
//

#include "world/weapon/FlameThrower.h"
#include "GameAssets.h"
#include "world/Space.h"
#include "util/SpriteUtil.h"
#include "world/enemy/EnemyShip.h"
#include "util/MathUtil.h"
#include "world/FloatingText.h"

FlameThrower::FlameThrower(Space& space)
        : space(space) {
    flameSprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_FLAME_PARTICLE));

    SpriteUtil::setSpriteOrigin(flameSprite, {0.5f, 0.5f });
}

void FlameThrower::update(float delta) {
    if (space.getShip().isUsingFlameThrower())
        generateParticles();

    time += delta / 1000.0f;
    bool display = time - lastDisplay >= 3.0f;
    if(display) {
        lastDisplay = time;
    }
    
    int index = 0;
    for(particleFrame_t& particle : particles) {
        sf::Vector2f pos = std::get<0>(particle);
        FlameParticle& flameParticle = std::get<1>(particle);

        flameParticle.lifetime += delta;
        if (flameParticle.lifetime > flameParticle.lifeSpan) {
            particles.erase(particles.begin()+index);
            currentNumberOfFlames--;
            continue;
        }

        flameParticle.size = flameParticle.finalSize*(flameParticle.lifetime / flameParticle.lifeSpan) +
                                flameParticle.finalSize / 4.0f;
        flameParticle.size = flameParticle.size > flameParticle.finalSize ? flameParticle.finalSize :
                                flameParticle.size;

        std::get<0>(particle) = std::get<0>(particle) + (std::get<0>(particle) -
                space.getShip().getLocation()).normalized() *
                delta / 1000.0f * flameParticle.speed;
        flameParticle.rot = flameParticle.rot + flameParticle.angVel * delta / 1000.0f;

        for(Entity* entity : space.getAllEntitiesInRect(pos, { 10.0f, 10.0f })) {
            if(EnemyShip* ship = dynamic_cast<EnemyShip*>(entity)) {
                if((ship->getLocation() - pos).lengthSq() < MathUtil::pow2(1.0f)) {
                    
                    float damage = 0.3f*(delta / 1000.f);
                    ship->damage(damage);
                    if(display)
                        space.addEntity(new FloatingText(space, ship->getLocation(), "-1", sf::Color::Yellow, 0.5f));
                }
            }
        }

        index++;
    }
}

void FlameThrower::generateParticles() {
    FlameParticle flameParticle;
    flameParticle.angle = space.getShip().getRotation() + 180.f + rand() / (RAND_MAX + 1.0f) * 10.0f;;
    flameParticle.finalSize = rand() / (RAND_MAX + 1.0f) * 1.0f + 0.5f;
    flameParticle.rot = rand() / (RAND_MAX + 1.0f) * 360.0f;
    flameParticle.angVel = rand() / (RAND_MAX + 1.0f) * 100.0f;
    flameParticle.speed = rand() / (RAND_MAX + 4.0f) * 10.0f;

    particles.emplace_back(space.getShip().getLocation() +
                            sf::Vector2f { 0.0f, .5f }.rotatedBy(sf::degrees(flameParticle.angle)), flameParticle);

    currentNumberOfFlames++;
}

bool FlameThrower::hasParticles() {
    return particles.size()>0;
}

void FlameThrower::clearParticles() {
    currentNumberOfFlames = 0;
    particles.clear();
}

void FlameThrower::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
    FlameParticle* flameParticle;
    int alpha;
    for(particleFrame_t particle : particles) {
        flameSprite.setPosition(std::get<0>(particle));
        flameParticle = &std::get<1>(particle);

        alpha = round(128.f - 128.f*(flameParticle->lifetime / flameParticle->lifeSpan));
        flameSprite.setColor(sf::Color(255, 255, 255, (alpha >= 0 ? alpha : 0)));

        SpriteUtil::setSpriteSize(flameSprite, {flameParticle->size, flameParticle->size});
        flameSprite.setRotation(sf::degrees(flameParticle->rot));
        target.draw(flameSprite);
    }
}

float FlameThrower::opacity(float value) {
    value *= 5.0f;

    if(value <= 1.0f)
        return value * value;

    if(value <= 5.0f)
        return 1.0f;

    return fmax(0.0f, 1.0f - (value - 5.0f));
}
