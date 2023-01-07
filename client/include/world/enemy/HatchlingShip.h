//
// Created by cedric on 1/6/23.
//

#pragma once

#include "EnemyShip.h"

class HatchlingShip : public EnemyShip {
public:
    explicit HatchlingShip(Space& space, sf::Vector2f location);
};
