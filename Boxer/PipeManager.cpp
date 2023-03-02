#include "PipeManager.h"
#include <iostream>
#include "Player.h"

//Starts the clock
PipesManager::PipesManager()
{
	clock.restart();
}

//Draws the pipe
void PipesManager::draw(sf::RenderWindow& window)
{
	for (Pipe& a : pipes)
	{
		a.Draw(window);
	}
}
//Checks collision with player
bool PipesManager::collisionPlayer(Player player1)
{
	for (Pipe& a : pipes)
	{
		if (a.collisionPlayer(player1))
		{
			return true;
		}
	}
	return false;
}
//Checks collision with player
bool PipesManager::PlayerPassed(Player player1)
{
	for (Pipe& a : pipes)
	{
		if (!a.isPassed)
		{
			if (a.GetPosition().x < (player1.GetPosition().x))
			{
				a.isPassed = true;
				return true;
			}
		}
		
	}
	return false;
}

//Resets pipes
void PipesManager::reset()
{
	clock.restart();
	pipes.clear();
}

//Spawn pipes each 4 seconds and erases them when outside of the screen
void PipesManager::update(float randomYPosition, float deltaTime, bool playerIsDead, Player player1, int points)
{

	if (clock.getElapsedTime().asSeconds() >= 4)
	{
		std::cout << "Pipe Generated \n";
		pipes.push_back(Pipe(randomYPosition));
		clock.restart();
	}

	for (Pipe& a : pipes)
	{
		a.Update(deltaTime, playerIsDead);

	}

	for (std::vector<Pipe>::iterator a = pipes.begin(); a != pipes.end(); a++)
	{
		//When the pipes go beyond the screen.
		if (a->IsGone())
		{
			//We delete them.
			pipes.erase(a);
			std::cout << "Erased a pipe \n";
			break;
		}
	}
}

int PipesManager::size()
{
	return pipes.size();
}
