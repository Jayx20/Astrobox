#include "asteroid.hpp"
#include <cmath>

asteroid::asteroid() {
    setTextureRect(sf::IntRect(32,96,32,32));
    radius = 14;
}

asteroid::asteroid(float x, float y) {
    setTextureRect(sf::IntRect(32,96,32,32));
    radius = 14;
    setPosition(x,y);
}

asteroid::asteroid(float x, float y, float largeness) {
    setTextureRect(sf::IntRect(32,96,32,32));
    setScale(largeness,largeness);
    radius = 14*largeness;
    mass=(pow(largeness,3)*4.18879020479);
    setPosition(x,y);
}

asteroid::asteroid(VECTOR2 velocityI) {
    setTextureRect(sf::IntRect(32,96,32,32));
    radius = 14;
    velocity = velocityI;
}

