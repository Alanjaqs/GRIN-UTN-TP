#include "Map.h"

Map::Map(Player* player) {
    backTexture.loadFromFile("images\\backGame.jpg");
    backSprite.setTexture(backTexture);

    platTexture1.loadFromFile("images\\Platform1.png");
    platSprite1.setTexture(platTexture1);

    doubleJump = new DoubleJump(player);  // Iniciar DoubleJump
    doubleJump->getSprite().setPosition(600, 500);
}

Map::~Map() {
    if (doubleJump) {
        delete doubleJump;
        doubleJump = nullptr;
    }
}

// Getters
sf::Sprite& Map::getBackground() {
    return backSprite;
}
sf::Sprite& Map::getPlatform(int tipoPlataforma) {
    if (tipoPlataforma == 1) return platSprite1;
    return platSprite1;
}

sf::Sprite* Map::getDoubleJump() {
    return doubleJump ? &doubleJump->getSprite() : nullptr;  // Retorna nullptr si no existe
}


// Settea sprite en la posicion elegida en x/y
void Map::setMapPosition(sf::Sprite& sprite, float x, float y) {
    sprite.setPosition(x, y);
}

void Map::detectCollisions(Player* player) {
    if (doubleJump && doubleJump->detectCollision()) {
        // Si hay colisión, da el poder, borra el objeto y lo iguala a nullptr para que no se siga usando
        player->setHasDoubleJump(true); 
        delete doubleJump;
        doubleJump = nullptr;
    }
}