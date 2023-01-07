//
// Created by cedric on 1/6/23.
//

#include "world/enemy/HatchlingShip.h"
#include "world/Space.h"
#include "GameAssets.h"
#include "world/crop/Crop.h"

HatchlingShip::HatchlingShip(Space &space, sf::Vector2f location) 
    : EnemyShip(space, location) {
    sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_HATCHLING));
    sprite.setOrigin({ sprite.getTexture()->getSize().x / 2.0f, sprite.getTexture()->getSize().y / 2.0f });
    targetAsteroid = nullptr;
    speed = 0.001f;
    damage = 1;
}

void HatchlingShip::tick(float delta) {

    EnemyShip::tick(delta);
    
    if(shouldBeRemoved())
        return;
    
    if(targetAsteroid && !targetAsteroid->isPlanted(targetPlant))
        targetAsteroid = nullptr;
    
    
    if(!targetAsteroid) {
        // find a target crop
        Crop* closestCrop = nullptr;

        for (Entity* entity : space.getEntities()) {
            if (Crop* potentialCrop = dynamic_cast<Crop*>(entity)) {
                
                if(potentialCrop->shouldBeRemoved())
                    continue;
                
                if (closestCrop == nullptr) {
                    closestCrop = potentialCrop;
                    continue;
                }
                
                float dx = closestCrop->getLocation().x - location.x;
                float dy = closestCrop->getLocation().y - location.y;

                float dx2 = potentialCrop->getLocation().x - location.x;
                float dy2 = potentialCrop->getLocation().y - location.y;
                
                float distanceToClosestCrop = dx * dx + dy * dy;
                float distanceToPotentialCrop = dx2 * dx2 + dy2 * dy2;

                if (distanceToPotentialCrop < distanceToClosestCrop) {
                    closestCrop = potentialCrop;
                }
            }
        }
        if(closestCrop) {
            targetAsteroid = &closestCrop->getAsteroid();
            targetPlant = closestCrop->getLocationOnAsteroid();   
        }
    }
    
    if(targetAsteroid == nullptr)
        return;
    
    Crop* crop = targetAsteroid->getCrop(targetPlant);

    sf::Vector2 distanceToCrop = crop->getLocation() - location;
    if(distanceToCrop.lengthSq() < 1.0f)  { // todo magic num
        
        crop->damage(this->damage * delta / 1000.0f);
        if (tractorBeam == nullptr) {
            tractorBeam = new TractorBeam(space);
        }
        
        if (crop->shouldBeRemoved()) {
            targetAsteroid = nullptr;
            delete tractorBeam;
            tractorBeam = nullptr;
        }

        if(tractorBeam)
        {
            tractorBeam->setLocation(location + velocityNormalized);
            tractorBeam->setRotationDegrees(this->rotation);
        }

        return;

    }



    velocityNormalized = distanceToCrop.normalized();

    // move towards crop
    this->location += velocityNormalized * speed;
    this->rotation = velocityNormalized.angle().asDegrees() + 90.0f;
}

void HatchlingShip::draw(sf::RenderTarget &target, const sf::RenderStates &states) const {
    sprite.setPosition({location.x, location.y});
    sprite.setScale({ 1.0f / sprite.getTexture()->getSize().x, 1.0f / sprite.getTexture()->getSize().y });

    sprite.setRotation(sf::degrees(rotation));
    target.draw(sprite);

    if(tractorBeam)
        tractorBeam->draw(target, states);
}

float HatchlingShip::getZOrder() const {
    return 2.f;
}