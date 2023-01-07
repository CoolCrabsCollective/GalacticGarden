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
#include <list>

class Space : public Tickable, public sf::Drawable {
protected:
	wiz::AssetLoader& assets;
	std::vector<Entity*> entities;

    Ship ship;
    
    mutable std::vector<Entity*> entities_draw_list;
    std::map<uint64_t, std::list<Entity*>> spacialMap;

    int enemy_count = 0;
    int max_enemy_count = 3;
    float spawn_delay = 100.0f;
    float time_since_last_spawn = .0f;
	
public:
	constexpr const static sf::Vector2f VIEW_SIZE = { 16.0f, 9.0f };
	constexpr const static float CHUNK_SIZE = 2.0f;

	Space(wiz::AssetLoader& assets);

	void tick(float delta) override;

    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

    Ship& getShip();

    const Ship& getShip() const;

	wiz::AssetLoader& getAssets() const;

    const std::vector<Entity*>& getEntities() const;

	std::vector<Entity*> getAllEntitiesInRect(sf::Vector2f center,
											  sf::Vector2f size) const;

    void addEntity(Entity* entity);

private:
	void initSpacialMap();
    void removeEntities();
	void removeFromMap(Entity* entity);

	uint64_t spacialKey(sf::Vector2f location) const;

    void manageEnemies();
    void spawnEnemy(sf::Vector2f pos);

};


#endif //LD52_CLIENT_SPACE_H
