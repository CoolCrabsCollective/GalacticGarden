//
// Created by cedric on 1/6/23.
//

#pragma once

#include "world/Entity.h"
#include "SFML/Graphics/Sprite.hpp"
#include "Lazer.h"

class SmallLaser : public Lazer {
protected:
    const float speed = 40.f;
    float lifetime = 2.f;
    
    const sf::Vector2f direction;
    mutable sf::Sprite sprite;
public:
    explicit SmallLaser(Space& space, 
                        const sf::Vector2f& location, 
                        const sf::Vector2f& direction);

    void draw(sf::RenderTarget &target, const sf::RenderStates &states) const override;
    
    void tick(float delta) override;

    float getZOrder() const override;

    float getDamage() override;

    void consume() override;

    [[nodiscard]]
    Fraction getFraction() {
        return FRIENDLY;
    };

    bool shouldBeRemoved() const override;
};
