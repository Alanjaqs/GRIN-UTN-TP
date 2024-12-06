#include "DoubleJump.h"
#include <iostream>
// Constructor
DoubleJump::DoubleJump(){
    dJumpTexture.loadFromFile("images\\doubleJump.png");
    dJumpSprite.setTexture(dJumpTexture);
}
// Setters
void DoubleJump::setVisible(bool v) { visible = v; }
void DoubleJump::setHasBeenPicked(bool v) { hasBeenPicked = v; }
// Getters
bool DoubleJump::getVisible() { return visible; }
bool DoubleJump::getHasBeenPicked() { return hasBeenPicked; }
sf::Sprite& DoubleJump::getDoubleJumpSprite() { return dJumpSprite; }
