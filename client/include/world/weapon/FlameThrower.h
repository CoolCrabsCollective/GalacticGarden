//
// Created by william on 08/01/23.
//

#ifndef LD52_CLIENT_FLAMETHROWER_H
#define LD52_CLIENT_FLAMETHROWER_H

#include <vector>
#include "world/Entity.h"
#include "SFML/Graphics/Sprite.hpp"
#include "Lazer.h"

typedef std::tuple<sf::Vector2f, float, float, float, float> particle_t;

class FlameThrower : public Entity {
    float explosionTime = -1.0f, lifetime = 1.0f;

    sf::Vector2f velocity = { 0.0f, 0.0f };

    float rotation = 0.0f;

    std::vector<particle_t> particles;

    mutable sf::Sprite bombSprite;
    mutable sf::Sprite explosionSprite;
public:
    FlameThrower(Space& space, sf::Vector2f location, sf::Vector2f direction);

    void tick(float delta) override;

    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

    inline Faction getFaction() const {
        return Faction::FRIENDLY;
    }

    bool shouldBeRemoved() const override;

    sf::Vector2f getVisualSize() const override;

    float getZOrder() const override;

private:
    static float opacity(float value);
};

#endif //LD52_CLIENT_FLAMETHROWER_H
