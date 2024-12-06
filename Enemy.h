#pragma once
#include <SFML/Graphics.hpp>
class Enemy : public sf:: Drawable
{
private:
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;
	float velocityX = 2;
	float rangeR;
	float rangeL;
	bool moveRight = true;
	bool spawned = true;
	bool visible = true;
public:
	Enemy();
	void update();
	// Metodo draw
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void respawnmanual(float x, float y);
	sf::FloatRect getBounds() const;
	void setSpawned(bool v);
	bool getSpawned();
	void setVisible(bool v);
	bool getVisible();
	sf::Sprite& getEnemySprite();
};

