#include <stdlib.h>
#include "Enemy.h"

Enemy::Enemy()
{
	texture.loadFromFile("images\\enemy.png");
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
}

void Enemy::setSpawned(bool v) {
	spawned = v;
}
bool Enemy::getSpawned() { return spawned; }
void Enemy::setVisible(bool v) {
	visible = v;
}
bool Enemy::getVisible() { return visible; }

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}
/*void Enemy::respawn()
{
	sprite.setPosition(std::rand() % 1180 + sprite.getGlobalBounds().width, std::rand() % 620 + sprite.getGlobalBounds().height);
}*/
void Enemy::respawnmanual(float x, float y)
{
	sprite.setPosition(x, y);
	rangeR = x + 70;
	rangeL = x - 70;
}
sf::FloatRect Enemy::getBounds() const
{
	return sprite.getGlobalBounds();
}

sf::Sprite Enemy::getSprite() { return sprite; }

void Enemy::update()
{
	if (moveRight) {
		sprite.setScale(1, 1);
		sprite.move(velocityX, 0);
		if (sprite.getPosition().x > rangeR) {
			moveRight = false;
		}
	}
	else {
		sprite.move(-velocityX, 0);
		sprite.setScale(-1, 1);
		if (sprite.getPosition().x < rangeL) {
			moveRight = true;
		}
	}
}