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

    /**this goes through every single entity in the game one at a time, not very efficient but I haven't spawned enough entities to see lag yet
    /in my eyes that's the beauty of C++ as compared to Unity, I'm sure you can get good performance out of Unity but when I was trying to use it
    /I wasn't forced to think about performance the way you are in C++, and something like this would have created a lot more lag. **/

    for (std::shared_ptr<entity> target : targets) {
            ///the line below first makes sure our entity does not try to check if its colliding with itself or any object with noclip
            ///then it uses the checkColliding method to check if it is colliding with the other entity
        if(target.get() != this && !target->noclip && checkColliding(*target) ) {

            /**The basis of this collision code was largely copied off of an article from the website Gamasutra
            /it's called Pool Hall Lessons: Fast, Acurrate Collision Detection Between Circles or Spheres
            /it really helped me because I do not have an especially great understanding of vectors and vector operations **/

            ///n is the vector we get from the difference of positions between the two objects,
            ///basically this gives us the directions the collision will move the objects in
            VECTOR2 n((getPosition().x-target->getPosition().x),(getPosition().y-target->getPosition().y));
            n = n.norm(); ///we just want a direction no magnitude

            ///the offset finds the distance between the two objects, minus the sizes of their radii.
            float offset = (sqrt(( pow((getPosition().x-target->getPosition().x),2) +
                                   pow((getPosition().y-target->getPosition().y),2) ))
                            -(radius+target->radius));

            ///we also find the ratios between their masses, to be used along with the offset...
            float massR1 = target->mass/(mass+target->mass);
            float massR2 = mass/(mass+target->mass);

            ///we use the mass ratios and the offset to teleport the objects slightly to make sure they aren't inside each other
            ///this is something I wrote myself but it's based on ideas from a video by the youtuber javidx9 about Circle Vs Circle collisions
            setPosition(getPosition()-(n*offset*massR1).sf());
            target->setPosition(target->getPosition()+(n*offset*massR2).sf());

            float a1 = velocity.dot(n);
            float a2 = target->velocity.dot(n);
            ///these lines are where we find how much force should be applied to each object
            float optimizedP = (2.0 * (a1 - a2)) / (mass + target->mass);

            ///calculating the final velocity vectors to apply to the two objects
            VECTOR2 newVelocityA = velocity - (n*(optimizedP * target->mass));
            VECTOR2 newVelocityB = target->velocity + (n*(optimizedP * mass));

            ///giving the two objects their new velocities after the collision
            setVelocity(newVelocityA);
            target->setVelocity(newVelocityB);
}   }   }

///used by entity on a target entity to check if they are colliding
bool entity::checkColliding(entity &target) {

    bool colliding = (pow((radius+target.radius),2)) ///first the method finds the square of the two radii of the two objects
                      > ( pow((getPosition().x-target.getPosition().x),2) + pow((getPosition().y-target.getPosition().y),2) );
                    ///then it sees if that is bigger than the square root of the distance between the two objects
                    ///this collision check does not actually find the square root of the distance for performance reasons
                    ///that is why we square the result from the first line of this collision check
    return colliding;
}
