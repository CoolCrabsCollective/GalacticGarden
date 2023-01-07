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
	ASSET(wiz::TextureAsset, BACKGROUND, ("gfx/background.png"))
    ASSET(wiz::TextureAsset, LOGO, ("gfx/logo.png"))
	ASSET(wiz::TextureAsset, TEXTURE_SHIP, ("gfx/ship.png"))
	ASSET(wiz::TextureAsset, TEXTURE_ASTEROID, ("gfx/ass_steroid2.png"))
    ASSET(wiz::TextureAsset, TEXTURE_FALLOUT_FLOWER, ("gfx/fallout_flower.png"))
    ASSET(wiz::TextureAsset, TEXTURE_HATCHLING, ("gfx/the_hatchling.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SMALL_LAZER, ("gfx/lazer.png"))
    ASSET(wiz::TextureAsset, TEXTURE_TRACTOR_BEAM, ("gfx/tractor_beam.png"))
    ASSET(wiz::TextureAsset, TEXTURE_SOIL, ("gfx/soil.png"))
    ASSET(wiz::TextureAsset, TEXTURE_PLANT_GROWING, ("gfx/plant_growing.png"))
}


#endif //GAMETEMPLATE_GAMEASSETS_H
