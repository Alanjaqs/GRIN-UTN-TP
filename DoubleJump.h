#ifndef DOUBLEJUMP_H
#define DOUBLEJUMP_H

#include <SFML/Graphics.hpp>
#include "PickableItem.h"
#include "Player.h"
#include <cmath>

class DoubleJump {
private:
    sf::Texture entityTexture;
    sf::Sprite sprite;
    bool visible = true;
    bool hasBeenPicked = false;

public:
    DoubleJump();

    //setters
    void setVisible(bool v);
    void setHasBeenPicked(bool v);
    // Getters
    bool getVisible();
    bool getHasBeenPicked();

    sf::Sprite& getDoubleJumpSprite();

};


#endif  // DOUBLEJUMP_H
