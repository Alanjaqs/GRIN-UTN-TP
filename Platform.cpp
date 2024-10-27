#include "Platform.h"

// Cargar tipos de plataformas en constructor
Platform::Platform() {
    platTexture1.loadFromFile("images\\platform1.png");
    platSprite1.setTexture(platTexture1);
}

// Obtener el sprite del tipo de plataforma requerido
sf::Sprite& Platform::getPlatform(int tipoPlataforma) {
    if (tipoPlataforma == 1) {
        return platSprite1;
    }

}
void Platform::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(platSprite1, states);
}
void Platform::setPlatPosition(float x, float y)
{
    platSprite1.setPosition(x, y);
}
// Hitbox
void Platform::updateHitbox() {
    platformTop = platSprite1.getGlobalBounds().top;
    platformBottom = platSprite1.getGlobalBounds().top + platSprite1.getGlobalBounds().height;
    platformLeft = platSprite1.getGlobalBounds().left;
    platformRight = platSprite1.getGlobalBounds().left + platSprite1.getGlobalBounds().width;
    hitbox = platSprite1.getGlobalBounds();
}
sf::FloatRect Platform::getHitbox() { return hitbox; }
float Platform::getPlatTop() { return platformTop; }
float Platform::getPlatBottom() { return platformBottom; }
float Platform::getPlatLeft() { return platformLeft; }
float Platform::getPlatRight() { return platformRight; }
