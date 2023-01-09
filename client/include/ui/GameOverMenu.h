//
// Created by Alexander Winter on 2023-01-07.
//

#ifndef LD52_CLIENT_GAMEOVERMENU_H
#define LD52_CLIENT_GAMEOVERMENU_H


#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"

class SpaceScreen;

class GameOverMenu : public sf::Drawable {
    mutable sf::Sprite dim;
    mutable sf::Sprite gameover;
    mutable sf::Text text, scoreText;
public:
    explicit GameOverMenu(SpaceScreen& screen);

    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
    
    void setStats(int wazeNumber, int score);
};


#endif //LD52_CLIENT_GAMEOVERMENU_H
