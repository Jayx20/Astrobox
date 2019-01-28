#include "asteroid.hpp"

asteroid::asteroid() {
    setTextureRect(sf::IntRect(32,96,32,32));
    radius = 14;
}

asteroid::asteroid(float x, float y) {
    setTextureRect(sf::IntRect(32,96,32,32));
    radius = 14;
    setPosition(x,y);
}


asteroid::asteroid(VECTOR2 velocityI) {
    setTextureRect(sf::IntRect(32,96,32,32));
    radius = 14;
    velocity = velocityI;
}

