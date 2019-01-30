#include "player.hpp"
#include "asteroid.hpp"
#include "iterator"

extern bool spawningAsteroid;
extern bool guiOn;
extern float asteroidMass;


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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && velocity.mag()!=0) {velocity=(velocity.norm())*(velocity.mag()-0.2);}

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket)) {asteroidMass-=0.1f;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket)) {asteroidMass+=0.1f;}


    keyboardUpdate();

    if(velocity.mag() < 0.1) {velocity=VECTOR2(0,0);}

}

void player::keyboardUpdate() {
    //printf("Bruh:%d\n", (sf::Keyboard::isKeyPressed(keyList[2])));
    for(int k=0;k< 4 ;k++) {

        if(sf::Keyboard::isKeyPressed(keyList[k])) {
            if(!keyStates[k]) {keyStates[k]=true;
                switch (k) {
                    case 0: spawningAsteroid=true; break; //A
                    case 1:  guiOn=!guiOn; break; //O
                    case 2:  break; //[
                    case 3:  break; //]

                }
            }
        } else {keyStates[k]=false;}

    }
}
