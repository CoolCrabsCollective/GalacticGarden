//
// Created by william on 07/01/23.
//

#ifndef LD52_CLIENT_SELECTION_H
#define LD52_CLIENT_SELECTION_H

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"

class SpaceScreen;

class Selection : public sf::Drawable {
    mutable sf::Sprite backdrop;
    mutable sf::Sprite item;
    mutable sf::Text text;
public:
    explicit Selection(SpaceScreen& screen);

    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

};

#endif //LD52_CLIENT_SELECTION_H
