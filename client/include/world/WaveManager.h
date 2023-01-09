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
    const float waveCooldown = 30.0f;
    float currentWaveCooldownProgress = -30.0f;
    std::function<void(int)> newWaveCallback;
    std::vector<std::vector<int>> waves {{
        // HATCHLINGS, CROWCRAFTS, NESTS, TREES
         {2, 0, 0, 0},
         {12, 0, 0, 0},
         {40, 0, 0, 0},
         {50, 1, 0, 0},
         {50, 2, 0, 0},
         {50, 20, 1, 0},
         {100, 50, 5, 0},
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
