//
// Created by william on 2022-04-04.
//

#include "world/anime/Anime.h"

void Anime::insertFrame(sf::Texture* Texture) {
    frames.push_back(Texture);
}

void Anime::setAnimationSprite(sf::Sprite* sprite) {
    this->animationSprite = sprite;
}

void Anime::tickAnimation() {
    if(frames.empty())
        return;

    if (currentFrame >= frames.size()) {
        currentFrame = 0;
    }

    animationSprite->setTexture(*frames.at(currentFrame));

    currentFrame++;
}

void Anime::startAnimation() {
    resetAnimation();
    tickAnimation();
    isAnimating = true;
}

void Anime::runAnimation(float delta) {
    if (!isAnimating)
        return;

    timeSinceLastFrame += delta;
    if (currentFrame < frames.size() && timeSinceLastFrame >= msBetweenFrames) {
        tickAnimation();
        timeSinceLastFrame = 0;
    }

    if (currentFrame >= frames.size() && timeSinceLastFrame >= msBetweenFrames)
        resetAnimation();
}

void Anime::resetAnimation() {
    if(frames.empty())
        return;
    animationSprite->setTexture(*frames.at(0));
    currentFrame = 1;
    timeSinceLastFrame = 0;
}

void Anime::setTimeSinceLastFrame(float timeSinceLastFrame) {
    this->timeSinceLastFrame = timeSinceLastFrame;
}
