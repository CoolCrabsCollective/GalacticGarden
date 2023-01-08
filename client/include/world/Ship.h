//
// Created by cedric on 1/6/23.
//

#pragma once

#include <unordered_map>
#include "Entity.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "world/weapon/WeaponType.h"
#include "Asteroid.h"
#include "world/anime/Anime.h"
#include "world/weapon/Lazer.h"

typedef std::pair<sf::Vector2f, Asteroid*> plantzone_t;

struct PlantZoneCompare {
    bool operator() (const plantzone_t & lhs, const plantzone_t & rhs) const {
        return lhs.second < rhs.second ||
               (lhs.second == rhs.second && (lhs.first.x < rhs.first.x ||
               (lhs.first.x == rhs.first.x && lhs.first.y < rhs.first.y)));
    }
};

class Ship : public Entity {
protected:
	mutable sf::Sprite sprite;
    float fire_delay = 0.4f;
    float time_since_last_fire = 0.f;
    float plant_delay = 0.2f;
    float time_since_last_plant = 0.f;
    float rotation = 0.0f;
    float maxSpeed = 4.f; // 4 units per second
    float maxSpeedBasicBoost = 15.f;
    float maxSpeedUltraBoost = 40.f;
    float acc = 10.f; // 10 units per second ^ 2
    float boostBasicAcc = 15.f;
    float boostUltraAcc = 20.f;
    sf::Vector2f moveVelocity = { 0.f, 0.f };
    std::map<plantzone_t, bool, PlantZoneCompare> seed_thrown;
    bool isBoosting = false;
    bool isIdle = true;

    Faction fraction = FRIENDLY;

    sf::Shader* damageShader = nullptr;
    float redness = 0.0f;

    float energy = 1000.f;
    
    WeaponType weaponType = WeaponType::SIMPLE;
    CropType cropType = CropType::CORN;
    
    mutable sf::Sprite normalAnimeSprite;
    Anime normalAnime;
    mutable sf::Sprite boostAnimeSprite;
    Anime boostAnime;
    mutable sf::Sprite megaBoostAnimeSprite;
    Anime megaBoostAnime;
    
public:
    void setIsIdle(bool isIdle);

    void setIsBoosting(bool isBoosting);

    int getEnergy() const;

    void buyShit(float cost);

	Ship(Space& space, const sf::Vector2f& location);

    float getZOrder() const override;

	void tick(float delta) override;
	
    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

    void fire();

    void moveInDirOfVec(const sf::Vector2f& moveVec, float good_delta);

    void setRotation(float rotationRad);
    
    void plantOnAsteroid(Space& space);

    float getRotation() const;

    WeaponType getWeaponType() const;

    CropType getCropType() const;

    void setWeaponType(WeaponType lazer_type);

    void setCropType(CropType crop_type);

    std::vector<std::pair<sf::Vector2f, Asteroid*>> getClosestAvailablePlantingZones(Asteroid& asteroid);

    std::map<plantzone_t, bool, PlantZoneCompare> &getSeedThrown();

    const sf::Vector2f& getMoveVelocity() const;

protected:

    bool energy_for_shot(int shot_count);
};
