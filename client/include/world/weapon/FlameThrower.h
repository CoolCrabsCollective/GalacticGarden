//
// Created by william on 08/01/23.
//

#ifndef LD52_CLIENT_FLAMETHROWER_H
#define LD52_CLIENT_FLAMETHROWER_H

#include <vector>
#include "world/Entity.h"
#include "SFML/Graphics/Sprite.hpp"
#include "Lazer.h"

struct FlameParticle {
    float lifeSpan = 500.f;
    float lifetime = .0f;
    float angle;
    float size;
    float rot;
    float angVel;
    float speed;
};

typedef std::tuple<sf::Vector2f, FlameParticle> particleFrame_t;

class FlameThrower : sf::Drawable {
    Space& space;

    float rotation = 0.0f;

    std::vector<particleFrame_t> particles;
    int maxNumberOfFlames = 1000;
    int currentNumberOfFlames = 0;

    float timeBetweenParticles = 1000.f;
    float timeSinceLastParticle = .0f;

    mutable sf::Sprite flameSprite;
public:
    FlameThrower(Space& space);

    void update(float delta);

    void generateParticles();

    bool hasParticles();

    void clearParticles();

    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const;

    inline Faction getFaction() const {
        return Faction::FRIENDLY;
    }

private:
    static float opacity(float value);
};

#endif //LD52_CLIENT_FLAMETHROWER_H
