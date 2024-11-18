#include "DoubleJump.h"
#include <iostream>

DoubleJump::DoubleJump(){
    entityTexture.loadFromFile("images\\doubleJump.png");
    sprite.setTexture(entityTexture);
}



void DoubleJump::setVisible(bool v) { visible = v; }
void DoubleJump::setHasBeenPicked(bool v) { hasBeenPicked = v; }
bool DoubleJump::getVisible() { return visible; }
bool DoubleJump::getHasBeenPicked() { return hasBeenPicked; }
sf::Sprite& DoubleJump::getDoubleJumpSprite() { return sprite; }
