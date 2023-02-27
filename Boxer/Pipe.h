#pragma once
#include "Collision.h"
#include "Player.h"

class Pipe
{
public:
    
	Pipe(float yPosition);
	~Pipe();
	void Update(float deltaTime, bool playerIsDead);
	void Draw(sf::RenderWindow& window);
	bool collisionPlayer(Player player1);
	bool IsGone();
	bool isPassed = false;
	sf::Vector2f GetPosition() { return pipesSprite.getPosition(); }

public:
	sf::Sprite pipesSprite;
private:
	sf::Texture pipesTexture;
	sf::Vector2f velocity;
	float speed = 200.0f;
};
