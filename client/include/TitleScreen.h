//
// Created by Alexander Winter on 2022-03-12.
//

#ifndef WIZENGINEQUICKSTART_CLIENT_TITLESCREEN_H
#define WIZENGINEQUICKSTART_CLIENT_TITLESCREEN_H

#include <WIZ/game/Screen.h>
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Sprite.hpp"

class TitleScreen : public wiz::Screen, public wiz::WindowListener, public wiz::InputListener {
	std::string name = "TitleScreen";

	sf::Sprite logo;
	sf::Sprite background;
    sf::Text pressStartText;
public:
	TitleScreen(wiz::Game& game);

	void tick(float delta) override;

	void render(sf::RenderTarget& target) override;

	void show() override;

	void hide() override;

	const std::string& getName() const override;

	void windowClosed() override;

    void keyPressed(const sf::Event::KeyEvent& keyEvent) override;
};


#endif //WIZENGINEQUICKSTART_CLIENT_TITLESCREEN_H
