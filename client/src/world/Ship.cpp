//
// Created by cedric on 1/6/23.
//

#include "world/Space.h"
#include "world/Ship.h"
#include "GameAssets.h"
#include "world/weapon/SmallLaser.h"
#include "world/crop/Crop.h"
#include "world/Asteroid.h"

Ship::Ship(Space& space, const sf::Vector2f& location) 
	: Entity(space, location) {
	
	this->sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_SHIP), true);
    sprite.setOrigin({ sprite.getTexture()->getSize().x / 2.0f, sprite.getTexture()->getSize().y / 2.0f });
}

void Ship::tick(float delta) {
    float bad_delta = delta / 1000.f;
    sf::Vector2f newPos = { moveVelocity.x * bad_delta + this->location.x, moveVelocity.y * bad_delta + this->location.y };

    this->location = newPos;
    time_since_last_fire += bad_delta;
    time_since_last_plant += bad_delta;
    
    for(Entity* entity : space.getAllEntitiesInRect(location, { 2.0f, 2.0f })) {
        Crop* crop = dynamic_cast<Crop*>(entity);
        if(crop && crop->isReady() && (crop->getLocation() - location).lengthSq() < 1.0f) {
            crop->harvest();
            harvestedCount++;
        }
    }
}

float Ship::getRotation() const {
    return rotation;
}

void Ship::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
	sprite.setPosition(location);
	sprite.setScale({ 1.0f / sprite.getTexture()->getSize().x, 1.0f / sprite.getTexture()->getSize().y });
    sprite.setRotation(sf::degrees(rotation));
	target.draw(sprite);
}

float Ship::getZOrder() const {
    return 8.f;
}

void Ship::moveInDirOfVec(const sf::Vector2f& moveVec, float good_delta) {
    sf::Vector2f moveVecNorm { 0.f, 0.f };
    
    if(moveVec.length() > 0.001f) // is not zero
        moveVecNorm = moveVec.normalized();

    this->moveVelocity += moveVecNorm * acc * good_delta;
    if(this->moveVelocity.length() > maxSpeed)
    {
        this->moveVelocity = this->moveVelocity.normalized() * maxSpeed;
    }
}

void Ship::fire() {
    if(time_since_last_fire >= fire_delay)
    {
        switch(lazerType) {

            case SIMPLE:
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation))));
                break;
            case DOUBLE:
                space.addEntity(new SmallLaser(space, location + (sf::Vector2f {0.25f, 0.0f}).rotatedBy(sf::degrees(rotation)), sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation))));
                space.addEntity(new SmallLaser(space, location + (sf::Vector2f {-0.25f, 0.0f}).rotatedBy(sf::degrees(rotation)), sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation))));
                break;
            case TRIANGLE:
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation))));
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation - 15.0f))));
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation + 15.0f))));
                break;
            case FOUR_WAY:
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation))));
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation + 90.0f))));
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation + 180.0f))));
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation + 270.0f))));
                break;
            case CRAZY:
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation))));
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation + 90.0f))));
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation + 180.0f))));
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation + 270.0f))));
                space.addEntity(new SmallLaser(space, location + (sf::Vector2f {0.25f, 0.0f}).rotatedBy(sf::degrees(rotation)), sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation))));
                space.addEntity(new SmallLaser(space, location + (sf::Vector2f {-0.25f, 0.0f}).rotatedBy(sf::degrees(rotation)), sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation))));
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation - 15.0f))));
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation + 15.0f))));
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation - 30.0f))));
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation + 30.0f))));
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation - 45.0f))));
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation + 45.0f))));
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation - 60.0f))));
                space.addEntity(new SmallLaser(space, location, sf::Vector2f(0.f, -1.0f).rotatedBy(sf::degrees(rotation + 60.0f))));
                break;
        }
        
        time_since_last_fire = 0.f;
    }
}

void Ship::setRotation(float rotationRad) {
    this->rotation = rotationRad;
}

void Ship::plantOnAsteroid(Space& space) {
    if(time_since_last_plant >= plant_delay) {
        sf::Vector2f shipLocation = space.getShip().getLocation();

        std::vector<Entity *> entities = space.getAllEntitiesInRect(this->location, {6, 6});

        for (Entity *entity: entities) {
            Asteroid *asteroid = dynamic_cast<Asteroid *>(entity);

            if (asteroid != nullptr) {
                std::optional<sf::Vector2f> closestPlantingZone = asteroid->getClosestAvailablePlantingZone(shipLocation);
                if (closestPlantingZone.has_value()) {
                    asteroid->plant(CropType::FLOWER, closestPlantingZone.value());
                    time_since_last_plant = .0f;
                }
                break;
            }
        }
    }
}

void Ship::setLazerType(LazerType lazer_type) {
    this->lazerType = lazer_type;
}
