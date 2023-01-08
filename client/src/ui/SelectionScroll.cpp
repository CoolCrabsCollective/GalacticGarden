//
// Created by william on 08/01/23.
//

#include "ui/SelectionScroll.h"
#include "SpaceScreen.h"

#include "util/MathUtil.h"
#include "world/weapon/WeaponType.h"

SelectionScroll::SelectionScroll(SpaceScreen& screen, SelectionType type, int numberOfItems,
                                 sf::Vector2f selectionDisPos) : type(type), selectionDisPos(selectionDisPos) {
    WeaponTextureGetter* weaponTextureGetter = new WeaponTextureGetter(screen.getAssets());

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

        sf::Vector2f highLightPos = {xOffsetSpacingBetweenBoxes*selection + selectionDisPos.x, selectionDisPos.y + yOffset};
        sf::Vector2f highLightSize = {.4f, .4f};

        selectHighLight.setPosition(highLightPos);
        selectHighLight.setScale(highLightSize);

        sf::Vector2f itemOffset = {backdrops.at(i).getLocalBounds().width / 5.f - 17.f,
                                   backdrops.at(i).getLocalBounds().height - 115.f};
        sf::Vector2f itemSize = {.7f, .7f};

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
    SelectionScroll::selection = selection;
}

void SelectionScroll::changeSelection(bool changeToNext) {
    if (timeBetweenChange>=changeSelectionInterval) {
        timeBetweenChange = .0f;

        int numberOfItems = 0;
        switch (type) {
            case WEAPON:
                numberOfItems = (int) WeaponType::LENGTH;
                break;
            case SEED:
                //            numberOfItems = (int) WeaponType.LENGTH;
                break;
            case BOOSTER:
                //            numberOfItems = (int) WeaponType.LENGTH;
                break;
        }

        if (changeToNext)
            selection++;
        else
            selection--;

        if (selection >= numberOfItems) {
            selection = 0;
        } else if (selection < 0) {
            selection = numberOfItems - 1;
        }

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
