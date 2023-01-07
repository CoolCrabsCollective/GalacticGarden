//
// Created by Alexander Winter on 2023-01-06.
//

#ifndef LD52_CLIENT_SPACE_H
#define LD52_CLIENT_SPACE_H


#include "SFML/Graphics/Drawable.hpp"
#include "Tickable.h"
#include "WIZ/asset/AssetLoader.h"
#include "Entity.h"
#include "Ship.h"

class Space : public Tickable, public sf::Drawable {
protected:
	wiz::AssetLoader& assets;
	std::vector<Entity*> entities;
    mutable std::vector<Entity*> entities_draw_list;
	
	Ship ship;
	
public:
	constexpr const static sf::Vector2f VIEW_SIZE = { 16.0f, 9.0f };
	
	Space(wiz::AssetLoader& assets);

	void tick(float delta) override;

	void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

  Ship getShip() const;

	wiz::AssetLoader& getAssets() const;

    const std::vector<Entity *> &getEntities() const;

};


#endif //LD52_CLIENT_SPACE_H
