//
// Created by cedric on 1/8/23.
//

#pragma once

#include <vector>
#include "SFML/Graphics/Drawable.hpp"
#include "UpgradeManager.h"
#include "SFML/Graphics/Texture.hpp"
#include "world/Space.h"

class UpgradeMenu : public sf::Drawable {
protected:
    mutable sf::Sprite sprite;

    std::vector<std::vector<std::vector<Upgrade>>> upgradeTree{
            {{BOOST_BASIC}, {BOOST_ULTRA}},
            {{LASER_DOUBLE}, {LASER_TRIANGLE}, {LASER_FOUR_WAY, LASER_CRAZY}},
            {{NUKE_SIMPLE}},
            {{FLAMETHROWER_SIMPLE}},
    };

    std::unordered_map<Upgrade, sf::Texture*> upgrade_texture;
    UpgradeManager& upgradeManager;
    bool upgradeBlockComplete(const std::vector<Upgrade>& upgradeBlock) const;
public:
    explicit UpgradeMenu(Space& space, UpgradeManager &upgradeManager);

    void draw(sf::RenderTarget &target, const sf::RenderStates &states) const override;
};
