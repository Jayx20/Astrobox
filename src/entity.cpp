#include "entity.hpp"
#include <cmath>

const double pi = 3.14159265358979323846;

entity::entity() {
    ///loads the generic texture sprite sheet
    entity::setTexture(SPRITE_SHEET);
    ///sets the generic missing texture values so any new entities without textures are drawn
    entity::setTextureRect(sf::IntRect(0,0,32,32));
    entity::setOrigin(getTextureRect().width/2,getTextureRect().height/2);
}

entity::entity(VECTOR2 velocityI) {
    ///loads the generic texture sprite sheet
    entity::setTexture(SPRITE_SHEET);
    ///sets the generic missing texture values so any new entities without textures are drawn
    entity::setTextureRect(sf::IntRect(0,0,32,32));
    entity::setOrigin(getTextureRect().width/2,getTextureRect().height/2);
    velocity = velocityI;
}

void entity::update() {
    movement();
}

void entity::movement() {
    //setRotation(direction+90); ///sets the rotation of the entity to its direction variable
    //move(cos(direction*(pi/180))*speed,sin(direction*(pi/180))*speed);
    move(velocity.sf());
    ///moves the entity
}

void entity::addForce (VECTOR2 force) {
    velocity += force;
}

void entity::setVelocity(VECTOR2 velocityN) {
    velocity = velocityN;
}
