#include "player.hpp"
#include "asteroid.hpp"
#include "iterator"

extern bool spawningAsteroid, guiOn;
extern float asteroidMass, viewX, viewY, viewScale;
bool viewFollow=true;
extern sf::View view;


player::player() {
    ///sets the player sprite to something other than the missing texture sprite
    setTextureRect(sf::IntRect(32,0,32,32));
    radius = 15;
}

void player::update() {
    movement(); ///part of entity class

    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)&&!sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) {
        ///player movement
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {addForce(VECTOR2(0,-0.1));}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {addForce(VECTOR2(0,0.1));}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {addForce(VECTOR2(-0.1,0));}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {addForce(VECTOR2(0.1,0));}
    }
    else {
        ///camera movement
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {viewY-=8.f;}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {viewY+=8.f;}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {viewX-=8.f;}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {viewX+=8.f;}
    }
    if (viewFollow) {viewX=getPosition().x-view.getSize().x/2; viewY=getPosition().y-view.getSize().y/2;}


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && velocity.mag()!=0) {velocity=(velocity.norm())*(velocity.mag()-0.2);}

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket)) {asteroidMass-=0.02f;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket)) {asteroidMass+=0.02f;}
    if(asteroidMass<0.1f) {asteroidMass=0.1f;}

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Equal)) {viewScale-=0.01f;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Dash)) {viewScale+=0.01f;}
    if(viewScale<0.1f) {viewScale=0.1f;}

    keyboardUpdate();

    if(velocity.mag() < 0.1) {velocity=VECTOR2(0,0);}

}

void player::keyboardUpdate() {
    //printf("Bruh:%d\n", (sf::Keyboard::isKeyPressed(keyList[2])));
    for(int k=0;k< 3 ;k++) {

        if(sf::Keyboard::isKeyPressed(keyList[k])) {
            if(!keyStates[k]) {keyStates[k]=true;
                switch (k) {
                    case 0: spawningAsteroid=true; break; //A
                    case 1:  guiOn=!guiOn; break; //O
                    case 2:  viewFollow=!viewFollow; break;
                }
            }
        } else {keyStates[k]=false;}

    }
}
