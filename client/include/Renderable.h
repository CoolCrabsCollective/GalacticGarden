//
// Created by cedric on 1/6/23.
//

#ifndef LD52_CLIENT_RENDERABLE_H
#define LD52_CLIENT_RENDERABLE_H
#include "SFML/Graphics/Drawable.hpp"

class Renderable : public sf::Drawable {
public:
    virtual float getZOrder() const = 0;
};


#endif //LD52_CLIENT_RENDERABLE_H
