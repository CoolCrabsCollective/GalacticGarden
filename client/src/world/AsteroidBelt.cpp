//
// Created by Alexander Winter on 2023-01-07.
//

#include "world/AsteroidBelt.h"
#include "world/Space.h"
#include "GameAssets.h"

AsteroidBelt::AsteroidBelt(Space& space) 
    : Entity(space, { 0.0f, 0.0f}) {
    
    float circum = (Space::MAP_RADIUS + 2.0f) * 2.0f * 3.14;
    int count = round(circum / 2.0f);
    
    for(int i = 0; i < count; i++)
    {
        float radius = Space::MAP_RADIUS + 2.0f;
        float angle = i * 360.0f / count;
        float size = rand() / (RAND_MAX + 1.0f) * 0.5f + 2.5f;
        float rotation = (rand() / (RAND_MAX + 1.0f) * 2.0f - 1.0f) * 180.0f;

        float x = cos(angle) * radius;
        float y = sin(angle) * radius;
        
        fake_astroids.emplace_back(sf::Vector2f { x, y }, size, rotation);
    }
    
    circum = (Space::MAP_RADIUS + 4.0f) * 2.0f * 3.14;
    count = round(circum / 3.0f);

    for(int i = 0; i < count; i++)
    {
        float radius = Space::MAP_RADIUS + 4.0f;
        float angle = i * 360.0f / count;
        float size = rand() / (RAND_MAX + 1.0f) * 1.0f + 4.0f;
        float rotation = (rand() / (RAND_MAX + 1.0f) * 2.0f - 1.0f) * 180.0f;

        float x = cos(angle) * radius;
        float y = sin(angle) * radius;

        fake_astroids.emplace_back(sf::Vector2f { x, y }, size, rotation);
    }

    asteroidSprite.setTexture(*space.getAssets().get(GameAssets::TEXTURE_ASTEROID));
    asteroidSprite.setOrigin({ 0.5f * asteroidSprite.getTexture()->getSize().x, 
                               0.5f * asteroidSprite.getTexture()->getSize().y });
}

void AsteroidBelt::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
    for(std::tuple<sf::Vector2f, float, float> asteroid : fake_astroids) {
        asteroidSprite.setPosition(std::get<0>(asteroid));
        float size = std::get<1>(asteroid);
        asteroidSprite.setScale({ size / asteroidSprite.getTexture()->getSize().x, size / asteroidSprite.getTexture()->getSize().y });
        asteroidSprite.setRotation(sf::degrees(std::get<2>(asteroid)));
        target.draw(asteroidSprite);
    }
}

float AsteroidBelt::getZOrder() const {
    return -10.0f;
}

void AsteroidBelt::tick(float delta) {

}

sf::Vector2f AsteroidBelt::getVisualSize() const {
    return { Space::MAP_RADIUS * 2.0f, Space::MAP_RADIUS * 2.0f };
}
