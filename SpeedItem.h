#pragma once
#include <SFML/Graphics.hpp>
#include "PickableItem.h"

class SpeedItem {
private:
    sf::Texture speedTexture;
    sf::Sprite speedSprite;
    bool visible = true;

public:
    SpeedItem();
    // Setters
    void setVisible(bool v);
    // Getters
    bool getVisible();
    sf::Sprite& getSpeedSprite();
};