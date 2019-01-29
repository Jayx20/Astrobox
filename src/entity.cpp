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

            //totally not copied off the internet (i do not math brain)
            VECTOR2 n((getPosition().x-target->getPosition().x),(getPosition().y-target->getPosition().y));
            n = n.norm();

            float offset = sqrt(( pow((getPosition().x-target->getPosition().x),2) + pow((getPosition().y-target->getPosition().y),2) ))-(radius+target->radius);

            setPosition(getPosition()-(n*offset).sf());
            target->setPosition(target->getPosition()+(n*offset).sf());


            float a1 = velocity.dot(n);
            float a2 = target->velocity.dot(n);

            float optimizedP = (2.0 * (a1 - a2)) / (mass + target->mass);

            VECTOR2 newVelocityA = velocity - (n*(optimizedP * target->mass));
            VECTOR2 newVelocityB = target->velocity + (n*(optimizedP * mass));

            setVelocity(newVelocityA);
            target->setVelocity(newVelocityB);

            //if(newVelocityA.mag() == 0 && newVelocityB.mag() == 0) {setVelocity(VECTOR2(5,5)); target->setVelocity(VECTOR2(-5,-5));}



}   }   }

bool entity::checkColliding(entity &target) {
    bool colliding;
    colliding = (pow((radius+target.radius),2)) > ( pow((getPosition().x-target.getPosition().x),2) + pow((getPosition().y-target.getPosition().y),2) );
    return colliding;
}
