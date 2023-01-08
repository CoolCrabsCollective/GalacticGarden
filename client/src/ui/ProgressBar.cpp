//
// Created by root on 2022-04-03.
//

#include "ui/ProgressBar.h"
#include "WIZ/asset/AssetLoader.h"
#include "GameAssets.h"

ProgressBar::ProgressBar(const wiz::AssetLoader& assetLoader) {
    barSprite = sf::Sprite((*assetLoader.get(GameAssets::WHITE_PIXEL)));
    backgroundColor = sf::Color(143, 211, 255, 255);
    foregroundColor = sf::Color(77, 155, 255, 255);
}

void ProgressBar::draw(sf::RenderTarget &target, const sf::RenderStates &states) const {

    barSprite.setPosition({position.x - (barWidth / 2), position.y});

    // draw background
    barSprite.setColor(backgroundColor);
    barSprite.setScale({barWidth, barHeight});
    target.draw(barSprite);

    // draw red fill
    barSprite.setColor(sf::Color(foregroundColor));
    barSprite.setScale({(health_percent) * barWidth, barHeight});
    target.draw(barSprite);
}

void ProgressBar::setHealth(float health_percent) {
    this->health_percent = health_percent;
}

void ProgressBar::setPosition(const sf::Vector2f &position) {
    this->position = position;
}
