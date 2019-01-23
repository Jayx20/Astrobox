#pragma once

#include <SFML/Graphics.hpp>

extern sf::Texture SPRITE_SHEET;

class entity : public sf::Sprite {
	public:

        entity();
        entity(float speedI, float directionI);

        virtual void update();
        void setVelocity(float speedNew, float directionNew);

	protected:

        void movement();

        float speed;
        float direction;
};
