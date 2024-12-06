#pragma once
#include <SFML/Graphics.hpp>

class Platform
{
private:
    sf::Texture platTexture1, platTexture2;
    sf::Sprite platSprite1, platSprite2;
public:
    Platform();
    sf::Sprite& getPlatform(int tipoPlataforma);
};