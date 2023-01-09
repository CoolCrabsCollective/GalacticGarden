//
// Created by william on 08/01/23.
//

#include "world/weapon/FlameThrower.h"
#include "GameAssets.h"
#include "world/Space.h"
#include "util/SpriteUtil.h"
#include "world/enemy/EnemyShip.h"
#include "util/MathUtil.h"

FlameThrower::FlameThrower(Space& space)
        : space(space) {
    flameSprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_FLAME_PARTICLE));

    SpriteUtil::setSpriteOrigin(flameSprite, {0.5f, 0.5f });
}

void FlameThrower::update(float delta) {
    timeSinceLastParticle += delta;

    if (space.getShip().isUsingFlameThrower() && timeSinceLastParticle > timeBetweenParticles)
        generateParticles();

    int index = 0;
    for(particleFrame_t& particle : particles) {
        FlameParticle& flameParticle = std::get<1>(particle);

        flameParticle.lifetime += delta;
        if (flameParticle.lifetime > flameParticle.lifeSpan) {
            particles.erase(particles.begin()+index);
            particles.clear();
            currentNumberOfFlames--;
            continue;
        }

        std::get<0>(particle) = std::get<0>(particle) + (std::get<0>(particle) -
                space.getShip().getLocation()).normalized() *
                delta / 1000.0f * flameParticle.speed;
        flameParticle.rot = flameParticle.rot + flameParticle.angVel * delta / 1000.0f;

        for(Entity* entity : space.getAllEntitiesInRect(std::get<0>(particle), { 10.0f, 10.0f })) {
            if(EnemyShip* ship = dynamic_cast<EnemyShip*>(entity)) {
                if((ship->getLocation() - space.getShip().getLocation()).lengthSq() < MathUtil::pow2(5.0f)) {
                    ship->damage(2.f*(delta / 1000.f));
                }
            }
        }

        index++;
    }
}

void FlameThrower::generateParticles() {
    for(; currentNumberOfFlames < maxNumberOfFlames; currentNumberOfFlames++) {
        FlameParticle flameParticle;
        flameParticle.angle = space.getShip().getRotation() + 180.f + rand() / (RAND_MAX + 1.0f) * 10.0f;;
        flameParticle.size = rand() / (RAND_MAX + 1.0f) * 2.0f + 0.5f;
        flameParticle.rot = rand() / (RAND_MAX + 1.0f) * 360.0f;
        flameParticle.angVel = rand() / (RAND_MAX + 1.0f) * 100.0f;
        flameParticle.speed = rand() / (RAND_MAX + 4.0f) * 10.0f;

        particles.emplace_back(space.getShip().getLocation() +
                                sf::Vector2f { 0.0f, 1.0f }.rotatedBy(sf::degrees(flameParticle.angle)), flameParticle);
    }
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
    for(particleFrame_t particle : particles) {
        flameSprite.setPosition(std::get<0>(particle));
        flameParticle = &std::get<1>(particle);

//        flameSprite.setColor(sf::Color(255, 255, 255, round(opacity(flameParticle->lifetime) * 128)));

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
