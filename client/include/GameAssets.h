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

	ASSET(wiz::MusicAsset, SOUNDTRACK, ("music/soundtrack.ogg"))
    ASSET(wiz::MusicAsset, BACH, ("music/literally_bach.ogg"))
	ASSET(wiz::SoundAsset, JUMP, ("sfx/jump.ogg"))

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
    ASSET(wiz::TextureAsset, TEXTURE_CROWCRAFT, ("gfx/the_crowcraft.png"))
    ASSET(wiz::TextureAsset, TEXTURE_NEST, ("gfx/the_nest.png"))
    ASSET(wiz::TextureAsset, TEXTURE_TREE, ("gfx/the_tree_craft.png"))
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
    ASSET(wiz::TextureAsset, TEXTURE_LORD_CROW_ICON, ("gfx/lord_crow_icon.png"))
    ASSET(wiz::TextureAsset, TEXTURE_CADET_CANDICE_ICON, ("gfx/cadet_candice_icon.png"))
    ASSET(wiz::TextureAsset, TEXTURE_NARRATOR_ICON, ("gfx/narrator_icon.png"))
    ASSET(wiz::TextureAsset, TEXTURE_BOMB, ("gfx/bomb.png"))
    ASSET(wiz::TextureAsset, TEXTURE_EXPLOSION_PARTICLE, ("gfx/explosion_particle.png"))

    ASSET(wiz::TextureAsset, TEXTURE_CORN, ("gfx/corn.png"))
    ASSET(wiz::TextureAsset, TEXTURE_CORN_YOUNG, ("gfx/corn_young.png"))

    ASSET(wiz::TextureAsset, TEXTURE_SHIP, ("gfx/ship.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SHIP_MOVING_1, ("gfx/ship_moving_1.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SHIP_MOVING_2, ("gfx/ship_moving_2.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SHIP_BOOSTING_1, ("gfx/ship_boosting_1.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SHIP_BOOSTING_2, ("gfx/ship_boosting_2.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SHIP_BOOSTING_ULTRA_1, ("gfx/ship_boosting_ultra_1.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SHIP_BOOSTING_ULTRA_2, ("gfx/ship_boosting_ultra_2.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SHIP_BOOSTING_ULTRA_3, ("gfx/ship_boosting_ultra_3.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SHIP_BOOSTING_ULTRA_4, ("gfx/ship_boosting_ultra_4.png"))

    ASSET(wiz::TextureAsset, DIALOG_BOX, ("gfx/dialog_box.png"))

    // Shaders
    ASSET(ShaderAsset, DAMAGE_SHADER, ("shaders/damage.vs", "shaders/damage.fs"))

    // Fonts
    ASSET(wiz::FontAsset, VT323_TTF, ("font/VT323-Regular.ttf"))

    // UI
    ASSET(wiz::TextureAsset, TEXTURE_WEAPON_SELECT_BACKDROP, ("gfx/ui/select/weapon_select_backdrop.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SEED_SELECT_BACKDROP, ("gfx/ui/select/seed_select_backdrop.png"))
    ASSET(wiz::TextureAsset, TEXTURE_BOOST_SELECT_BACKDROP, ("gfx/ui/select/boost_select_backdrop.png"))
    ASSET(wiz::TextureAsset, TEXTURE_WEAPON_SELECTION_BOX, ("gfx/ui/select/weapon_select_scroll_box.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SEED_SELECTION_BOX, ("gfx/ui/select/seed_select_scroll_box.png"))
    ASSET(wiz::TextureAsset, TEXTURE_BOOST_SELECTION_BOX, ("gfx/ui/select/boost_select_scroll_box.png"))
    ASSET(wiz::TextureAsset, TEXTURE_HIGHLIGHT_SELECTION_BOX, ("gfx/ui/select/highlight_scroll_box.png"))

    ASSET(wiz::TextureAsset, TEXTURE_LASER_SIMPLE, ("gfx/upgrades/laser_simple.png"))
    ASSET(wiz::TextureAsset, TEXTURE_LASER_DOUBLE, ("gfx/upgrades/laser_double.png"))
    ASSET(wiz::TextureAsset, TEXTURE_LASER_TRIANGLE, ("gfx/upgrades/laser_triangle.png"))
    ASSET(wiz::TextureAsset, TEXTURE_LASER_FOUR_WAY, ("gfx/upgrades/laser_quad.png"))
    ASSET(wiz::TextureAsset, TEXTURE_LASER_CRAZY, ("gfx/upgrades/laser_crazy.png"))
    ASSET(wiz::TextureAsset, TEXTURE_NUKE_SIMPLE, ("gfx/upgrades/nuke.png"))
    ASSET(wiz::TextureAsset, TEXTURE_FLAMETHROWER_SIMPLE, ("gfx/upgrades/flame_thrower.png"))
    ASSET(wiz::TextureAsset, TEXTURE_BOOST_NONE, ("gfx/upgrades/boost_none.png"))
    ASSET(wiz::TextureAsset, TEXTURE_BOOST_BASIC, ("gfx/upgrades/boost_basic.png"))
    ASSET(wiz::TextureAsset, TEXTURE_BOOST_ULTRA, ("gfx/upgrades/boost_ultra.png"))
    ASSET(wiz::TextureAsset, TEXTURE_FLOWER_ICON, ("gfx/upgrades/flower.png"))
    ASSET(wiz::TextureAsset, TEXTURE_CORN_ICON, ("gfx/upgrades/corn.png"))

    ASSET(wiz::TextureAsset, TEXTURE_LOCKED, ("gfx/upgrades/too_costly.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SELECTED, ("gfx/upgrades/select.png"))
}

#endif //GAMETEMPLATE_GAMEASSETS_H
