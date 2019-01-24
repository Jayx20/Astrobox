#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <memory>


#include "player.hpp"
#include "entity.hpp"




///this is the creation of our game window.
sf::RenderWindow window(sf::VideoMode(960, 540), "Astrobox");

///stuff for the FrameCounter function
int frames;
sf::Clock frameTimer;
int secondsPassed;


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
    SPRITE_SHEET.loadFromFile("../sprites/spritesheet.png"); ///loads the sprite sheet into SPRITE_SHEET


    ///player testEntity; //creates a test entity
    ///testEntity.setPosition(400.f,300.f);

    allEntities.push_back(std::shared_ptr<entity>(new player()));
    allEntities[0]->setPosition(510,270);
    ///adding new entities for testing purposes
    for (int i=0;i<5;i++)
    {
        allEntities.push_back(std::shared_ptr<entity>(new entity()));
        allEntities[i+1]->setPosition(300+i*50,0+i*50);
        allEntities[i+1]->setVelocity(VECTOR2(i,1));
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



		//
		///here is the actual game code:



        //yeah i haven't added much game code yet but this is where it would be



        FrameCounter(); //test frame counting stuff

        for (std::shared_ptr<entity> e : allEntities) {
            window.draw(*e);
            e->update();
        }
        window.display(); ///updates the whole window

		///this is where the main loop ends
		//
    }

    return 0;
}

