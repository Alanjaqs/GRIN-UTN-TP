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
void Platform::setPlatPosition(float x, float y)
{
    platSprite1.setPosition(x, y);
}
