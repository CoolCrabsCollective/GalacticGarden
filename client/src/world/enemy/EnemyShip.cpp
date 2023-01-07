//
// Created by cedric on 1/6/23.
//

#include "world/enemy/EnemyShip.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Texture.hpp"


EnemyShip::EnemyShip(Space &space, sf::Vector2f location) : Entity(space, location) {

}

void EnemyShip::draw(sf::RenderTarget &target, const sf::RenderStates &states) const {
    sprite.setPosition({location.x, -location.y});
    sprite.setScale({ 1.0f / sprite.getTexture()->getSize().x, 1.0f / sprite.getTexture()->getSize().y });
    target.draw(sprite);
}

void EnemyShip::tick(float delta) {

}
