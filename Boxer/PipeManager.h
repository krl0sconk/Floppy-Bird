#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include "Pipe.h"

class PipesManager
{
	std::vector<Pipe> pipes;
public:
	PipesManager();

	void draw(sf::RenderWindow& i_window);
	bool collisionPlayer(Player player1);
	void reset();
	void update(float randomYPosition, float deltaTime, bool playerIsDead, Player player1, int points);
	int size();
	sf::Clock clock;
};

