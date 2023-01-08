//
// Created by Alexander Winter on 2023-01-07.
//

#include "ui/GameOverMenu.h"
#include "SpaceScreen.h"

#include "util/MathUtil.h"


GameOverMenu::GameOverMenu(SpaceScreen& screen) {
    dim.setTexture(*screen.getAssets().get(GameAssets::WHITE_PIXEL));
    dim.setPosition({ 0.0f, 0.0f });
    dim.setScale(SpaceScreen::UI_VIEW_SIZE);
    dim.setColor(sf::Color(0, 0, 0, 128));
    
    gameover.setTexture(*screen.getAssets().get(GameAssets::GAMEOVER));
    sf::Vector2f vec = SpaceScreen::UI_VIEW_SIZE.cwiseDiv(MathUtil::toFloat(gameover.getTexture()->getSize()));
    gameover.setPosition({ 0.0f, 0.0f });
    gameover.setScale({ vec.x, vec.y / 4.0f * 16.0f / 9.0f });

    text.setString("The Cosmic Crows have defeated you and are now eating your vegetables.\n\nPress any key to restart");
    text.setScale({1.0f, 1.0f});
    text.setFont(*screen.getAssets().get(GameAssets::VT323_TTF));
    text.setCharacterSize(60);
    text.setFillColor(sf::Color::White);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setPosition({ SpaceScreen::UI_VIEW_SIZE.x / 2.0f - textRect.width, 600.0f});
}

void GameOverMenu::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
    target.draw(dim);
    target.draw(gameover);
    target.draw(text);
}
