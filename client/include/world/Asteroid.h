//
// Created by Alexander Winter on 2023-01-06.
//

#ifndef LD52_CLIENT_ASTEROID_H
#define LD52_CLIENT_ASTEROID_H

#include "SFML/Graphics/Drawable.hpp"
#include "Entity.h"
#include "SFML/Graphics/Sprite.hpp"


class Asteroid : public Entity {
	mutable sf::Sprite sprite;
    sf::Vector2f velocity;
public:
	explicit Asteroid(Space& space, const sf::Vector2f& location);

	void tick(float delta) override;

	void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
};


#endif //LD52_CLIENT_ASTEROID_H
