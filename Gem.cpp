#include "Gem.h"

Gem::Gem() {
	gemTexture.loadFromFile("images\\gemFrame1.png");
	gemSprite.setTexture(gemTexture);
	gemTexture2.loadFromFile("images\\gemFrame2.png");
	gemSprite2.setTexture(gemTexture2);
}

sf::Sprite& Gem::getGemSprite(int g) {
	if (g == 1) return gemSprite;
	if (g == 2) return gemSprite2;
}

void Gem::setVisible(bool v) { visible = v; }
void Gem::setHasBeenPicked(bool v) { hasBeenPicked = v; }
bool Gem::getVisible() { return visible; }
bool Gem::getHasBeenPicked() { return hasBeenPicked;}
bool Gem::getFirstSprite() {
	if (clock.getElapsedTime().asSeconds() >= animationTime) {
		firstSprite = !firstSprite;
		clock.restart();
	}
	return firstSprite;
}