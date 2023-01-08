//
// Created by Alexander Winter on 2023-01-07.
//

#include "MiniMap.h"
#include "world/enemy/EnemyShip.h"
#include "SpaceScreen.h"

MiniMap::MiniMap(SpaceScreen& screen) 
    : screen(screen) {
    sprite.setTexture(*screen.getAssets().get(GameAssets::WHITE_PIXEL));
}

void MiniMap::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
    target.setView(sf::View({ 800.0f, 450.0f }, { 1600.0f, 900.0f }));
    
    sf::Vector2f offset = { 1410.0f, 10.0f };
    sf::Vector2f size = { 180.0f, 180.0f };

    sprite.setOrigin({ 0.5f, 0.5f });
    sprite.setColor(sf::Color::Black);
    sprite.setPosition(offset + size / 2.0f);
    sprite.setScale(size);
    target.draw(sprite);
    float mapSize = Space::MAP_RADIUS * 2.0f;
    
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

        //sprite.setScale((entity->getVisualSize() / mapSize).cwiseMul(size));
        sprite.setScale({ 2.0f, 2.0f });
        sprite.setPosition(offset + (entity->getLocation() + sf::Vector2f { mapSize / 2.0f, mapSize / 2.0f }).cwiseMul(size) / mapSize);
        target.draw(sprite);
    }
}
