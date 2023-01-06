//
// Created by cedric on 1/6/23.
//

#pragma once

#include "Tickable.h"
#include "SFML/Graphics/Drawable.hpp"

class Crop : public Tickable, public sf::Drawable{
protected:
    float time_since_planted = 0.f;
public:
    explicit Crop() : time_since_planted(0.f) {}
    bool is_ready() const;
    void tick(float delta) override;
    virtual float get_time_to_maturity() const = 0;
};
