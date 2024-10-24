#include "SpeedItem.h"

SpeedItem::SpeedItem() {
	speedTexture.loadFromFile("images\\speedItem.png");
	speedSprite.setTexture(speedTexture);
}

void SpeedItem::setVisible(bool v) {
	visible = v;
}

bool SpeedItem::getVisible() { return visible; }

sf::Sprite& SpeedItem::getSpeedSprite() { return speedSprite; }