#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Map.h"
#include "MenuScene.h"

int main() 
{
    // Menu
    MenuScene menu;

    // Jugador
    Player player;
    
    Map map(&player);
    float gravity = 0.5f;
    float winWidth = 1280.0f, winHeight = 720.0f;


    // Ventana
    sf::RenderWindow window(sf::VideoMode(1280, 720), "GRIN");
    window.setFramerateLimit(60);
    sf::Vector2f camPosition;

    sf::Music music;
    music.openFromFile("audio\\backMusic.mp3");
    music.play();
    music.setLoop(true);

    // Camera
    sf::View view(sf::FloatRect(0, 0, 1280, 720));

    // Game Loop (update del juego)
    while(window.isOpen())
    {
        // ReadInput Actualizar los estados de los perifericos de entrada
        // "pollEvent" Leer la cola de mensajes/eventos en la ventana
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // CMD (comandos) - Joy
        player.update();
        player.moveJump(gravity);
        player.detectFloor();

        // Detectar colisiones para DoubleJump
        map.detectCollisions(&player);

        window.clear();

        // Render Menu
        //window.draw(menu.getMenuBack());
        //window.draw(menu.getJugarButton(1));
        //window.draw(menu.getSalirButton(0));
        
        
        // Camara sigue player
        camPosition = player.getPlayerPosition();
        // Evita que salga la camara para la izquierda (x < 0)
        if (camPosition.x - winWidth / 2 < 0) camPosition.x = winWidth / 2;
        view.setCenter(camPosition.x, camPosition.y - 240);
        window.setView(view);

        // Dibujar background 3 veces consecutivas

        map.setMapPosition(map.getBackground(), 0, 0);
        window.draw(map.getBackground());
        map.setMapPosition(map.getBackground(), 1280, 0);
        window.draw(map.getBackground());
        map.setMapPosition(map.getBackground(), 2560, 0);
        window.draw(map.getBackground());

        // Dibujar mapeado plataformas
        map.setMapPosition(map.getPlatform(1), 0, 650);
        window.draw(map.getPlatform(1));
        map.setMapPosition(map.getPlatform(1), 300, 600);
        window.draw(map.getPlatform(1));

        // Dibujar DoubleJump si no ha sido eliminado
        sf::Sprite* doubleJumpSprite = map.getDoubleJump(); // Obtén el puntero
        if (doubleJumpSprite) { // Verifica si no es nullptr
            map.setMapPosition(*doubleJumpSprite, 280, 500);
            window.draw(*doubleJumpSprite);
        }
        else {
            // Manejo opcional si doubleJump no existe (puedes dejarlo vacío o imprimir un mensaje)
        }


        // Dibujar Player
        window.draw(player);


        window.display();
    }

    // Liberacion del juego

    return 0;
}
