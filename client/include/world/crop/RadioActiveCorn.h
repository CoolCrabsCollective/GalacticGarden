//
// Created by Alexander Winter on 2023-01-08.
//

#ifndef LD52_CLIENT_RADIOACTIVECORN_H
#define LD52_CLIENT_RADIOACTIVECORN_H

#include "world/crop/Crop.h"

class RadioActiveCorn : public Crop {
public:
    explicit RadioActiveCorn(Asteroid& asteroid, sf::Vector2f relLocation);

    float getTimeToMaturity() const override;

    float getZOrder() const override;

    float getEnergyGain() const override;
};


#endif //LD52_CLIENT_RADIOACTIVECORN_H
