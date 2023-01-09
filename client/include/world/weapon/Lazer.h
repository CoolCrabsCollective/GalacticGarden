//
// Created by Alexander Winter on 2023-01-07.
//

#ifndef LD52_CLIENT_LAZER_H
#define LD52_CLIENT_LAZER_H


#include "world/Entity.h"

enum Faction {
    FRIENDLY,
    ENEMY
};

class Lazer : public Entity {
public:
    Lazer(Space& space, sf::Vector2f location) 
        : Entity(space, location) {}

    virtual float getDamage() = 0;
    
    virtual void consume() = 0;

    virtual Faction getFaction() = 0;

    bool shouldBeRemoved() const override {
        return Entity::shouldBeRemoved();
    }
};


#endif //LD52_CLIENT_LAZER_H
