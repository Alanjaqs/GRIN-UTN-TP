#pragma once
#include <SFML/Graphics.hpp>
class Enemy : public sf:: Drawable
{
private:
	sf::Texture enemyTexture, bossTexture;
	sf::Sprite enemySprite, bossSprite;
	float velocityX = 2;
	float rangeR;
	float rangeL;
	int vidaBoss = 3;
	bool moveRight = true;
	bool spawned = true;
	bool visible = true;
	bool bossHitted = false;
public:
	Enemy();
	void update();
	void bossUpdate();
	// Metodo draw
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void respawnmanual(float x, float y);
	void spawnBoss(float x, float y);
	sf::FloatRect getBounds() const;
	void setSpawned(bool v);
	bool getSpawned();
	void setVisible(bool v);
	bool getVisible();
	void setVidaBoss(int v);
	void restarVidaBoss(int v);
	int getVidaBoss();
	void setBossHitted(bool v);
	bool getBossHitted();
	sf::Sprite& getEnemySprite();
	sf::Sprite& getBossSprite();
};

