#pragma once

#include "entity.hpp"

class player : public entity {
	public:
	    player();
	    void update();

    private:

        //enum keyState {OFF, HIT, HELD};
        bool keyStates[4];
        ///this set up of two enumerators for all my keys in a random order is bad I know... I tried using a Map but it was weird
        //A = 0
        //O = 1
        // / = 2
        sf::Keyboard::Key keyList[3] = {sf::Keyboard::A,sf::Keyboard::O,sf::Keyboard::Slash};
        //sf::Keyboard::
        void keyboardUpdate();
        bool aPressed;
        bool oPressed;
        float fast;
        bool viewFollow=true;
};
