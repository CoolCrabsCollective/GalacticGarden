//
// Created by adrien on 07/01/23.
//
#include "world/enemy/TractorBeam.h"
#include "util/SpriteUtil.h"

TractorBeam::TractorBeam(Space &space) : Entity(space, sf::Vector2f{0.0f, 0.0f}) {
    sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_TRACTOR_BEAM));
}

void TractorBeam::draw(sf::RenderTarget &target, const sf::RenderStates &states) const {
    SpriteUtil::setSpriteOrigin(sprite, { 0.5f, 0.5f });
    sprite.setPosition(location);
    SpriteUtil::setSpriteSize(sprite, { 1.0f, 1.0f });
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
