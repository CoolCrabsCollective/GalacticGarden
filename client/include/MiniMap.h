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
    const sf::Color spaceStationColor = sf::Color::Yellow;
    const sf::Color noPlantingSpotsColor = sf::Color(128, 128, 128, 255);
    const sf::Color unplantedAsteroidColor = sf::Color(128, 128, 128, 255);
    const sf::Color plantedAsteroidColor = sf::Color::Blue;
    const sf::Color readyAsteroidColor = sf::Color::Green;
    const sf::Color enemyShipColor = sf::Color::Red;
public:
    explicit MiniMap(SpaceScreen& screen);

    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
};


#endif //LD52_CLIENT_MINIMAP_H
