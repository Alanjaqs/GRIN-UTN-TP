#include "Platform.h"

// Cargar tipos de plataformas en constructor
Platform::Platform() {
    platTexture1.loadFromFile("images\\platform1.png");
    platSprite1.setTexture(platTexture1);
    platTexture2.loadFromFile("images\\platform2.png");
    platSprite2.setTexture(platTexture2);
}

// Obtener el sprite del tipo de plataforma requerido
sf::Sprite& Platform::getPlatform(int tipoPlataforma) {
    if (tipoPlataforma == 1) return platSprite1;
    if (tipoPlataforma == 2) return platSprite2;
}