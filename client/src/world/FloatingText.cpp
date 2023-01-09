//
// Created by Alexander Winter on 2023-01-08.
//

#include "world/FloatingText.h"
#include "world/Space.h"
#include "GameAssets.h"

FloatingText::FloatingText(Space& space, 
                           sf::Vector2f location, 
                           const std::string& content, 
                           sf::Color color,
                           float duration)
        : Entity(space, location), maxLife(duration), life(duration), text() {
    text.setFont(*space.getAssets().get(GameAssets::VT323_TTF));
    text.setStyle(sf::Text::Bold);
    text.setFillColor(color);
    text.setOutlineColor(sf::Color::White);
    text.setOutlineThickness(2.0f);
    text.setString(content);
    text.setScale({ 0.01f, 0.01f });
    text.setCharacterSize(30);
}

void FloatingText::tick(float delta) {
    location += sf::Vector2f(-0.1f, -0.9f) * delta / 1000.0f;
    life -= delta / 1000.0f;
}

void FloatingText::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
    text.setPosition(location);
    float alpha = opacity();
    text.setFillColor({ text.getFillColor().r, 
                        text.getFillColor().g, 
                        text.getFillColor().b, 
                        static_cast<sf::Uint8>(round(alpha * 255)) });
    text.setOutlineColor({ text.getOutlineColor().r,
                           text.getOutlineColor().g,
                           text.getOutlineColor().b,
                           static_cast<sf::Uint8>(round(alpha * 255)) });
    target.draw(text);
}

float FloatingText::opacity() const {
    float progress = 1.0f - life / maxLife;
    
    if(progress < 0.1f)
        return progress / 0.1f;
    
    if(progress < 0.5f)
        return 1.0f;
    
    return 1.0f - (progress - 0.5f) / 0.5f;
}

float FloatingText::getZOrder() const {
    return 1000.0f;
}

bool FloatingText::shouldBeRemoved() const {
    return life <= 0.0f;
}
