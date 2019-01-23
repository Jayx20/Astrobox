#include "player.hpp"

player::player() {
    //sets the player sprite to something other than the missing texture sprite
    player::setTextureRect(sf::IntRect(32,0,32,32));
}
