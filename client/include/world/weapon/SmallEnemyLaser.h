//
// Created by william on 07/01/23.
//

#ifndef LD52_CLIENT_SMALLENEMYLASER_H
#define LD52_CLIENT_SMALLENEMYLASER_H

#include "world/Entity.h"
#include "SFML/Graphics/Sprite.hpp"
#include "Lazer.h"

class SmallEnemyLaser : public Lazer {
protected:
    const float speed = 8.0f;
    float lifetime = 2.0f;

    const sf::Vector2f direction;
    mutable sf::Sprite sprite;
public:
    explicit SmallEnemyLaser(Space& space,
                        const sf::Vector2f& location,
                        const sf::Vector2f& direction);

    void draw(sf::RenderTarget &target, const sf::RenderStates &states) const override;

    void tick(float delta) override;

    float getZOrder() const override;

    float getDamage() override;

    void consume() override;

    [[nodiscard]]
    Faction getFraction() {
        return ENEMY;
    };

    bool shouldBeRemoved() const override;
};

#endif //LD52_CLIENT_SMALLENEMYLASER_H
