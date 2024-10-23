#pragma once
#include <SFML/Graphics.hpp>

class Platform{
private:
    sf::Texture platTexture1;
    sf::Sprite platSprite1;

public:
    Platform();
    sf::Sprite& getPlatform(int tipoPlataforma);

};