//
// Created by cedric on 1/8/23.
//

#ifndef LD52_CLIENT_THENEST_H
#define LD52_CLIENT_THENEST_H

#include "EnemyShip.h"

class TheNest : public EnemyShip {
protected:
public:
    TheNest(Space &space, const sf::Vector2f &location);
    void fire() override;

    void tick(float delta) override;

protected:
    void pushAwayFrom(sf::Vector2f location, float delta) override;
};

#endif //LD52_CLIENT_THENEST_H
