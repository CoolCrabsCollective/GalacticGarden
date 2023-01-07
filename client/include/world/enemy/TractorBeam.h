//
// Created by adrien on 07/01/23.
//

#ifndef LD52_CLIENT_TRACTORBEAM_H
#define LD52_CLIENT_TRACTORBEAM_H

#include "GameAssets.h"
#include "world/Space.h"

class TractorBeam : public Entity {
protected:
    mutable sf::Sprite sprite;
    float rotationDegrees = 0.0f;
    sf::Vector2f location{};
public:
    explicit TractorBeam(Space &space);
    void tick(float delta) override;
    void draw(sf::RenderTarget &target, const sf::RenderStates &states) const override;

    void setRotationDegrees(float rotationDegrees);

    void setLocation(const sf::Vector2f &location);
};


#endif //LD52_CLIENT_TRACTORBEAM_H
