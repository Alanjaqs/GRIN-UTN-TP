#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Player.h"
#include "Map.h"
#include "Platform.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "SpeedItem.h"
#include "Enemy.h"

int main() 
{
    // Menu
    MenuScene menu;
    // Game
    GameScene game;

    // Jugador
    Player player;
    
    //Enemigo
    Enemy enemy;
    
    Platform platform;

    Map map(&player);
    SpeedItem speedIt;
    float gravity = 0.5f;
    float winWidth = 1280.0f, winHeight = 720.0f;


    // Ventana
    sf::RenderWindow window(sf::VideoMode(1280, 720), "GRIN");
    window.setFramerateLimit(60);

    sf::Music music, soundSel;
    music.openFromFile("audio\\backMusic.mp3");
    music.play();
    music.setLoop(true);

    // Camera
    sf::View view(sf::FloatRect(0, 0, 1280, 720));
    sf::Vector2f camPosition;

    // Game Loop (update del juego)
    // Definir estado para menu
    game.setGameState(1);


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


        window.clear();

        // Render Menu
        if (game.getGameState() == 1)
        {
            menu.MenuUpdate();
            window.draw(menu.getMenuBack());
            if (menu.getOpc() == 1) {
                window.draw(menu.getJugarSelButton());
                window.draw(menu.getSalirButton());
            }
            else if (menu.getOpc() == 0) {
                window.draw(menu.getJugarButton());
                window.draw(menu.getSalirSelButton());
            }
            if (menu.getSalir()) {
                window.close();
            }
            if (menu.getJugar()) {
                game.setGameState(2);
            } 
            
        }
   
        // Render Tutorial
        if (game.getGameState() == 2) {
            // CMD (comandos) - Joy
            player.update();
            player.moveJump(gravity);

            // Detectar colisiones para DoubleJump
            map.detectCollisions(&player);
            map.collisionFloorCheck(player, platform);

            // Camara sigue player
            camPosition = player.getPlayerPosition();
            // Evita que salga la camara para la izquierda (x < 0)
            if (camPosition.x - winWidth / 2 < 0) camPosition.x = winWidth / 2;
            view.setCenter(camPosition.x, 358);
            window.setView(view);

            // Dibujar background 3 veces consecutivas
            map.setMapPosition(map.getBackground(), 0, 0);
            window.draw(map.getBackground());
            map.setMapPosition(map.getBackground(), 1280, 0);
            window.draw(map.getBackground());
            map.setMapPosition(map.getBackground(), 2560, 0);
            window.draw(map.getBackground());
            map.setMapPosition(map.getBackground(), 3840, 0);
            window.draw(map.getBackground());
            map.setMapPosition(map.getBackground(), 5120, 0);
            window.draw(map.getBackground());

            // Dibujar chats
            map.setChatSprite(1);
            map.setMapPosition(map.getChat(), 380, 200);
            window.draw(map.getChat());
            map.setChatSprite(2);
            map.setMapPosition(map.getChat(), 1400, 200);
            window.draw(map.getChat());
            map.setChatSprite(3);
            map.setMapPosition(map.getChat(), 2000, 200);
            window.draw(map.getChat());
            map.setChatSprite(4);
            map.setMapPosition(map.getChat(), 3200, 200);
            window.draw(map.getChat());
            map.setChatSprite(5);
            map.setMapPosition(map.getChat(), 3800, 200);
            window.draw(map.getChat());
            map.setChatSprite(6);
            map.setMapPosition(map.getChat(), 5000, 200);
            window.draw(map.getChat());
            map.setChatSprite(7);
            map.setMapPosition(map.getChat(), 5600, 200);
            window.draw(map.getChat());


            // Dibujar ground
            map.setMapPosition(map.getGround(), 0, 650);
            window.draw(map.getGround());
            map.setMapPosition(map.getGround(), 1280, 650);
            window.draw(map.getGround());
            map.setMapPosition(map.getGround(), 2560, 650);
            window.draw(map.getGround());
            map.setMapPosition(map.getGround(), 3840, 650);
            window.draw(map.getGround());
            map.setMapPosition(map.getGround(), 5120, 650);
            window.draw(map.getGround());

            // Dibujar DoubleJump si no ha sido eliminado
            sf::Sprite* doubleJumpSprite = map.getDoubleJump(); // Obtén el puntero
            if (doubleJumpSprite) { // Verifica si no es nullptr
                map.setMapPosition(*doubleJumpSprite, 1850, 500);
                window.draw(*doubleJumpSprite);
            }
            else {
                // Manejo opcional si doubleJump no existe (puedes dejarlo vacío o imprimir un mensaje)
            }

            // Dibujar SpeedItem (por ahora dibujado asi nomas)
            if (speedIt.getVisible()) {
                map.setMapPosition(speedIt.getSpeedSprite(), 3650, 500);
                window.draw(speedIt.getSpeedSprite());
            } 
            map.detectSpeedCollision(player, speedIt);
            // Dibujar Player
            window.draw(player);

            // Dibujar Enemy
            if (enemy.getSpawned()) {
                enemy.respawnmanual(5600, 630);
                enemy.setSpawned(false);
            }       
            if (enemy.getVisible()) {
                enemy.update();
                window.draw(enemy);
            }
            map.collisionEnemyCheck(player, enemy);

        }

        // Render Level 1
        if (game.getGameState() == 3) {
            // Dibujar DoubleJump si no ha sido eliminado
            sf::Sprite* doubleJumpSprite = map.getDoubleJump(); // Obtén el puntero
            if (doubleJumpSprite) { // Verifica si no es nullptr
                map.setMapPosition(*doubleJumpSprite, 280, 500);
                window.draw(*doubleJumpSprite);
            }
            else {
                // Manejo opcional si doubleJump no existe (puedes dejarlo vacío o imprimir un mensaje)
            }

            map.setMapPosition(platform.getPlatform(1), 550, 500);
            window.draw(platform.getPlatform(1));
        }
        

        window.display();
    }

    // Liberacion del juego

    return 0;
}
