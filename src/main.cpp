#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>


int main()
{
	//this is the creation of our game window.
    sf::RenderWindow window(sf::VideoMode(800, 600), "Astrobox");
	window.setFramerateLimit(60);



	////here is where we declare important variables for use in the main loop


	//test shape creation
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    //stuff for the frame counting thing
    int frames;
    sf::Clock frameTimer;
    int secondsPassed;


    // this is our main loop that runs the entire time our game is running
    while (window.isOpen())
    {
        // the event loop is what manages all the user interaction with the window
		//it is safe to ignore this loop.
        sf::Event event;
        while (window.pollEvent(event))
        {
            //closes the window when the close button is hit
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(); //resets the window so it can be drawn again
		//
		////here is the actual game code:


		//test stuff


//booger ooger

        //spams the framerate in the console every second
		frames++; //adds a frame to the count
        if(frameTimer.getElapsedTime().asMilliseconds() > 1000) //runs when a second has passed
            {
             frameTimer.restart(); printf("%i\n",frames); frames = 0; //resets the frames back to 0 for the next count
             secondsPassed++; printf("Your mom!! This program has been running for %i seconds\n",secondsPassed); //displays the number of seconds that have passed in total
             //this is mostly for testing, hence the Your Mom!!
            }

        //atm the framerate keeps displaying as 62 idk why but its not a big deal we can work with 2 extra frames lol


		//this is where all the graphical rendering stuff happens

        window.draw(shape); //draws our test shape
        window.display(); //updates the whole window

		////this is where the main loop ends
		//
    }

    return 0;
}
