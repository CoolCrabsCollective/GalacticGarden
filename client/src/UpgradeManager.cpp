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

#include <iostream>
float UpgradeManager::get_cost(Upgrade upgrade) const {
    //std::cout << upgrade << std::endl;
    if(!upgrade_cost.contains(upgrade))
        return 0;
    return upgrade_cost.at(upgrade);
}

bool UpgradeManager::has_unlocked(Upgrade upgrade) const {
    return has_upgraded.at(upgrade);
}

