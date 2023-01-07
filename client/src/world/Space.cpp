//
// Created by Alexander Winter on 2023-01-06.
//

#include <algorithm>
#include "world/Space.h"
#include "world/Asteroid.h"
#include "world/crop/FalloutFlower.h"
#include "world/enemy/HatchlingShip.h"

Space::Space(wiz::AssetLoader& assets) 
	: assets(assets), entities(), ship(*this, { 0.0f, 0.0f }) {
	entities.push_back(&ship);
	entities.push_back(new Asteroid(*this, { 0.0f, 3.0f }, 0.0f, { 0.0f, 0.0f }, 10.0f ));
    entities.push_back(new FalloutFlower(*this, { 1.0, 3.f}));
    entities.push_back(new HatchlingShip(*this, {-1.0f, -1.0f}));
	entities.push_back(new Asteroid(*this, { 0.0f, -3.0f }, 0.0f, { 0.0f, 0.0f }, -1.0f));

}

void Space::tick(float delta) {
	for(Entity* entity : entities)
		entity->tick(delta);

    renderables.clear();

    for(Entity* obj : entities) {
        Renderable* renderable = dynamic_cast<Renderable*>(obj);
        if(renderable)
            renderables.push_back(renderable);
    }

    std::sort(renderables.begin(), renderables.end(), [&](Renderable* a, Renderable* b){
        return a->getZOrder() < b->getZOrder();
    });
}

void Space::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
	sf::Vector2f viewSize = VIEW_SIZE;
	sf::Vector2f start = getShip().getLocation() - viewSize / 2.0f;
	sf::Vector2f end = getShip().getLocation() + viewSize / 2.0f;

	for(Renderable* renderable : renderables)
    {
        if(Entity* entity = dynamic_cast<Entity*>(renderable))
        {
            if(entity->getLocation().x >= start.x
               && entity->getLocation().y >= start.y
               && entity->getLocation().x <= end.x
               && entity->getLocation().y <= end.y)
                target.draw(*entity);
        }
    }
}

const Ship& Space::getShip() const {
	return ship;
}

wiz::AssetLoader& Space::getAssets() const {
	return assets;
}
