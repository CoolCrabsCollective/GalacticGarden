//
// Created by william on 06/01/23.
//

#include "SpaceScreen.h"
#include "SFML/Window/Touch.hpp"
#include <string>
#include <X11/Xlibint.h>
#include "GameAssets.h"
#include "MiniMap.h"
#include "world/FloatingText.h"

SpaceScreen::SpaceScreen(wiz::Game& game)
	: Screen(game),
        space(game.getAssets(), [&](int waveNumber){
            switch(waveNumber)
            {
                case 0:
                    space.paused = true;
                    dialogBox.startDialog({
                                                  "~Caw~ ~Caw~ ~Caw~ I see the space station! Vegetables!",
                                                  "Giddy up birdy.",
                                          },
                                          {
                                                  "Celestial Crow",
                                                  "Celestial Chad",
                                          },
                                          {
                                                  getGame().getAssets().get(GameAssets::TEXTURE_COSMIC_CROW_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_CELESTIAL_CHAD_ICON),

                                          },
                                          [&]() {
                                              space.paused = false;
                                          }
                    );
                    break;
                case 1:
                    space.paused = true;
                    dialogBox.startDialog({
                                                  "Another wave of crow hatchlings is inbound commander! Get Ready!",
                                                  "Don't sweat it.",
                                          },
                                          {
                                                  "Cadet Candice",
                                                  "Celestial Chad",
                                          },
                                          {
                                                  getGame().getAssets().get(GameAssets::TEXTURE_CADET_CANDICE_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_CELESTIAL_CHAD_ICON),

                                          },
                                          [&]() {
                                              space.paused = false;
                                          }
                    );
                    break;
                case 2:
                    space.paused = true;
                    dialogBox.startDialog({
                                                  "Even more hatchlings coming!",
                                                  "Yee-haw!. We're wrangling crows tonight!",
                                                  "~CAW~ ~CAW~ ~CAW~",
                                          },
                                          {
                                                  "Cadet Candice",
                                                  "Celestial Chad",
                                                  "Cosmic Crow",
                                          },
                                          {
                                                  getGame().getAssets().get(GameAssets::TEXTURE_CADET_CANDICE_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_CELESTIAL_CHAD_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_COSMIC_CROW_ICON),

                                          },
                                          [&]() {
                                              space.paused = false;
                                          }
                    );
                    break;
                case 3:
                    space.paused = true;
                    dialogBox.startDialog({
                                                  "~CAW~ It appears my hatchlings have failed me...",
                                                  "Send in the crowcraft! ~CAW~ ~CAW~",
                                          },
                                          {
                                                  "Lord Crow",
                                                  "Lord Crow",
                                          },
                                          {
                                                  getGame().getAssets().get(GameAssets::TEXTURE_LORD_CROW_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_LORD_CROW_ICON),

                                          },
                                          [&]() {
                                              space.paused = false;
                                          }
                    );
                    break;
                case 4:
                    space.paused = true;
                    dialogBox.startDialog({
                                                  "I'm detecting additional reinforcements, be careful Celestial Chad.",
                                          },
                                          {
                                                  "Cadet Candice",
                                          },
                                          {
                                                  getGame().getAssets().get(GameAssets::TEXTURE_CADET_CANDICE_ICON),

                                          },
                                          [&]() {
                                              space.paused = false;
                                          }
                    );
                    break;
                case 5:
                    space.paused = true;
                    dialogBox.startDialog({
                                                  "The enemy is sending in a Nest! I repeat, the enemy is sending in a Nest!",
                                                  "Oh the humanity!",
                                          },
                                          {
                                                  "Cadet Candice",
                                                  "Cadet Candice",
                                          },
                                          {
                                                  getGame().getAssets().get(GameAssets::TEXTURE_CADET_CANDICE_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_CADET_CANDICE_ICON),
                                          },
                                          [&]() {
                                              space.paused = false;
                                          }
                    );
                    break;
                case 6:
                    space.paused = true;
                    dialogBox.startDialog({
                                                  "Is this all you yellow belly birds got?",
                                          },
                                          {
                                                  "Celestial Chad",
                                          },
                                          {
                                                  getGame().getAssets().get(GameAssets::TEXTURE_CELESTIAL_CHAD_ICON),

                                          },
                                          [&]() {
                                              space.paused = false;
                                          }
                    );
                    break;
                case 7:
                    space.paused = true;
                    dialogBox.startDialog({
                                                  "Holy Pegasus... Lord Crow himself has entered the asteroid belt...",
                                                  "~CAW~ All your vegetables will soon be mine Chad!.",
                                                  "Not if I can help it buster!",
                                                  "I've just about had it with you and your varmint canary friends.",
                                                  "FACE MY TREECRAFT! ~CAW~ A marvel of avian engineering. ~CAW~",
                                          },
                                          {
                                                  "Cadet Candice",
                                                  "Lord Crow",
                                                  "Celestial Chad",
                                                  "Celestial Chad",
                                                  "Lord Crow",
                                          },
                                          {
                                                  getGame().getAssets().get(GameAssets::TEXTURE_CADET_CANDICE_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_LORD_CROW_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_CELESTIAL_CHAD_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_CELESTIAL_CHAD_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_LORD_CROW_ICON),

                                          },
                                          [&]() {
                                              space.paused = false;
                                          }
                    );
                    break;
                case 8:
                    space.paused = true;
                    dialogBox.startDialog({
                                                "NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoooooooo",
                                                "oooooooo ~CAW~ ooooooooooooooo...........",
                                                "...",
                                                "My treecraft is destroyed. You have bested me...",
                                                "I thought I would die with a beak full of vegtables ~CAW~ ~CAW~ CAW~",
                                                "[End Of Communication]",
                                                "[Lord Crow is no more]",
                                                "[The human space station is saved from the cosmic crow threat... or is it?]",
                                                "Commander! This can't be possible!",
                                                "I'm reading more crows inbound!",
                                                "~CAW~ ~CAW~ Vegtables! ~CAW~ ",
                                                "Its hog-killin' time! Yee Haw!",
                                          },
                                          {
                                                  "Lord Crow",
                                                  "Lord Crow",
                                                  "Lord Crow",
                                                  "Lord Crow",
                                                  "Lord Crow",
                                                  "Narrator",
                                                  "Narrator",
                                                  "Cadet Candice",
                                                  "Cadet Candice",
                                                  "Cosmic Crow",
                                                  "Celestial Chad",
                                          },
                                          {

                                                  getGame().getAssets().get(GameAssets::TEXTURE_LORD_CROW_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_LORD_CROW_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_LORD_CROW_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_LORD_CROW_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_LORD_CROW_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_NARRATOR_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_NARRATOR_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_CADET_CANDICE_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_CADET_CANDICE_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_COSMIC_CROW_ICON),
                                                  getGame().getAssets().get(GameAssets::TEXTURE_CELESTIAL_CHAD_ICON),

                                          },
                                          [&]() {
                                              space.paused = false;
                                          }
                    );
                    break;

                default:
                    space.paused = true;
                    dialogBox.startDialog({
                                                  "Another wave of crows inbound commander!",
                                          },
                                          {
                                                  "Cadet Candice",
                                          },
                                          {
                                                  getGame().getAssets().get(GameAssets::TEXTURE_CADET_CANDICE_ICON),
                                          },
                                          [&]() {
                                              space.paused = false;
                                          }
                    );
                    break;
            }

        }),
        mappingDatabase(),
        gameOverMenu(*this),
        miniMap(*this),
        dialogBox(game.getAssets().get(GameAssets::VT323_TTF),  game.getAssets().get(GameAssets::DIALOG_BOX)),
        weaponSelectionUi(*this, WEAPON, &space.getUpgradeManager()),
        seedSelectionUi(*this, SEED, &space.getUpgradeManager()),
        boostSelectionUi(*this, BOOSTER, &space.getUpgradeManager()),
        upgradeMenu(space, space.getUpgradeManager()) {
    mappingDatabase.loadFromCSV(*getGame().getAssets().get(GameAssets::CONTROLLER_DB));
    smoothPosition = cameraPosition = space.getShip().getLocation();
    shipSmoothVelocity = { 0.0f, 0.0f };
    energySprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_ENERGY));

    space.paused = true;

    energyText.setPosition({ 175.0f, 45.0f});
    energyText.setScale({1.0f, 1.0f});
    energyText.setFillColor(sf::Color::White);
    energyText.setFont(*space.getAssets().get(GameAssets::VT323_TTF));
    energyText.setCharacterSize(90);

    shopText.setString("Press 'F' to open the Space Station Store");
    shopText.setFont(*game.getAssets().get(GameAssets::VT323_TTF));

    dialogBox.startDialog({
        "Commander! Lord Crow is on the line!",
        "Put him on.",
        "~CAW~ Master we have detected the human space station and their vegetables." ,
        "~CAW~ Excellent... dispatch the hatchlings...",
        "~CAW~ Space Vegetables! ~CAW~ ~CAW~",
        "~CAW~ Oh... It's you...",
        "~CAW~ Greetings Celestial Chad...",
        "You called me, Lord Crow.",
        "~CAW~ Only to tell you to prepare to die earthling.",
        "Why don't you get away from my asteroid belt you mangy birds?",
        "[End Of Communication]",
        "Oh no!",
        "Prepare my fighter jet. Time to show these Cosmic Crows who's boss!",
    },
      {
        "Cadet Candice",
        "Celestial Chad",
        "Cosmic Crow",
        "Lord Crow",
        "Cosmic Crow",
        "Lord Crow",
        "Lord Crow",
        "Celestial Chad",
        "Lord Crow",
        "Celestial Chad",
        "Narrator",
        "Cadet Candice",
        "Celestial Chad",
        },
          {
              getGame().getAssets().get(GameAssets::TEXTURE_CADET_CANDICE_ICON),
              getGame().getAssets().get(GameAssets::TEXTURE_CELESTIAL_CHAD_ICON),
              getGame().getAssets().get(GameAssets::TEXTURE_COSMIC_CROW_ICON),
              getGame().getAssets().get(GameAssets::TEXTURE_LORD_CROW_ICON),
              getGame().getAssets().get(GameAssets::TEXTURE_COSMIC_CROW_ICON),
              getGame().getAssets().get(GameAssets::TEXTURE_LORD_CROW_ICON),
              getGame().getAssets().get(GameAssets::TEXTURE_LORD_CROW_ICON),
              getGame().getAssets().get(GameAssets::TEXTURE_CELESTIAL_CHAD_ICON),
              getGame().getAssets().get(GameAssets::TEXTURE_LORD_CROW_ICON),
              getGame().getAssets().get(GameAssets::TEXTURE_CELESTIAL_CHAD_ICON),
              getGame().getAssets().get(GameAssets::TEXTURE_NARRATOR_ICON),
              getGame().getAssets().get(GameAssets::TEXTURE_CADET_CANDICE_ICON),
              getGame().getAssets().get(GameAssets::TEXTURE_CELESTIAL_CHAD_ICON),
               },
               [&]() {
                    getAssets().get(GameAssets::BACH)->stop();
                    getAssets().get(GameAssets::SOUNDTRACK)->setLoop(true);
                    getAssets().get(GameAssets::SOUNDTRACK)->play();
               }
           );
}

