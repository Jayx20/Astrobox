#pragma once

#include <SFML/Graphics.hpp>
#include "vector2.hpp"
#include <vector>
#include <memory>

extern sf::Texture SPRITE_SHEET;

class entity : public sf::Sprite {
	public:

        entity();
        entity(VECTOR2 velocityI);

        virtual void update();
        void setVelocity(VECTOR2 velocityN);
        void addForce (VECTOR2 force);

        void collisionsUpdate(std::vector<std::shared_ptr<entity>> &targets);

        bool noclip = false;
        float radius;

	protected:

        void movement();

        VECTOR2 velocity;
        float mass;


        bool checkColliding(entity &target);
        //float speed;
        //float direction;

};
