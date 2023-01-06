//
// Created by william on 06/01/23.
//

#include "SpaceScreen.h"
#include "SFML/Window/Touch.hpp"
#include "SFML/Network/TcpSocket.hpp"
#include "SFML/Network/IpAddress.hpp"
#include <string>
#include <iostream>
#include "Box2DTestScreen.h"


SpaceScreen::SpaceScreen(wiz::Game& game)
        : Screen(game) {
}

void SpaceScreen::tick(float delta) {


}

void SpaceScreen::render(sf::RenderTarget& target) {
  target.clear();
  target.draw(background);
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