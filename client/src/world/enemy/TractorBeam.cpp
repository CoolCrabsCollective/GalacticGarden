//
// Created by adrien on 07/01/23.
//

#include "TractorBeam.h"
TractorBeam::TractorBeam(Space &space) : Entity(space, sf::Vector2f{0.0f, 0.0f}) {
    sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_TRACTOR_BEAM));
    // Set origin at the bottom of the tractor beam, not the middle
    sprite.setOrigin({ sprite.getTexture()->getSize().x / 2.0f, static_cast<float>(sprite.getTexture()->getSize().y)});
}

void TractorBeam::draw(sf::RenderTarget &target, const sf::RenderStates &states) const {
    sprite.setOrigin({0.5f * sprite.getTexture()->getSize().x, 0.5f * sprite.getTexture()->getSize().y});
    sprite.setPosition({location.x, location.y});
    sprite.setScale({ 1.0f / sprite.getTexture()->getSize().x, 1.0f / sprite.getTexture()->getSize().y });
    sprite.setRotation(sf::degrees(rotationDegrees));
    target.draw(sprite);
}

void TractorBeam::tick(float delta) {

}

void TractorBeam::setRotationDegrees(float rotationDegrees) {
    this->rotationDegrees = rotationDegrees;
}

void TractorBeam::setLocation(const sf::Vector2f &location) {
    this->location = location;
}
