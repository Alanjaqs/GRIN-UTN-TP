#include "DoubleJump.h"
#include <iostream>

DoubleJump::DoubleJump(Player* player) : player(player) {
    entityTexture.loadFromFile("images\\DoubleJump.png");
    sprite.setTexture(entityTexture);
}

DoubleJump::~DoubleJump() {
    if (player != nullptr) {
        player->setHasDoubleJump(true);  // Activar el doble salto
        std::cout << "Doble salto activado" << std::endl;
    }
}

void DoubleJump::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

sf::Sprite& DoubleJump::getSprite() {
    return sprite;
}

bool DoubleJump::detectCollision() {
    if (player == nullptr) return false;

    float dx = sprite.getPosition().x - player->getPlayerPosition().x;
    float dy = sprite.getPosition().y - player->getPlayerPosition().y;
    float distance = std::sqrt(dx * dx + dy * dy);

    if (distance < 50.0f) {
        std::cout << "COLISIONNNNN" << "\n";
        collided = true; 
        return true;
    }
    return false;
}
