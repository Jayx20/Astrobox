#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <memory>
#include <string>
#include <cmath>



#include "src/player.hpp"
#include "src/entity.hpp"
#include "src/asteroid.hpp"
#include "src/resource.hpp"



///this is the creation of our game window and view
sf::RenderWindow window(sf::VideoMode(1440, 810), "Astrobox");
sf::View view;

///stuff for the FrameCounter function
int frames;
sf::Clock frameTimer;
int secondsPassed;

///global variables to use along with player
bool spawningAsteroid;
bool guiOn = true;
//bool guiSeen;
float asteroidMass = 1.f;
float viewX, viewY;
float viewScale = 1;

///gui stuff
sf::Font freesans;


    ///functions to be used in the main game loop

void FrameCounter() {
        ///spams the framerate in the console every second
		frames++; ///adds a frame to the count
        if(frameTimer.getElapsedTime().asMilliseconds() > 1000) ///runs when a second has passed
            {
             frameTimer.restart(); ///resets the clock the keeps track of millseconds passed
             printf("%i\n",frames); ///prints the framerate
             frames = 0; ///resets the frames back to 0 for the next count

             secondsPassed++;
             printf("Your mom!! This program has been running for %i seconds\n",secondsPassed);
             ///displays the number of seconds that have passed in total
             //this is mostly for testing, hence the Your Mom!!
            }

        //atm the framerate keeps displaying as 62 idk why but its not a big deal we can work with 2 extra frames lol
}


sf::Texture SPRITE_SHEET;
//this is the sprite sheet that acts like a global variable so all the entities can access it by reference without
//me having to pass it through every single construction of every entity because i find that annoying

///array for all the entities
//later i might have to break it into many arrays in like a grid for better performance
//like how minecraft has chunks, but maybe more in depth
std::vector<std::shared_ptr<entity>> allEntities;

int main()
{
    window.setFramerateLimit(60); //i think you know what this does
    SPRITE_SHEET.loadFromImage(LoadImageFromResource("IMG_SPRITES"));  ///loads the sprite sheet into SPRITE_SHEET


    freesans = LoadFontFromResource("FREE_SANS");
    sf::Text liveMessage("uninitialized",freesans,20);
    sf::Text message(
        "Press O to toggle ui.\n"
        "Arrow keys to move, and Space to slow down.\n"
        "Press / to toggle the camera following the player.\n"
        "Holding alt will let you move the camera if it is not locked. - and + Zoom.\n"
        "Press [ and ] to change asteroid size and A to spawn asteroid."
        "\n\n\n" /*space for the size and entity count*/
        "Tell me how many entities can lag your game, I'm curious.",freesans,20);

    liveMessage.setPosition(0,120);
    ///player testEntity; //creates a test entity
    ///testEntity.setPosition(400.f,300.f);

    allEntities.push_back(std::shared_ptr<entity>(new player()));
    allEntities[0]->setPosition(510,270);

    ///adding new entities for testing purposes
    for (int i=0;i<11;i++)
    {
        allEntities.push_back(std::shared_ptr<entity>(new asteroid(300+i*50.f,0+i*50.f,i*0.5)));
        //allEntities[i+1]->setPosition(300+i*50,0+i*50);
        //allEntities[i+1]->setVelocity(VECTOR2(0,0));
    }


    /// this is our main loop that runs the entire time our game is running
    while (window.isOpen())
    {
        window.clear(); ///resets the window so it can be drawn again
        /// the event loop is what manages all the user interaction with the window
		/// just dont fiddle with this
        sf::Event event;
        while (window.pollEvent(event))
        {
            ///closes the window when the close button is hit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        view.reset(sf::FloatRect(viewX,viewY,window.getSize().x*viewScale,window.getSize().y*viewScale));
        window.setView(view);
		//
		///here is the actual game code:



		///goes through every single entity and runs updates
        for (std::shared_ptr<entity> e : allEntities) {
            e->update();
            window.draw(*e);
            if (!e->noclip) {e->collisionsUpdate(allEntities);}
        }
        if(spawningAsteroid) {
        allEntities.push_back(std::shared_ptr<entity>(new asteroid(allEntities[0]->getPosition().x,allEntities[0]->getPosition().y-50,asteroidMass)));
        spawningAsteroid=false;}


        FrameCounter(); //test frame counting stuff


        window.setView(window.getDefaultView());

        liveMessage.setString( "Size: "+(std::to_string(asteroidMass)).erase(std::to_string(asteroidMass).length()-4,4) +"\nEntity Count: "+std::to_string(allEntities.size()));
        //the rounding fix is really stupid if somebody can make it simpler do so im just removing decimals
        if(guiOn) { //guiSeen=true;
            window.draw(liveMessage);
            window.draw(message);
            }
        //if(!guiSeen) {window.draw(message);}

        window.display(); ///updates the whole window

		///this is where the main loop ends
		//
    }

    return 0;
}

