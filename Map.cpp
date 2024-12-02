#include "Map.h"

Map::Map() {
    backTexture.loadFromFile("images\\backGame.jpg");
    backSprite.setTexture(backTexture);
    backTexture2.loadFromFile("images\\backGame2.jpg");
    backSprite2.setTexture(backTexture2);
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
    chatTexture8.loadFromFile("images\\chatTexto8.png");
    // Portal
    portalTexture.loadFromFile("images\\portal.png");
    portalSprite.setTexture(portalTexture);

    // Music and sounds
    menuMusic.openFromFile("audio\\menuMusic.mp3");
    level1Music.openFromFile("audio\\level1Music.wav");
    level2Music.openFromFile("audio\\level2Music.mp3");
    gameOverMusic.openFromFile("audio\\gameOverMusic.mp3");
    smashSound.openFromFile("audio\\smash.mp3");
    hitSound.openFromFile("audio\\golpeado.mp3");
    gemSound.openFromFile("audio\\gemPick.mp3");
    powerUpSound.openFromFile("audio\\powerUpPick.mp3");
    victorySound.openFromFile("audio\\victory.mp3");
}

Map::~Map() {

}

// Getters
sf::Sprite& Map::getBackground(int b) {
    if(b==1) return backSprite;
    if (b == 2) return backSprite2;
}
sf::Sprite& Map::getGround() {
    return groundSprite;
}
sf::Sprite& Map::getChat() {
    return chatSprite;
}
sf::Sprite& Map::getPortal() {
    return portalSprite;
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
    if (n == 8) { chatSprite.setTexture(chatTexture8); }
}

// Settea sprite en la posicion elegida en x/y
void Map::setMapPosition(sf::Sprite& sprite, float x, float y) {
    sprite.setPosition(x, y);
}

// Detect collision double jump
void Map::colissionDoubleJumpCheck(Player& player, DoubleJump& dj) {
    if (player.getHitbox().intersects(dj.getDoubleJumpSprite().getGlobalBounds())) {
        // Si hay colisión, da el poder, borra el objeto y lo iguala a nullptr para que no se siga usando
        player.setHasDoubleJump(true);
        dj.setVisible(false);
        powerUpSound.play();
    }
}

// Detect collision speed item
void Map::detectSpeedCollision(Player& player, SpeedItem& speedIt) {
    if(player.getHitbox().intersects(speedIt.getSpeedSprite().getGlobalBounds())) {
        speedIt.setVisible(false);
        player.setHasSpeed(true);
        powerUpSound.play();
    }
}

// Detect collision floor
void Map::collisionFloorCheck(Player& player) {
    if (player.getPlayerPosition().y >= 616) {
        player.getPlayerSprite().setPosition(player.getPlayerPosition().x, 616);
        player.onFloor();
    }
}

// Detect spike 
void Map::collisionSpikeCheck(Player& player, Spike& spike) {
    float TIME_BEFORE_DAMAGE = 1.0f;
    if (player.getHitbox().intersects(spike.getSpikeSprites(2).getGlobalBounds())) {
        player.setIsDead(true);
    }
    if (player.getHitbox().intersects(spike.getSpikeSprites(1).getGlobalBounds())) {

         if (player.getCurrentLife() < 1 && player.getDamageClock().getElapsedTime().asSeconds() > TIME_BEFORE_DAMAGE) {
              player.setIsDead(1);
         }
         else if (player.getDamageClock().getElapsedTime().asSeconds() > TIME_BEFORE_DAMAGE) {
              hitSound.play();
              player.doDamage(1);
              player.getDamageClock().restart();
         }
    }

    
}

