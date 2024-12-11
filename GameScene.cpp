#include "GameScene.h"
#include "utils.h"

// Constructor
GameScene::GameScene() {
    // Hearts
    emptyHeartTex.loadFromFile("images\\empty_heart.png");
    fullHeartTex.loadFromFile("images\\full_heart.png");
    // Textos
    // Establecer color y fuente
    sf::Color color(0xD1CB95FF);
    font.loadFromFile("pixel.otf");
    // Manejo de todos los textos
    text.setFont(font);
    text.setFillColor(color);
    textPuntos.setFont(font);
    textPuntos.setFillColor(color);
    textNuevoNombre.setFont(font);
    textNuevoNombre.setFillColor(color);
    textGracias.setFont(font);
    textGracias.setFillColor(color);
    textGracias.setString("Gracias por jugar");
    textGracias.setScale(1.5, 1.5);
    textPuntosFinal.setFont(font);
    textPuntosFinal.setFillColor(color);
    textEnter.setFont(font);
    textEnter.setFillColor(color);
    textEnter.setString("Presiona ENTER para volver");
    textPos.setFont(font);
    textPos.setFillColor(color);
    textName.setFont(font);
    textName.setFillColor(color);
    textPoints.setFont(font);
    textPoints.setFillColor(color);
    textIngresarNombre.setFont(font);
    textIngresarNombre.setFillColor(color);
    textIngresarNombre.setString("Ingresa tu nombre (maximo 5 letras):");
    textNivel.setFont(font);
    textNivel.setFillColor(color);
    textNivel.setString("NIVEL 1");
    textNivel.setScale(1.5, 1.5);
    textBorrado.setFont(font);
    textBorrado.setFillColor(color);
    textBorrado.setString("El rank se ha reiniciado");

    // Seteos para los metodos de estructura
    setGameState(1);
    winWidth = 1280.0f, winHeight = 720.0f;
    vecData = new DataPlayer[cantReg];
    menuMusicBD = true, tutoMusicBD = false, level1MusicBD = false, level2MusicBD = false;

    // Creacion de primer archivo
    if (!archive.leerRank(vecData)) {
        archive.iniciarRank();
        std::cout << "Archivo.dat creado!" << std::endl;
    }
    std::cout << "Archivo.dat ya existe" << std::endl;
}
void GameScene::setGameState(int e) {
	state = e;
}
int GameScene::getGameState() {
	return state;
}

float GameScene::getBossDefeatedTime() { return bossDefeatedTime; }

// METODOS DE LA ESTRUCTURA DEL JUEGO

void GameScene::GameMenu(sf::RenderWindow& window, sf::View& view, sf::Event& event) {
    if (menuMusicBD) {
        map.getMusic(2).stop();
        map.getMusic(3).stop();
        map.getMusic(1).play();
        map.getMusic(1).setLoop(1);
        menuMusicBD = false;
    }
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
            if (menu.getBorrarRank()) {
                textBorrado.setPosition(350, 600);
                window.draw(textBorrado);
            }
        }
        else if (menu.getOpc() == 8) {
            window.draw(menu.getVerRankButton());
            window.draw(menu.getBorrarRankButton());
            window.draw(menu.getVolverSelButton());
        }
    }
    // Tipo Menu 4 Rank
    else if (menu.getTipoMenu() == 4) {
        window.draw(menu.getMenu2Back());
        archive.leerRank(vecData);
        // Textos del rank
        textPos.setString("Posicion");
        textPos.setPosition(500, 50);
        window.draw(textPos);
        textName.setString("Nombre");
        textName.setPosition(780, 50);
        window.draw(textName);
        textPoints.setString("Puntaje");
        textPoints.setPosition(980, 50);
        window.draw(textPoints);
        // Boton enter back
        textEnter.setPosition(500, 600);
        window.draw(textEnter);
        // Textos de registros
        for (int i = 0; i < cantReg; i++) {
            // Primer posicionamiento
            if (i == 0) {
                textPos.setString(std::to_string(vecData[i].getPosicion()));
                textPos.setPosition(500, 100);
                window.draw(textPos);
                textName.setString(vecData[i].getNombre());
                textName.setPosition(780, 100);
                window.draw(textName);
                textPoints.setString(std::to_string(vecData[i].getPuntaje()));
                textPoints.setPosition(980, 100);
                window.draw(textPoints);
            }
            // Demas posicionamientos 
            else {
                textPos.setString(std::to_string(vecData[i].getPosicion()));
                textPos.setPosition(500, ((i * 100) + 100));
                window.draw(textPos);
                textName.setString(vecData[i].getNombre());
                textName.setPosition(780, ((i * 100) + 100));
                window.draw(textName);
                textPoints.setString(std::to_string(vecData[i].getPuntaje()));
                textPoints.setPosition(980, ((i * 100) + 100));
                window.draw(textPoints);
            }
        }
    }
    // Tipo Menu 5 Ingresar Nombre
    else if (menu.getTipoMenu() == 5) {
        window.draw(menu.getMenu2Back());
        textIngresarNombre.setPosition(340, 60);
        window.draw(textIngresarNombre);
        textNuevoNombre.setPosition(540, 150);
        window.draw(textNuevoNombre);
        // Detecta texto ingresado
        if (event.type == event.TextEntered) {
            if (event.text.unicode >= 'A' && event.text.unicode <= 'Z' ||
                event.text.unicode >= 'a' && event.text.unicode <= 'z') {
                if (nuevoNombre.size() < 5 && keyReleased) {
                    nuevoNombre += static_cast<char>(event.text.unicode);
                    textNuevoNombre.setString(nuevoNombre);
                    keyReleased = false;
                }
            }
        }
        if (event.type != event.TextEntered) keyReleased = true;
        // Verificar si nombre tiene al menos 1 caracter para seguir
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && nuevoNombre.size() >= 1 && nuevoNombre.size() <= 5) {
            menu.setComenzar(1);
            tutoMusicBD = true;
        }
        if (menu.getComenzar()) {
            setGameState(2);
        }
    }
    // Tipo Menu 6 Game Over
    else if (menu.getTipoMenu() == 6) {
        window.draw(menu.getGameOver());
        textEnter.setPosition(300, 600);
        window.draw(textEnter);
        // Reinicio de variables
        // Camara
        view.setCenter(winWidth / 2, winHeight / 2);
        window.setView(view);
        // Power ups
        dj.setVisible(true);
        player.setHasDoubleJump(false);
        speedIt.setVisible(true);
        player.setHasSpeed(false);
        // Puntaje, vida, pos
        player.setCurrentLife(3);
        player.setPuntaje(1010);
        player.getPlayerSprite().setPosition(200, 500);\
        // Enemies
        enemy.setSpawned(true);
        enemy.setVisible(true);
        enemy2.setSpawned(true);
        enemy2.setVisible(true);
        enemy3.setSpawned(true);
        enemy3.setVisible(true);
        enemy4.setSpawned(true);
        enemy4.setVisible(true);
        enemy5.setSpawned(true);
        enemy5.setVisible(true);
        enemy6.setSpawned(true);
        enemy6.setVisible(true);
        enemy7.setSpawned(true);
        enemy7.setVisible(true);
        enemy8.setSpawned(true);
        enemy8.setVisible(true);
        enemy9.setSpawned(true);
        enemy9.setVisible(true);
        // Gems
        gem1.setVisible(true);
        gem1.setHasBeenPicked(false);
        gem2.setVisible(true);
        gem2.setHasBeenPicked(false);
        gem3.setVisible(true);
        gem3.setHasBeenPicked(false);
        gem4.setVisible(true);
        gem4.setHasBeenPicked(false);
        gem5.setVisible(true);
        gem5.setHasBeenPicked(false);
        gem6.setVisible(true);
        gem6.setHasBeenPicked(false);
        gem7.setVisible(true);
        gem7.setHasBeenPicked(false);
        gem8.setVisible(true);
        gem8.setHasBeenPicked(false);
        gem9.setVisible(true);
        gem9.setHasBeenPicked(false);
        gem10.setVisible(true);
        gem10.setHasBeenPicked(false);
        gem11.setVisible(true);
        gem11.setHasBeenPicked(false);
        gem12.setVisible(true);
        gem12.setHasBeenPicked(false);
        // Otros
        menuMusicBD = true;
        nuevoNombre = "";
        player.setIsDead(0);
        menu.setComenzar(0);
        menu.setSalir(0);
    }
}

