//
// Created by cedric on 1/8/23.
//

#pragma once
#include <vector>
#include <functional>

class Space;
class WaveManager {
protected:
    int currentWave = 0;
    const float waveCooldown = 10.f;
    float currentWaveCooldownProgress = 0.f;
    std::function<void(int)> newWaveCallback;
    std::vector<std::vector<int>> waves {{
        // HATCHLINGS, CROWCRAFTS, NESTS, TREES
         {3, 0, 0, 0},
         {6, 0, 0, 0},
         {3, 1, 0, 0},
         {6, 3, 0, 0},
         {8, 3, 1, 0},
         {16, 5, 3, 0},
         {0, 0, 0, 1},
    }};
    Space& space;
public:
    WaveManager(Space& space);
    void setCallback(std::function<void (int)> newWaveCallback);
    void spawnNextWave();
    void update(float good_delta);
};
