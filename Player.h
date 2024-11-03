#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Player : public sf::Drawable
{
private:
    // Atributos varios
    float velocityX = 0;
    float velocityY = 0;
    float jumpForce = -10;
    bool isJumping = false;
    bool isMoving = false;
    bool isRunning = false;
    bool isDashKeyPressed = false;
    bool isDead = false;

    // Lados Player
    float playerTop;
    float playerBottom;
    float playerLeft;
    float playerRight;

    // Texturas
    sf::Texture textureIdle;
    sf::Texture textureJump;
    sf::Texture textureMove;
    sf::Texture textureRun;
    sf::Texture textureRunJump;
    sf::Sprite sprite;

    // Hitbox, para predefinir las medidas del sprite
    sf::FloatRect hitbox;

    // Doble salto
    bool hasDoubleJump = false;
    bool hasAlreadyJumped = false;
    bool spaceReleased = true;
    bool hasSpeed = false;

    //Tiempo de doble salto
    sf::Clock doubleJumpClock;
    float doubleJumpDuration = 10.0f; //Segundos

    // AudioPlayer
    sf::Music jumpSound;
    sf::Music dashSound;

    //Vida
    int life = 3;
    int totalLife = 3;
    sf::Clock damageClock;


public:
    // Constructor (carga textura, setea textura, setea posicion en pantalla, setea origen de sprite)
    Player();
    // Metodos
    void update();
    // Set & get velocity
    void setVelocityX(float v);
    float getVelocityX();
    void setVelocityY(float v);
    float getVelocityY();
    // Dibujar sprite con metodo de Drawable
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    /* Explicacion: velocityY esta en negativo por la jumpForce aplicada, personaje subiendo
    se acumula la gravedad con valor positivo hasta que velocityY llega a 0
    cuando llega a 0, velocityY comienza a ser positivo por ende el sprite empieza a bajar */
    void moveJump(float g);
    // Deteccion de suelo, ya sea predeterminado o plataforma
    void onFloor();
    // Obtener la posición del jugador y el sprite
    sf::Vector2f getPlayerPosition();
    sf::Sprite& getPlayerSprite();
    // Métodos para gestionar el doble salto
    void setHasDoubleJump(bool hasIt);
    void setHasAlreadyJumped(bool hasIt);
    // Metodos para gestionar speed boost
    void setHasSpeed(bool hasIt);
    bool getHasSpeed();
    bool getIsJumping();
    // Metodos Hitbox
    void updateHitbox();
    sf::FloatRect getHitbox();
    float getPlayerTop();
    float getPlayerBottom();
    float getPlayerLeft();
    float getPlayerRight();
    void setIsDead(int v);
    bool getIsDead();
    
    //Vida
    void doDamage(int damage = 1);
    int getCurrentLife();
    int getTotalLife();
    void setTotalLife(int newTotalLife);
    void healLife(int healing = 1);
    sf::Clock& getDamageClock();
};

#endif 