void GameScene::Tutorial(sf::RenderWindow& window, sf::View& view) {
    if (tutoMusicBD) {
        map.getMusic(1).stop();
        map.getMusic(2).play();
        map.getMusic(2).setLoop(1);
        tutoMusicBD = false;
    }
    // Player update
    player.update();
    player.moveJump();

    // Camara sigue player
    camPosition = player.getPlayerPosition();

    // Evita que salga la camara para la izquierda (x < 0)
    if (camPosition.x - winWidth / 2 < 0) camPosition.x = winWidth / 2;
    view.setCenter(camPosition.x, 358);
    window.setView(view);

    // Sistema reduccion de puntaje
    calcularPuntaje(clock, decrementIntervalo, player, elapsedTime);

    // RENDER BACKGROUNDS
    map.setMapPosition(map.getBackground(1), 0, 0);
    window.draw(map.getBackground(1));
    map.setMapPosition(map.getBackground(1), 1280, 0);
    window.draw(map.getBackground(1));
    map.setMapPosition(map.getBackground(1), 2560, 0);
    window.draw(map.getBackground(1));
    map.setMapPosition(map.getBackground(1), 3840, 0);
    window.draw(map.getBackground(1));
    map.setMapPosition(map.getBackground(1), 5120, 0);
    window.draw(map.getBackground(1));
    map.setMapPosition(map.getBackground(1), 6400, 0);
    window.draw(map.getBackground(1));
    map.setMapPosition(map.getBackground(1), 7680, 0);
    window.draw(map.getBackground(1));

    // RENDER CHATS
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
    map.setMapPosition(map.getChat(), 3850, 200);
    window.draw(map.getChat());
    map.setChatSprite(6);
    map.setMapPosition(map.getChat(), 5100, 200);
    window.draw(map.getChat());
    map.setChatSprite(7);
    map.setMapPosition(map.getChat(), 5600, 200);
    window.draw(map.getChat());
    map.setChatSprite(8);
    map.setMapPosition(map.getChat(), 820, 200);
    window.draw(map.getChat());

    // RENDER GROUNDS
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
    map.setMapPosition(map.getGround(), 6400, 650);
    window.draw(map.getGround());

    map.collisionFloorCheck(player);

    // RENDER PLATFORMS
    map.setMapPosition(platform.getPlatform(1), 1500, 560);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 1800, 500);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 3300, 500);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(2), 3600, 350);
    window.draw(platform.getPlatform(2));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(2), 6200, 500);
    window.draw(platform.getPlatform(2));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 6550, 350);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 7000, 350);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    // RENDER SPIKES
    map.setMapPosition(spike.getSpikeSprites(2), 6820, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    // RENDER GEMS
    // Objeto para obtener bool para animacion de gemas
    gemAnim.getAnimationFrame();
    //
    if (gem1.getVisible()) {
        map.setMapPosition(gem1.getGemSprite(1), 950, 550);
        map.setMapPosition(gem1.getGemSprite(2), 950, 550);
        if (gemAnim.getAnimationFrame())
            window.draw(gem1.getGemSprite(1));
        else
            window.draw(gem1.getGemSprite(2));
    }
    if (gem2.getVisible()) {
        map.setMapPosition(gem2.getGemSprite(1), 1600, 480);
        map.setMapPosition(gem2.getGemSprite(2), 1600, 480);
        if (gemAnim.getAnimationFrame())
            window.draw(gem2.getGemSprite(1));
        else
            window.draw(gem2.getGemSprite(2));
    }
    if (gem3.getVisible()) {
        map.setMapPosition(gem3.getGemSprite(1), 2800, 400);
        map.setMapPosition(gem3.getGemSprite(2), 2800, 400);
        if (gemAnim.getAnimationFrame())
            window.draw(gem3.getGemSprite(1));
        else
            window.draw(gem3.getGemSprite(2));
    }
    if (gem4.getVisible()) {
        map.setMapPosition(gem4.getGemSprite(1), 3500, 400);
        map.setMapPosition(gem4.getGemSprite(2), 3500, 400);
        if (gemAnim.getAnimationFrame())
            window.draw(gem4.getGemSprite(1));
        else
            window.draw(gem4.getGemSprite(2));
    }
    if (gem5.getVisible()) {
        map.setMapPosition(gem5.getGemSprite(1), 4000, 500);
        map.setMapPosition(gem5.getGemSprite(2), 4000, 500);
        if (gemAnim.getAnimationFrame())
            window.draw(gem5.getGemSprite(1));
        else
            window.draw(gem5.getGemSprite(2));
    }
    if (gem6.getVisible()) {
        map.setMapPosition(gem6.getGemSprite(1), 5000, 550);
        map.setMapPosition(gem6.getGemSprite(2), 5000, 550);
        if (gemAnim.getAnimationFrame())
            window.draw(gem6.getGemSprite(1));
        else
            window.draw(gem6.getGemSprite(2));
    }
    if (gem7.getVisible()) {
        map.setMapPosition(gem7.getGemSprite(1), 7050, 220);
        map.setMapPosition(gem7.getGemSprite(2), 7050, 220);
        if (gemAnim.getAnimationFrame())
            window.draw(gem7.getGemSprite(1));
        else
            window.draw(gem7.getGemSprite(2));
    }
    map.detectGemColission(player, gem1);
    map.detectGemColission(player, gem2);
    map.detectGemColission(player, gem3);
    map.detectGemColission(player, gem4);
    map.detectGemColission(player, gem5);
    map.detectGemColission(player, gem6);
    map.detectGemColission(player, gem7);

    // RENDER ENEMIES
    // Enemy 1
    if (enemy.getSpawned()) {
        enemy.respawnmanual(5600, 630);
        enemy.setSpawned(false);
    }
    if (enemy.getVisible()) {
        enemy.update();
        window.draw(enemy);
    }
    // Enemy 2
    if (enemy2.getSpawned()) {
        enemy2.respawnmanual(6650, 330);
        enemy2.setSpawned(false);
    }
    if (enemy2.getVisible()) {
        enemy2.update();
        window.draw(enemy2);
    }
    map.collisionEnemyCheck(player, enemy);
    map.collisionEnemyCheck(player, enemy2);

    // RENDER DOUBLE JUMP
    if (dj.getVisible()) {
        map.setMapPosition(dj.getSprite(), 1860, 420);
        map.colissionDoubleJumpCheck(player, dj);
        window.draw(dj.getSprite());
    }

    // RENDER SPEED ITEM
    if (speedIt.getVisible()) {
        map.setMapPosition(speedIt.getSprite(), 3660, 270);
        map.detectSpeedCollision(player, speedIt);
        window.draw(speedIt.getSprite());
    }

    // RENDER PORTAL
    map.setMapPosition(map.getPortal(), 7500, 572);
    window.draw(map.getPortal());

    // RENDER PLAYER
    window.draw(player);

    // RENDER PUNTOS DECRECIENDO
    window.setView(window.getDefaultView());
    textPuntos.setString("Puntos:");
    window.draw(textPuntos);
    text.setString(std::to_string(player.getPuntaje()));
    text.setPosition(180, 0);
    window.draw(text);

    // RENDER PLAYER NAME
    textNuevoNombre.setPosition(600, 0);
    window.draw(textNuevoNombre);

    // RENDER HEARTS
    int currentLife = player.getCurrentLife();
    int totalLife = player.getTotalLife();
    map.renderHearts(window, currentLife, totalLife, emptyHeartTex, fullHeartTex);

    // GAME OVER
    if (player.getIsDead()) {
        map.getMusic(2).stop();
        map.getMusic(4).play();
        menu.setTipoMenu(6);
        gem1.setVisible(true);
        gem1.setHasBeenPicked(false);
        gem2.setVisible(true);
        gem2.setHasBeenPicked(false);
        gem3.setVisible(true);
        gem3.setHasBeenPicked(false);
        gem4.setVisible(true);
        gem4.setHasBeenPicked(false);
        gem5.setVisible(true);
        gem5.setHasBeenPicked(false);
        gem6.setVisible(true);
        gem6.setHasBeenPicked(false);
        gem7.setVisible(true);
        gem7.setHasBeenPicked(false);
        setGameState(1);
    }

    // Deteccion Portal + reinicio para level 1   
    if (player.getHitbox().intersects(map.getPortal().getGlobalBounds())) {
        // Reinicio de variables
        // Camara
        view.setCenter(winWidth / 2, winHeight / 2);
        window.setView(view);
        // Power ups
        dj.setVisible(true);
        player.setHasDoubleJump(false);
        speedIt.setVisible(true);
        player.setHasSpeed(false);
        // Puntaje, vida, pos
        player.setCurrentLife(3);
        player.getPlayerSprite().setPosition(200, 500);
        // Enemies
        enemy.setSpawned(true);
        enemy.setVisible(true);
        enemy2.setSpawned(true);
        enemy2.setVisible(true);
        enemy3.setSpawned(true);
        enemy3.setVisible(true);
        enemy4.setSpawned(true);
        enemy4.setVisible(true);
        enemy5.setSpawned(true);
        enemy5.setVisible(true);
        enemy6.setSpawned(true);
        enemy6.setVisible(true);
        enemy7.setSpawned(true);
        enemy7.setVisible(true);
        enemy8.setSpawned(true);
        enemy8.setVisible(true);
        enemy9.setSpawned(true);
        enemy9.setVisible(true);
        // Gems
        gem1.setVisible(true);
        gem1.setHasBeenPicked(false);
        gem2.setVisible(true);
        gem2.setHasBeenPicked(false);
        gem3.setVisible(true);
        gem3.setHasBeenPicked(false);
        gem4.setVisible(true);
        gem4.setHasBeenPicked(false);
        gem5.setVisible(true);
        gem5.setHasBeenPicked(false);
        gem6.setVisible(true);
        gem6.setHasBeenPicked(false);
        gem7.setVisible(true);
        gem7.setHasBeenPicked(false);
        gem8.setVisible(true);
        gem8.setHasBeenPicked(false);
        gem9.setVisible(true);
        gem9.setHasBeenPicked(false);
        gem10.setVisible(true);
        gem10.setHasBeenPicked(false);
        gem11.setVisible(true);
        gem11.setHasBeenPicked(false);
        gem12.setVisible(true);
        gem12.setHasBeenPicked(false);
        setGameState(3);
    }
}

