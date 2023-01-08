//
// Created by Alexander Winter on 2023-01-08.
//

#include "world/FloatingText.h"
#include "world/Space.h"
#include "GameAssets.h"

FloatingText::FloatingText(Space& space, 
                           sf::Vector2f location, 
                           std::string content, 
                           sf::Color color,
                           float duration)
        : Entity(space, location) {
    text.setFont(*space.getAssets().get(GameAssets::VT323_TTF));
    text.setFillColor(color);
    text.setString(content);
}
