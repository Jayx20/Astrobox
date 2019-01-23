#pragma once

#include <SFML/Graphics.hpp>

extern sf::Texture SPRITE_SHEET;

class entity : public sf::Sprite {
	public:

        entity();

	private:

        float speed; //for use later
        float direction; //when i add physics

};
