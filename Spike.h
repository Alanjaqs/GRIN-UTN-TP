#pragma once
#include <SFML/Graphics.hpp>

class Spike {
private:
    sf::Texture spikeFiveTexture;
    sf::Sprite spikeFiveSprite;
public:
    Spike();
    sf::Sprite& getSpikeFive();

};