#include <stdlib.h>
#include "Enemy.h"

Enemy::Enemy()
{
	enemyTexture.loadFromFile("images\\enemy.png");
	enemySprite.setTexture(enemyTexture);
	bossTexture.loadFromFile("images\\enemyBoss.png");
	bossSprite.setTexture(bossTexture);
	enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
	bossSprite.setOrigin(bossSprite.getGlobalBounds().width / 2, bossSprite.getGlobalBounds().height / 2);
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
void Enemy::spawnBoss(float x, float y) {
	bossSprite.setPosition(x, y);
	rangeR = x + 220;
	rangeL = x - 210;
}

sf::FloatRect Enemy::getBounds() const
{
	return enemySprite.getGlobalBounds();
}

sf::Sprite& Enemy::getEnemySprite() { return enemySprite; }
sf::Sprite& Enemy::getBossSprite() { return bossSprite; }

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

void Enemy::bossUpdate() {
	if (moveRight) {
		bossSprite.setScale(1, 1);
		bossSprite.move(velocityX + 6, 0);
		if (bossSprite.getPosition().x > rangeR) {
			moveRight = false;
		}
	}
	else {
		bossSprite.move(-velocityX - 6, 0);
		bossSprite.setScale(-1, 1);
		if (bossSprite.getPosition().x < rangeL) {
			moveRight = true;
		}
	}
}
void Enemy::setBossHitted(bool v) { bossHitted = v; }
bool Enemy::getBossHitted() { return bossHitted; }
void Enemy::restarVidaBoss(int v) { vidaBoss -= v; }
void Enemy::setVidaBoss(int v) { vidaBoss = v; }
int Enemy::getVidaBoss() { return vidaBoss; }