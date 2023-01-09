//
// Created by Alexander Winter on 2023-01-08.
//

#ifndef LD52_CLIENT_FLOATINGTEXT_H
#define LD52_CLIENT_FLOATINGTEXT_H


#include "Entity.h"
#include "SFML/Graphics/Text.hpp"

class FloatingText : public Entity {
    float maxLife, life;
    
    mutable sf::Text text;
    
public:
    FloatingText(Space& space, 
                 sf::Vector2f location,
                 const std::string& text,
                 sf::Color color,
                 float duration);

    void tick(float delta) override;

    void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

    float getZOrder() const override;

    bool shouldBeRemoved() const override;
private:
    float opacity() const;
};


#endif //LD52_CLIENT_FLOATINGTEXT_H
