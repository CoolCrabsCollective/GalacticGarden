//
// Created by william on 07/01/23.
//

#ifndef LD52_CLIENT_SELECTION_H
#define LD52_CLIENT_SELECTION_H

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"
#include "WIZ/asset/TextureAsset.h"
#include "SelectionScroll.h"
#include "world/crop/CropType.h"
#include "world/weapon/WeaponType.h"

class SpaceScreen;

class Selection : public sf::Drawable {
    mutable sf::Text text;
    mutable sf::Sprite backdrop;
    mutable sf::Sprite item;

protected:
    std::string itemName;
    SelectionScroll* selectionScroll = nullptr;
    WeaponTextureGetter* weaponTextureGetter = nullptr;
    SeedTextureGetter* seedTextureGetter = nullptr;

public:
    explicit Selection(SpaceScreen& screen, SelectionType type);

    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

    bool isEnableScroll() const;

    void setEnableScroll(bool enableScroll);

    void changeSelection(bool changeToNext);

    void update(float delta);

    int getSelection() const;

    void setSelection(int i);
};

#endif //LD52_CLIENT_SELECTION_H
