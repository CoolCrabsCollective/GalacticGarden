//
// Created by william on 06/01/23.
//

#include "SpaceScreen.h"
#include "SFML/Window/Touch.hpp"
#include <string>

SpaceScreen::SpaceScreen(wiz::Game& game)
	: Screen(game), space(game.getAssets()), mappingDatabase() {
    mappingDatabase.loadFromCSV(*getGame().getAssets().get(GameAssets::CONTROLLER_DB));
    cameraPosition = space.getShip().getLocation();
}

void SpaceScreen::tick(float delta) {
    processInput(delta);
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

}

void SpaceScreen::keyPressed(const sf::Event::KeyEvent &keyEvent) {

}

const std::string& SpaceScreen::getName() const {
	return name;
}

void SpaceScreen::windowClosed() {
	getGame().getWindow().close();
}
#include <iostream>
void SpaceScreen::processInput(float delta) {
    bool isFiring = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) ||
                    sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

    if(isFiring)
        space.getShip().fire();

    bool isPlanting = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) ||
                      sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);

    if (isPlanting)
        space.getShip().PlantOnAsteroid(space);

    bool rotateLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q);
    bool rotateRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E);

    bool connected = sf::Joystick::isConnected(0);

    float xAxisInput = connected ? sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) :
                       (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                       ? 100.00 : (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ? -100.00 : 0.00);

    float yAxisInput = connected ? sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) :
                       (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                       ? -100.00 : (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ? 100.00 : 0.00);

    sf::Vector2f moveVec = {xAxisInput, yAxisInput};

    sf::Vector2i mousePos = sf::Mouse::getPosition();
    space.getShip().moveInDirOfVec(moveVec, delta / 1000.f);

    sf::Vector2f pos = getWindow().mapPixelToCoords(sf::Mouse::getPosition(getWindow()), sf::View({ 0.f, 0.f }, Space::VIEW_SIZE));

    float rotation = 0.0f;
    if(pos.length() >= 0.0001)
    {
        pos = pos.normalized();
        rotation = pos.angle().asRadians();
    }
    space.getShip().setRotation(rotation + M_PI_2);
}
