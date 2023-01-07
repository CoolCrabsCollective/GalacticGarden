//
// Created by cedric on 1/6/23.
//

#include "world/Space.h"
#include "world/Ship.h"
#include "GameAssets.h"
#include "world/weapon/SmallLaser.h"

Ship::Ship(Space& space, const sf::Vector2f& location) 
	: Entity(space, location) {
	
	this->sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_SHIP), true);
}

void Ship::tick(float delta) {
  sf::Vector2f newPos = {moveDir.x*delta*moveSpeed + this->location.x, moveDir.y*delta*moveSpeed + this->location.y};
  updatePos(newPos);
  time_since_last_fire += delta / 1000.f;
}

void Ship::updatePos(sf::Vector2f& moveVec) {
  this->location = moveVec;
  this->sprite.setPosition(moveVec);

  processInput();
}

void Ship::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
	sprite.setPosition(location - sf::Vector2f {0.5f, 0.5f});
	sprite.setScale({ 1.0f / sprite.getTexture()->getSize().x, 1.0f / sprite.getTexture()->getSize().y });
	target.draw(sprite);
}

float Ship::getZOrder() const {
    return 5.f;
}

void Ship::moveInDirOfVec(const sf::Vector2f& moveVec) {
  this->moveDir = {moveVec.x / 100, moveVec.y / 100};
}

void Ship::processInput() {
  bool connected = sf::Joystick::isConnected(0);

  float xAxisInput = connected ? sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) :
                     (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
                     ? 100.00 : ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ||
                                  sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) ? -100.00 : 0.00));

  float yAxisInput = connected ? sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) :
                     (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
                     ? -100.00 : ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
                                  sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) ? 100.00 : 0.00));

  sf::Vector2f moveVec = {xAxisInput, yAxisInput};


  moveInDirOfVec(moveVec);

}

void Ship::fire() {
    if(time_since_last_fire >= fire_delay)
    {
        space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f)));
        time_since_last_fire = 0.f;
    }
}
