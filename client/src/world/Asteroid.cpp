//
// Created by Alexander Winter on 2023-01-06.
//

#include "world/Asteroid.h"
#include "GameAssets.h"
#include "world/Space.h"

Asteroid::Asteroid(Space& space, 
				   const sf::Vector2f& location, 
				   float rotation,
				   float size,
				   const sf::Vector2f& startVelocity,
				   float startAngVelocity) 
	: Entity(space, location) {
	
	sprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_ASTEROID), true);
	sprite.setOrigin({ sprite.getTexture()->getSize().x / 2.0f, sprite.getTexture()->getSize().y / 2.0f });

    zoneSprite.setTexture(*space.getAssets().get(GameAssets::WHITE_PIXEL), true);
    zoneSprite.setOrigin({ zoneSprite.getTexture()->getSize().x / 2.0f, zoneSprite.getTexture()->getSize().y / 2.0f });
	
	this->rotation = rotation;
	
	this->size = size;
	this->velocity = startVelocity;
	this->angularVelocity = startAngVelocity;

  generatePlantingZones();
}

void Asteroid::tick(float delta) {
	
	sf::Vector2 extent = { size + MAX_SIZE, size + MAX_SIZE };
	
	std::vector<Entity*> close = space.getAllEntitiesInRect(location, extent);
	
	for(Entity* entity : close) {
		Asteroid* other = dynamic_cast<Asteroid*>(entity);
		
		if(other) {
			sf::Vector2f normal = other->getLocation() - location;
			float dst2 = normal.lengthSq();
			float normalDst = size / 2.0f + other->size / 2.0f;
			if(dst2 < normalDst * normalDst * 7.0f / 8.0f && velocity.dot(normal) > 0.0f) {
				velocity = velocity - 2.0f * velocity.dot(normal) * normal / normal.lengthSq();
				angularVelocity = -angularVelocity;
			}
		}
	}
	
	this->location += this->velocity * delta / 1000.0f;
	this->rotation += this->angularVelocity * delta / 1000.0f;
}

float Asteroid::getZOrder() const {
	return 0;
}

void Asteroid::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
	sprite.setPosition(location);
	sprite.setScale({ size / sprite.getTexture()->getSize().x, size / sprite.getTexture()->getSize().y });
	sprite.setRotation(sf::degrees(rotation));
	target.draw(sprite);
	
	for(auto &[key, value] : plantingZones) {
        
        zoneSprite.setPosition(location + key.rotatedBy(sf::degrees(rotation)));
        zoneSprite.setScale({ 0.5f / zoneSprite.getTexture()->getSize().x, 0.5f / zoneSprite.getTexture()->getSize().y });
        target.draw(zoneSprite);
	}
}

void Asteroid::generatePlantingZones() {
	float minRadius = size / 4.0f;
	float maxRadius = size / 2.0f * 7.0f / 8.0f;

    int randDir = 0;
    int randDes = 0;

    for(int i = 0; i<10; i++) {
		randDir = rand() % 360;
		randDes = rand() * minRadius / maxRadius;

		plantingZones.insert(std::pair<sf::Vector2f, Crop*>{{randDes * cosf(randDir), randDes * sinf(randDir)}, nullptr});
    }
}
