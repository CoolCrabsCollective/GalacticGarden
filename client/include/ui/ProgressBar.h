//
// Created by root on 2022-04-03.
//

#ifndef LD50_CLIENT_HEALTHBAR_H
#define LD50_CLIENT_HEALTHBAR_H

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "WIZ/asset/AssetLoader.h"

class ProgressBar : public sf::Drawable {

protected:
    mutable sf::Sprite barSprite;
    sf::Color backgroundColor;
    sf::Color foregroundColor;

    float health_percent = 0.0f;
    sf::Vector2f position{};
    float barWidth = 0.25f;
    float barHeight = 0.06f;

public:
    explicit ProgressBar(const wiz::AssetLoader& assetLoader);

    void draw(sf::RenderTarget &target, const sf::RenderStates &states) const override;
    void setHealth(float health_percent);

    void setPosition(const sf::Vector2f &position);
};

#endif //LD50_CLIENT_HEALTHBAR_H