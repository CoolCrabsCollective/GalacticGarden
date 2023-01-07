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
	
	float size;
	
	float rotation;
	
    sf::Vector2f velocity;
	float angularVelocity;
public:
	constexpr static const float MAX_SIZE = 10.0f;
	
	explicit Asteroid(Space& space,
					  const sf::Vector2f& location,
	                  float rotation,
	                  float size,
	                  const sf::Vector2f& startVelocity,
	                  float startAngVelocity);

	void tick(float delta) override;

	void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
};


#endif //LD52_CLIENT_ASTEROID_H