bool SpaceScreen::isShopIsOpen() const {
    return shopIsOpen;
}

void SpaceScreen::setShopIsOpen(bool shopIsOpen) {
    SpaceScreen::shopIsOpen = shopIsOpen;
}

void SpaceScreen::tick(float delta) {
    dialogBox.update(delta);

    timeBetweenKeyPresses += delta;
    if (timeBetweenKeyPresses>intervalBetweenKeyPresses)
        canProcessKeyPress = true;

    if (space.paused)
        return;

    if(!space.gameover) {
        processInput(delta);
        space.tick(delta);
        
        float trans = pow(0.99f, delta);

        shipSmoothVelocity = shipSmoothVelocity * trans + space.getShip().getMoveVelocity() * (1.0f - trans);

        smoothPosition = smoothPosition * trans + (space.getShip().getLocation()) * (1.0f - trans);
        cameraPosition = space.getShip().getLocation() + space.getShip().getLocation() - smoothPosition;

        weaponSelectionUi.update(delta);
        seedSelectionUi.update(delta);
        boostSelectionUi.update(delta);
    } else {
        gameoverCooldown -= delta / 1000.0f;
    }
}

void SpaceScreen::render(sf::RenderTarget& target) {
    sf::Vector2f vec = { 1.0f, 1.0f };
    vec.x /= static_cast<float>(background.getTextureRect().getSize().x);
    vec.y /= static_cast<float>(background.getTextureRect().getSize().y);
    background.setScale(vec);
    energySprite.setPosition({50.0f, 50.0f});
    energySprite.setScale({8.0f * 16.0f / energySprite.getTexture()->getSize().x, 8.0f * 16.0f / energySprite.getTexture()->getSize().y});

    energyText.setString(std::to_string(space.getShip().getEnergy()));
    
	target.clear();
	target.setView(sf::View({ 0.5f, 0.5f }, { 1.0f, 1.0f }));
	target.draw(background);
    
	target.setView(sf::View(cameraPosition, Space::VIEW_SIZE * zoom));
	target.draw(space);

    // mini map
    target.draw(miniMap);

    // ui
    target.setView(sf::View(SpaceScreen::UI_VIEW_SIZE / 2.0f, SpaceScreen::UI_VIEW_SIZE));
    if (space.gameover) {
        gameOverMenu.setStats(space.get_wave_manager().get_current_wave(), space.getShip().getScore());
        target.draw(gameOverMenu);   
    }
    else if (space.paused) {
        dim.setTexture(*getAssets().get(GameAssets::WHITE_PIXEL));
        dim.setPosition({ 0.0f, 0.0f });
        dim.setScale(SpaceScreen::UI_VIEW_SIZE);
        dim.setColor(sf::Color(0, 0, 0, 128));
        target.draw(dim);

        if(shopIsOpen) {
            target.draw(upgradeMenu);
            target.draw(energySprite);
            target.draw(energyText);
        } else if (!dialogBox.isInProgress()) {
            infographicSprite.setTexture(*getAssets().get(GameAssets::TEXTURE_INFOGRAPHIC));
            infographicSprite.setPosition({ 0.0f, 100.0f });
            infographicSprite.setScale(sf::Vector2f(1.95f, 2.2f));
            target.draw(infographicSprite);

            infographicText.setString("Paused (Esc to unpause)");
            infographicText.setPosition({ 800.0f, 940.0f});
            infographicText.setScale({1.0f, 1.0f});
            infographicText.setFillColor(sf::Color::White);
            infographicText.setFont(*space.getAssets().get(GameAssets::VT323_TTF));
            infographicText.setCharacterSize(40);
            target.draw(infographicText);
        }
    } else {
        target.draw(energySprite);
        target.draw(energyText);
        target.draw(weaponSelectionUi);

        sf::Vector2f ssVec = space.getGayStation().getLocation();
        sf::Vector2f pVec = space.getShip().getLocation();
        sf::Vector2f diff = ssVec - pVec;
        float ssDis = diff.x * diff.x + diff.y * diff.y;
        if(ssDis < SPACE_STATION_STORE_DIS_SQ)
        {
            shopText.setPosition({ 700.0f, 500.0f});
            target.draw(shopText);
        }

        target.draw(seedSelectionUi);
        target.draw(boostSelectionUi);
    }
    target.draw(dialogBox);
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
    if (dialogBox.isInProgress())
        dialogBox.interact();

    if(space.gameover && gameoverCooldown <= 0.0f) {
        getGame().setScreen(new SpaceScreen(getGame()));
        return;
    }

    if(shopIsOpen)
    {
        Upgrade upgrade = upgradeMenu.select();
        if (space.getUpgradeManager().get_cost(upgrade) < space.getShip().getEnergy()) {
            space.getUpgradeManager().unlock(upgrade);
            float cost = space.getUpgradeManager().get_cost(upgrade);
            space.getShip().buyShit(cost);

            space.addEntity(new FloatingText(space, space.getShip().getLocation(), "-" + std::to_string((int)round(cost)), sf::Color::Blue, 2.0f));
        }
    }
}

