//
// Created by cedric on 1/6/23.
//

#include "world/weapon/SmallLaser.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Texture.hpp"

void SmallLaser::tick(float delta) {
    float good_delta = delta / 1000.f;
    lifetime -= good_delta;
    location += good_delta * direction;
}




void SmallLaser::draw(sf::RenderTarget &target, const sf::RenderStates &states) const {
    sprite.setOrigin({0.5f * sprite.getTexture()->getSize().x, 0.5f * sprite.getTexture()->getSize().y});
    sprite.setPosition({location.x, -location.y});
    sprite.setScale({ 1.0f / sprite.getTexture()->getSize().x, 1.0f / sprite.getTexture()->getSize().y });
    target.draw(sprite);
}
