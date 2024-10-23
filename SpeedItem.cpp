#include "SpeedItem.h"

SpeedItem::SpeedItem() {
	speedTexture.loadFromFile("images\\speedItem.png");
	speedSprite.setTexture(speedTexture);

}

sf::Sprite& SpeedItem::getSpeedSprite() { return speedSprite; }