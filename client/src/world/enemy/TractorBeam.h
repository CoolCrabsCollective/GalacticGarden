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
    void draw(sf::RenderTarget &target, const sf::RenderStates &states) const override;
    bool remove;
public:
    explicit TractorBeam(Space &space, sf::Vector2f location);
    void tick(float delta) override;
    bool shouldBeRemoved() const override;
    void setRemove(bool remove);
};


#endif //LD52_CLIENT_TRACTORBEAM_H
