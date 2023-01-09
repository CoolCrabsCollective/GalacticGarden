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
#include "world/station/GayStation.h"
#include "UpgradeManager.h"
#include "world/enemy/EnemyShip.h"
#include "WaveManager.h"
#include <list>

class Space : public Tickable, public sf::Drawable {
protected:
	wiz::AssetLoader& assets;
	std::vector<Entity*> entities;

    Ship ship;
    GayStation gayStation;
    
    mutable std::vector<Entity*> entities_draw_list;
    std::map<uint64_t, std::list<Entity*>> spacialMap;

    UpgradeManager upgradeManager {
            { Upgrade::LASER_SIMPLE,        0.0f },
            { Upgrade::LASER_DOUBLE,        15.0f },
            { Upgrade::LASER_TRIANGLE,      50.0f },
            { Upgrade::LASER_SHOTGUN,       100.0f },
            { Upgrade::LASER_CRAZY,         300.0f },
            { Upgrade::NUKE_SIMPLE,         500.0f },
            { Upgrade::FLAMETHROWER_SIMPLE, 300.0f },
            { Upgrade::BOOST_BASIC,         75.0f },
            { Upgrade::BOOST_ULTRA,         300.0f },
    };

    WaveManager waveManager;
public:
	constexpr const static sf::Vector2f VIEW_SIZE = { 16.0f, 9.0f };
	constexpr const static float CHUNK_SIZE = 2.0f;
    constexpr const static float MAP_RADIUS = 200.0f;

	Space(wiz::AssetLoader& assets, std::function<void (int)> waveCallback);

	void tick(float delta) override;

    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

    Ship& getShip();

    GayStation& getGayStation();

    const Ship& getShip() const;

	wiz::AssetLoader& getAssets() const;

    const std::vector<Entity*>& getEntities() const;

	std::vector<Entity*> getAllEntitiesInRect(sf::Vector2f center,
											  sf::Vector2f size) const;

    void addEntity(Entity* entity);

    sf::Vector2f getNearestFriendly(sf::Vector2f pos);

    bool gameover = false; // why is this public
    bool paused = false;

    UpgradeManager &getUpgradeManager();

    void spawnEnemyHatchling();
    void spawnEnemyCrowCraft();
    void spawnEnemyNest();
    void spawnEnemyTree();

private:
	void initSpacialMap();
    void removeEntities();
	void removeFromMap(Entity* entity);

	uint64_t spacialKey(sf::Vector2f location) const;
    void spawnAsteroids();

};


#endif //LD52_CLIENT_SPACE_H
