//
// Created by william on 08/01/23.
//

#include "ui/SelectionScroll.h"
#include "SpaceScreen.h"

#include "util/MathUtil.h"
#include "world/weapon/WeaponType.h"

SelectionScroll::SelectionScroll(SpaceScreen& screen, SelectionType type, int numberOfItems,
                                 sf::Vector2f selectionDisPos, UpgradeManager* upgradeManager) : type(type),
                                 selectionDisPos(selectionDisPos), upgradeManager(upgradeManager) {
    WeaponTextureGetter* weaponTextureGetter = new WeaponTextureGetter(screen.getAssets());
    SeedTextureGetter* seedTextureGetter = new SeedTextureGetter(screen.getAssets());

    float currentXOffset;

    selectHighLight.setTexture(*screen.getAssets().get(GameAssets::TEXTURE_HIGHLIGHT_SELECTION_BOX));

    for (int i = 0; i < numberOfItems; i++) {
        currentXOffset = xOffsetSpacingBetweenBoxes*i;

        backdrops.push_back(sf::Sprite());
        items.push_back(sf::Sprite());
        switch (type) {
            case WEAPON:
                backdrops.at(i).setTexture(*screen.getAssets().get(GameAssets::TEXTURE_WEAPON_SELECTION_BOX));
                items.at(i).setTexture(*weaponTextureGetter->get().at(i));
                break;
            case SEED:
                backdrops.at(i).setTexture(*screen.getAssets().get(GameAssets::TEXTURE_SEED_SELECTION_BOX));
                items.at(i).setTexture(*seedTextureGetter->get().at(i));
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

        sf::Vector2f highLightPos = {xOffsetSpacingBetweenBoxes*selection + selectionDisPos.x, selectionDisPos.y + yOffset};
        sf::Vector2f highLightSize = {.4f, .4f};

        selectHighLight.setPosition(highLightPos);
        selectHighLight.setScale(highLightSize);

        sf::Vector2f itemOffset = {backdrops.at(i).getLocalBounds().width / 5.f - 19.f,
                                   backdrops.at(i).getLocalBounds().height - 120.7f};
        sf::Vector2f itemSize = {1.2f, 1.2f};

        items.at(i).setPosition(pos + itemOffset);
        items.at(i).setScale(itemSize);
    }
}

void SelectionScroll::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
    if (enableScroll) {
        sf::Vector2f highLightPos = {xOffsetSpacingBetweenBoxes*selection + selectionDisPos.x, selectionDisPos.y +
                                     yOffset};
        selectHighLight.setPosition(highLightPos);

        for (int i = 0; i < backdrops.size(); i++) {
            if (!upgradeManager->has_unlocked(static_cast<Upgrade>(i)) &&
                type != SelectionType::SEED) {
                backdrops.at(i).setColor({255, 255, 255, 128});
                items.at(i).setColor({255, 255, 255, 128});
            } else {
                backdrops.at(i).setColor({255, 255, 255, 255});
                items.at(i).setColor({255, 255, 255, 255});
            }

            target.draw(backdrops.at(i));
            target.draw(items.at(i));
        }

        target.draw(selectHighLight);
    }
}

bool SelectionScroll::isEnableScroll() const {
    return enableScroll;
}

void SelectionScroll::setEnableScroll(bool enableScroll) {
    SelectionScroll::enableScroll = enableScroll;
}

int SelectionScroll::getSelection() const {
    return selection;
}

void SelectionScroll::setSelection(int selection) {
    if (upgradeManager->has_unlocked(static_cast<Upgrade>(selection)) || type == SelectionType::SEED) {
        SelectionScroll::selection = selection;
        enableScroll = true;
        openDuration = .0f;
    }
}

void SelectionScroll::changeSelection(bool changeToNext) {
    if (timeBetweenChange>=changeSelectionInterval) {
        timeBetweenChange = .0f;

        int checkUpGradeStartIndex = 0;

        int numberOfItems = 0;
        switch (type) {
            case WEAPON:
                numberOfItems = (int) WeaponType::LENGTH;
                break;
            case SEED:
                numberOfItems = (int) CropType::CROP_LENGTH;
//                checkUpGradeStartIndex = WEAPON_UPGRADE_LENGTH + 1;
                break;
        }

        do {
            if (changeToNext)
                selection++;
            else
                selection--;

            if (selection >= numberOfItems) {
                selection = 0;
            } else if (selection < 0) {
                selection = numberOfItems - 1;
            }
        } while (!upgradeManager->has_unlocked(static_cast<Upgrade>(selection + checkUpGradeStartIndex)) &&
                    type != SelectionType::SEED);

        enableScroll = true;
        openDuration = .0f;
    }
}

void SelectionScroll::update(float delta) {
    if (enableScroll) {
        openDuration+=delta;

        if (openDuration>=openTime) {
            openDuration = .0f;
            enableScroll = false;
        }
    }
    timeBetweenChange+=delta;
}

SelectionType SelectionScroll::getType() const {
    return type;
}
