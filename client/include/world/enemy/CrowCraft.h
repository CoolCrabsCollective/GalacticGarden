//
// Created by cedric on 1/6/23.
//

#pragma once

#include "HatchlingShip.h"

class CrowCraft : public HatchlingShip {
public:
    CrowCraft(Space &space, const sf::Vector2f &location);

    void fire() override;
};

