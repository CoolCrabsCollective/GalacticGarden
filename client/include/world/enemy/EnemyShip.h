//
// Created by cedric on 1/6/23.
//

#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "world/Entity.h"

class EnemyShip : public Entity {
protected:
    mutable sf::Sprite sprite;
    
    float speed;
    float damage;
    float health = 10.0f;
    
    float rotation = 0.0f;
public:
    explicit EnemyShip(Space& space, sf::Vector2f location);
    
    void tick(float delta) override;
    
    void draw(sf::RenderTarget &target, const sf::RenderStates &states) const override;

    bool shouldBeRemoved() const override;
};

