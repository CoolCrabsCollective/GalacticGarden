//
// Created by cedric on 1/9/23.
//

#ifndef LD52_CLIENT_TREECRAFT_H
#define LD52_CLIENT_TREECRAFT_H

#include "world/Space.h"

class TreeCraft : public EnemyShip {
protected:
public:
    TreeCraft(Space &space, const sf::Vector2f &location);
    void fire() override;

    void tick(float delta) override;
};

#endif //LD52_CLIENT_TREECRAFT_H
