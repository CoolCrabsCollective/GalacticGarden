//
// Created by cedric on 1/6/23.
//

#include "world/enemy/HatchlingShip.h"
#include "world/Space.h"
#include "GameAssets.h"
#include "world/crop/Crop.h"

HatchlingShip::HatchlingShip(Space &space, sf::Vector2f location) : EnemyShip(space, location) {
    sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_HATCHLING));
    sprite.setOrigin({ sprite.getTexture()->getSize().x / 2.0f, sprite.getTexture()->getSize().y / 2.0f });
    targetCrop = nullptr;
    speed = 0.001f;
    damage = 1;
}

void HatchlingShip::tick(float delta) {
    if (targetCrop == nullptr) {
        // find a target crop
        Crop* closestCrop = nullptr;

        for (Entity* entity : space.getEntities()) {
            if (Crop* potentialCrop = dynamic_cast<Crop*>(entity)) {
                if (closestCrop == nullptr) {
                    closestCrop = potentialCrop;
                    continue;
                }

                float distanceToClosestCrop = pow(closestCrop->getLocation().x - location.x,2) + pow(closestCrop->getLocation().y - location.y, 2);
                float distanceToPotentialCrop = pow(potentialCrop->getLocation().x - location.x,2) + pow(potentialCrop->getLocation().y - location.y, 2);

                if (distanceToPotentialCrop < distanceToClosestCrop) {
                    closestCrop = potentialCrop;
                }
            }
        }
        targetCrop = closestCrop;
        return;
    }

    sf::Vector2 distanceToCrop = targetCrop->getLocation() - location;
    if (distanceToCrop.length() < 1)  { // todo magic num
        targetCrop->damage(this->damage * (delta/1000));
        if (targetCrop->shouldBeRemoved())
            targetCrop = nullptr;
        return;
    }

    velocityNormalized = distanceToCrop.normalized();

    // move towards crop
    this->location += velocityNormalized * speed;
    this->rotation = velocityNormalized.angle().asRadians() + M_PI_2;

}

void HatchlingShip::draw(sf::RenderTarget &target, const sf::RenderStates &states) const {
    sprite.setPosition({location.x, location.y});
    sprite.setScale({ 1.0f / sprite.getTexture()->getSize().x, 1.0f / sprite.getTexture()->getSize().y });

    sprite.setRotation(sf::radians(rotation));
    target.draw(sprite);
}

float HatchlingShip::getZOrder() const {
    return 2.f;
}
