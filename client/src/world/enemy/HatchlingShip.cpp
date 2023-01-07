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
}

void HatchlingShip::tick(float delta) {
    if (targetCrop == nullptr) {
        // find a target crop
        Crop* closestCrop = nullptr;

        for (Entity* entity : space.getEntities()) {
            Crop* potentialCrop;
            if (potentialCrop = dynamic_cast<Crop*>(entity)) {
                if (closestCrop == nullptr) {
                    closestCrop = potentialCrop;
                    continue;
                }

                float distanceToClosestCrop = sqrt(pow(closestCrop->getLocation().x - location.x,2) + pow(closestCrop->getLocation().y - location.y, 2));
                float distanceToPotentialCrop = sqrt(pow(potentialCrop->getLocation().x - location.x,2) + pow(potentialCrop->getLocation().y - location.y, 2));

                if (distanceToPotentialCrop < distanceToClosestCrop) {
                    closestCrop = potentialCrop;
                }
            }
        }

        targetCrop = closestCrop;
    } else {
        // move towards crop
        sf::Vector2 moveDirection = targetCrop->getLocation() - location;
        sf::Vector2 moveDirectionNormalized = moveDirection.normalized();

        this->location += moveDirectionNormalized * speed;
    }
}

float HatchlingShip::getZOrder() const {
    return 2.f;
}
