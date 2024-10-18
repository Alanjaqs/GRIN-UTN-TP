#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable
{
private:
    // Atributos
    float velocityX = 1;
    float velocityY = 0;
    float jumpForce = -10;
    bool isJumping = false;
    bool isMoving = false;
    sf::Texture textureIdle;
    sf::Texture textureJump;
    sf::Texture textureMove;
    sf::Sprite sprite;
    bool spaceReleased = true;

    // Doble salto
    bool hasDoubleJump = false;
    bool hasAlreadyJumped = false;

public:
    // Constructor (carga textura, setea textura, setea posicion en pantalla, setea origen de sprite)
    Player();
    // Metodos
    void update();
    // Set & get velocity
    void setVelocity(float v);
    float getVelocity();
    // Dibujar sprite con metodo de Drawable
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    /* Explicacion: velocityY esta en negativo por la jumpForce aplicada, personaje subiendo
    se acumula la gravedad con valor positivo hasta que velocityY llega a 0
    cuando llega a 0, velocityY comienza a ser positivo por ende el sprite empieza a bajar */
    void moveJump(float g);
    void detectFloor();
    // Obtener la posición del jugador
    sf::Vector2f getPlayerPosition();
    // Métodos para gestionar el doble salto
    void setHasDoubleJump(bool hasIt);
    void setHasAlreadyJumped(bool hasIt);
};

#endif 