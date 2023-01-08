//
// Created by william on 07/01/23.
//

#include "ui/Selection.h"
#include "ui/SelectionScroll.h"
#include "SpaceScreen.h"

#include "util/MathUtil.h"

Selection::Selection(SpaceScreen& screen, SelectionType type, UpgradeManager* upgradeManager) {
    weaponTextureGetter = new WeaponTextureGetter(screen.getAssets());
    seedTextureGetter = new SeedTextureGetter(screen.getAssets());

    float xOffset = .0f;
    float xOffsetSpacing = 50.f;

    switch (type) {
        case WEAPON:
            backdrop.setTexture(*screen.getAssets().get(GameAssets::TEXTURE_WEAPON_SELECT_BACKDROP));
            break;
        case SEED:
            xOffset = xOffsetSpacing*2.5f;
            backdrop.setTexture(*screen.getAssets().get(GameAssets::TEXTURE_SEED_SELECT_BACKDROP));
            item.setTexture(*screen.getAssets().get(GameAssets::TEXTURE_GAY_STATION));
            break;
        case BOOSTER:
            xOffset = xOffsetSpacing*5.f;
            backdrop.setTexture(*screen.getAssets().get(GameAssets::TEXTURE_BOOST_SELECT_BACKDROP));
            item.setTexture(*screen.getAssets().get(GameAssets::TEXTURE_GAY_STATION));
            break;
    }

    sf::Vector2f pos = { xOffset + 30.f, 940.0f };
    sf::Vector2f size = { .8f, .8f };

    switch (type) {
        case WEAPON:
            selectionScroll = new SelectionScroll(screen, type, WeaponType::LENGTH, pos, upgradeManager);
            item.setTexture(*weaponTextureGetter->get().at(selectionScroll->getSelection()));
            break;
        case SEED:
            selectionScroll = new SelectionScroll(screen, type, CropType::CROP_LENGTH, pos, upgradeManager);
            item.setTexture(*seedTextureGetter->get().at(selectionScroll->getSelection()));
            break;
        case BOOSTER:
            selectionScroll = new SelectionScroll(screen, type, 5, pos, upgradeManager);
            break;
    }

    backdrop.setPosition(pos);
    backdrop.setScale(size);

    sf::Vector2f itemOffset = { backdrop.getLocalBounds().width / 5.f + 2.4f, backdrop.getLocalBounds().height - 115.f };
    sf::Vector2f itemSize = { 1.5f, 1.5f };

    item.setPosition(pos + itemOffset);
    item.setScale(itemSize);

    sf::Vector2f textOffset = {backdrop.getLocalBounds().width / 4.f - 1.f, -62.5f + backdrop.getLocalBounds().height};
    sf::Vector2f textSize = { .5f, .5f };

    text.setString("Single");
    text.setScale(textSize);
    text.setFont(*screen.getAssets().get(GameAssets::VT323_TTF));
    text.setFillColor(sf::Color::White);
    text.setPosition(pos + textOffset);
}

void Selection::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
    if (selectionScroll->isEnableScroll()) {
        // TODO: check that this was already down for selection change
        switch (selectionScroll->getType()) {
            case WEAPON:
                item.setTexture(*weaponTextureGetter->get().at(selectionScroll->getSelection()));
                break;
            case SEED:
                item.setTexture(*seedTextureGetter->get().at(selectionScroll->getSelection()));
                break;
        }
    }

    target.draw(backdrop);
    target.draw(item);
    target.draw(text);

    target.draw(*selectionScroll);
}
bool Selection::isEnableScroll() const {
    return selectionScroll->isEnableScroll();
}

void Selection::setEnableScroll(bool enableScroll) {
    selectionScroll->setEnableScroll(enableScroll);
}

void Selection::changeSelection(bool changeToNext) {
    selectionScroll->changeSelection(changeToNext);
}

void Selection::update(float delta) {
    selectionScroll->update(delta);
}

int Selection::getSelection() const {
    return selectionScroll->getSelection();
}

void Selection::setSelection(int i) {
    selectionScroll->setSelection(i);
}
