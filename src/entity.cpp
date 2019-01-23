#include "entity.hpp"


entity::entity() {
    //loads the generic texture sprite sheet
    entity::setTexture(SPRITE_SHEET);
    //sets the generic missing texture values so any new entities without textures are drawn
    entity::setTextureRect(sf::IntRect(0,0,32,32));
}

