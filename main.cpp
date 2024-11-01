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
#include "DataPlayer.h"
#include "GameArchive.h"

int main() 
{
    // Variables generales
    float gravity = 0.5f;
    float winWidth = 1280.0f, winHeight = 720.0f;
  
    //fuente de texto prueba
    sf::Font font;
    font.loadFromFile("pixel.otf");
    sf::Text textPuntos, text;
    textPuntos.setFont(font);
    text.setFont(font);

    //inicializacion de puntos prueba
    int puntos=1000;

    sf::Clock clock;
    float decrementIntervalo = 1.0f; // Reducir el puntaje cada 1 segundo
    float elapsedTime = 0.0f;


    // Inicializacion de objetos
    MenuScene menu;
    GameScene game;
    Player player;
    Enemy enemy;
    // Plataformas tutorial
    Platform platform, platform2, platform3, platform4;
    // Map render
    Map map(&player);
    SpeedItem speedIt;
    // Ventana
    sf::RenderWindow window(sf::VideoMode(1280, 720), "GRIN");
    window.setFramerateLimit(60);
    // Camera
    sf::View view(sf::FloatRect(0, 0, 1280, 720));
    sf::Vector2f camPosition;
    // Data y Archive
    DataPlayer data;
    GameArchive archive;

    // Music
    // Hice que la musica general la tenga la clase Map
    // Por ahora hay 3 canciones, la idea es una para el menu y otra para el tutorial
    // Pero si se llama el play dentro del loop del juego se realentiza todo
    // Ver mas adelante como solucionar
    map.getMusic(2).play();
    map.getMusic(2).setLoop(1);

    // Creacion de primer archivo
    archive.iniciarRank();

    // Lectura en consola temporal para ver funcionamiento
    archive.leerRank();

   // Definir estado para menu inicial
    game.setGameState(1);

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
            menu.MenuUpdate();
            // Tipo Menu 1
            if (menu.getTipoMenu() == 1) {
                // Se dibuja fondo y botones seleccionados segun opcion
                window.draw(menu.getMenuBack());
                if (menu.getOpc() == 1) {
                    window.draw(menu.getJugarSelButton());
                    window.draw(menu.getSalirButton());
                }
                else if (menu.getOpc() == 2) {
                    window.draw(menu.getJugarButton());
                    window.draw(menu.getSalirSelButton());
                }
                // Si salir presionado ciera juego
                if (menu.getSalir()) {
                    window.close();
                }
            }
            // Tipo Menu 2
            else if (menu.getTipoMenu() == 2) {
                // Se dibuja fondo y botones seleccionados segun opcion
                window.draw(menu.getMenu2Back());   
                if (menu.getOpc() == 3) {
                    window.draw(menu.getComenzarSelButton());
                    window.draw(menu.getRankButton());
                    window.draw(menu.getVolverButton());
                }
                else if (menu.getOpc() == 4) {
                    window.draw(menu.getComenzarButton());
                    window.draw(menu.getRankSelButton());
                    window.draw(menu.getVolverButton());
                }
                else if (menu.getOpc() == 5) {
                    window.draw(menu.getComenzarButton());
                    window.draw(menu.getRankButton());
                    window.draw(menu.getVolverSelButton());
                }
                // Si se presiona comenzar, cambia a estado de juego 2 - tutorial
                // Nota: por ahora esta asi, pero la idea es que cuando le de comenzar
                // haya un sistema para ingresar el nombre del jugador y luego empezar el juego
                if (menu.getComenzar()) {
                    game.setGameState(2);
                }
                
            }
            // Tipo Menu 3
            else if (menu.getTipoMenu() == 3) {
                // Se dibuja fondo y botones seleccionados segun opcion
                window.draw(menu.getMenu2Back());
                if (menu.getOpc() == 6) {
                    window.draw(menu.getVerRankSelButton());
                    window.draw(menu.getBorrarRankButton());
                    window.draw(menu.getVolverButton());
                }
                else if (menu.getOpc() == 7) {
                    window.draw(menu.getVerRankButton());
                    window.draw(menu.getBorrarRankSelButton());
                    window.draw(menu.getVolverButton());
                }
                else if (menu.getOpc() == 8) {
                    window.draw(menu.getVerRankButton());
                    window.draw(menu.getBorrarRankButton());
                    window.draw(menu.getVolverSelButton());
                }

            }
            // Tipo Menu 6 Game Over
            else if (menu.getTipoMenu() == 6) {
                window.draw(menu.getGameOver());
                view.setCenter(winWidth / 2, winHeight / 2);
                window.setView(view);
                player.setIsDead(0);
                menu.setComenzar(0);
                menu.setSalir(0);
            }
        }
   
        // ESTADO 2: RENDER TUTORIAL
        else if (game.getGameState() == 2) {

            // Player update
            player.update();
            player.moveJump(gravity);

            // Camara sigue player
            camPosition = player.getPlayerPosition();

            
            // Evita que salga la camara para la izquierda (x < 0)
            if (camPosition.x - winWidth / 2 < 0) camPosition.x = winWidth / 2;
            view.setCenter(camPosition.x, 358);
            window.setView(view);

            // Dibujar background x veces consecutivas
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
            map.setMapPosition(map.getChat(), 3150, 200);
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


            //Dibujar plataforma
            platform.updateHitbox();
            platform.setPlatPosition(1500, 560);
            window.draw(platform);

            platform2.updateHitbox();
            platform2.setPlatPosition(1800, 500);
            window.draw(platform2);

            platform3.updateHitbox();
            platform3.setPlatPosition(3300, 500);
            window.draw(platform3);

            platform4.updateHitbox();
            platform4.setPlatPosition(3600, 350);
            window.draw(platform4);

            // Dibujar DoubleJump si no ha sido eliminado
            sf::Sprite* doubleJumpSprite = map.getDoubleJump(); // Obtén el puntero
            if (doubleJumpSprite) { // Verifica si no es nullptr
                map.setMapPosition(*doubleJumpSprite, 1850, 420);
                window.draw(*doubleJumpSprite);
            }
            else {
                // Manejo opcional si doubleJump no existe (puedes dejarlo vacío o imprimir un mensaje)
            }
            // Detectar colisiones para DoubleJump
            map.detectCollisions(&player);

            // Dibujar SpeedItem
            if (speedIt.getVisible()) {
                map.setMapPosition(speedIt.getSpeedSprite(), 3650, 270);
                window.draw(speedIt.getSpeedSprite());
            }
            // Colision Speed Item
            map.detectSpeedCollision(player, speedIt);

            // Colision suelo y plataformas
            map.collisionFloorCheck(player);
            map.collisionPlatCheck(player, platform);
            map.collisionPlatCheck(player, platform2);
            map.collisionPlatCheck(player, platform3);
            map.collisionPlatCheck(player, platform4);

            // Dibujar Player
            window.draw(player);

            // Sistema de reduccion de puntaje
            elapsedTime += clock.restart().asSeconds(); // Reinicia el reloj y suma el tiempo transcurrido
            if (elapsedTime >= decrementIntervalo) {
                puntos-=10; // Reduce el puntaje cada segundo
                elapsedTime = 0.0f; // Reinicia el contador
                if (puntos < 0) {
                    puntos = 0;
                }
            }    

            // Dibujar Enemy
            if (enemy.getSpawned()) {
                enemy.respawnmanual(5600, 630);
                enemy.setSpawned(false);
            }       
            if (enemy.getVisible()) {
                enemy.update();
                window.draw(enemy);
            }

            //Dibujar texto "Puntos" y el puntaje decreciendo
            window.setView(window.getDefaultView());
            textPuntos.setString("Puntos:");
            window.draw(textPuntos);
            text.setString(std::to_string(puntos));
            text.setPosition(180, 0);
            window.draw(text);


            // Colision Enemy
            map.collisionEnemyCheck(player, enemy);
            // Comprobar si player perdio
            if (player.getIsDead()) {
                map.getMusic(2).stop();
                map.getMusic(3).play();
                menu.setTipoMenu(6);
                player.getPlayerSprite().setPosition(200, 500);
                game.setGameState(1);
            }
        }

        // RENDER LEVEL 1
        else if (game.getGameState() == 3) {
         
        }
        
        // DISPLAY
        window.display();
    }

    // Liberacion del juego

    return 0;
}
