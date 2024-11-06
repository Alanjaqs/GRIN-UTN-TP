#include "Spike.h"

Spike::Spike(){
	spikeFiveTexture.loadFromFile("images\\spikeFive.png");
	spikeFiveSprite.setTexture(spikeFiveTexture);
}

sf::Sprite& Spike::getSpikeFive() { return spikeFiveSprite; }