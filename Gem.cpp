#include "Gem.h"

Gem::Gem() {
	gemTexture.loadFromFile("images\\Gem.png");
	gemSprite.setTexture(gemTexture);
}

sf::Sprite& Gem::getGemSprite() { return gemSprite; }

void Gem::setVisible(bool v) { visible = v; }
void Gem::setHasBeenPicked(bool v) { hasBeenPicked = v; }
bool Gem::getVisible() { return visible; }
bool Gem::getHasBeenPicked() { return hasBeenPicked;}