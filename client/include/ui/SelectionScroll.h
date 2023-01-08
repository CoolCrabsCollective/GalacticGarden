//
// Created by william on 08/01/23.
//

#ifndef LD52_CLIENT_SELECTIONSCROLL_H
#define LD52_CLIENT_SELECTIONSCROLL_H

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"
#include "WIZ/asset/TextureAsset.h"

class SpaceScreen;

enum SelectionType {
    WEAPON,
    SEED,
    BOOSTER
};

class SelectionScroll : public sf::Drawable {
    mutable std::vector<sf::Sprite> backdrops;
    mutable std::vector<sf::Sprite> items;
    bool enableScroll = false;

public:
    explicit SelectionScroll(SpaceScreen& screen, SelectionType type, int numberOfItems, sf::Vector2f selectionDisPos);

    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

    bool isEnableScroll() const;

    void setEnableScroll(bool enableScroll);
};

#endif //LD52_CLIENT_SELECTIONSCROLL_H
