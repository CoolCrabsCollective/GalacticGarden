//
// Created by Alexander Winter on 2023-01-07.
//

#include "MiniMap.h"
#include "world/enemy/EnemyShip.h"
#include "SpaceScreen.h"
#include "util/SpriteUtil.h"

MiniMap::MiniMap(SpaceScreen& screen) 
    : screen(screen) {
    mapSprite.setTexture(*screen.getAssets().get(GameAssets::MAP_BG));
    sprite.setTexture(*screen.getAssets().get(GameAssets::CIRCLE));
    arrowSprite.setTexture(*screen.getAssets().get(GameAssets::ARROW));
}

void MiniMap::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
    target.setView(sf::View({ 800.0f, 450.0f }, { 1600.0f, 900.0f }));
    
    sf::Vector2f offset = { 1410.0f, 10.0f };
    sf::Vector2f size = { 180.0f, 180.0f };

    SpriteUtil::setSpriteOrigin(mapSprite, { 0.5f, 0.5f });
    mapSprite.setPosition(offset + size / 2.0f);
    SpriteUtil::setSpriteSize(mapSprite, size);
    target.draw(mapSprite);
    float mapSize = 50.0f;
    
    sf::Vector2f center = screen.getSpace().getShip().getLocation();

    SpriteUtil::setSpriteOrigin(arrowSprite, { 0.5f, 0.5f });
    SpriteUtil::setSpriteSize(arrowSprite, { 16.0f, 16.0f });
    SpriteUtil::setSpriteOrigin(sprite, { 0.5f, 0.5f });
    
    for(Entity* entity : screen.getSpace().getEntities()) {
        if(dynamic_cast<Ship*>(entity)) 
            sprite.setColor(sf::Color::White);
        else if(dynamic_cast<GayStation*>(entity))
            sprite.setColor(sf::Color::Yellow);
        else if(dynamic_cast<Asteroid*>(entity))
            sprite.setColor(sf::Color::Green);
        else if(dynamic_cast<EnemyShip*>(entity))
            sprite.setColor(sf::Color::Red);
        else
            continue;

        SpriteUtil::setSpriteSize(sprite, (entity->getVisualSize() / mapSize).cwiseMul(size));
        
        sf::Vector2f pos = offset + (entity->getLocation() - center + sf::Vector2f { mapSize / 2.0f, mapSize / 2.0f }).cwiseMul(size) / mapSize;
        
        if(pos.x < offset.x 
        || pos.y < offset.y 
        || pos.x > offset.x + size.x
        || pos.y > offset.y + size.y) {
            if(dynamic_cast<GayStation*>(entity)) {
                arrowSprite.setRotation((entity->getLocation() - center).angle() + sf::degrees(90.0f));
                
                pos.x = fmax(pos.x, offset.x);
                pos.x = fmin(pos.x, offset.x + size.x);
                pos.y = fmax(pos.y, offset.y);
                pos.y = fmin(pos.y, offset.y + size.y);

                arrowSprite.setColor(sf::Color::Yellow);
                arrowSprite.setPosition(pos);
                target.draw(arrowSprite);
            }
            continue;   
        }

        sprite.setPosition(pos);
        target.draw(sprite);
    }
}
