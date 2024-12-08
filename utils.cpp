#include "utils.h"

void calcularPuntaje(sf::Clock& clock, float intervaloDecremento, Player& player, float& elapsedTime) {
    int puntos = player.getPuntaje();
    elapsedTime += clock.restart().asSeconds(); // Reinicia el reloj y suma el tiempo transcurrido
    if (elapsedTime >= intervaloDecremento) {
        player.quitarPuntaje(10); // Reduce el puntaje cada segundo
        elapsedTime = 0.0f; // Reinicia el contador
        if (puntos <= 0) {
            player.setPuntaje(0);
        }
    }

}