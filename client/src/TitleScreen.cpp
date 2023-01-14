//
// Created by Alexander Winter on 2022-03-12.
//

#include "TitleScreen.h"

#include <memory>
#include "GameAssets.h"
#include "SFML/Window/Touch.hpp"
#include "SpaceScreen.h"
#include "GalacticGarden.h"
#include "util/MathUtil.h"

TitleScreen::TitleScreen(wiz::Game& game)
	: Screen(game) {
    
    pressStartText.setString("Press any key to start");
    pressStartText.setScale({ 1.0f, 1.0f });
    pressStartText.setFont(*getAssets().get(GameAssets::VT323_TTF));
    pressStartText.setCharacterSize(60);
    pressStartText.setFillColor(sf::Color::White);
}

void TitleScreen::tick(float delta) {

	logo.setPosition({ 640.0f, 720.0f / 2.0f - 100.0f });
	logo.setScale(sf::Vector2f(2.0f, 2.0f));
    
    sf::FloatRect textRect2 = pressStartText.getLocalBounds();
    pressStartText.setPosition({ 640.0f - textRect2.width / 2.0f, 500.0f });

	bool pressingButton = false;
	for(int i = 0; sf::Joystick::isConnected(0) && i < sf::Joystick::getButtonCount(0); i++) {
		if(sf::Joystick::isButtonPressed(0, i)) {
			pressingButton = true;
			break;
		}
	}

	if(pressingButton || sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Touch::isDown(1))
	{
		getGame().setScreen(std::make_shared<SpaceScreen>(getGame()));
		return;
	}
}

void TitleScreen::render(sf::RenderTarget& target) {
    target.setView(sf::View({ 640.0f, 360.0f }, { 1280.0f, 720.0f}));
    
	target.clear();
	target.draw(background);
	target.draw(logo);
    target.draw(pressStartText);
}

void TitleScreen::keyPressed(const sf::Event::KeyEvent& keyEvent) {
    if (keyEvent.code != sf::Keyboard::Escape)
        getGame().setScreen(std::make_shared<SpaceScreen>(getGame()));
}

void TitleScreen::show() {
	logo.setTexture(*getAssets().get(GameAssets::LOGO));
	background.setTexture(*getAssets().get(GameAssets::BACKGROUND));
    logo.setOrigin(sf::Vector2f(logo.getTextureRect().getSize() / 2));

    getAssets().get(GameAssets::BACH)->setLoop(true);
    getAssets().get(GameAssets::BACH)->play();

	getGame().addWindowListener(this);
    getGame().addInputListener(this);
}

void TitleScreen::hide() {
    getGame().removeInputListener(this);
	getGame().removeWindowListener(this);
}

const std::string& TitleScreen::getName() const {
	return name;
}

void TitleScreen::windowClosed() {
	getGame().getWindow().close();
}
