//
// Created by william on 07/01/23.
//

#ifndef LD52_CLIENT_WEAPONSELECTION_H
#define LD52_CLIENT_WEAPONSELECTION_H

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"

class SpaceScreen;

class WeaponSelection : public sf::Drawable {
    mutable sf::Sprite backdrop;
    mutable sf::Sprite item;
    mutable sf::Text text;
public:
    explicit WeaponSelection(SpaceScreen& screen);

    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

};

#endif //LD52_CLIENT_WEAPONSELECTION_H
