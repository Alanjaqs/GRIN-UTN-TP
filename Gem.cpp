#include "Gem.h"

Gem::Gem() {
	gemTexture.loadFromFile("images\\Gem.png");
	gemSprite.setTexture(gemTexture);
}

sf::Sprite& Gem::getGemSprite() { return gemSprite; }