#ifndef DOUBLEJUMP_H
#define DOUBLEJUMP_H

#include <SFML/Graphics.hpp>
#include "PickableItem.h"
#include "Player.h"
#include <cmath>

class DoubleJump : public PickableItem {
private:
    sf::Texture entityTexture;
    sf::Sprite sprite;
    Player* player;
    bool collided = false;  // Indica si ocurrió una colisión

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    DoubleJump(Player* player);
    ~DoubleJump();

    sf::Sprite& getSprite();
    bool detectCollision();
    bool hasCollided() const { return collided; }  // Getter para el estado de colisión
};

#endif  // DOUBLEJUMP_H
