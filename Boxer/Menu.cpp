#include "Menu.h"
#include <iostream>

Menu::Menu(bool isPlaying)
{
    if (!playTexture.loadFromFile("Textures/play.png"))
    {
        std::cout << "Error with button file!";
    }
    playSprite.setTexture(playTexture);
    playSprite.setScale(sf::Vector2f(2.5f, 2.5f));
    playSprite.setPosition(sf::Vector2f(105.0f, 250.0f));

    if (!titleTexture.loadFromFile("Textures/title.png"))
    {
        std::cout << "Error with title file!";
    }
    titleSprite.setTexture(titleTexture);
    titleSprite.setScale(sf::Vector2f(2.5f, 2.5f));
    titleSprite.setPosition(sf::Vector2f(60.0f, 40.0f));
}

Menu::~Menu()
{
}

bool Menu::Update(sf::RenderWindow& window)
{
    std::cout << "X: " << (float)sf::Mouse::getPosition(window).x << "Y: " << (float)sf::Mouse::getPosition(window).y << "\n";
    mousePos = sf::Mouse::getPosition(window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if ((mousePos.x > 110 && mousePos.x < 240 && mousePos.y > 255 && mousePos.y < 320))
        {
            return true;
        }
    }
    return false;
}

void Menu::Draw(sf::RenderWindow& window)
{
    window.draw(playSprite);
    window.draw(titleSprite);
}
