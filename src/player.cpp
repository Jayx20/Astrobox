#include "player.hpp"

player::player() {
    ///sets the player sprite to something other than the missing texture sprite
    player::setTextureRect(sf::IntRect(32,0,32,32));
}

void player::update() {
    movement(); ///part of entity class
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {speed+=0.05;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {speed-=0.05;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {direction-=2;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {direction+=2;}

    //printf("%f",speed);
}
