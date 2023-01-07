//
// Created by william on 07/01/23.
//

#ifndef LD52_CLIENT_GAYSTATION_H
#define LD52_CLIENT_GAYSTATION_H

#include "SFML/Graphics/Sprite.hpp"
#include "world/Entity.h"

class GayStation : public Entity {
protected:
    mutable sf::Sprite sprite;

    float size = 10.f;

    float bobbingDisplacement = 0.0f;
    bool bobbingDirection = true; // true: upwards, false: downwards
    float bob_starting_pos = 0.0f;
    float bob_speed = .3f;
    float bob_max_displacement = .1f;

public:
    explicit GayStation(Space& space, sf::Vector2f location);

    void tick(float delta) override;

    void draw(sf::RenderTarget &target, const sf::RenderStates &states) const override;

    [[nodiscard]]
    sf::Vector2f getVisualSize() const override {
        return sf::Vector2f { size, size };
    }

    bool shouldBeRemoved() const override;

    float getZOrder() const override;
};

#endif //LD52_CLIENT_GAYSTATION_H
