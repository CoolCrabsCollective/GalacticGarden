//
// Created by Alexander Winter on 2023-01-08.
//

#ifndef LD52_CLIENT_FLOATINGTEXT_H
#define LD52_CLIENT_FLOATINGTEXT_H


#include "Entity.h"
#include "SFML/Graphics/Text.hpp"

class FloatingText : public Entity {
    mutable sf::Text text;
    
public:
    FloatingText(Space& space, 
                 sf::Vector2f location,
                 std::string text,
                 sf::Color color,
                 float duration);
};


#endif //LD52_CLIENT_FLOATINGTEXT_H
