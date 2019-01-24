#pragma once

#include <SFML/Graphics.hpp>
#include "vector2.hpp"

extern sf::Texture SPRITE_SHEET;

class entity : public sf::Sprite {
	public:

        entity();
        entity(VECTOR2 velocityI);

        virtual void update();
        void setVelocity(VECTOR2 velocityN);
        void addForce (VECTOR2 force);

	protected:

        void movement();

        VECTOR2 velocity;
        float mass;
        //float speed;
        //float direction;

};
