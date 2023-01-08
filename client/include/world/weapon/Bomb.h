//
// Created by Alexander Winter on 2023-01-08.
//

#ifndef LD52_CLIENT_BOMB_H
#define LD52_CLIENT_BOMB_H

#include <vector>
#include "world/Entity.h"
#include "SFML/Graphics/Sprite.hpp"

typedef std::tuple<sf::Vector2f, float, float, float, float> particle_t;

class Bomb : public Entity {
    float explosionTime = -1.0f, lifetime = 1.0f;
    
    sf::Vector2f velocity = { 0.0f, 0.0f };
    
    float rotation = 0.0f;
    
    std::vector<particle_t> particles;
    
    mutable sf::Sprite bombSprite;
    mutable sf::Sprite explosionSprite;
public:
    Bomb(Space& space, sf::Vector2f location, sf::Vector2f direction);

    void tick(float delta) override;

    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
    
    bool isDamaging()
    
private:
    static float opacity(float value);
};


#endif //LD52_CLIENT_BOMB_H
