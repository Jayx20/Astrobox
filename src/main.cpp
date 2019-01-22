#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>

#include "player.h"



//this is the creation of our game window.
sf::RenderWindow window(sf::VideoMode(800, 600), "Astrobox");

//stuff for the frame counting thing
int frames;
sf::Clock frameTimer;
int secondsPassed;


    //functions to be used in the main game loop

void FrameCounter() {
        //spams the framerate in the console every second
		frames++; //adds a frame to the count
        if(frameTimer.getElapsedTime().asMilliseconds() > 1000) //runs when a second has passed
            {
             frameTimer.restart(); //resets the clock the keeps track of millseconds passed
             printf("%i\n",frames); //prints the framerate
             frames = 0; //resets the frames back to 0 for the next count

             secondsPassed++;
             printf("Your mom!! This program has been running for %i seconds\n",secondsPassed);
             //displays the number of seconds that have passed in total
             //this is mostly for testing, hence the Your Mom!!
            }

        //atm the framerate keeps displaying as 62 idk why but its not a big deal we can work with 2 extra frames lol
}

void MainRender() {
        //window.draw(shape); //draws our test shape
        window.display(); //updates the whole window
}


int main()
{
    window.setFramerateLimit(60);

    // this is our main loop that runs the entire time our game is running
    while (window.isOpen())
    {
        window.clear(); //resets the window so it can be drawn again
        // the event loop is what manages all the user interaction with the window
		// just dont fiddle with this
        sf::Event event;
        while (window.pollEvent(event))
        {
            //closes the window when the close button is hit
            if (event.type == sf::Event::Closed)
                window.close();
        }



		//
		////here is the actual game code:


        //yeah i haven't added much game code yet but this is where it would be



        FrameCounter(); //test frame counting stuff

        MainRender(); //my main rendering function, everything graphical happens in here

		////this is where the main loop ends
		//
    }

    return 0;
}

