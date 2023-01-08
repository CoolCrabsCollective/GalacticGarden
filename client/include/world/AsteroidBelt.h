//
// Created by Alexander Winter on 2023-01-07.
//

#ifndef LD52_CLIENT_ASTEROIDBELT_H
#define LD52_CLIENT_ASTEROIDBELT_H

#include <vector>
#include "Entity.h"
#include "SFML/Graphics/Sprite.hpp"

class AsteroidBelt : public Entity {
    std::vector<std::tuple<sf::Vector2f, float, float>> fake_astroids;
    
    mutable sf::Sprite asteroidSprite;
public:
    AsteroidBelt(Space& space);

    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

    float getZOrder() const override;

    void tick(float delta) override;

    sf::Vector2f getVisualSize() const override;
};


#endif //LD52_CLIENT_ASTEROIDBELT_H
