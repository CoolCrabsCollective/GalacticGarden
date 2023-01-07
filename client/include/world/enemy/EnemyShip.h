//
// Created by cedric on 1/6/23.
//

#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "world/Entity.h"
#include "SFML/Graphics/Shader.hpp"
#include "world/weapon/Lazer.h"

class EnemyShip : public Entity {
protected:
    mutable sf::Sprite sprite;
    
    float speed;
    float damage;
    float health = 10.0f;
    
    float rotation = 0.0f;

    sf::Shader* damageShader = nullptr;
    float redness = 0.0f;

    Fraction fraction = ENEMY;

    float fire_delay = 0.4f;
    float time_since_last_fire = 0.f;

public:
    explicit EnemyShip(Space& space, sf::Vector2f location);
    
    void tick(float delta) override;
    
    void draw(sf::RenderTarget &target, const sf::RenderStates &states) const override;

    void fire();

    bool shouldBeRemoved() const override;
};

