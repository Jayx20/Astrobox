#pragma once

#include "entity.hpp"

class asteroid : public entity {
	public:
		asteroid();
        asteroid(VECTOR2 velocityI);
        asteroid(float x, float y);
		//void update() {movement();}

};

