//
// Created by william on 06/01/23.
//

#include "SpaceScreen.h"
#include "SFML/Window/Touch.hpp"
#include <string>

SpaceScreen::SpaceScreen(wiz::Game& game)
	: Screen(game), space(game.getAssets()), mappingDatabase() {
  mappingDatabase.loadFromCSV(*getGame().getAssets().get(GameAssets::CONTROLLER_DB));
}

void SpaceScreen::tick(float delta) {
	sf::Vector2f vec = { 1.0f, 1.0f };

	vec.x /= static_cast<float>(background.getTextureRect().getSize().x);
	vec.y /= static_cast<float>(background.getTextureRect().getSize().y);
	background.setScale(vec);
	
	space.tick(delta);
}

void SpaceScreen::render(sf::RenderTarget& target) {
	target.clear();
	target.setView(sf::View({ 0.5f, 0.5f }, { 1.0f, 1.0f }));
	
	target.draw(background);
	target.setView(sf::View({ space.getShip().getLocation().x,
	                          space.getShip().getLocation().y }, Space::VIEW_SIZE));
	
	target.draw(space);
}

void SpaceScreen::show() {
	background.setTexture(*getGame().getAssets().get(GameAssets::BACKGROUND));

	getGame().addWindowListener(this);
    getGame().addInputListener(this);
}

void SpaceScreen::hide() {
	getGame().removeWindowListener(this);
    getGame().removeInputListener(this);
}

void SpaceScreen::mouseButtonPressed(const sf::Event::MouseButtonEvent &mouseButtonEvent) {
    if(mouseButtonEvent.button == sf::Mouse::Button::Left)
    {
        space.getShip().fire();
    }
}

void SpaceScreen::keyPressed(const sf::Event::KeyEvent &keyEvent) {
    if(keyEvent.code == sf::Keyboard::Key::Space)
    {
        space.getShip().fire();
    }
}

const std::string& SpaceScreen::getName() const {
	return name;
}

void SpaceScreen::windowClosed() {
	getGame().getWindow().close();
}