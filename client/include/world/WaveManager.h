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
    const float waveCooldown = 45.0f;
    float currentWaveCooldownProgress = 0.0f;
    std::function<void(int)> newWaveCallback;
    std::vector<std::vector<int>> waves {{
        // HATCHLINGS, CROWCRAFTS, NESTS, TREES
         {3, 0, 0, 0},
         {10, 0, 0, 0},
         {30, 0, 0, 0},
         {15, 5, 0, 0},
         {15, 10, 0, 0},
         {15, 20, 1, 0},
         {25, 20, 3, 0},
         {0, 0, 0, 1},
    }};
    Space& space;
public:
    WaveManager(Space& space);
    void setCallback(std::function<void (int)> newWaveCallback);
    void spawnNextWave();
    void update(float good_delta);

    int get_current_wave() const;
};
