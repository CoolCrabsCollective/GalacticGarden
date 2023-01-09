//
// Created by Alexander Winter on 2023-01-07.
//

#ifndef LD52_CLIENT_MINIMAP_H
#define LD52_CLIENT_MINIMAP_H

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"

class SpaceScreen;

class MiniMap : public sf::Drawable {
protected:
    SpaceScreen& screen;
    mutable sf::Sprite mapSprite, sprite, arrowSprite;

    const sf::Color shipColor = sf::Color::White;
    const sf::Color spaceStationColor = sf::Color(0xd5, 0xe0, 0x4b);
    const sf::Color noPlantingSpotsColor = sf::Color(0x9b, 0xab, 0xb2);
    const sf::Color unplantedAsteroidColor = sf::Color(0x9b, 0xab, 0xb2);
    const sf::Color plantedAsteroidColor = sf::Color(0x4d, 0x9b, 0xe6);
    const sf::Color readyAsteroidColor = sf::Color(0x1e, 0xbc, 0x73);
    const sf::Color enemyShipColor = sf::Color(0xe8, 0x3b, 0x3b);

public:
    explicit MiniMap(SpaceScreen& screen);

    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
};


#endif //LD52_CLIENT_MINIMAP_H
