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
    
    cameraPosition = cameraPosition * 0.995f + space.getShip().getLocation() * 0.005f;
	target.setView(sf::View(cameraPosition, Space::VIEW_SIZE));
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

void SpaceScreen::processInput(float delta) {
    bool connected = sf::Joystick::isConnected(0);
    // TODO: figure out why TF fetching the joystick name doesn't work
    mappingFound = connected;
//    if (connected) {
//        sf::Joystick::Identification id = sf::Joystick::getIdentification(0);
//        if (controllerDisconnected && mappingDatabase.hasMapping(id.name)) {
//            mapping = mappingDatabase.getMapping(id.name);
//            controllerDisconnected = false;
//            mappingFound = true;
//        }
//    } else {
//        controllerDisconnected = true;
//        mappingFound = false;
//    }

    bool isFiring = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) || sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

    if(isFiring)
        space.getShip().fire();

//    bool isPlanting = mappingFound && connected ? sf::Joystick::isButtonPressed(0, mapping.getButton(wiz::MapButton::Left_Shoulder)) :
//            (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) ||
//            sf::Mouse::isButtonPressed(sf::Mouse::Button::Right));

    bool isPlanting = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) || sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);

    if (isPlanting)
        space.getShip().PlantOnAsteroid(space);

    float xAxisInput = mappingFound && connected ? sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) :
                       (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                       ? 100.00 : (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ? -100.00 : 0.00);

    float yAxisInput = mappingFound && connected ? sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) :
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
        rotation = pos.angle().asDegrees();
    }
    space.getShip().setRotation(rotation + 90.0f);
}