void GameScene::Level1(sf::RenderWindow& window, sf::View& view) {
    // Player update
    player.update();
    player.moveJump();

    // Reiniciar Camara
    view.setCenter(winWidth / 2, winHeight / 2);
    window.setView(view);

    // Camara sigue player
    camPosition = player.getPlayerPosition();

    // Evita que salga la camara para la izquierda (x < 0)
    if (camPosition.x - winWidth / 2 < 0) camPosition.x = winWidth / 2;
    view.setCenter(camPosition.x, 358);
    window.setView(view);

    // Sistema reduccion de puntaje
    calcularPuntaje(clock, decrementIntervalo, player, elapsedTime);

    // RENDER BACKGROUNDS
    map.setMapPosition(map.getBackground(1), 0, 0);
    window.draw(map.getBackground(1));
    map.setMapPosition(map.getBackground(1), 1280, 0);
    window.draw(map.getBackground(1));
    map.setMapPosition(map.getBackground(1), 2560, 0);
    window.draw(map.getBackground(1));
    map.setMapPosition(map.getBackground(1), 3840, 0);
    window.draw(map.getBackground(1));
    map.setMapPosition(map.getBackground(1), 5120, 0);
    window.draw(map.getBackground(1));
    map.setMapPosition(map.getBackground(1), 6400, 0);
    window.draw(map.getBackground(1));
    map.setMapPosition(map.getBackground(1), 7680, 0);
    window.draw(map.getBackground(1));

    // RENDER GROUNDS
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
    map.setMapPosition(map.getGround(), 6400, 650);
    window.draw(map.getGround());

    // RENDER PLATFORMS
    map.setMapPosition(platform.getPlatform(1), 1390, 550);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(2), 1700, 550);
    window.draw(platform.getPlatform(2));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 2000, 470);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 2200, 420);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 2600, 420);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 3000, 420);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 4300, 550);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 4650, 500);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 5300, 500);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(2), 6200, 500);
    window.draw(platform.getPlatform(2));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 6000, 330);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 6400, 200);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 7200, 500);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.collisionFloorCheck(player);

    // RENDER SPIKES
    map.setMapPosition(spike.getSpikeSprites(2), 1390, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 2400, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 2800, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 3900, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 4830, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 4940, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 5050, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 5160, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 5270, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 6400, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 6510, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 6620, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 6730, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 6840, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 6950, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 7060, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 7170, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    // RENDER GEMS
    // Objeto para obtener bool para animacion de gemas
    gemAnim.getAnimationFrame();
    //
    if (gem1.getVisible()) {
        map.setMapPosition(gem1.getGemSprite(1), 2100, 420);
        map.setMapPosition(gem1.getGemSprite(2), 2100, 420);
        if (gemAnim.getAnimationFrame())
            window.draw(gem1.getGemSprite(1));
        else
            window.draw(gem1.getGemSprite(2));
    }
    if (gem2.getVisible()) {
        map.setMapPosition(gem2.getGemSprite(1), 2570, 300);
        map.setMapPosition(gem2.getGemSprite(2), 2570, 300);
        if (gemAnim.getAnimationFrame())
            window.draw(gem2.getGemSprite(1));
        else
            window.draw(gem2.getGemSprite(2));
    }
    if (gem3.getVisible()) {
        map.setMapPosition(gem3.getGemSprite(1), 3000, 300);
        map.setMapPosition(gem3.getGemSprite(2), 3000, 300);
        if (gemAnim.getAnimationFrame())
            window.draw(gem3.getGemSprite(1));
        else
            window.draw(gem3.getGemSprite(2));
    }
    if (gem4.getVisible()) {
        map.setMapPosition(gem4.getGemSprite(1), 3500, 400);
        map.setMapPosition(gem4.getGemSprite(2), 3500, 400);
        if (gemAnim.getAnimationFrame())
            window.draw(gem4.getGemSprite(1));
        else
            window.draw(gem4.getGemSprite(2));
    }
    if (gem5.getVisible()) {
        map.setMapPosition(gem5.getGemSprite(1), 4000, 500);
        map.setMapPosition(gem5.getGemSprite(2), 4000, 500);
        if (gemAnim.getAnimationFrame())
            window.draw(gem5.getGemSprite(1));
        else
            window.draw(gem5.getGemSprite(2));
    }
    if (gem6.getVisible()) {
        map.setMapPosition(gem6.getGemSprite(1), 5150, 500);
        map.setMapPosition(gem6.getGemSprite(2), 5150, 500);
        if (gemAnim.getAnimationFrame())
            window.draw(gem6.getGemSprite(1));
        else
            window.draw(gem6.getGemSprite(2));
    }
    if (gem7.getVisible()) {
        map.setMapPosition(gem7.getGemSprite(1), 7050, 220);
        map.setMapPosition(gem7.getGemSprite(2), 7050, 220);
        if (gemAnim.getAnimationFrame())
            window.draw(gem7.getGemSprite(1));
        else
            window.draw(gem7.getGemSprite(2));
    }
    map.detectGemColission(player, gem1);
    map.detectGemColission(player, gem2);
    map.detectGemColission(player, gem3);
    map.detectGemColission(player, gem4);
    map.detectGemColission(player, gem5);
    map.detectGemColission(player, gem6);
    map.detectGemColission(player, gem7);

    // RENDER ENEMIES
    if (enemy.getSpawned()) {
        enemy.respawnmanual(1470, 532);
        enemy.setSpawned(false);
    }
    if (enemy.getVisible()) {
        enemy.update();
        window.draw(enemy);
    }
    if (enemy2.getSpawned()) {
        enemy2.respawnmanual(2683, 402);
        enemy2.setSpawned(false);
    }
    if (enemy2.getVisible()) {
        enemy2.update();
        window.draw(enemy2);
    }
    if (enemy3.getSpawned()) {
        enemy3.respawnmanual(3082, 402);
        enemy3.setSpawned(false);
    }
    if (enemy3.getVisible()) {
        enemy3.update();
        window.draw(enemy3);
    }
    if (enemy4.getSpawned()) {
        enemy4.respawnmanual(5500, 625);
        enemy4.setSpawned(false);
    }
    if (enemy4.getVisible()) {
        enemy4.update();
        window.draw(enemy4);
    }
    if (enemy5.getSpawned()) {
        enemy5.respawnmanual(5700, 625);
        enemy5.setSpawned(false);
    }
    if (enemy5.getVisible()) {
        enemy5.update();
        window.draw(enemy5);
    }
    if (enemy6.getSpawned()) {
        enemy6.respawnmanual(6100, 625);
        enemy6.setSpawned(false);
    }
    if (enemy6.getVisible()) {
        enemy6.update();
        window.draw(enemy6);
    }
    if (enemy7.getSpawned()) {
        enemy7.respawnmanual(6300, 625);
        enemy7.setSpawned(false);
    }
    if (enemy7.getVisible()) {
        enemy7.update();
        window.draw(enemy7);
    }
    if (enemy8.getSpawned()) {
        enemy8.respawnmanual(5900, 625);
        enemy8.setSpawned(false);
    }
    if (enemy8.getVisible()) {
        enemy8.update();
        window.draw(enemy8);
    }
    map.collisionEnemyCheck(player, enemy);
    map.collisionEnemyCheck(player, enemy2);
    map.collisionEnemyCheck(player, enemy3);
    map.collisionEnemyCheck(player, enemy4);
    map.collisionEnemyCheck(player, enemy5);
    map.collisionEnemyCheck(player, enemy6);
    map.collisionEnemyCheck(player, enemy7);
    map.collisionEnemyCheck(player, enemy8);

    // RENDER DOUBLE JUMP
    if (dj.getVisible()) {
        map.setMapPosition(dj.getSprite(), 4710, 420);
        map.colissionDoubleJumpCheck(player, dj);
        window.draw(dj.getSprite());
    }

    // RENDER SPEED ITEM
    if (speedIt.getVisible()) {
        map.setMapPosition(speedIt.getSprite(), 5660, 270);
        map.detectSpeedCollision(player, speedIt);
        window.draw(speedIt.getSprite());
    }

    // CARTEL NIVEL 1
    //textNivel.setPosition(430, 200);
    //window.draw(textNivel);

    // RENDER PORTAL
    map.setMapPosition(map.getPortal(), 7500, 572);
    window.draw(map.getPortal());

    // RENDER PLAYER
    window.draw(player);

    // RENDER PUNTOS DECRECIENDO
    window.setView(window.getDefaultView());
    textPuntos.setString("Puntos:");
    window.draw(textPuntos);
    text.setString(std::to_string(player.getPuntaje()));
    text.setPosition(180, 0);
    window.draw(text);

    // RENDER PLAYER NAME
    textNuevoNombre.setPosition(600, 0);
    window.draw(textNuevoNombre);

    // RENDER HEARTS
    int currentLife = player.getCurrentLife();
    int totalLife = player.getTotalLife();
    map.renderHearts(window, currentLife, totalLife, emptyHeartTex, fullHeartTex);

    // GAME OVER
    if (player.getIsDead()) {
        map.getMusic(2).stop();
        map.getMusic(4).play();
        menu.setTipoMenu(6);     
        setGameState(1);
    }

    // Deteccion Portal + reinicio para nivel 2
    if (player.getHitbox().intersects(map.getPortal().getGlobalBounds())) {
        // Reinicio de variables
        // Camara
        view.setCenter(winWidth / 2, winHeight / 2);
        window.setView(view);
        // Power ups
        dj.setVisible(true);
        player.setHasDoubleJump(false);
        speedIt.setVisible(true);
        player.setHasSpeed(false);
        // Puntaje, vida, pos
        player.setCurrentLife(3);
        player.getPlayerSprite().setPosition(200, 500);
        // Enemies
        enemy.setSpawned(true);
        enemy.setVisible(true);
        enemy2.setSpawned(true);
        enemy2.setVisible(true);
        enemy3.setSpawned(true);
        enemy3.setVisible(true);
        enemy4.setSpawned(true);
        enemy4.setVisible(true);
        enemy5.setSpawned(true);
        enemy5.setVisible(true);
        enemy6.setSpawned(true);
        enemy6.setVisible(true);
        enemy7.setSpawned(true);
        enemy7.setVisible(true);
        enemy8.setSpawned(true);
        enemy8.setVisible(true);
        enemy9.setSpawned(true);
        enemy9.setVisible(true);
        // Gems
        gem1.setVisible(true);
        gem1.setHasBeenPicked(false);
        gem2.setVisible(true);
        gem2.setHasBeenPicked(false);
        gem3.setVisible(true);
        gem3.setHasBeenPicked(false);
        gem4.setVisible(true);
        gem4.setHasBeenPicked(false);
        gem5.setVisible(true);
        gem5.setHasBeenPicked(false);
        gem6.setVisible(true);
        gem6.setHasBeenPicked(false);
        gem7.setVisible(true);
        gem7.setHasBeenPicked(false);
        gem8.setVisible(true);
        gem8.setHasBeenPicked(false);
        gem9.setVisible(true);
        gem9.setHasBeenPicked(false);
        gem10.setVisible(true);
        gem10.setHasBeenPicked(false);
        gem11.setVisible(true);
        gem11.setHasBeenPicked(false);
        gem12.setVisible(true);
        gem12.setHasBeenPicked(false);
        // Otros
        level2MusicBD = true;
        setGameState(4);
    }

}

