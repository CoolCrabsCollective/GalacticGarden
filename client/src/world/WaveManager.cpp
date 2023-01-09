//
// Created by cedric on 1/8/23.
//

#include "world/WaveManager.h"
#include "world/Space.h"

WaveManager::WaveManager(Space &space) : space(space){

}


void WaveManager::spawnNextWave() {
    std::vector<int>& wave = waves[currentWave];
    int hatchlingsToSpawn = wave[0];
    int crowCraftsToSpawn = wave[1];
    int nestsToSpawn = wave[2];
    int treesToSpawn = wave[3];

    for(int i = 0; i < hatchlingsToSpawn; i++)
        space.spawnEnemyHatchling();

    for(int i = 0; i < crowCraftsToSpawn; i++)
        space.spawnEnemyCrowCraft();

    for(int i = 0; i < nestsToSpawn; i++)
        space.spawnEnemyNest();

    for(int i = 0; i < treesToSpawn; i++)
        space.spawnEnemyTree();
    currentWave++;
}

void WaveManager::update(float good_delta) {
    currentWaveCooldownProgress += good_delta;
    if(currentWaveCooldownProgress >= waveCooldown)
    {
        currentWaveCooldownProgress = 0;
        newWaveCallback(currentWave);
        spawnNextWave();
        currentWave++;
    }
}

void WaveManager::setCallback(std::function<void(int)> newWaveCallback) {
    this->newWaveCallback = newWaveCallback;
}

