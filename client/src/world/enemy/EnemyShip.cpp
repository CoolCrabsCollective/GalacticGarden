//
// Created by cedric on 1/6/23.
//

#include "world/Space.h"
#include "world/enemy/EnemyShip.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "world/weapon/Lazer.h"


EnemyShip::EnemyShip(Space &space, sf::Vector2f location) 
    : Entity(space, location) {

}

void EnemyShip::draw(sf::RenderTarget &target, const sf::RenderStates &states) const {
    if(shouldBeRemoved())
        return;
    
    sprite.setOrigin({0.5f * sprite.getTexture()->getSize().x, 0.5f * sprite.getTexture()->getSize().y});
    sprite.setPosition(location);
    sprite.setScale({ 1.0f / sprite.getTexture()->getSize().x, 1.0f / sprite.getTexture()->getSize().y });

    sprite.setRotation(sf::degrees(rotation));
    target.draw(sprite);
}

void EnemyShip::tick(float delta) {
    if(shouldBeRemoved())
        return;
    
    for(Entity* entity : space.getAllEntitiesInRect(location, { 1.0f, 1.0f })) {
        if(entity->shouldBeRemoved())
            continue;
        
        if(Lazer* lazer = dynamic_cast<Lazer*>(entity)) {
            health -= lazer->getDamage();
            lazer->consume();
            if(health <= 0.0f) {
                health = 0.0f;
                return;
            }
        }
    }
}

bool EnemyShip::shouldBeRemoved() const {
    return health == 0.0f;
}