void GameScene::Level2(sf::RenderWindow& window, sf::View& view) {
    if (level2MusicBD) {
        map.getMusic(2).stop();
        map.getMusic(3).play();
        map.getMusic(3).setLoop(1);
        level2MusicBD = false;
    }
    // Player update
    player.update();
    player.moveJump();

    // Reiniciar Camara
    view.setCenter(winWidth / 2, winHeight / 2);
    window.setView(view);

    // Camara sigue player
    camPosition = player.getPlayerPosition();

    // Evita que salga la camara para la izquierda (x < 0)
    if (camPosition.x - winWidth / 2 < 0) camPosition.x = winWidth / 2;
    view.setCenter(camPosition.x, 358);
    window.setView(view);

    // Sistema reduccion de puntaje
    calcularPuntaje(clock, decrementIntervalo, player, elapsedTime);

    // RENDER BACKGROUNDS
    map.setMapPosition(map.getBackground(2), 0, 0);
    window.draw(map.getBackground(2));
    map.setMapPosition(map.getBackground(2), 1280, 0);
    window.draw(map.getBackground(2));
    map.setMapPosition(map.getBackground(2), 2560, 0);
    window.draw(map.getBackground(2));
    map.setMapPosition(map.getBackground(3), 3840, 0);
    window.draw(map.getBackground(3));
    map.setMapPosition(map.getBackground(2), 5120, 0);
    window.draw(map.getBackground(2));
    map.setMapPosition(map.getBackground(2), 6400, 0);
    window.draw(map.getBackground(2));
    map.setMapPosition(map.getBackground(2), 7680, 0);
    window.draw(map.getBackground(2));

    // RENDER GROUNDS
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
    map.setMapPosition(map.getGround(), 6400, 650);
    window.draw(map.getGround());

    map.collisionFloorCheck(player);

    // RENDER PLATFORMS
    map.setMapPosition(platform.getPlatform(1), 150, 550);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 500, 500);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 900, 500);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 1230, 400);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(2), 1230, 300);
    window.draw(platform.getPlatform(2));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 1550, 200);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 1740, 550);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 2240, 385);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 2690, 550);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(2), 3300, 550);
    window.draw(platform.getPlatform(2));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 3550, 400);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 4400, 550);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 5150, 420);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 6000, 420);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 6770, 420);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 7400, 360);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    // RENDER SPIKES FIVE
    map.setMapPosition(spike.getSpikeSprites(2), 0, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 110, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 220, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 330, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 440, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 740, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 1260, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 1480, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 1990, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 2100, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 2210, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 2320, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 2430, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 2540, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 2900, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 3010, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 3120, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 4150, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 4260, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 4700, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 4810, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 5000, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 5110, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 5300, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 5410, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 5800, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 5910, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 6200, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 6400, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 6700, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 6810, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 7400, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(2), 7510, 625);
    window.draw(spike.getSpikeSprites(2));
    map.collisionSpikeCheck(player, spike);

    // RENDER SPIKES ONE
    map.setMapPosition(spike.getSpikeSprites(1), 780, 425);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 1180, 300);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 1445, 300);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 2080, 470);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 2500, 400);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 2500, 450);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 2500, 500);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 2630, 180);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 2630, 230);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 2630, 280);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 2630, 330);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 2630, 380);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 2630, 430);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 3100, 290);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 3100, 410);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 3250, 605);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 3500, 420);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 3500, 470);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 3500, 520);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 3765, 420);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 3765, 470);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 3765, 520);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 3765, 570);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 3820, 570);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 3875, 570);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 3930, 570);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 3985, 400);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 4040, 570);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 4095, 570);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 5650, 390);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeSprites(1), 6500, 320);
    window.draw(spike.getSpikeSprites(1));
    map.collisionSpikeCheck(player, spike);

    // RENDER ENEMIES
    if (enemy.getSpawned()) {
        enemy.respawnmanual(586, 480);
        enemy.setSpawned(false);
    }
    if (enemy.getVisible()) {
        enemy.update();
        window.draw(enemy);
    }
    if (enemy2.getSpawned()) {
        enemy2.respawnmanual(985, 480);
        enemy2.setSpawned(false);
    }
    if (enemy2.getVisible()) {
        enemy2.update();
        window.draw(enemy2);
    }
    if (enemy3.getSpawned()) {
        enemy3.respawnmanual(1310, 283);
        enemy3.setSpawned(false);
    }
    if (enemy3.getVisible()) {
        enemy3.update();
        window.draw(enemy3);
    }
    if (enemy4.getSpawned()) {
        enemy4.respawnmanual(1700, 629);
        enemy4.setSpawned(false);
    }
    if (enemy4.getVisible()) {
        enemy4.update();
        window.draw(enemy4);
    }
    if (enemy5.getSpawned()) {
        enemy5.respawnmanual(2800, 531);
        enemy5.setSpawned(false);
    }
    if (enemy5.getVisible()) {
        enemy5.update();
        window.draw(enemy5);
    }
    if (enemy6.getSpawned()) {
        enemy6.respawnmanual(3380, 531);
        enemy6.setSpawned(false);
    }
    if (enemy6.getVisible()) {
        enemy6.update();
        window.draw(enemy6);
    }
    if (enemy7.getSpawned()) {
        enemy7.respawnmanual(3700, 629);
        enemy7.setSpawned(false);
    }
    if (enemy7.getVisible()) {
        enemy7.update();
        window.draw(enemy7);
    }
    if (enemy8.getSpawned()) {
        enemy8.respawnmanual(5250, 400);
        enemy8.setSpawned(false);
    }
    if (enemy8.getVisible()) {
        enemy8.update();
        window.draw(enemy8);
    }
    if (enemy9.getSpawned()) {
        enemy9.respawnmanual(6850, 400);
        enemy9.setSpawned(false);
    }
    if (enemy9.getVisible()) {
        enemy9.update();
        window.draw(enemy9);
    }
    map.collisionEnemyCheck(player, enemy);
    map.collisionEnemyCheck(player, enemy2);
    map.collisionEnemyCheck(player, enemy3);
    map.collisionEnemyCheck(player, enemy4);
    map.collisionEnemyCheck(player, enemy5);
    map.collisionEnemyCheck(player, enemy6);
    map.collisionEnemyCheck(player, enemy7);
    map.collisionEnemyCheck(player, enemy8);
    map.collisionEnemyCheck(player, enemy9);

    // RENDER GEMS
    // Objeto para obtener bool para animacion de gemas
    gemAnim.getAnimationFrame();
    //
    if (gem1.getVisible()) {
        map.setMapPosition(gem1.getGemSprite(1), 400, 420);
        map.setMapPosition(gem1.getGemSprite(2), 400, 420);
        if (gemAnim.getAnimationFrame())
            window.draw(gem1.getGemSprite(1));
        else
            window.draw(gem1.getGemSprite(2));
    }
    if (gem2.getVisible()) {
        map.setMapPosition(gem2.getGemSprite(1), 1580, 150);
        map.setMapPosition(gem2.getGemSprite(2), 1580, 150);
        if (gemAnim.getAnimationFrame())
            window.draw(gem2.getGemSprite(1));
        else
            window.draw(gem2.getGemSprite(2));
    }
    if (gem3.getVisible()) {
        map.setMapPosition(gem3.getGemSprite(1), 1680, 150);
        map.setMapPosition(gem3.getGemSprite(2), 1680, 150);
        if (gemAnim.getAnimationFrame())
            window.draw(gem3.getGemSprite(1));
        else
            window.draw(gem3.getGemSprite(2));
    }
    if (gem4.getVisible()) {
        map.setMapPosition(gem4.getGemSprite(1), 2560, 400);
        map.setMapPosition(gem4.getGemSprite(2), 2560, 400);
        if (gemAnim.getAnimationFrame())
            window.draw(gem4.getGemSprite(1));
        else
            window.draw(gem4.getGemSprite(2));
    }
    if (gem5.getVisible()) {
        map.setMapPosition(gem5.getGemSprite(1), 2560, 500);
        map.setMapPosition(gem5.getGemSprite(2), 2560, 500);
        if (gemAnim.getAnimationFrame())
            window.draw(gem5.getGemSprite(1));
        else
            window.draw(gem5.getGemSprite(2));
    }
    if (gem6.getVisible()) {
        map.setMapPosition(gem6.getGemSprite(1), 3095, 350);
        map.setMapPosition(gem6.getGemSprite(2), 3095, 350);
        if (gemAnim.getAnimationFrame())
            window.draw(gem6.getGemSprite(1));
        else
            window.draw(gem6.getGemSprite(2));
    }
    if (gem7.getVisible()) {
        map.setMapPosition(gem7.getGemSprite(1), 3570, 470);
        map.setMapPosition(gem7.getGemSprite(2), 3570, 470);
        if (gemAnim.getAnimationFrame())
            window.draw(gem7.getGemSprite(1));
        else
            window.draw(gem7.getGemSprite(2));
    }
    if (gem8.getVisible()) {
        map.setMapPosition(gem8.getGemSprite(1), 3670, 470);
        map.setMapPosition(gem8.getGemSprite(2), 3670, 470);
        if (gemAnim.getAnimationFrame())
            window.draw(gem8.getGemSprite(1));
        else
            window.draw(gem8.getGemSprite(2));
    }
    if (gem9.getVisible()) {
        map.setMapPosition(gem9.getGemSprite(1), 3570, 540);
        map.setMapPosition(gem9.getGemSprite(2), 3570, 540);
        if (gemAnim.getAnimationFrame())
            window.draw(gem9.getGemSprite(1));
        else
            window.draw(gem9.getGemSprite(2));
    }
    if (gem10.getVisible()) {
        map.setMapPosition(gem10.getGemSprite(1), 3670, 540);
        map.setMapPosition(gem10.getGemSprite(2), 3670, 540);
        if (gemAnim.getAnimationFrame())
            window.draw(gem10.getGemSprite(1));
        else
            window.draw(gem10.getGemSprite(2));
    }
    if (gem11.getVisible()) {
        map.setMapPosition(gem11.getGemSprite(1), 5644, 330);
        map.setMapPosition(gem11.getGemSprite(2), 5644, 330);
        if (gemAnim.getAnimationFrame())
            window.draw(gem11.getGemSprite(1));
        else
            window.draw(gem11.getGemSprite(2));
    }
    if (gem12.getVisible()) {
        map.setMapPosition(gem12.getGemSprite(1), 6494, 390);
        map.setMapPosition(gem12.getGemSprite(2), 6494, 390);
        if (gemAnim.getAnimationFrame())
            window.draw(gem12.getGemSprite(1));
        else
            window.draw(gem12.getGemSprite(2));
    }
    map.detectGemColission(player, gem1);
    map.detectGemColission(player, gem2);
    map.detectGemColission(player, gem3);
    map.detectGemColission(player, gem4);
    map.detectGemColission(player, gem5);
    map.detectGemColission(player, gem6);
    map.detectGemColission(player, gem7);
    map.detectGemColission(player, gem8);
    map.detectGemColission(player, gem9);
    map.detectGemColission(player, gem10);
    map.detectGemColission(player, gem11);
    map.detectGemColission(player, gem12);

    // RENDER DOUBLE JUMP
    if (dj.getVisible()) {
        map.setMapPosition(dj.getSprite(), 1800, 470);
        map.colissionDoubleJumpCheck(player, dj);
        window.draw(dj.getSprite());
    }

    // RENDER SPEED ITEM
    if (speedIt.getVisible()) {
        map.setMapPosition(speedIt.getSprite(), 3605, 320);
        map.detectSpeedCollision(player, speedIt);
        window.draw(speedIt.getSprite());
    }

    // RENDER PORTAL
    map.setMapPosition(map.getPortal(), 7500, 280);
    window.draw(map.getPortal());

    // RENDER PLAYER
    window.draw(player);

    // RENDER PUNTOS DECRECIENDO
    window.setView(window.getDefaultView());
    textPuntos.setString("Puntos:");
    window.draw(textPuntos);
    text.setString(std::to_string(player.getPuntaje()));
    text.setPosition(180, 0);
    window.draw(text);

    // RENDER PLAYER NAME
    textNuevoNombre.setPosition(600, 0);
    window.draw(textNuevoNombre);

    // RENDER HEARTS
    int currentLife = player.getCurrentLife();
    int totalLife = player.getTotalLife();
    map.renderHearts(window, currentLife, totalLife, emptyHeartTex, fullHeartTex);

    // GAME OVER    
    if (player.getIsDead()) {
        map.getMusic(3).stop();
        map.getMusic(4).play();
        menu.setTipoMenu(6);
        setGameState(1);
    }

    // Deteccion Portal + reinicio fin del juego     
    if (player.getHitbox().intersects(map.getPortal().getGlobalBounds())) {
        // Reinicio de variables
        // Camara
        view.setCenter(winWidth / 2, winHeight / 2);
        window.setView(view);
        // Power ups
        dj.setVisible(true);
        player.setHasDoubleJump(true);
        speedIt.setVisible(true);
        player.setHasSpeed(true);
        // Puntaje, vida, pos
        player.setCurrentLife(3);
        player.getPlayerSprite().setPosition(200, 500);
        // Enemies
        enemy.setSpawned(true);
        enemy.setVisible(true);
        enemy2.setSpawned(true);
        enemy2.setVisible(true);
        enemy3.setSpawned(true);
        enemy3.setVisible(true);
        enemy4.setSpawned(true);
        enemy4.setVisible(true);
        enemy5.setSpawned(true);
        enemy5.setVisible(true);
        enemy6.setSpawned(true);
        enemy6.setVisible(true);
        enemy7.setSpawned(true);
        enemy7.setVisible(true);
        enemy8.setSpawned(true);
        enemy8.setVisible(true);
        enemy9.setSpawned(true);
        enemy9.setVisible(true);
        // Gems
        gem1.setVisible(true);
        gem1.setHasBeenPicked(false);
        gem2.setVisible(true);
        gem2.setHasBeenPicked(false);
        gem3.setVisible(true);
        gem3.setHasBeenPicked(false);
        gem4.setVisible(true);
        gem4.setHasBeenPicked(false);
        gem5.setVisible(true);
        gem5.setHasBeenPicked(false);
        gem6.setVisible(true);
        gem6.setHasBeenPicked(false);
        gem7.setVisible(true);
        gem7.setHasBeenPicked(false);
        gem8.setVisible(true);
        gem8.setHasBeenPicked(false);
        gem9.setVisible(true);
        gem9.setHasBeenPicked(false);
        gem10.setVisible(true);
        gem10.setHasBeenPicked(false);
        gem11.setVisible(true);
        gem11.setHasBeenPicked(false);
        gem12.setVisible(true);
        gem12.setHasBeenPicked(false);
        bossLevelMusicBD = true;
        setGameState(5);
    }
}

