#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Player.h"
#include "Map.h"
#include "Platform.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "DoubleJump.h"
#include "SpeedItem.h"
#include "Enemy.h"
#include "DataPlayer.h"
#include "GameArchive.h"
#include "Gem.h"
#include "Spike.h"


int main() 
{
    GameScene game;
    Map map;

    // Ventana
    sf::RenderWindow window(sf::VideoMode(1280, 720), "GRIN");
    window.setFramerateLimit(60);

    // Camera
    sf::View view(sf::FloatRect(0, 0, 1280, 720));

    // Establecer musica principal del juego


    // Game Loop (update del juego)
    while(window.isOpen())
    {
        // "pollEvent" Leer la cola de mensajes/eventos en la ventana
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // CLEAR
        window.clear();

        // ESTADO 1: RENDER MENU
        if (game.getGameState() == 1)
        {      
            game.GameMenu(window, view, event);
        }
   
        // ESTADO 2: RENDER TUTORIAL
        else if (game.getGameState() == 2) {
            game.Tutorial(window, view);
        }

        // ESTADO 3: RENDER LEVEL 1
        else if (game.getGameState() == 3) {
            game.Level1(window, view);
        }

        // ESTADO 4: RENDER LEVEL 2
        else if (game.getGameState() == 4) {
            game.Level2(window, view);
        }

        // ESTADO 5: BOSS LEVEL
        else if (game.getGameState() == 5) {
            game.BossLevel(window, view);
        }

        // ESTADO 6: PANTALLA DATOS
        else if (game.getGameState() == 6) {
            game.DataScreen(window, view);
        }
        
        // DISPLAY
        window.display();
    }

    // Liberacion del juego

    return 0;
}
