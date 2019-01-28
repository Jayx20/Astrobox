#pragma once

#include "entity.hpp"

class player : public entity {
	public:
	    player();
	    void update();

    private:
        bool aPressed;
};
