#pragma once
#include <SFML/Graphics.hpp>

class Gem {
private:
	sf::Texture gemTexture, gemTexture2;
	sf::Sprite  gemSprite, gemSprite2;
	bool visible = true;
	bool hasBeenPicked = false;
	// Animation
	sf::Clock clock;
	float animationTime = 0.2f;
	bool firstSprite = true;
public:
	Gem();
	// Setters
	void setVisible(bool v);
	void setHasBeenPicked(bool v);
	// Getters
	bool getVisible();
	bool getHasBeenPicked();
	sf::Sprite& getGemSprite(int g);
	bool getFirstSprite();

};