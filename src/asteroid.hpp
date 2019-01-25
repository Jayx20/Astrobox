#pragma once

#include "entity.hpp"

class asteroid : public entity {
	public:
		asteroid();
        asteroid(VECTOR2 velocityI);

		//void update() {movement();}

};

