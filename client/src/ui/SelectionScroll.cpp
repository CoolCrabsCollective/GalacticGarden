//
// Created by william on 08/01/23.
//

#include "ui/SelectionScroll.h"
#include "SpaceScreen.h"

#include "util/MathUtil.h"

SelectionScroll::SelectionScroll(SpaceScreen& screen, SelectionType type, int numberOfItems,
                                 sf::Vector2f selectionDisPos) {
    float yOffset = -60.f;
    float xOffsetSpacingBetweenBoxes = 50.f;
    float currentXOffset;

    for (int i = 0; i < numberOfItems; i++) {
        currentXOffset = xOffsetSpacingBetweenBoxes*i;

        backdrops.push_back(sf::Sprite());
        items.push_back(sf::Sprite());
        switch (type) {
            case WEAPON:
                backdrops.at(i).setTexture(*screen.getAssets().get(GameAssets::TEXTURE_WEAPON_SELECTION_BOX));
                items.at(i).setTexture(*screen.getAssets().get(GameAssets::TEXTURE_GAY_STATION));
                break;
            case SEED:
                backdrops.at(i).setTexture(*screen.getAssets().get(GameAssets::TEXTURE_SEED_SELECTION_BOX));
                items.at(i).setTexture(*screen.getAssets().get(GameAssets::TEXTURE_GAY_STATION));
                break;
            case BOOSTER:
                backdrops.at(i).setTexture(*screen.getAssets().get(GameAssets::TEXTURE_BOOST_SELECTION_BOX));
                items.at(i).setTexture(*screen.getAssets().get(GameAssets::TEXTURE_GAY_STATION));
                break;
        }

        sf::Vector2f pos = {currentXOffset + selectionDisPos.x, selectionDisPos.y + yOffset};
        sf::Vector2f size = {.4f, .4f};

        backdrops.at(i).setPosition(pos);
        backdrops.at(i).setScale(size);

        sf::Vector2f itemOffset = {backdrops.at(i).getLocalBounds().width / 5.f - 17.f,
                                   backdrops.at(i).getLocalBounds().height - 115.f};
        sf::Vector2f itemSize = {.7f, .7f};

        items.at(i).setPosition(pos + itemOffset);
        items.at(i).setScale(itemSize);
    }
}

void SelectionScroll::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
    if (enableScroll) {
        for (int i = 0; i < backdrops.size(); i++) {
            target.draw(backdrops.at(i));
            target.draw(items.at(i));
        }
    }
}

bool SelectionScroll::isEnableScroll() const {
    return enableScroll;
}

void SelectionScroll::setEnableScroll(bool enableScroll) {
    SelectionScroll::enableScroll = enableScroll;
}