// Detect collision platforms
void Map::collisionPlatCheck(Player & player, Platform & platform) {
        if (player.getHitbox().intersects(platform.getPlatform(1).getGlobalBounds())) {
            // Top 
            if (player.getPlayerBottom() > platform.getPlatform(1).getGlobalBounds().top && player.getPlayerTop() <= platform.getPlatform(1).getGlobalBounds().top) {
                if (player.getVelocityY() > 0) {
                    player.onFloor();
                    player.getPlayerSprite().setPosition(player.getPlayerPosition().x, platform.getPlatform(1).getGlobalBounds().top - player.getHitbox().height);
                }
            }
            // Bottom 
            
            else if (player.getPlayerTop() < platform.getPlatform(1).getGlobalBounds().top + platform.getPlatform(1).getGlobalBounds().height && player.getPlayerBottom() > platform.getPlatform(1).getGlobalBounds().top + platform.getPlatform(1).getGlobalBounds().height && player.getPlayerBottom()) {    
                if (player.getVelocityY() < 0) {
                    player.setVelocityY(0);
                    player.getPlayerSprite().setPosition(player.getPlayerPosition().x, platform.getPlatform(1).getGlobalBounds().top + platform.getPlatform(1).getGlobalBounds().height);
                }       
            }
            
            // Left (no funciona bien, ver solucion)
            /*
            if (player.getPlayerRight() > platform.getPlatform(1).getGlobalBounds().left && player.getPlayerLeft() < platform.getPlatform(1).getGlobalBounds().left) {
                if (player.getVelocityX() > 0) {
                    player.setVelocityX(0);
                    player.getPlayerSprite().setPosition((platform.getPlatform(1).getGlobalBounds().left - player.getHitbox().width - 2), player.getPlayerPosition().y);

                }
            }
            */
        }
}
       
// Detect collision enemy
void Map::collisionEnemyCheck(Player& player, Enemy& enemy) {
    float TIME_BEFORE_DAMAGE = 1.0f;
    if (enemy.getVisible()) {
        if (player.getHitbox().intersects(enemy.getSprite().getGlobalBounds()) && player.getVelocityY() > 0) {
            player.addPuntaje(150);
            smashSound.play();
            enemy.setVisible(false);
            
        }
        if (player.getHitbox().intersects(enemy.getSprite().getGlobalBounds()) && player.getVelocityY() == 0) {
            
            if (player.getCurrentLife() < 1 && player.getDamageClock().getElapsedTime().asSeconds() > TIME_BEFORE_DAMAGE) {
                player.setIsDead(1);
            }
            else if (player.getDamageClock().getElapsedTime().asSeconds() > TIME_BEFORE_DAMAGE) {
                hitSound.play();
                player.doDamage(1);
                player.getDamageClock().restart();
            }
        }

    }
    
}

// Music
sf::Music& Map::getMusic(int v) {
     if (v == 1) return menuMusic;
     if (v == 2) return level1Music;
     if (v == 3) return level2Music;
     if (v == 4) return gameOverMusic;
     if (v == 5) return victorySound;
}

void Map::renderHearts(sf::RenderWindow& window, int currentLife, int totalLife, sf::Texture& emptyHeartTex, sf::Texture& fullHeartTex) {
    float heartSize = 40.0f;  // Tamaño de cada corazón
    float xOffset = window.getSize().x - heartSize - 10.0f; // Inicial desde la esquina derecha
    float yOffset = 10.0f; // Posición vertical en la parte superior

    for (int i = 0; i < totalLife; i++) {
        sf::Sprite heartSprite;
        if (i < currentLife) {
            heartSprite.setTexture(fullHeartTex);
        }
        else {
            heartSprite.setTexture(emptyHeartTex);
        }

        heartSprite.setPosition(xOffset - i * (heartSize + 5), yOffset); // Espaciado entre corazones
        heartSprite.setScale(heartSize / heartSprite.getTexture()->getSize().x, heartSize / heartSprite.getTexture()->getSize().y);

        window.draw(heartSprite);
    }
}


void Map::detectGemColission(Player& player, Gem& gem) {
    if (player.getHitbox().intersects(gem.getGemSprite(1).getGlobalBounds()) || player.getHitbox().intersects(gem.getGemSprite(2).getGlobalBounds())) {
        if (!gem.getHasBeenPicked()) {
            gemSound.play();
            gem.setVisible(false);
            gem.setHasBeenPicked(true);
            player.addPuntaje();
        }
    }
}

