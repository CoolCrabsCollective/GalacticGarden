//
// Created by william on 06/01/23.
//

#include "SpaceScreen.h"
#include "SFML/Window/Touch.hpp"
#include <string>
#include <X11/Xlibint.h>
#include "GameAssets.h"
#include "MiniMap.h"

SpaceScreen::SpaceScreen(wiz::Game& game)
	: Screen(game),
        space(game.getAssets()),
        mappingDatabase(),
        gameOverMenu(*this),
        miniMap(*this),
        dialogBox(game.getAssets().get(GameAssets::VT323_TTF),  game.getAssets().get(GameAssets::DIALOG_BOX)),
        weaponSelectionUi(*this),
        upgradeMenu(space, space.getUpgradeManager()) {
    mappingDatabase.loadFromCSV(*getGame().getAssets().get(GameAssets::CONTROLLER_DB));
    smoothPosition = cameraPosition = space.getShip().getLocation();
    shipSmoothVelocity = { 0.0f, 0.0f };
    energySprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_ENERGY));

    space.paused = true;
    dialogBox.startDialog({
        "~CAW~ We have detected the human base!",
        "We're not going out that easy...",
        "~CAW~ I'm hungry",
    }, {"Cosmic Crow", "Celestial Chad",
        "Cosmic Crow"},
              {getGame().getAssets().get(GameAssets::TEXTURE_COSMIC_CROW_ICON),
               getGame().getAssets().get(GameAssets::TEXTURE_CELESTIAL_CHAD_ICON),
               getGame().getAssets().get(GameAssets::TEXTURE_COSMIC_CROW_ICON)
               },
               [&]() {
                    space.paused = false;
                    printf("penis");
               }
               );
}

void SpaceScreen::tick(float delta) {
    dialogBox.update(delta);

    if (space.paused)
        return;

    if(!space.gameover) {
        processInput(delta);
        space.tick(delta);
        
        float trans = pow(0.99f, delta);

        shipSmoothVelocity = shipSmoothVelocity * trans + space.getShip().getMoveVelocity() * (1.0f - trans);

        smoothPosition = smoothPosition * trans + (space.getShip().getLocation()) * (1.0f - trans);
        cameraPosition = space.getShip().getLocation() + space.getShip().getLocation() - smoothPosition;
    } else {
        gameoverCooldown -= delta / 1000.0f;
    }
}

void SpaceScreen::render(sf::RenderTarget& target) {

    sf::Vector2f vec = { 1.0f, 1.0f };
    vec.x /= static_cast<float>(background.getTextureRect().getSize().x);
    vec.y /= static_cast<float>(background.getTextureRect().getSize().y);
    background.setScale(vec);
    energySprite.setPosition({50.f, 900.f});
    energySprite.setScale({8.0f * 16.0f / energySprite.getTexture()->getSize().x, 8.0f * 16.0f / energySprite.getTexture()->getSize().y});

    energyText.setString(std::to_string(space.getShip().getEnergy()));
    energyText.setPosition({ 175.f, 925.f});
    energyText.setScale({2.f, 2.f});
    energyText.setFillColor(sf::Color::White);
    energyText.setFont(*space.getAssets().get(GameAssets::SANS_TTF));
    
	target.clear();
	target.setView(sf::View({ 0.5f, 0.5f }, { 1.0f, 1.0f }));
	target.draw(background);
    
	target.setView(sf::View(cameraPosition, Space::VIEW_SIZE * zoom));
	target.draw(space);

    // mini map
    target.draw(miniMap);

    // ui
    target.setView(sf::View(SpaceScreen::UI_VIEW_SIZE / 2.0f, SpaceScreen::UI_VIEW_SIZE));
    target.draw(energySprite);
    target.draw(energyText);
    if(space.gameover)
        target.draw(gameOverMenu);

    target.draw(weaponSelectionUi);

    target.draw(dialogBox);
    target.draw(upgradeMenu);
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

void SpaceScreen::mouseWheelScrolled(const sf::Event::MouseWheelScrollEvent& mouseWheelScrollEvent) {
    zoom -= mouseWheelScrollEvent.delta;
    zoom = fmax(zoom, 1.0f);
}

void SpaceScreen::mouseButtonPressed(const sf::Event::MouseButtonEvent &mouseButtonEvent) {
    if(space.gameover && gameoverCooldown <= 0.0f) {
        getGame().setScreen(new SpaceScreen(getGame()));
        return;
    }
}

void SpaceScreen::keyPressed(const sf::Event::KeyEvent &keyEvent) {
    if(space.gameover && gameoverCooldown <= 0.0f) {
        getGame().setScreen(new SpaceScreen(getGame()));
        return;
    }
    
    switch(keyEvent.code) {
        case sf::Keyboard::Escape:
            if(!space.gameover)
                space.gameover = true;
            break;

        case sf::Keyboard::Space:
            if (dialogBox.isInProgress())
                dialogBox.interact();
            break;

        case sf::Keyboard::Num1:
        case sf::Keyboard::Numpad1:
            space.getShip().setLazerType(LazerType::SIMPLE);
            break;
        
        case sf::Keyboard::Num2:
        case sf::Keyboard::Numpad2:
            space.getShip().setLazerType(LazerType::DOUBLE);
            break;
        
        case sf::Keyboard::Num3:
        case sf::Keyboard::Numpad3:
            space.getShip().setLazerType(LazerType::TRIANGLE);
            break;
        
        case sf::Keyboard::Num4:
        case sf::Keyboard::Numpad4:
            space.getShip().setLazerType(LazerType::FOUR_WAY);
            break;
            
        case sf::Keyboard::Num5:
        case sf::Keyboard::Numpad5:
            space.getShip().setLazerType(LazerType::CRAZY);
            break;
            
        default:
            break;
    }
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
    bool isBoosting = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift);

    if(isFiring)
        space.getShip().fire();

    space.getShip().setIsBoosting(isBoosting);

//    bool isPlanting = mappingFound && connected ? sf::Joystick::isButtonPressed(0, mapping.getButton(wiz::MapButton::Left_Shoulder)) :
//            (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) ||
//            sf::Mouse::isButtonPressed(sf::Mouse::Button::Right));

    bool isPlanting = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) || sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);

    if (isPlanting)
        space.getShip().plantOnAsteroid(space);

    float xAxisInput = mappingFound && connected ? sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) :
                       (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                       ? 100.00 : (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ? -100.00 : 0.00);

    float yAxisInput = mappingFound && connected ? sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) :
                       (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                       ? -100.00 : (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ? 100.00 : 0.00);

    space.getShip().setIsIdle(std::abs(xAxisInput) <= 0.1 && std::abs(yAxisInput) <= 0.1f);
    sf::Vector2f moveVec = {xAxisInput, yAxisInput};

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

const std::string& SpaceScreen::getName() const {
    return name;
}

const Space& SpaceScreen::getSpace() const {
    return space;
}
