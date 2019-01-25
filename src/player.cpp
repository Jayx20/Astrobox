#include "player.hpp"

player::player() {
    ///sets the player sprite to something other than the missing texture sprite
    setTextureRect(sf::IntRect(32,0,32,32));
    radius = 15;
}

void player::update() {
    movement(); ///part of entity class
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {addForce(VECTOR2(0,-0.1));}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {addForce(VECTOR2(0,0.1));}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {addForce(VECTOR2(-0.1,0));}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {addForce(VECTOR2(0.1,0));}

    //printf("%f",velocity.x,velocity.y);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && velocity.mag()!=0) {velocity=(velocity.norm())*(velocity.mag()-0.2);}

    if(velocity.mag() < 0.1) {velocity=VECTOR2(0,0);}



    //printf("%f",velocity.mag());
}
