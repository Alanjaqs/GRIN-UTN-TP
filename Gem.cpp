#include "Gem.h"

Gem::Gem() {
	gemTexture.loadFromFile("images\\gemFrame1.png");
	gemSprite.setTexture(gemTexture);
	gemTexture2.loadFromFile("images\\gemFrame2.png");
	gemSprite2.setTexture(gemTexture2);
}
// Setters
void Gem::setVisible(bool v) { visible = v; }
void Gem::setHasBeenPicked(bool v) { hasBeenPicked = v; }
// Getters
bool Gem::getVisible() { return visible; }
bool Gem::getHasBeenPicked() { return hasBeenPicked;}

bool Gem::getAnimationFrame() {
	if (clock.getElapsedTime().asSeconds() >= animationTime) {
		animationFrame = !animationFrame;
		clock.restart();
	}
	return animationFrame;
}

sf::Sprite& Gem::getGemSprite(int g) {
	if (g == 1) return gemSprite;
	if (g == 2) return gemSprite2;
}