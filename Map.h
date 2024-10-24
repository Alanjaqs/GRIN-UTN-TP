#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include "DoubleJump.h"
#include "Player.h"
#include "Platform.h"
#include "SpeedItem.h"

class Map 
{
private:
    // Background
    sf::Texture backTexture;
    sf::Sprite backSprite;

    // Chats
    sf::Texture chatTexture1;
    sf::Texture chatTexture2;
    sf::Texture chatTexture3;
    sf::Texture chatTexture4;
    sf::Texture chatTexture5;
    sf::Sprite chatSprite;

    // Ground
    sf::Texture groundTexture;
    sf::Sprite groundSprite;

    DoubleJump* doubleJump;  // Puntero que puede ser nullptr tras una colisión
public:
    Map(Player* player);
    ~Map();

    // Getters
    sf::Sprite& getBackground();
    sf::Sprite& getGround();
    sf::Sprite& getChat();
    sf::Sprite* getDoubleJump();

    // Settea sprite en la posicion elegida en x/y
    void setMapPosition(sf::Sprite& sprite, float x, float y);

    void setChatSprite(int n);
    

    // Deteccion de colisiones varias
    void detectCollisions(Player* player); // DoubleJump
    void detectSpeedCollision(Player& player, SpeedItem& speedIt);
    void collisionFloorCheck(Player& player, Platform platform); // Suelo y plataformas
};

#endif  // MAP_H
