//
// Created by william on 07/01/23.
//

#include "ui/WeaponSelection.h"
#include "SpaceScreen.h"

#include "util/MathUtil.h"

WeaponSelection::WeaponSelection(SpaceScreen& screen) {
    backdrop.setTexture(*screen.getAssets().get(GameAssets::TEXTURE_WEAPON_SELECT_BACKDROP));
    backdrop.setPosition({ SpaceScreen::UI_VIEW_SIZE.x, SpaceScreen::UI_VIEW_SIZE.y });
    backdrop.setScale(SpaceScreen::UI_VIEW_SIZE);
    backdrop.setColor(sf::Color(0, 0, 0, 128));

//    text.setString("Single");
//    text.setScale({.2f, .2f});
//    text.setFont(*screen.getAssets().get(GameAssets::SANS_TTF));
//    text.setFillColor(sf::Color::White);
//    sf::FloatRect textRect = text.getLocalBounds();
//    text.setPosition({ SpaceScreen::UI_VIEW_SIZE.x / 2.0f - textRect.width, 600.0f});
}

void WeaponSelection::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
    target.draw(backdrop);
//    target.draw(text);
}