#include "Gem.h"

Gem::Gem() : PickableItem("images\\gemFrame1.png") {
    gemTexture2.loadFromFile("images\\gemFrame2.png");
    gemSprite2.setTexture(gemTexture2);
}

bool Gem::getAnimationFrame() {
    if (clock.getElapsedTime().asSeconds() >= animationTime) {
        animationFrame = !animationFrame;
        clock.restart();
    }
    return animationFrame;
}

sf::Sprite& Gem::getGemSprite(int g) {
    if (g == 1) return sprite;
    if (g == 2) return gemSprite2;
    throw std::out_of_range("Invalid sprite index");
}
