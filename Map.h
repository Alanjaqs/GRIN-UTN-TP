#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include "DoubleJump.h"
#include "Player.h"

class Map 
{
private:
    sf::Texture backTexture;
    sf::Sprite backSprite;
    sf::Texture platTexture1;
    sf::Sprite platSprite1;

    DoubleJump* doubleJump;  // Puntero que puede ser nullptr tras una colisión
public:
    Map(Player* player);
    ~Map();

    sf::Sprite& getBackground();
    sf::Sprite& getPlatform(int tipoPlataforma);
    sf::Sprite* getDoubleJump();

    void setMapPosition(sf::Sprite& sprite, float x, float y);

    void detectCollisions(Player* player);
};

#endif  // MAP_H
