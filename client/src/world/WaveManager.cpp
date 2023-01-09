//
// Created by cedric on 1/8/23.
//

#include "world/WaveManager.h"
#include "world/Space.h"

WaveManager::WaveManager(Space &space) : space(space){

}


void WaveManager::spawnNextWave() {
    int hatchlingsToSpawn = 0;
    int crowCraftsToSpawn = 0;
    int nestsToSpawn = 0;
    int treesToSpawn = 0;

    if (currentWave < waves.size()) {
        std::vector<int>& wave = waves[currentWave];
        hatchlingsToSpawn = wave[0];
        crowCraftsToSpawn = wave[1];
        nestsToSpawn = wave[2];
        treesToSpawn = wave[3];
    } else {
        hatchlingsToSpawn = currentWave * 10;
    }

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
    }
}

void WaveManager::setCallback(std::function<void(int)> newWaveCallback) {
    this->newWaveCallback = newWaveCallback;
}

int WaveManager::get_current_wave() const {
    return currentWave;
}

