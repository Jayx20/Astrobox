#include "asteroid.hpp"

asteroid::asteroid() {
    setTextureRect(sf::IntRect(32,96,32,32));
}

asteroid::asteroid(VECTOR2 velocityI) {
    setTextureRect(sf::IntRect(32,96,32,32));
    velocity = velocityI;
}
