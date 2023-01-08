//
// Created by Alexander Winter on 2023-01-06.
//

#ifndef LD52_CLIENT_ASTEROID_H
#define LD52_CLIENT_ASTEROID_H

#include <map>
#include <vector>
#include "SFML/Graphics/Drawable.hpp"
#include "Entity.h"
#include "SFML/Graphics/Sprite.hpp"
#include "world/crop/CropType.h"

class Crop;

struct VecCompare {
    bool operator() (const sf::Vector2f& lhs, const sf::Vector2f& rhs) const {
        return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
    }
};

class Asteroid : public Entity {
    mutable sf::Sprite sprite;
    mutable sf::Sprite zoneSprite;
    
    float size;
    
    float rotation;
    
    sf::Vector2f velocity;
    float angularVelocity;

    std::map<sf::Vector2f, Crop*, VecCompare> plantingZones;

public:
    constexpr static const float MAX_SIZE = 10.0f;
    
    explicit Asteroid(Space& space,
                      const sf::Vector2f& location,
                      float rotation,
                      float size,
                      const sf::Vector2f& startVelocity,
                      float startAngVelocity,
                      int plantingZoneCount);

    void tick(float delta) override;

    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

    float getZOrder() const override;

    float getRotation() const;

    const sf::Vector2f& getVelocity() const;

    float getAngularVelocity() const;
    
    std::vector<sf::Vector2f> getPlantingLocations() const;
    
    bool isPlanted(sf::Vector2f location) const;

    Crop* getCrop(sf::Vector2f relLocation);
    
    void plant(CropType cropType, sf::Vector2f relLocation);
    
    void removeCrop(sf::Vector2f relLocation);
    
    [[nodiscard]]
    sf::Vector2f getVisualSize() const override {
        return sf::Vector2f { size, size };
    }

    bool is_fully_planted();
    bool has_grown_plants();
    bool has_planting_spots();

private:
    void generatePlantingZones(int count);
};


#endif //LD52_CLIENT_ASTEROID_H
