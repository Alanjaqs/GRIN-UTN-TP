#pragma once
#include <SFML/Graphics.hpp>

class Spike {
private:
    sf::Texture spikeFiveTexture, spikeOneTexture;
    sf::Sprite spikeFiveSprite, spikeOneSprite;
public:
    Spike();
    sf::Sprite& getSpikeSprites(int s);
};