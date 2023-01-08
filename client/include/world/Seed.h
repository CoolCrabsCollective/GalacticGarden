//
// Created by adrien on 07/01/23.
//

#ifndef LD52_CLIENT_SEED_H
#define LD52_CLIENT_SEED_H

#include "GameAssets.h"
#include "world/Space.h"
#include "world/crop/Crop.h"

class Seed : public Entity {
protected:
    mutable sf::Sprite sprite;
    float rotationDegrees = 0.0f;
    sf::Vector2f location{};
    float speed = 4.0f;
    Asteroid* targetAsteroid;
    sf::Vector2f targetPlantingZone;
    bool shouldDie = false;
public:
    explicit Seed(Space &space,
                  const sf::Vector2f& location,
                  Asteroid* targetAsteroid,
                  const sf::Vector2f& targetPlantingZOne);

    void tick(float delta) override;
    void draw(sf::RenderTarget &target, const sf::RenderStates &states) const override;

    void setRotationDegrees(float rotationDegrees);

    void setLocation(const sf::Vector2f &location);

    float getZOrder() const override;

    bool shouldBeRemoved() const override;
};

#endif //LD52_CLIENT_SEED_H
