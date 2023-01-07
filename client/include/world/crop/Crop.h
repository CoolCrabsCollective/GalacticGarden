//
// Created by cedric on 1/6/23.
//

#pragma once

#include "world/Entity.h"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

class Crop : public Entity {
protected:
    float time_since_planted = 0.f;
    int health;
    mutable sf::Sprite sprite;
public:
    explicit Crop(Space& space, sf::Vector2f location);
		
    bool is_ready() const;
	
    void tick(float delta) override;
	
	void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
	
	virtual float get_time_to_maturity() const = 0;

    void damage(int value);

    bool shouldBeRemoved() const override;
};
