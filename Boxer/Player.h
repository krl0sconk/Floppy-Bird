#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation.h"


class Player
{
public:
	Player(sf::Texture* playerTexture);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	sf::Vector2f GetPosition() { return playerSprite.getPosition(); }

public:
	bool isDead = false;
	sf::Sprite playerSprite;

private:
	Animation animation;

	sf::Vector2f velocity;
	sf::Sound jumpsound;
	sf::SoundBuffer jumpbuffer;

	unsigned int row;
	
	bool deadBounce = false;
	bool faceRight = true;
	bool isMouseButtonPressed = false;

	float speed = 200.0f;
	float jumpHeight;
};

