//
// Created by william on 08/01/23.
//

#ifndef LD52_CLIENT_SELECTIONTEXT_H
#define LD52_CLIENT_SELECTIONTEXT_H

#include <vector>
#include <string>

class WeaponTextGetter {
    std::vector<std::string> weaponText;

public:
    WeaponTextGetter() {
        weaponText =
                {"SIMPLE",
                 "DOUBLE",
                 "TRIANGLE",
                 "SHOTGUN",
                 "CRAZY",
                 "NUKE"};
    }

    ~WeaponTextGetter() = default;

    std::vector<std::string> get() {
        return weaponText;
    }
};

class SeedTextGetter {
    std::vector<std::string> seedText;

public:
    SeedTextGetter() {
        seedText =
                {"FLOWER",
                 "CORN"};
    }

    ~SeedTextGetter() = default;

    std::vector<std::string> get() {
        return seedText;
    }
};

class BoostTextGetter {
    std::vector<std::string> boostText;

public:
    BoostTextGetter() {
        boostText =
                {"NONE",
                 "BASIC",
                 "ULTRA"};
    }

    ~BoostTextGetter() = default;

    std::vector<std::string> get() {
        return boostText;
    }
};

#endif //LD52_CLIENT_SELECTIONTEXT_H
