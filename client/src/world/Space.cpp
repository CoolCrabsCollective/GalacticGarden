//
// Created by Alexander Winter on 2023-01-06.
//

#include "world/Space.h"
#include "world/Asteroid.h"

Space::Space(wiz::AssetLoader& assets) 
	: assets(assets), entities(), ship(*this, { 0.0f, 0.0f }) {
	entities.push_back(&ship);
	entities.push_back(new Asteroid(*this, { 0.0f, 3.0f }));
}

void Space::tick(float delta) {

	for(Entity* entity : entities)
		entity->tick(delta);
}

void Space::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
	sf::Vector2f viewSize = VIEW_SIZE;
	sf::Vector2f start = getShip().getLocation() - viewSize / 2.0f;
	sf::Vector2f end = getShip().getLocation() + viewSize / 2.0f;


	for(Entity* entity : entities)
		if(entity->getLocation().x >= start.x
		   && entity->getLocation().y >= start.y
		   && entity->getLocation().x <= end.x
		   && entity->getLocation().y <= end.y)
			target.draw(*entity);
}

const Ship& Space::getShip() const {
	return ship;
}

wiz::AssetLoader& Space::getAssets() const {
	return assets;
}
