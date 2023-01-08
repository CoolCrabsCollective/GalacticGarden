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
        : Entity(space, location), life(duration) {
    text.setFont(*space.getAssets().get(GameAssets::VT323_TTF));
    text.setFillColor(color);
    text.setString(content);
}

void FloatingText::tick(float delta) {
    location += sf::Vector2f(0.1f, 0.9f) * delta / 1000.0f;
    life -= delta / 1000.0f;
}

void FloatingText::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
    text.setPosition(location);
    float alpha = opacity();
    text.setFillColor({ text.getFillColor().r, 
                        text.getFillColor().g, 
                        text.getFillColor().b, 
                        static_cast<sf::Uint8>(round(alpha * 255)) });
    target.draw(text);
}

float FloatingText::opacity() const {
    return life;
}

float FloatingText::getZOrder() const {
    return 1000.0f;
}

bool FloatingText::shouldBeRemoved() const {
    return life <= 0.0f;
}
