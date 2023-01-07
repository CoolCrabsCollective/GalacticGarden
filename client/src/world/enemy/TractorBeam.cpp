//
// Created by adrien on 07/01/23.
//

#include "world/enemy/TractorBeam.h"
TractorBeam::TractorBeam(Space &space, sf::Vector2f location) : Entity(space, location) {
    sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_TRACTOR_BEAM));
    sprite.setOrigin({ sprite.getTexture()->getSize().x / 2.0f, sprite.getTexture()->getSize().y / 2.0f });
    this->remove = false;
}

void TractorBeam::draw(sf::RenderTarget &target, const sf::RenderStates &states) const {
    sprite.setOrigin({0.5f * sprite.getTexture()->getSize().x, 0.5f * sprite.getTexture()->getSize().y});
    sprite.setPosition({location.x, location.y});
    sprite.setScale({ 1.0f / sprite.getTexture()->getSize().x, 1.0f / sprite.getTexture()->getSize().y });
    target.draw(sprite);
}

void TractorBeam::tick(float delta) {

}

bool TractorBeam::shouldBeRemoved() const {
    return this->remove;
};
void TractorBeam::setRemove(bool remove) {
    this->remove = remove;
}
