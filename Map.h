#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "DoubleJump.h"
#include "Player.h"
#include "Platform.h"
#include "SpeedItem.h"
#include "Gem.h"
#include "Enemy.h"
#include "Spike.h"
#include <iostream>

class Map 
{
private:
    // Background
    sf::Texture backTexture, backTexture2, backTexture3;
    sf::Sprite backSprite, backSprite2, backSprite3;

    // Chats
    sf::Texture chatTexture1;
    sf::Texture chatTexture2;
    sf::Texture chatTexture3;
    sf::Texture chatTexture4;
    sf::Texture chatTexture5;
    sf::Texture chatTexture6;
    sf::Texture chatTexture7;
    sf::Texture chatTexture8;
    sf::Sprite chatSprite;

    // Portal
    sf::Texture portalTexture;
    sf::Sprite portalSprite;

    // Ground
    sf::Texture groundTexture;
    sf::Sprite groundSprite;

    // Audio
    sf::Music menuMusic, level1Music, level2Music, gameOverMusic, smashSound, hitSound, gemSound
        , powerUpSound, victorySound;

public:
    Map();
    ~Map();

    // Getters
    sf::Sprite& getBackground(int b);
    sf::Sprite& getGround();
    sf::Sprite& getChat();
    sf::Sprite& getPortal();
    // Settea sprite en la posicion elegida en x/y
    void setMapPosition(sf::Sprite& sprite, float x, float y);
    void setChatSprite(int n);

    // Deteccion de colisiones varias
    void colissionDoubleJumpCheck(Player& player, DoubleJump& dj); // DoubleJump
    void detectSpeedCollision(Player& player, SpeedItem& speedIt);
    void detectGemColission(Player& player, Gem& gem);
    void collisionFloorCheck(Player& player); // Suelo
    void collisionPlatCheck(Player& player, Platform& platform); // Plataformas
    void collisionEnemyCheck(Player& player, Enemy& enemy);
    void collisionSpikeCheck(Player& player, Spike& spike);

    // Music
    sf::Music& getMusic(int v);

    // Renderizar corazones
    void renderHearts(sf::RenderWindow& window, int currentLife, int totalLife, sf::Texture& emptyHeartTex, sf::Texture& fullHeartTex);
};

#endif  // MAP_H
