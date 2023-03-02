#include "Player.h"
#include <SFML/Window/Joystick.hpp>
#include "PipeManager.h"
#include "Pipe.h"
#include <iostream>

Player::Player(sf::Texture* playerTexture) :
	animation(playerTexture, sf::Vector2u(3, 3), 0.1f)
{
	playerSprite.setTexture(*playerTexture);
	playerSprite.setScale(2.0f,2.0f);
	playerSprite.setPosition(sf::Vector2f(180.0f, 320.0f));
	if (!jumpbuffer.loadFromFile("Sounds/Jump.ogg"))
	{
		std::cout << "Error with sound file!";
	}
	jumpsound.setBuffer(jumpbuffer);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	//stops the player
	velocity.x *= 0.2f;
	if (!isDead)
	{
		//Jumps
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isMouseButtonPressed)
		{
			// Set the flag to true to prevent repeated action on subsequent frames
			row = 1;
			velocity.y = -sqrtf(2.0f * 981.0f * 50);
			isMouseButtonPressed = true;
			jumpsound.play();
		}
		else
		{
			if (velocity.y > 0)
			{
				row = 0;
			}
		}
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			// Mouse button released, reset the flag to detect the next press
			isMouseButtonPressed = false;
		}
	}
	else
	{
		if (!deadBounce)
		{
			row = 2;
			velocity.y = -sqrtf(2.0f * 981.0f * 30);
			deadBounce = true;
		}
	}
	if (playerSprite.getPosition().y > 620)
	{
		velocity.y = 0.0f;
		isDead = true;
	}
	//Gravity
	velocity.y += 981.0f * deltaTime;
	//moves the player and updates animation
	playerSprite.setTextureRect(animation.uvRect);
	playerSprite.move(velocity * deltaTime);
	animation.Update(row, deltaTime, faceRight);
}

void Player::Draw(sf::RenderWindow& window)
{
	//draw the player
	window.draw(playerSprite);
}


