//
// Created by william on 08/01/23.
//

#ifndef LD52_CLIENT_SELECTIONSCROLL_H
#define LD52_CLIENT_SELECTIONSCROLL_H

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"
#include "WIZ/asset/TextureAsset.h"
#include "GameAssets.h"
#include "WIZ/asset/AssetLoader.h"
#include "UpgradeManager.h"

class SpaceScreen;

enum SelectionType {
    WEAPON,
    SEED,
    BOOSTER
};

class WeaponTextureGetter {
    std::vector<sf::Texture*> weaponTextures;

public:
    WeaponTextureGetter(wiz::AssetLoader& assets) {
        weaponTextures =
                {assets.get(GameAssets::TEXTURE_LASER_SIMPLE),
                 assets.get(GameAssets::TEXTURE_LASER_DOUBLE),
                 assets.get(GameAssets::TEXTURE_LASER_TRIANGLE),
                 assets.get(GameAssets::TEXTURE_LASER_FOUR_WAY),
                 assets.get(GameAssets::TEXTURE_LASER_CRAZY),
                 assets.get(GameAssets::TEXTURE_NUKE_SIMPLE)};
    }

    ~WeaponTextureGetter() = default;

    std::vector<sf::Texture *> get() {
        return weaponTextures;
    }
};

class SeedTextureGetter {
    std::vector<sf::Texture*> seedTextures;

public:
    SeedTextureGetter(wiz::AssetLoader& assets) {
        seedTextures =
                {assets.get(GameAssets::TEXTURE_FALLOUT_FLOWER),
                 assets.get(GameAssets::TEXTURE_CORN)};
    }

    ~SeedTextureGetter() = default;

    std::vector<sf::Texture *> get() {
        return seedTextures;
    }
};

class SelectionScroll : public sf::Drawable {
    mutable std::vector<sf::Sprite> backdrops;
    mutable std::vector<sf::Sprite> items;
    mutable sf::Sprite selectHighLight;
    int selection = 0;
    bool enableScroll = false;

    float openTime = 2000.f;
    float openDuration = .0f;

    float xOffsetSpacingBetweenBoxes = 50.f;
    float yOffset = -60.f;
    sf::Vector2f selectionDisPos;

    float changeSelectionInterval = 50.f;
    float timeBetweenChange = .0f;

    UpgradeManager* upgradeManager = nullptr;

protected:
    SelectionType type;

public:
    explicit SelectionScroll(SpaceScreen& screen, SelectionType type, int numberOfItems, sf::Vector2f selectionDisPos,
                             UpgradeManager* upgradeManager);

    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

    bool isEnableScroll() const;

    void setEnableScroll(bool enableScroll);

    int getSelection() const;

    void setSelection(int selection);

    void changeSelection(bool changeToNext);

    void update(float delta);

    SelectionType getType() const;
};

#endif //LD52_CLIENT_SELECTIONSCROLL_H
