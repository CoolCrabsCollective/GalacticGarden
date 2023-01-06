//
// Created by william on 06/01/23.
//

#ifndef LD52_CLIENT_SPACESCREEN_H
#define LD52_CLIENT_SPACESCREEN_H


#include "GameAssets.h"
#include "WIZ/game/Screen.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
#include "SFML/Audio/Music.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "world/Space.h"

class SpaceScreen : public wiz::Screen, public wiz::WindowListener {
    std::string name = "SpaceScreen";

    sf::Sound sound;
    sf::Music* music;

    sf::Sprite background;
	Space space;

public:
    SpaceScreen(wiz::Game& game);

    void tick(float delta) override;

    void render(sf::RenderTarget& target) override;

    void show() override;

    void hide() override;

    const std::string& getName() const override;

    void windowClosed() override;
};


#endif //LD52_CLIENT_SPACESCREEN_H