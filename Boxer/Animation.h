#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
public:

	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();

	void setSwitchTime(float switchTime);

	void setImageCount(sf::Vector2u imageCount);

	void setTexture(sf::Texture* texture);

	void Update(int row, float deltatime, bool faceRight);


public:
	sf::IntRect uvRect;
	sf::Vector2u currentImage; 

private:
	sf::Texture texture;
	//Total amount of sprites
	sf::Vector2u imageCount; 

	float totalTime; 
	//Switch time between animation sprites
	float switchTime; 
};

