//
// Created by cedric on 1/6/23.
//

#include "world/enemy/HatchlingShip.h"
#include "world/Space.h"
#include "GameAssets.h"
#include "world/crop/Crop.h"

HatchlingShip::HatchlingShip(Space &space, sf::Vector2f location) : EnemyShip(space, location) {
    sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_HATCHLING));
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

    sf::Vector2 moveDirection = targetCrop->getLocation() - location;
    if (moveDirection.length() < 0.1)  { // TODO: magic number and I don't care
        targetCrop->damage(this->damage);
        if (targetCrop->shouldBeRemoved())
            targetCrop = nullptr;
        return;
    }

    sf::Vector2 moveDirectionNormalized = moveDirection.normalized();

    // move towards crop
    this->location += moveDirectionNormalized * speed;
}

float HatchlingShip::getZOrder() const {
    return 2.f;
}
