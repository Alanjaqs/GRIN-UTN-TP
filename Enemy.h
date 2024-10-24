#pragma once
#include <SFML/Graphics.hpp>
class Enemy : public sf:: Drawable
{

	sf::Sprite sprite;
	sf::Texture texture;
public:
	Enemy();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	//void respawn();
	void respawnmanual(float x, float y);
	sf::FloatRect getBounds() const;
};

