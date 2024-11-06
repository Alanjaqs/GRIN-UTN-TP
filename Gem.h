#pragma once
#include <SFML/Graphics.hpp>

class Gem {
private:
	sf::Texture gemTexture;
	sf::Sprite gemSprite;

public:
	Gem();
	sf::Sprite& getGemSprite();
};