void GameScene::BossLevel(sf::RenderWindow & window, sf::View & view) {
    if (bossLevelMusicBD) {
        map.getMusic(3).stop();
        map.getMusic(6).play();
        map.getMusic(6).setLoop(1);
        bossLevelMusicBD = false;
    }
    // Player update
    player.update();
    player.moveJump();
    // Limite right antes
    if ((player.getPlayerSprite().getPosition().x + player.getPlayerSprite().getGlobalBounds().width) > 1280) {
        player.getPlayerSprite().setPosition(1280 - player.getPlayerSprite().getGlobalBounds().width, player.getPlayerSprite().getPosition().y);
    }

    // Reiniciar Camara
    view.setCenter(winWidth / 2, winHeight / 2);
    window.setView(view);

    // Camara sigue player
    camPosition = player.getPlayerPosition();

    // Evita que salga la camara para la izquierda (x < 0)
    if (camPosition.x - winWidth / 2 < 0) camPosition.x = winWidth / 2;
    else if (camPosition.x + winWidth / 2 > 1280) camPosition.x = 1280 - winWidth / 2;
    view.setCenter(camPosition.x, 358);
    window.setView(view);

    // Sistema reduccion de puntaje
    calcularPuntaje(clock, decrementIntervalo, player, elapsedTime);

    // RENDER BACKGROUND
    if (bossEnemy.getVisible()) {
        map.setMapPosition(map.getBackground(4), 0, 0);
        window.draw(map.getBackground(4));
    }
    else {
        map.setMapPosition(map.getBackground(1), 0, 0);
        window.draw(map.getBackground(1));
    }

    // RENDER GROUNDS
    map.setMapPosition(map.getGround(), 0, 650);
    window.draw(map.getGround());
    map.setMapPosition(map.getGround(), 1280, 650);
    window.draw(map.getGround());

    map.collisionFloorCheck(player);

    // RENDER BOSS
    if (bossEnemy.getSpawned()) {
        bossEnemy.spawnBoss(630, 520);
        bossEnemy.setSpawned(false);
    }
    if (bossEnemy.getVisible()) {
        bossEnemy.bossUpdate();
        window.draw(bossEnemy.getBossSprite());
    }

    map.collisionBossCheck(player, bossEnemy);

    // RENDER PLATFORMS
    map.setMapPosition(platform.getPlatform(1), 10, 480);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 230, 300);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 855, 300);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.setMapPosition(platform.getPlatform(1), 1080, 480);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    // RENDER PLAYER
    window.draw(player);

    // RENDER PUNTOS DECRECIENDO
    window.setView(window.getDefaultView());
    textPuntos.setString("Puntos:");
    window.draw(textPuntos);
    text.setString(std::to_string(player.getPuntaje()));
    text.setPosition(180, 0);
    window.draw(text);

    // RENDER PLAYER NAME
    textNuevoNombre.setPosition(600, 0);
    window.draw(textNuevoNombre);

    // RENDER HEARTS
    int currentLife = player.getCurrentLife();
    int totalLife = player.getTotalLife();
    map.renderHearts(window, currentLife, totalLife, emptyHeartTex, fullHeartTex);

    // GAME OVER    
    if (player.getIsDead()) {
        map.getMusic(3).stop();
        map.getMusic(4).play();
        menu.setTipoMenu(6);
        setGameState(1);
    }

    // BOSS DEFEATED
    if (!bossEnemy.getVisible()) {
        if (winningMusicBD) {
            clockBoss.restart();
            map.getMusic(6).stop();
            map.getMusic(7).play();
            winningMusicBD = false;
        }
        if (clockBoss.getElapsedTime().asSeconds() > getBossDefeatedTime()) {
            setGameState(6);
            bossEnemy.setSpawned(true);
            bossEnemy.setVisible(true);
            bossEnemy.setVidaBoss(3);
            winningMusicBD = true;
            // Reinicio de variables
            // Camara
            view.setCenter(winWidth / 2, winHeight / 2);
            window.setView(view);
            // Power ups
            dj.setVisible(true);
            player.setHasDoubleJump(false);
            speedIt.setVisible(true);
            player.setHasSpeed(false);
            // Puntaje, vida, pos
            player.setCurrentLife(3);
            player.getPlayerSprite().setPosition(200, 500);
            menuMusicBD = true;
        }
    }


}

void GameScene::DataScreen(sf::RenderWindow& window, sf::View& view) {
    window.draw(menu.getMenu2Back());
    textGracias.setPosition(500, 150);
    window.draw(textGracias);
    textNuevoNombre.setPosition(600, 240);
    window.draw(textNuevoNombre);
    textPuntosFinal = text;
    textPuntosFinal.setPosition(600, 300);
    window.draw(textPuntosFinal);
    textEnter.setPosition(300, 600);
    window.draw(textEnter);
    // Guardar datos
    data.setNombre(nuevoNombre.c_str());
    puntaje = textPuntosFinal.getString();
    data.setPuntaje(std::stoi(puntaje));
    //
    archive.leerRank(vecData);
    if (!agregado) {
        archive.agregarRank(data, vecData);
        agregado = true;
    }

    // Enter para continuar
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && enterReleased) {
        menu.setOpc(1);
        menu.setTipoMenu(1);
        menu.setComenzar(0);
        menu.setSalir(0);
        setGameState(1);
        nuevoNombre = "";
        player.setPuntaje(1010);
        enterReleased = false;
        agregado = false;
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) enterReleased = true;

}