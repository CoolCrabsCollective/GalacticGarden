//
// Created by william on 07/01/23.
//

#include "ui/Selection.h"
#include "ui/SelectionScroll.h"
#include "SpaceScreen.h"

#include "util/MathUtil.h"
#include "util/SpriteUtil.h"

Selection::Selection(SpaceScreen& screen, SelectionType type, UpgradeManager* upgradeManager) {
    this->upgradeManager = upgradeManager;

    weaponTextureGetter = new WeaponTextureGetter(screen.getAssets());
    seedTextureGetter = new SeedTextureGetter(screen.getAssets());
    boostTextureGetter = new BoostTextureGetter(screen.getAssets());

    weaponTextGetter = new WeaponTextGetter();
    seedTextGetter = new SeedTextGetter();
    boostTextGetter = new BoostTextGetter();

    float xOffset = .0f;
    float xOffsetSpacing = 50.0f;

    switch (type) {
        case WEAPON:
            backdrop.setTexture(*screen.getAssets().get(GameAssets::TEXTURE_WEAPON_SELECT_BACKDROP), true);
            break;
        case SEED:
            xOffset = xOffsetSpacing*2.5f;
            backdrop.setTexture(*screen.getAssets().get(GameAssets::TEXTURE_SEED_SELECT_BACKDROP), true);
            item.setTexture(*screen.getAssets().get(GameAssets::TEXTURE_GAY_STATION), true);
            break;
        case BOOSTER:
            xOffset = xOffsetSpacing*5.0f;
            backdrop.setTexture(*screen.getAssets().get(GameAssets::TEXTURE_BOOST_SELECT_BACKDROP), true);
            item.setTexture(*screen.getAssets().get(GameAssets::TEXTURE_GAY_STATION), true);
            break;
    }

    sf::Vector2f pos = { xOffset + 30.0f, 955.0f };
    sf::Vector2f size = sf::Vector2f { 0.8f, 0.8f } * 128.0f;

    switch (type) {
        case WEAPON:
            selectionScroll = new SelectionScroll(screen, type, WeaponType::LENGTH, pos, upgradeManager);
            item.setTexture(*weaponTextureGetter->get().at(selectionScroll->getSelection()), true);
            break;
        case SEED:
            selectionScroll = new SelectionScroll(screen, type, CropType::CROP_LENGTH, pos, upgradeManager);
            item.setTexture(*seedTextureGetter->get().at(selectionScroll->getSelection()), true);
            break;
        case BOOSTER:
            selectionScroll = new SelectionScroll(screen, type, 3, pos, upgradeManager);
            item.setTexture(*boostTextureGetter->get().at(selectionScroll->getSelection()), true);
            break;
    }
    pos += size / 2.0f;

    backdrop.setPosition(pos);
    SpriteUtil::setSpriteOrigin(backdrop, { 0.5f, 0.5f });
    SpriteUtil::setSpriteSize(backdrop, size * 1.1f);

    sf::Vector2f itemSize = { 1.5f, 1.5f };

    item.setPosition(pos - sf::Vector2f { 0.0f, 7.0f });
    item.setScale(itemSize * 1.4f);
    SpriteUtil::setSpriteOrigin(item, { 0.5f, 0.5f });

     sf::Vector2f textSize = { 0.8f, 0.8f };

    switch(type) {
        case WEAPON:
            titleText.setString("WEAPON");
            break;
        case SEED:
            titleText.setString("SEED");
            break;
        case BOOSTER:
            titleText.setString("BOOSTER");
            break;
    }
    
    titleText.setCharacterSize(30);
    titleText.setScale(textSize);
    titleText.setStyle(sf::Text::Bold);
    titleText.setFont(*screen.getAssets().get(GameAssets::VT323_TTF));
    titleText.setOrigin({titleText.getLocalBounds().width / 2.0f, titleText.getLocalBounds().height / 2.0f});
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(pos + sf::Vector2f { 0.0f, size.y / 2.0f - 17.0f });
}

void Selection::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
    if (selectionScroll->isEnableScroll()) {
        // TODO: check that this was already down for selection change
        switch (selectionScroll->getType()) {
            case WEAPON:
                item.setTexture(*weaponTextureGetter->get().at(selectionScroll->getSelection()), true);
                break;
            case SEED:
                item.setTexture(*seedTextureGetter->get().at(selectionScroll->getSelection()), true);
                break;
        }
    }
    
    target.draw(backdrop);
    target.draw(item);
    target.draw(titleText);

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

    if (selectionScroll->getType() == BOOSTER) {
        if (upgradeManager->has_unlocked(BOOST_BASIC) && (int) selectedBoost != (int) BOOST_BASIC && selectedBoost == NONE) {
            selectedBoost = BASIC_BOOST;
            selectionScroll->setSelection(1);
            item.setTexture(*boostTextureGetter->get().at(selectionScroll->getSelection()), true);
        } else if (upgradeManager->has_unlocked(BOOST_ULTRA) && (int) selectedBoost != (int) BOOST_ULTRA) {
            selectedBoost = SUPER_BOOST;
            selectionScroll->setSelection(2);
            item.setTexture(*boostTextureGetter->get().at(selectionScroll->getSelection()), true);
        }
    }
}

int Selection::getSelection() const {
    return selectionScroll->getSelection();
}

void Selection::setSelection(int i) {
    selectionScroll->setSelection(i);
}
