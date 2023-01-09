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
         {3, 0, 1, 1},
         {8, 0, 0, 0},
         {14, 1, 0, 0},
         {17, 4, 0, 0},
         {20, 5, 1, 0},
         {20, 5, 3, 0},
         {0, 0, 0, 1},
    }};
    Space& space;
public:
    WaveManager(Space& space);
    void setCallback(std::function<void (int)> newWaveCallback);
    void spawnNextWave();
    void update(float good_delta);
};
