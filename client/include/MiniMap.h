//
// Created by Alexander Winter on 2023-01-07.
//

#ifndef LD52_CLIENT_MINIMAP_H
#define LD52_CLIENT_MINIMAP_H

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"

class SpaceScreen;

class MiniMap : public sf::Drawable {
    SpaceScreen& screen;
    mutable sf::Sprite sprite, arrowSprite;
public:
    explicit MiniMap(SpaceScreen& screen);

    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
};


#endif //LD52_CLIENT_MINIMAP_H
