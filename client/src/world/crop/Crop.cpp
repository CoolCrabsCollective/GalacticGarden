//
// Created by cedric on 1/6/23.
//

#include "world/crop/Crop.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

Crop::Crop(Space& space, sf::Vector2f location)
	: Entity(space, location), time_since_planted(0.f) {}

void Crop::tick(float delta) {
    time_since_planted += delta;
}

bool Crop::is_ready() const {
    return time_since_planted >= get_time_to_maturity();
}

void Crop::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
    sprite.setOrigin({0.5f * sprite.getTexture()->getSize().x, 0.5f * sprite.getTexture()->getSize().y});
    sprite.setPosition({location.x, -location.y});
    sprite.setScale({ 1.0f / sprite.getTexture()->getSize().x, 1.0f / sprite.getTexture()->getSize().y });
    target.draw(sprite);
}

void Crop::damage(int value) {
    this->health -= value;
}