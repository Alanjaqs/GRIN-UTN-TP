#include <SFML/Graphics.hpp>
#include "Map.h"

// Constructor
Map::Map() {
	// Background
	Map::backTexture.loadFromFile("images\\backGame.jpg");
	Map::backSprite.setTexture(backTexture);
	// Plataformas
	Map::platTexture1.loadFromFile("images\\Platform1.png");
	Map::platSprite1.setTexture(platTexture1);
}

// Getters
sf::Sprite& Map::getBackground() {
	return backSprite;
}
sf::Sprite& Map::getPlatform(int tipoPlataforma) {
	if (tipoPlataforma == 1) return platSprite1;
}

// Settea sprite en la posicion elegida en x/y
void Map::setMapPosition(sf::Sprite &sprite, float x, float y) {
	sprite.setPosition(x, y);
}