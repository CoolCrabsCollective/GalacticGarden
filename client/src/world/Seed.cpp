//
// Created by adrien on 07/01/23.
//

#include "world/Seed.h"

Seed::Seed(Space &space, const sf::Vector2f& location, Asteroid* targetAsteroid, const sf::Vector2f& targetPlantingZone) : Entity(space, sf::Vector2f{0.0f, 0.0f}), location(location), targetAsteroid(targetAsteroid), targetPlantingZone(targetPlantingZone) {
    sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_SEED));
    // Set origin at the bottom of the tractor beam, not the middle
    sprite.setOrigin({ sprite.getTexture()->getSize().x / 2.0f, static_cast<float>(sprite.getTexture()->getSize().y)});
}

void Seed::draw(sf::RenderTarget &target, const sf::RenderStates &states) const {
    sprite.setOrigin({0.5f * sprite.getTexture()->getSize().x, 0.5f * sprite.getTexture()->getSize().y});
    sprite.setPosition({location.x, location.y});
    sprite.setScale({ 1.0f / 4.0f / sprite.getTexture()->getSize().x, 1.0f / 4.0f / sprite.getTexture()->getSize().y });
    sprite.setRotation(sf::degrees(rotationDegrees));
    target.draw(sprite);
}

void Seed::tick(float delta) {
    if(shouldBeRemoved())
        return;

    float good_delta = delta / 1000.f;

    sf::Vector2f direction = targetAsteroid->getLocation() + targetPlantingZone.rotatedBy(sf::degrees(targetAsteroid->getRotation()))  - this->location;

    if (direction.lengthSq() <= 0.001) {
        targetAsteroid->plant(CropType::FLOWER, targetPlantingZone);
        plantzone_t zone = std::make_pair<sf::Vector2f, Asteroid*>({targetPlantingZone.x, targetPlantingZone.y}, std::move(targetAsteroid));
        shouldDie = true;
        Ship& ship = space.getShip();
        ship.getSeedThrown()[zone] = false;
    }

    location += good_delta * direction.normalized() * speed;
}

void Seed::setRotationDegrees(float rotationDegrees) {
    this->rotationDegrees = rotationDegrees;
}

void Seed::setLocation(const sf::Vector2f &location) {
    this->location = location;
}

float Seed::getZOrder() const {
    return 100;
}

bool Seed::shouldBeRemoved() const {
    return shouldDie;
}