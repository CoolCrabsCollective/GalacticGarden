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
    sprite.setOrigin({ sprite.getTexture()->getSize().x / 2.0f, sprite.getTexture()->getSize().y / 2.0f });
}

void Ship::tick(float delta) {
  float good_delta = delta / 1000.f;
  sf::Vector2f newPos = {moveDirection.x*good_delta*moveSpeed + this->location.x, moveDirection.y*good_delta*moveSpeed + this->location.y};
  if(rotateLeft)
  {
      rotation -= good_delta * angularVelocity;
  }

  if(rotateRight)
  {
      rotation += good_delta * angularVelocity;
  }
  updatePos(newPos);
  time_since_last_fire += good_delta;
}

float Ship::getRotation() const {
    return rotation;
}

void Ship::updatePos(sf::Vector2f& moveVec) {
  this->location = moveVec;
  this->sprite.setPosition(moveVec);
}

void Ship::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
	sprite.setPosition(location);
	sprite.setScale({ 1.0f / sprite.getTexture()->getSize().x, 1.0f / sprite.getTexture()->getSize().y });
    sprite.setRotation(sf::radians(rotation ));
	target.draw(sprite);
}

float Ship::getZOrder() const {
    return 8.f;
}

void Ship::moveInDirOfVec(const sf::Vector2f& moveVec) {
    sf::Vector2f moveVecNorm{0.f, 0.f};
    if(moveVec.length() > 0.001f) // is not zero
    {
        moveVecNorm = moveVec.normalized().rotatedBy(sf::radians(rotation));
    }
  this->moveDirection = moveVecNorm;
}

void Ship::fire() {
    if(time_since_last_fire >= fire_delay)
    {
        space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f)));
        time_since_last_fire = 0.f;
    }
}

void Ship::setRotateLeft(bool rotateLeft) {
    this->rotateLeft = rotateLeft;
}

void Ship::setRotateRight(bool rotateRight) {
    this->rotateRight = rotateRight;
}
