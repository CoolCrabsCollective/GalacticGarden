//
// Created by cedric on 1/6/23.
//

#include "world/Crop.h"

Crop::Crop(Space& space, sf::Vector2f location)
	: Entity(space, location), time_since_planted(0.f) {}

void Crop::tick(float delta) {
    time_since_planted += delta;
}

bool Crop::is_ready() const {
    return time_since_planted >= get_time_to_maturity();
}

void Crop::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {

}
