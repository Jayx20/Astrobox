#include "entity.hpp"
#include <cmath>

const double pi = 3.14159265358979323846;

entity::entity() {
    ///loads the generic texture sprite sheet
    setTexture(SPRITE_SHEET);
    ///sets the generic missing texture values so any new entities without textures are drawn
    setTextureRect(sf::IntRect(0,0,32,32));
    setOrigin(getTextureRect().width/2,getTextureRect().height/2);
    radius = 16;
}

entity::entity(VECTOR2 velocityI) {
    ///loads the generic texture sprite sheet
    setTexture(SPRITE_SHEET);
    ///sets the generic missing texture values so any new entities without textures are drawn
    setTextureRect(sf::IntRect(0,0,32,32));
    setOrigin(getTextureRect().width/2,getTextureRect().height/2);
    radius = 16;
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

void entity::collisionsUpdate(std::vector<std::shared_ptr<entity>> &targets) {
    for (std::shared_ptr<entity> target : targets) {
        if(target.get() != this && !target->noclip && checkColliding(*target) ) {
            printf("colliding!!");
        }
    }
}

bool entity::checkColliding(entity &target) {
    bool colliding;
    //printf("testing!!");
    //colliding = (pow((radius+target.radius),2) > ( (getPosition().x-target.getPosition().x) + (getPosition().y-target.getPosition().y) ));


    //float radiis = pow((radius+target.radius),2);
    //float distance = ( pow((getPosition().x-target.getPosition().x),2) + pow((getPosition().y-target.getPosition().y),2) );

    //printf("Radiis: %f, Distance %f\n",radiis,distance);
    colliding = (pow((radius+target.radius),2)) > ( pow((getPosition().x-target.getPosition().x),2) + pow((getPosition().y-target.getPosition().y),2) );

    return colliding;
}
