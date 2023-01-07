//
// Created by cedric on 1/6/23.
//

#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "world/Entity.h"

class EnemyShip : public Entity {
public:
    explicit EnemyShip(Space& space, sf::Vector2f location);
protected:
    void draw(sf::RenderTarget &target, const sf::RenderStates &states) const override;
    mutable sf::Sprite sprite;
public:
    void tick(float delta) override;
};

