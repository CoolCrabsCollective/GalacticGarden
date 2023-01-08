//
// Created by cedric on 1/8/23.
//

#include "UpgradeManager.h"

UpgradeManager::UpgradeManager(std::initializer_list<std::pair<const Upgrade, float>> costs) : upgrade_cost(costs){

    for(auto & [key, value] : upgrade_cost)
    {
        has_upgraded[key] = value <= 0.01f;
    }
}
void UpgradeManager::unlock(Upgrade upgrade) {
    has_upgraded[upgrade] = true;
}

float UpgradeManager::get_cost(Upgrade upgrade) {
    return upgrade_cost.at(upgrade);
}

bool UpgradeManager::has_unlocked(Upgrade upgrade) {
    return has_upgraded.at(upgrade);
}

