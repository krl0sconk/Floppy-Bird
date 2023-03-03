
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>
#include "Collision.h"
#include "Pipe.h"
#include "PipeManager.h"
#include "Menu.h"

int main()
{
    //Pipes
    srand(time(NULL));
    PipesManager pipeManager;
    float RandomY;
    //Texture declaration
    sf::Texture playerTexture;
    Collision::CreateTextureAndBitmask(playerTexture, "Textures/yellowBird.png");
    //Points text
    sf::Text pointsText;
    sf::Font pointsFont;
    if (!pointsFont.loadFromFile("Fonts/Points.ttf/"))
    {
        std::cout << "Error loading font!";
    }
    pointsText.setFont(pointsFont);
    pointsText.setCharacterSize(80);
    pointsText.setPosition(sf::Vector2f(165.0f, 0.0f));
    //Sounds
    sf::SoundBuffer deathbuffer;
    if (!deathbuffer.loadFromFile("Sounds/Death.ogg"))
    {
        std::cout << "Error with sound file!";
    }
    sf::Sound deathsound;
    deathsound.setBuffer(deathbuffer);
    sf::SoundBuffer pointbuffer;
    if (!pointbuffer.loadFromFile("Sounds/Point.ogg"))
    {
        std::cout << "Error with sound file!";
    }
    bool deathPlayed = false;
    sf::Sound pointsound;
    pointsound.setBuffer(pointbuffer);
    //Background
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Textures/dayBackground.png"))
    {
        std::cout << "Error loading background image!";
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    //Player Object
    Player player1(&playerTexture);
    //Menu
    bool isPlaying = false;
    Menu mainMenu(isPlaying);
    //Deltatime variables
    float deltaTime = 0.0f;
    sf::Clock clock;
    //Points variables
    int points = 0;
    //Create view
    sf::View camera(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(360.0f, 640.0f));
    //Create the window
    sf::RenderWindow window(sf::VideoMode(360, 640), "Floppy Bird", sf::Style::Close);

    while (window.isOpen())
    {
        if (mainMenu.Update(window))
        {
            isPlaying = true;
        }
        if (isPlaying)
        {
            pointsText.setString(std::to_string(points));
            RandomY = (rand() % 380) + 200;
            deltaTime = clock.restart().asSeconds();
            if (deltaTime > 1.0f / 20.0f)
            {
                deltaTime = 1.0f / 20.0f;
            }

            //Handle collisions with obstacles
            if (pipeManager.collisionPlayer(player1))
            {
                player1.isDead = true;
                if (player1.isDead)
                {     
                    if (!deathPlayed)
                    {
                        deathsound.play();
                        deathPlayed = true;
                    }
                }
            }
            //Handle Points
            if (pipeManager.PlayerPassed(player1))
            {
                points++;
                pointsound.play();
            }
            //Update here
            player1.Update(deltaTime);
            pipeManager.update(RandomY, deltaTime, player1.isDead, player1, points);
            camera.setCenter(player1.GetPosition().x, 320.0f);
            // Clear the window
            window.clear(sf::Color::Cyan);
            window.setView(camera);
            // Draw here
            window.draw(backgroundSprite);
            pipeManager.draw(window);
            window.draw(pointsText);
            player1.Draw(window);
            // Display the window
            window.display();
        }
        else
        {
            mainMenu.Update(window);
            window.draw(backgroundSprite);
            mainMenu.Draw(window);
            // Display the window
            window.display();
        }
        // Handle events
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }

    return 0;
}
/*


                ________o8A888888o_
            _o888888888888K_]888888o
                      ~~~+8888888888o
                          ~8888888888
                          o88888888888
                         o8888888888888
                       _8888888888888888
                      o888888888888888888_
                     o88888888888888888888_
                    _8888888888888888888888_
                    888888888888888888888888_
                    8888888888888888888888888
                    88888888888888888888888888
                    88888888888888888888888888
                    888888888888888888888888888
                    ~88888888888888888888888888_
                     (88888888888888888888888888
                      888888888888888888888888888
                       888888888888888888888888888_
                       ~8888888888888888888888888888
                         +88888888888888888888~~~~~
                          ~=888888888888888888o
                   _=oooooooo888888888888888888
                    _o88=8888==~88888888===8888_  
                    ~   =~~ _o88888888=      ~~~
                            ~ o8=~88=~

*/