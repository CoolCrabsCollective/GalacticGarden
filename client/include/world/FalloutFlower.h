//
// Created by cedric on 1/6/23.
//

#pragma once

#include "Crop.h"

class FalloutFlower : public Crop {
public:
    float get_time_to_maturity() const override;
};
