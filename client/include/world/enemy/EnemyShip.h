//
// Created by cedric on 1/6/23.
//

#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "world/Entity.h"

class EnemyShip : public Entity {
protected:
    void draw(sf::RenderTarget &target, const sf::RenderStates &states) const override;
    mutable sf::Sprite sprite;
    float speed;
    int damage;
public:
    explicit EnemyShip(Space& space, sf::Vector2f location);
    void tick(float delta) override;
};

