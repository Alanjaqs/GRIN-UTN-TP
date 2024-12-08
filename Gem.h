#ifndef GEM_H
#define GEM_H

#include "PickableItem.h"

class Gem : public PickableItem {
private:
    sf::Texture gemTexture2;
    sf::Sprite gemSprite2;
    // Animation
    sf::Clock clock;
    float animationTime = 0.2f;
    bool animationFrame = true;
public:
    Gem();

    // Getters
    bool getAnimationFrame();
    sf::Sprite& getGemSprite(int g);
};

#endif // GEM_H
