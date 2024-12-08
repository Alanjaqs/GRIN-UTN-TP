#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
//Utilities functions 

void calcularPuntaje(sf::Clock& clock, float intervaloDecremento, Player& player, float& elapsedTime);