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
         {5, 0, 0, 0},
         {10, 0, 0, 0},
         {10, 1, 0, 0},
         {5, 5, 0, 0},
         {10, 4, 1, 0},
         {15, 3, 3, 0},
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
