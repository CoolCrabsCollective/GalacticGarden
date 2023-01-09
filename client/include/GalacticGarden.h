//
// Created by Winter on 12/02/2022.
//
#pragma once
#include <WIZ/game/BasicGame.h>

class GalacticGarden : public wiz::BasicGame {
public:
	GalacticGarden(std::shared_ptr<sf::RenderWindow> window,
				std::shared_ptr<wiz::Logger> logger,
				std::shared_ptr<wiz::AssetLoader> assetLoader);

    // Stupid shit (blame SFML joy)
    std::string joyStickName;

    const std::string &getJoyStickName() const;

    void setJoyStickName(const sf::String joyStickName);
};

