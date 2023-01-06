//
// Created by cedric on 1/6/23.
//

#include "Crop.h"

void Crop::tick(float delta) {
    time_since_planted += delta;
}

bool Crop::is_ready() const {
    return time_since_planted >= get_time_to_maturity();
}