void SpaceScreen::mouseMoved(const sf::Event::MouseMoveEvent &mouseMoveEvent) {
    sf::Vector2f pos = getWindow().mapPixelToCoords(sf::Mouse::getPosition(getWindow()), sf::View({ UI_VIEW_SIZE.x/ 2.f, UI_VIEW_SIZE.y/2.0f }, UI_VIEW_SIZE));
    upgradeMenu.handleMouse({static_cast<int>(pos.x), static_cast<int>(pos.y)});
}

void SpaceScreen::keyPressed(const sf::Event::KeyEvent &keyEvent) {
    if (canProcessKeyPress) {
        timeBetweenKeyPresses = .0f;
        canProcessKeyPress = false;

        if (space.gameover && gameoverCooldown <= 0.0f) {
            getGame().setScreen(new SpaceScreen(getGame()));
            return;
        }

        switch (keyEvent.code) {
            case sf::Keyboard::Escape:
                if (dialogBox.isInProgress()) {
                    dialogBox.kill();
                } else if (shopIsOpen) {
                    shopIsOpen = false;
                    space.paused = false;
                } else {
                    space.paused = !space.paused;
                }
                break;

            case sf::Keyboard::Space:
            case sf::Keyboard::Enter:
                if (dialogBox.isInProgress())
                    dialogBox.interact();
                if (shopIsOpen) {
                    Upgrade upgrade = upgradeMenu.select();
                    if (space.getUpgradeManager().get_cost(upgrade) < space.getShip().getEnergy()) {
                        space.getUpgradeManager().unlock(upgrade);
                        float cost = space.getUpgradeManager().get_cost(upgrade);
                        space.getShip().buyShit(cost);

                        space.addEntity(new FloatingText(space, space.getShip().getLocation(), "-" + std::to_string((int)round(cost)), sf::Color::Blue, 2.0f));
                    }
                }
                break;
            case sf::Keyboard::F: {
                sf::Vector2f ssVec = space.getGayStation().getLocation();
                sf::Vector2f pVec = space.getShip().getLocation();
                sf::Vector2f diff = ssVec - pVec;
                float ssDis = diff.x * diff.x + diff.y * diff.y;
                if (ssDis < SPACE_STATION_STORE_DIS_SQ) {
                    shopIsOpen = !shopIsOpen;
                    space.paused = shopIsOpen;
                } else {
                    seedSelectionUi.changeSelection(true);
                    space.getShip().setCropType(static_cast<CropType>(seedSelectionUi.getSelection()));
                }
            }
                break;
            case sf::Keyboard::Num1:
            case sf::Keyboard::Numpad1:
            {
                weaponSelectionUi.setSelection(0);
                space.getShip().setWeaponType(static_cast<WeaponType>(weaponSelectionUi.getSelection()));
                break;
            }
            case sf::Keyboard::Num2:
            case sf::Keyboard::Numpad2:
            {
                weaponSelectionUi.setSelection(1);
                space.getShip().setWeaponType(static_cast<WeaponType>(weaponSelectionUi.getSelection()));
                break;
            }
            case sf::Keyboard::Num3:
            case sf::Keyboard::Numpad3:
            {
                weaponSelectionUi.setSelection(2);
                space.getShip().setWeaponType(static_cast<WeaponType>(weaponSelectionUi.getSelection()));
                break;
            }
            case sf::Keyboard::Num4:
            case sf::Keyboard::Numpad4:
            {
                weaponSelectionUi.setSelection(3);
                space.getShip().setWeaponType(static_cast<WeaponType>(weaponSelectionUi.getSelection()));
                break;
            }
            case sf::Keyboard::Num5:
            case sf::Keyboard::Numpad5:
            {
                weaponSelectionUi.setSelection(4);
                space.getShip().setWeaponType(static_cast<WeaponType>(weaponSelectionUi.getSelection()));
                break;
            }
            case sf::Keyboard::Num6:
            case sf::Keyboard::Numpad6:
            {
                weaponSelectionUi.setSelection(5);
                space.getShip().setWeaponType(static_cast<WeaponType>(weaponSelectionUi.getSelection()));
                break;
            }
            case sf::Keyboard::A:
            case sf::Keyboard::Left:
                if (shopIsOpen)
                    upgradeMenu.moveLeft();
                break;
            case sf::Keyboard::D:
            case sf::Keyboard::Right:
                if (shopIsOpen)
                    upgradeMenu.moveRight();
                break;
            case sf::Keyboard::Q: {
                weaponSelectionUi.changeSelection(false);
                space.getShip().setWeaponType(static_cast<WeaponType>(weaponSelectionUi.getSelection()));
                break;
            }
            case sf::Keyboard::E: {
                weaponSelectionUi.changeSelection(true);
                space.getShip().setWeaponType(static_cast<WeaponType>(weaponSelectionUi.getSelection()));
                break;
            }
            // TODO: CHEAT - remove
            case sf::Keyboard::V:
                space.getShip().buyShit(-1000.0f);
                break;
            default:
                break;
        }
    }
}

void SpaceScreen::windowClosed() {
	getGame().getWindow().close();
}

void SpaceScreen::processInput(float delta) {
    bool connected = sf::Joystick::isConnected(0);
    // TODO: figure out why SFML fetching the joystick name doesn't work
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
    else
        space.getShip().noFire();

    space.getShip().setIsBoosting(isBoosting);

//    bool isPlanting = mappingFound && connected ? sf::Joystick::isButtonPressed(0, mapping.getButton(wiz::MapButton::Left_Shoulder)) :
//            (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) ||
//            sf::Mouse::isButtonPressed(sf::Mouse::Button::Right));

    bool isPlanting = sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);

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

    space.getShip().moveInDirOfVec(moveVec, delta / 1000.0f);

    sf::Vector2f pos = getWindow().mapPixelToCoords(sf::Mouse::getPosition(getWindow()), sf::View({ 0.0f, 0.0f }, Space::VIEW_SIZE));

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
