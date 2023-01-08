//
// Created by Alexander Winter on 2022-02-13.
//

#ifndef GAMETEMPLATE_GAMEASSETS_H
#define GAMETEMPLATE_GAMEASSETS_H

#include "WIZ/asset/MusicAsset.h"
#include "WIZ/asset/SoundAsset.h"
#include "WIZ/asset/FontAsset.h"
#include "WIZ/asset/TextureAsset.h"
#include "TextAsset.h"
#include "ShaderAsset.h"

#ifndef ASSET
#define ASSET(TYPE, NAME, CONSTRUCTOR) extern const TYPE NAME;
#endif

namespace GameAssets {
	extern std::vector<const wiz::AssetBase*> ALL;

  ASSET(TextAsset, CONTROLLER_DB, ("gamecontrollerdb.txt"))

	ASSET(wiz::MusicAsset, GREENLIFE, ("music/greenlife.ogg"))
	ASSET(wiz::SoundAsset, JUMP, ("sfx/jump.ogg"))
	ASSET(wiz::FontAsset, SANS_TTF, ("font/sans.ttf"))

	ASSET(wiz::TextureAsset, WHITE_PIXEL, ("gfx/white_pixel.png"))
    ASSET(wiz::TextureAsset, ARROW, ("gfx/arrow.png"))
    ASSET(wiz::TextureAsset, CIRCLE, ("gfx/circle.png"))
	ASSET(wiz::TextureAsset, BACKGROUND, ("gfx/background.png"))
    ASSET(wiz::TextureAsset, LOGO, ("gfx/logo.png"))
    ASSET(wiz::TextureAsset, GAMEOVER, ("gfx/gameover.png"))
    ASSET(wiz::TextureAsset, MAP_BG, ("gfx/map_bg.png"))
	ASSET(wiz::TextureAsset, TEXTURE_ASTEROID, ("gfx/ass_steroid2.png"))
    ASSET(wiz::TextureAsset, TEXTURE_LARGE_ASTEROID, ("gfx/large_ass.png"))
    ASSET(wiz::TextureAsset, TEXTURE_FALLOUT_FLOWER, ("gfx/fallout_flower.png"))
    ASSET(wiz::TextureAsset, TEXTURE_HATCHLING, ("gfx/the_hatchling.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SMALL_LAZER, ("gfx/lazer.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SMALL_ENEMY_LAZER, ("gfx/enemy_lazer.png"))
    ASSET(wiz::TextureAsset, TEXTURE_TRACTOR_BEAM, ("gfx/tractor_beam.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SOIL, ("gfx/soil.png"))
    ASSET(wiz::TextureAsset, TEXTURE_ENERGY, ("gfx/energy.png"))
    ASSET(wiz::TextureAsset, TEXTURE_PLANT_GROWING, ("gfx/plant_growing.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SEED, ("gfx/seed_rick.png"))
    ASSET(wiz::TextureAsset, TEXTURE_GAY_STATION, ("gfx/gay_station.png"))
    ASSET(wiz::TextureAsset, TEXTURE_COSMIC_CROW_ICON, ("gfx/cosmic_crow_icon.png"))
    ASSET(wiz::TextureAsset, TEXTURE_CELESTIAL_CHAD_ICON, ("gfx/celestial_chad_icon.png"))

    ASSET(wiz::TextureAsset, TEXTURE_SHIP, ("gfx/ship.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SHIP_MOVING_1, ("gfx/ship_moving_1.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SHIP_MOVING_2, ("gfx/ship_moving_2.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SHIP_BOOSTING_1, ("gfx/ship_boosting_1.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SHIP_BOOSTING_2, ("gfx/ship_boosting_2.png"))

    ASSET(wiz::TextureAsset, DIALOG_BOX, ("gfx/dialog_box.png"))

    // Shaders
    ASSET(ShaderAsset, DAMAGE_SHADER, ("shaders/damage.vs", "shaders/damage.fs"))

    // Fonts
    ASSET(wiz::FontAsset, VT323_TTF, ("font/VT323-Regular.ttf"))

    // UI
    ASSET(wiz::TextureAsset, TEXTURE_WEAPON_SELECT_BACKDROP, ("gfx/ui/weapon_select/weapon_select_dropdown.png"))


    ASSET(wiz::TextureAsset, TEXTURE_LASER_DOUBLE, ("gfx/upgrades/laser_double.png"))
    ASSET(wiz::TextureAsset, TEXTURE_LASER_TRIANGLE, ("gfx/upgrades/laser_triangle.png"))
    ASSET(wiz::TextureAsset, TEXTURE_LASER_FOUR_WAY, ("gfx/white_pixel.png"))
    ASSET(wiz::TextureAsset, TEXTURE_LASER_CRAZY, ("gfx/upgrades/flame_thrower.png"))
    ASSET(wiz::TextureAsset, TEXTURE_NUKE_SIMPLE, ("gfx/upgrades/nuke.png"))
    ASSET(wiz::TextureAsset, TEXTURE_FLAMETHROWER_SIMPLE, ("gfx/white_pixel.png"))
    ASSET(wiz::TextureAsset, TEXTURE_BOOST_BASIC, ("gfx/upgrades/boost_basic.png"))
    ASSET(wiz::TextureAsset, TEXTURE_BOOST_ULTRA, ("gfx/upgrades/boost_ultra.png"))
}

#endif //GAMETEMPLATE_GAMEASSETS_H
