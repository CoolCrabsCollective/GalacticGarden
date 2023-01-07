//
// Created by cedric on 1/6/23.
//

#pragma once

#include "Entity.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "world/weapon/LazerType.h"
#include "world/anime/Anime.h"

class Ship : public Entity {
protected:
	mutable sf::Sprite sprite;
    float fire_delay = 0.4f;
    float time_since_last_fire = 0.f;
    float plant_delay = 0.2f;
    float time_since_last_plant = 0.f;
    float rotation = 0.0f;
    float maxSpeed = 4.f; // 4 units per second
    float maxSpeedBoost = 40.f;
    float acc = 10.f; // 10 units per second ^ 2
    float boostAcc = 20.f;
    sf::Vector2f moveVelocity = { 0.f, 0.f };
    bool isBoosting = false;
    bool isIdle = true;
public:
    void setIsIdle(bool isIdle);

protected:
    mutable sf::Sprite normalAnimeSprite;
    Anime normalAnime;
    mutable sf::Sprite boostAnimeSprite;
    Anime boostAnime;
public:
    void setIsBoosting(bool isBoosting);

public:
    int getEnergy() const;

protected:

    float energy = 100.f;
    LazerType lazerType = LazerType::SIMPLE;

    bool energy_for_shot(int shot_count);

public:
	Ship(Space& space, const sf::Vector2f& location);

    float getZOrder() const override;

	void tick(float delta) override;
	
    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

    void fire();

    void moveInDirOfVec(const sf::Vector2f& moveVec, float good_delta);

    void setRotation(float rotationRad);
    
    void plantOnAsteroid(Space& space);

    float getRotation() const;

    void setLazerType(LazerType lazer_type);
};
