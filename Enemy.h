#pragma once
#include <SFML/Graphics.hpp>
class Enemy : public sf:: Drawable
{
	float velocityX = 2;
	float rangeR;
	float rangeL;
	bool moveRight = true;
	bool spawned = true;
	bool visible = true;

	sf::Texture texture;
	sf::Sprite sprite;
public:
	Enemy();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	//void respawn();
	void respawnmanual(float x, float y);
	sf::FloatRect getBounds() const;
	void setSpawned(bool v);
	bool getSpawned();
	void setVisible(bool v);
	bool getVisible();
	sf::Sprite getSprite();
};

