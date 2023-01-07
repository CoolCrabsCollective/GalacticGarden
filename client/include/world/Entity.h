//
// Created by Alexander Winter on 2023-01-06.
//

#ifndef LD52_CLIENT_ENTITY_H
#define LD52_CLIENT_ENTITY_H

#include "SFML/System/Vector2.hpp"
#include "Tickable.h"
#include "SFML/Graphics/Drawable.hpp"

class Space;

/**
 * Something which has a location in 2D space
 */
class Entity : public Tickable, public sf::Drawable {
protected:
	Space& space;
	sf::Vector2f location;
public:

	Entity(Space& space, 
		   sf::Vector2f location)
			: space(space), location(location) {}

	virtual ~Entity() = default;

	[[nodiscard]]
	Space& getSpace() const {
		return space;
	}

	[[nodiscard]] 
	const sf::Vector2f& getLocation() const {
		return location;
	}

    virtual float getZOrder() const {
        return 0.;
    };
};

#endif //LD52_CLIENT_ENTITY_H
