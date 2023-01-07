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
#include "world/crop/Crop.h"

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
                      float startAngVelocity);

    void tick(float delta) override;

    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

    float getZOrder() const override;

private:
    void generatePlantingZones();
};


#endif //LD52_CLIENT_ASTEROID_H
