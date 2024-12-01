#include "Spike.h"

Spike::Spike(){
	spikeFiveTexture.loadFromFile("images\\spikeFive.png");
	spikeFiveSprite.setTexture(spikeFiveTexture);
	spikeOneTexture.loadFromFile("images\\spikeOne.png");
	spikeOneSprite.setTexture(spikeOneTexture);
}

sf::Sprite& Spike::getSpikeSprites(int s) { 
	if (s == 1) return spikeOneSprite;
	if (s == 2) return spikeFiveSprite;
}