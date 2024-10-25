#include "Map.h"

Map::Map(Player* player) {
    backTexture.loadFromFile("images\\backGame.jpg");
    backSprite.setTexture(backTexture);
    groundTexture.loadFromFile("images\\ground.png");
    groundSprite.setTexture(groundTexture);
    //Chats
    chatTexture1.loadFromFile("images\\chatTexto1.png");
    chatTexture2.loadFromFile("images\\chatTexto2.png");
    chatTexture3.loadFromFile("images\\chatTexto3.png");
    chatTexture4.loadFromFile("images\\chatTexto4.png");
    chatTexture5.loadFromFile("images\\chatTexto5.png");
    chatTexture6.loadFromFile("images\\chatTexto6.png");
    chatTexture7.loadFromFile("images\\chatTexto7.png");

    doubleJump = new DoubleJump(player);  // Iniciar DoubleJump
    doubleJump->getSprite().setPosition(2150, 500);

    smashSound.openFromFile("audio\\smash.mp3");
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

sf::Sprite& Map::getGround() {
    return groundSprite;
}

sf::Sprite& Map::getChat() {
    return chatSprite;
}

sf::Sprite* Map::getDoubleJump() {
    return doubleJump ? &doubleJump->getSprite() : nullptr;  // Retorna nullptr si no existe
}


// Set chat
void Map::setChatSprite(int n) {
    if (n == 1) { chatSprite.setTexture(chatTexture1); }
    if (n == 2) { chatSprite.setTexture(chatTexture2); }
    if (n == 3) { chatSprite.setTexture(chatTexture3); }
    if (n == 4) { chatSprite.setTexture(chatTexture4); }
    if (n == 5) { chatSprite.setTexture(chatTexture5); }
    if (n == 6) { chatSprite.setTexture(chatTexture6); }
    if (n == 7) { chatSprite.setTexture(chatTexture7); }
}

// Settea sprite en la posicion elegida en x/y
void Map::setMapPosition(sf::Sprite& sprite, float x, float y) {
    sprite.setPosition(x, y);
}

// Detect collision double jump
void Map::detectCollisions(Player* player) {
    if (doubleJump && doubleJump->detectCollision()) {
        // Si hay colisión, da el poder, borra el objeto y lo iguala a nullptr para que no se siga usando
        player->setHasDoubleJump(true); 
        delete doubleJump;
        doubleJump = nullptr;
    }
}

// Detect collision speed item
void Map::detectSpeedCollision(Player& player, SpeedItem& speedIt) {
    if(player.getHitbox().intersects(speedIt.getSpeedSprite().getGlobalBounds())) {
        speedIt.setVisible(false);
        player.setHasSpeed(true);
    }
}

void Map::collisionFloorCheck(Player& player, Platform platform) {
    // Suelo predeterminado
    if (player.getPlayerPosition().y >= 600) {
        player.getPlayerSprite().setPosition(player.getPlayerPosition().x, 600);
        player.onFloor();
    }
    // Plataformas
    if (player.getHitbox().intersects(platform.getPlatform(1).getGlobalBounds()) && player.getVelocityY() > 0) {
        player.setVelocityY(0);
        player.getPlayerSprite().setPosition(player.getPlayerPosition().x, platform.getPlatform(1).getGlobalBounds().top - player.getHitbox().height);
        player.onFloor();

    }
       
}

void Map::collisionEnemyCheck(Player& player, Enemy& enemy) {
    if (enemy.getVisible()) {
        if (player.getHitbox().intersects(enemy.getSprite().getGlobalBounds()) && player.getVelocityY() > 0) {
            enemy.setVisible(false);
            smashSound.play();
        }
    }
    
}