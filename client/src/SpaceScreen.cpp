//
// Created by william on 06/01/23.
//

#include "SpaceScreen.h"
#include "SFML/Window/Touch.hpp"
#include <string>

SpaceScreen::SpaceScreen(wiz::Game& game)
	: Screen(game), space(game.getAssets()) {
}

void SpaceScreen::tick(float delta) {
	sf::Vector2f vec(getGame().getWindow().getView().getSize());

	vec.x /= static_cast<float>(background.getTextureRect().getSize().x);
	vec.y /= static_cast<float>(background.getTextureRect().getSize().y);
	background.setScale(vec);
	
	space.tick(delta);
}

void SpaceScreen::render(sf::RenderTarget& target) {
	target.clear();
	target.draw(background);
	target.draw(space);
}

void SpaceScreen::show() {
	background.setTexture(*getGame().getAssets().get(GameAssets::BACKGROUND));

	getGame().addWindowListener(this);
}

void SpaceScreen::hide() {
	getGame().removeWindowListener(this);
}

const std::string& SpaceScreen::getName() const {
	return name;
}

void SpaceScreen::windowClosed() {
	getGame().getWindow().close();
}