//
// Created by cedric on 1/8/23.
//

#include "ui/UpgradeMenu.h"
#include "world/Space.h"
#include "GameAssets.h"

UpgradeMenu::UpgradeMenu(Space& space, UpgradeManager &upgradeManager) : upgradeManager(upgradeManager) {

    wiz::AssetLoader& ass = space.getAssets();
    upgrade_texture[Upgrade::LASER_DOUBLE] = ass.get(GameAssets::TEXTURE_LASER_DOUBLE);
    upgrade_texture[Upgrade::LASER_TRIANGLE] = ass.get(GameAssets::TEXTURE_LASER_TRIANGLE);
    upgrade_texture[Upgrade::LASER_FOUR_WAY] = ass.get(GameAssets::TEXTURE_LASER_FOUR_WAY);
    upgrade_texture[Upgrade::LASER_CRAZY] = ass.get(GameAssets::TEXTURE_LASER_CRAZY);
    upgrade_texture[Upgrade::NUKE_SIMPLE] = ass.get(GameAssets::TEXTURE_NUKE_SIMPLE);
    upgrade_texture[Upgrade::FLAMETHROWER_SIMPLE] = ass.get(GameAssets::TEXTURE_FLAMETHROWER_SIMPLE);
    upgrade_texture[Upgrade::BOOST_BASIC] = ass.get(GameAssets::TEXTURE_BOOST_BASIC);
    upgrade_texture[Upgrade::BOOST_ULTRA] = ass.get(GameAssets::TEXTURE_BOOST_ULTRA);
}


void UpgradeMenu::draw(sf::RenderTarget &target, const sf::RenderStates &states) const {
    float offsetY = 0.f;
    float xPos = 150.f;
    float yPos = 15.f;
    sprite.setScale({2.f, 2.f}); // make alex cringe

    for(const auto& upgradeLine : upgradeTree)
    {
        size_t index = -1;
        for(size_t i = 0; i < upgradeLine.size(); i++)
        {
            bool upgradeBlockDone = upgradeBlockComplete(upgradeLine[i]);
            if(!upgradeBlockDone)
            {
                index = i;
                break;
            }
        }

        if(index != -1)
        {
            const std::vector<Upgrade>& upgradeBlock = upgradeLine.at(index);
            for(int i = 0; i < upgradeBlock.size(); i++)
            {
                sf::Texture* texture = upgrade_texture.at(upgradeBlock[index]);
                sprite.setTexture(*texture);
                sprite.setPosition({xPos, yPos + offsetY});
                target.draw(sprite);
                offsetY += 40;
            }
        }
    }
}

bool UpgradeMenu::upgradeBlockComplete(const std::vector<Upgrade> &upgradeBlock) const {
    for (const auto &upgrade: upgradeBlock)
    {
        if(!upgradeManager.has_unlocked(upgrade))
            return false;
    }

    return true;
}

