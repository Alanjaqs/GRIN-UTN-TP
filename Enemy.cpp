#include <stdlib.h>
#include "Enemy.h"

Enemy::Enemy()
{
	enemyTexture.loadFromFile("images\\enemy.png");
	enemySprite.setTexture(enemyTexture);
	enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
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
	target.draw(enemySprite, states);
}
void Enemy::respawnmanual(float x, float y)
{
	enemySprite.setPosition(x, y);
	rangeR = x + 70;
	rangeL = x - 70;
}
sf::FloatRect Enemy::getBounds() const
{
	return enemySprite.getGlobalBounds();
}

sf::Sprite& Enemy::getEnemySprite() { return enemySprite; }

void Enemy::update()
{
	if (moveRight) {
		enemySprite.setScale(1, 1);
		enemySprite.move(velocityX, 0);
		if (enemySprite.getPosition().x > rangeR) {
			moveRight = false;
		}
	}
	else {
		enemySprite.move(-velocityX, 0);
		enemySprite.setScale(-1, 1);
		if (enemySprite.getPosition().x < rangeL) {
			moveRight = true;
		}
	}
}