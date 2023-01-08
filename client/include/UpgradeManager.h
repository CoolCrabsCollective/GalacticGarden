//
// Created by cedric on 1/8/23.
//

#pragma once
#include <algorithm>
#include <unordered_map>

enum Upgrade {
    // LASERS
    LASER_SIMPLE,
    LASER_DOUBLE,
    LASER_TRIANGLE,
    LASER_FOUR_WAY,
    LASER_CRAZY,

    // NUKES
    NUKE_SIMPLE,
    WEAPON_UPGRADE_LENGTH,

    // FLAMETHROWER
    FLAMETHROWER_SIMPLE,

    // BOOST
    BOOST_BASIC,
    BOOST_ULTRA

};

class UpgradeManager {
protected:
    std::unordered_map<Upgrade, bool> has_upgraded;
    std::unordered_map<Upgrade, float> upgrade_cost;
public:
    explicit UpgradeManager(std::initializer_list<std::pair<const Upgrade, float>> costs);

    void unlock(Upgrade upgrade);
    float get_cost(Upgrade upgrade) const;
    bool has_unlocked(Upgrade upgrade) const;
};
