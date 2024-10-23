#pragma once
#include <SFML/Graphics.hpp>
#include "PickableItem.h"

class SpeedItem {
private:
    sf::Texture speedTexture;
    sf::Sprite speedSprite;

public:
    SpeedItem();
    // Getters
    sf::Sprite& getSpeedSprite();
};