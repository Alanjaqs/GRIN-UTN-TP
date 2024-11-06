#pragma once
#include <SFML/Graphics.hpp>

class Gem {
private:
	sf::Texture gemTexture;
	sf::Sprite  gemSprite;
	bool visible = true;
	bool hasBeenPicked = false;
public:
	Gem();

	// Setters
	void setVisible(bool v);
	void setHasBeenPicked(bool v);
	// Getters
	bool getVisible();
	bool getHasBeenPicked();
	sf::Sprite& getGemSprite();

};