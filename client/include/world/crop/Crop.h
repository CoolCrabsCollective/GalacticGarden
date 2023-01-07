//
// Created by cedric on 1/6/23.
//

#pragma once

#include "world/Entity.h"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "world/Asteroid.h"

#include "world/crop/CropType.h"

class Crop : public Entity {
protected:

    Asteroid& asteroid;
    const sf::Vector2f relLocation;
    
    float timeSincePlanted = 0.f;
    int health;
    mutable sf::Sprite sprite;
    
public:
    explicit Crop(Asteroid& asteroid, 
                  sf::Vector2f relLocation);
		
    bool isReady() const;
	
    void tick(float delta) override;
	
	void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
	
	virtual float getTimeToMaturity() const = 0;

    void damage(int value);

    bool shouldBeRemoved() const override;
};
