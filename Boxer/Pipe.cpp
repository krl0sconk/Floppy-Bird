#include "Pipe.h"
#include <stdlib.h>  
#include <time.h>      
#include <iostream>

Pipe::Pipe(float yPosition)
{
		pipesSprite.setPosition(400.0f, yPosition);
}

Pipe::~Pipe()
{
}

//Moves the pipe
void Pipe::Update(float deltaTime, bool playerIsDead)
{
	if (!playerIsDead)
	{
		velocity.x = -50.0f;
		pipesSprite.move(velocity * deltaTime);
	}	
}

//Draws the pipe
void Pipe::Draw(sf::RenderWindow& window)
{
	Collision::CreateTextureAndBitmask(pipesTexture, "Textures/greenPipes.png");
	pipesSprite.setTexture(pipesTexture);
	pipesSprite.setOrigin(14.0f, 485.0f);
	pipesSprite.setScale(2.0f, 2.0f);


	window.draw(pipesSprite);
}

//Checks collision with player
bool Pipe::collisionPlayer(Player player1)
{
	if (Collision::PixelPerfectTest(player1.playerSprite, pipesSprite))
	{
		return true;
	} 
	return false;
}

//Checks if the pipe is outside of the screen
bool Pipe::IsGone()
{
	if (pipesSprite.getPosition().x < -100.0f)
	{
		return true;
	}
	return false;
}
