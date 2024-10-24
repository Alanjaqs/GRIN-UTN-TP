#include <stdlib.h>
#include "Enemy.h"

Enemy::Enemy()
{
	texture.loadFromFile("images\\enemy.png");
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
}

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
}
sf::FloatRect Enemy::getBounds() const
{
	return sprite.getGlobalBounds();
}
void Enemy::update()
{

}