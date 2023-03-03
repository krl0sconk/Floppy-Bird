#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Menu
{
	public:
		Menu(bool isPlaying);
		~Menu();

		bool Update(sf::RenderWindow& window);
		void Draw(sf::RenderWindow& window);

	public:

	private:
		sf::Sprite playSprite;
		sf::Texture playTexture;
		sf::Sprite titleSprite;
		sf::Texture titleTexture;
		sf::Vector2i mousePos;
		sf::Sound buttonsound;
		sf::SoundBuffer buttonbuffer;
	};

