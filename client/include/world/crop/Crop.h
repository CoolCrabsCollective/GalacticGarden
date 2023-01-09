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
#include "ui/ProgressBar.h"

class Crop : public Entity {
protected:

    Asteroid& asteroid;
    const sf::Vector2f relLocation;
    
    float timeSincePlanted = 0.0f;
    float health;
    bool dead = false, harvested = false;
    
    float harvestingSpeed = 10.0f;
    
    sf::Texture* plantGrowing;
    sf::Texture* grown;
    mutable sf::Sprite sprite;
    ProgressBar progress;
    
public:
    explicit Crop(Asteroid& asteroid, 
                  sf::Vector2f relLocation,
                  sf::Texture* plantGrowing,
                  sf::Texture* grown);
		
    bool isReady() const;
	
    void tick(float delta) override;
	
	void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
	
	virtual float getTimeToMaturity() const = 0;

    virtual float getEnergyGain() const = 0;

    void damage(float value);

    bool shouldBeRemoved() const override;

    void harvest();

    Asteroid& getAsteroid() const;
    
    sf::Vector2f getLocationOnAsteroid() const;

    bool isHarvested();
};
