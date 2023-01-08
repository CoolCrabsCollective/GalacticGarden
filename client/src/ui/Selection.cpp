//
// Created by william on 07/01/23.
//

#include "ui/Selection.h"
#include "SpaceScreen.h"

#include "util/MathUtil.h"

Selection::Selection(SpaceScreen& screen) {
    sf::Vector2f pos = { 270.0f, 910.0f };
    sf::Vector2f size = { .8f, .8f };

    backdrop.setTexture(*screen.getAssets().get(GameAssets::TEXTURE_WEAPON_SELECT_BACKDROP));
    backdrop.setPosition(pos);
    backdrop.setScale(size);

    sf::Vector2f itemOffset = { backdrop.getLocalBounds().width / 5.f + 2.4f, backdrop.getLocalBounds().height - 115.f };
    sf::Vector2f itemSize = { 1.f, 1.f };

    item.setTexture(*screen.getAssets().get(GameAssets::TEXTURE_GAY_STATION));
    item.setPosition(pos + itemOffset);
    item.setScale(itemSize);

    sf::Vector2f textOffset = {backdrop.getLocalBounds().width / 4.f - 1.f, -62.5f + backdrop.getLocalBounds().height};
    sf::Vector2f textSize = { .5f, .5f };

    text.setString("Single");
    text.setScale(textSize);
    text.setFont(*screen.getAssets().get(GameAssets::SANS_TTF));
    text.setFillColor(sf::Color::White);
    text.setPosition(pos + textOffset);
}

void Selection::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
    target.draw(backdrop);
    target.draw(item);
    target.draw(text);
}