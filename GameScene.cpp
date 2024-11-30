#include "GameScene.h"

// Constructor
GameScene::GameScene() {
    // Hearts
    emptyHeartTex.loadFromFile("images\\empty_heart.png");
    fullHeartTex.loadFromFile("images\\full_heart.png");

    // Textos
    sf::Color color(0xD1CB95FF);
    font.loadFromFile("pixel.otf");

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

    winWidth = 1280.0f, winHeight = 720.0f;
    setGameState(1);
    vecData = new DataPlayer[cantReg];

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

// METODOS DE LA ESTRUCTURA DEL JUEGO

void GameScene::GameMenu(sf::RenderWindow& window, sf::View& view, sf::Event& event) {
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
        view.setCenter(winWidth / 2, winHeight / 2);
        window.setView(view);
        nuevoNombre = "";
        player.setIsDead(0);
        menu.setComenzar(0);
        menu.setSalir(0);
    }
}

void GameScene::Tutorial(sf::RenderWindow& window, sf::View& view) {
    // Player update
    player.update();
    player.moveJump();

    // Camara sigue player
    camPosition = player.getPlayerPosition();

    // Evita que salga la camara para la izquierda (x < 0)
    if (camPosition.x - winWidth / 2 < 0) camPosition.x = winWidth / 2;
    view.setCenter(camPosition.x, 358);
    window.setView(view);

    // Sistema de reduccion de puntaje
    int puntos = player.getPuntaje();
    elapsedTime += clock.restart().asSeconds(); // Reinicia el reloj y suma el tiempo transcurrido
    if (elapsedTime >= decrementIntervalo) {
        player.quitarPuntaje(10); // Reduce el puntaje cada segundo
        elapsedTime = 0.0f; // Reinicia el contador
        if (puntos < 0) {
            player.setPuntaje(0);
        }
    }

    // RENDER BACKGROUNDS
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
    map.setMapPosition(map.getBackground(), 6400, 0);
    window.draw(map.getBackground());
    map.setMapPosition(map.getBackground(), 7680, 0);
    window.draw(map.getBackground());

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
    map.setMapPosition(map.getChat(), 3800, 200);
    window.draw(map.getChat());
    map.setChatSprite(6);
    map.setMapPosition(map.getChat(), 5000, 200);
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

    platform.setPlatPosition(3300, 500);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    platform.setPlatPosition(3600, 350);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    platform.setPlatPosition(6200, 500);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    platform.setPlatPosition(6550, 350);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    platform.setPlatPosition(7000, 350);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    // RENDER SPIKES
    map.setMapPosition(spike.getSpikeFive(), 6820, 625);
    window.draw(spike.getSpikeFive());
    map.collisionSpikeCheck(player, spike);

    // RENDER GEMS
    if (gem1.getVisible()) {
        map.setMapPosition(gem1.getGemSprite(), 950, 550);
        window.draw(gem1.getGemSprite());
    }
    if (gem2.getVisible()) {
        map.setMapPosition(gem2.getGemSprite(), 1600, 480);
        window.draw(gem2.getGemSprite());
    }
    if (gem3.getVisible()) {
        map.setMapPosition(gem3.getGemSprite(), 2800, 400);
        window.draw(gem3.getGemSprite());
    }
    if (gem4.getVisible()) {
        map.setMapPosition(gem4.getGemSprite(), 3500, 400);
        window.draw(gem4.getGemSprite());
    }
    if (gem5.getVisible()) {
        map.setMapPosition(gem5.getGemSprite(), 4000, 500);
        window.draw(gem5.getGemSprite());
    }
    if (gem6.getVisible()) {
        map.setMapPosition(gem6.getGemSprite(), 5000, 550);
        window.draw(gem6.getGemSprite());
    }
    if (gem7.getVisible()) {
        map.setMapPosition(gem7.getGemSprite(), 7050, 220);
        window.draw(gem7.getGemSprite());
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
        map.setMapPosition(dj.getDoubleJumpSprite(), 1850, 420);
        map.colissionDoubleJumpCheck(player, dj);
        window.draw(dj.getDoubleJumpSprite());
    }

    // RENDER SPEED ITEM
    if (speedIt.getVisible()) {
        map.setMapPosition(speedIt.getSpeedSprite(), 3650, 270);
        map.detectSpeedCollision(player, speedIt);
        window.draw(speedIt.getSpeedSprite());
    }

    // RENDER PORTAL
    map.setMapPosition(map.getPortal(), 7500, 572);
    window.draw(map.getPortal());

    // RENDER PLAYER
    window.draw(player);

    // RENDER PLAYER NAME
    textNuevoNombre.setPosition(600, 0);
    window.draw(textNuevoNombre);

    // RENDER PUNTOS DECRECIENDO
    window.setView(window.getDefaultView());
    textPuntos.setString("Puntos:");
    window.draw(textPuntos);
    text.setString(std::to_string(puntos));
    text.setPosition(180, 0);
    window.draw(text);

    // RENDER HEARTS
    int currentLife = player.getCurrentLife();
    int totalLife = player.getTotalLife();
    map.renderHearts(window, currentLife, totalLife, emptyHeartTex, fullHeartTex);

    // GAME OVER
    if (player.getIsDead()) {
        map.getMusic(3).play();
        menu.setTipoMenu(6);
        player.setCurrentLife(3);
        player.setPuntaje(1010);
        player.getPlayerSprite().setPosition(200, 500);
        enemy.setSpawned(true);
        enemy.setVisible(true);
        enemy2.setSpawned(true);
        enemy2.setVisible(true);
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
        player.setCurrentLife(3);
        enemy.setSpawned(true);
        enemy.setVisible(true);
        enemy2.setSpawned(true);
        enemy2.setVisible(true);
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
        dj.setVisible(true);
        player.setHasDoubleJump(false);
        speedIt.setVisible(true);
        player.setHasSpeed(false);
        player.getPlayerSprite().setPosition(200, 500);
        setGameState(3);
    }
}

void GameScene::Level1(sf::RenderWindow& window, sf::View& view) {
    std::cout << player.getPlayerPosition().x << std::endl;
    std::cout << "y: " << player.getPlayerPosition().y << std::endl;

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
    int puntos = player.getPuntaje();
    elapsedTime += clock.restart().asSeconds(); // Reinicia el reloj y suma el tiempo transcurrido
    if (elapsedTime >= decrementIntervalo) {
        player.quitarPuntaje(10); // Reduce el puntaje cada segundo
        elapsedTime = 0.0f; // Reinicia el contador
        if (puntos <= 0) {
            player.setPuntaje(0);
        }
    }

    // RENDER BACKGROUNDS
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
    map.setMapPosition(map.getBackground(), 6400, 0);
    window.draw(map.getBackground());
    map.setMapPosition(map.getBackground(), 7680, 0);
    window.draw(map.getBackground());

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
    platform.setPlatPosition(1390, 550);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    platform.setPlatPosition(1700, 550);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    platform.setPlatPosition(2000, 470);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    platform.setPlatPosition(2200, 420);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    platform.setPlatPosition(2600, 420);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    platform.setPlatPosition(3000, 420);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    platform.setPlatPosition(4300, 550);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    platform.setPlatPosition(4650, 500);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    platform.setPlatPosition(5300, 500);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    platform.setPlatPosition(6200, 500);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    platform.setPlatPosition(6000, 330);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    platform.setPlatPosition(6400, 200);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    platform.setPlatPosition(7200, 500);
    window.draw(platform.getPlatform(1));
    map.collisionPlatCheck(player, platform);

    map.collisionFloorCheck(player);

    // RENDER SPIKES
    map.setMapPosition(spike.getSpikeFive(), 1390, 625);
    window.draw(spike.getSpikeFive());
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeFive(), 2400, 625);
    window.draw(spike.getSpikeFive());
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeFive(), 2800, 625);
    window.draw(spike.getSpikeFive());
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeFive(), 3900, 625);
    window.draw(spike.getSpikeFive());
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeFive(), 4830, 625);
    window.draw(spike.getSpikeFive());
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeFive(), 4940, 625);
    window.draw(spike.getSpikeFive());
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeFive(), 5050, 625);
    window.draw(spike.getSpikeFive());
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeFive(), 5160, 625);
    window.draw(spike.getSpikeFive());
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeFive(), 5270, 625);
    window.draw(spike.getSpikeFive());
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeFive(), 6400, 625);
    window.draw(spike.getSpikeFive());
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeFive(), 6510, 625);
    window.draw(spike.getSpikeFive());
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeFive(), 6620, 625);
    window.draw(spike.getSpikeFive());
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeFive(), 6730, 625);
    window.draw(spike.getSpikeFive());
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeFive(), 6840, 625);
    window.draw(spike.getSpikeFive());
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeFive(), 6950, 625);
    window.draw(spike.getSpikeFive());
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeFive(), 7060, 625);
    window.draw(spike.getSpikeFive());
    map.collisionSpikeCheck(player, spike);

    map.setMapPosition(spike.getSpikeFive(), 7170, 625);
    window.draw(spike.getSpikeFive());
    map.collisionSpikeCheck(player, spike);

    // RENDER GEMS
    if (gem1.getVisible()) {
        map.setMapPosition(gem1.getGemSprite(), 2100, 420);
        window.draw(gem1.getGemSprite());
    }
    if (gem2.getVisible()) {
        map.setMapPosition(gem2.getGemSprite(), 2570, 300);
        window.draw(gem2.getGemSprite());
    }
    if (gem3.getVisible()) {
        map.setMapPosition(gem3.getGemSprite(), 3000, 300);
        window.draw(gem3.getGemSprite());
    }
    if (gem4.getVisible()) {
        map.setMapPosition(gem4.getGemSprite(), 3500, 400);
        window.draw(gem4.getGemSprite());
    }
    if (gem5.getVisible()) {
        map.setMapPosition(gem5.getGemSprite(), 4000, 500);
        window.draw(gem5.getGemSprite());
    }
    if (gem6.getVisible()) {
        map.setMapPosition(gem6.getGemSprite(), 5100, 500);
        window.draw(gem6.getGemSprite());
    }
    if (gem7.getVisible()) {
        map.setMapPosition(gem7.getGemSprite(), 7050, 220);
        window.draw(gem7.getGemSprite());
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
        map.setMapPosition(dj.getDoubleJumpSprite(), 4700, 420);
        map.colissionDoubleJumpCheck(player, dj);
        window.draw(dj.getDoubleJumpSprite());
    }

    // RENDER SPEED ITEM
    if (speedIt.getVisible()) {
        map.setMapPosition(speedIt.getSpeedSprite(), 5650, 270);
        map.detectSpeedCollision(player, speedIt);
        window.draw(speedIt.getSpeedSprite());
    }

    // CARTEL NIVEL 1
    textNivel.setPosition(430, 200);
    window.draw(textNivel);

    // RENDER PORTAL
    map.setMapPosition(map.getPortal(), 7500, 572);
    window.draw(map.getPortal());

    // RENDER PLAYER
    window.draw(player);

    // RENDER PLAYER NAME
    textNuevoNombre.setPosition(600, 0);
    window.draw(textNuevoNombre);

    // RENDER PUNTOS DECRECIENDO
    window.setView(window.getDefaultView());
    textPuntos.setString("Puntos:");
    window.draw(textPuntos);
    text.setString(std::to_string(puntos));
    text.setPosition(180, 0);
    window.draw(text);

    // RENDER HEARTS
    int currentLife = player.getCurrentLife();
    int totalLife = player.getTotalLife();
    map.renderHearts(window, currentLife, totalLife, emptyHeartTex, fullHeartTex);

    // GAME OVER
    if (player.getIsDead()) {
        map.getMusic(2).stop();
        map.getMusic(3).play();
        menu.setTipoMenu(6);
        player.setCurrentLife(3);
        player.setPuntaje(1010);
        player.getPlayerSprite().setPosition(200, 500);
        setGameState(1);
    }

    // Deteccion Portal       
    if (player.getHitbox().intersects(map.getPortal().getGlobalBounds())) {
        player.setCurrentLife(3);
        player.setHasSpeed(false);
        player.setHasDoubleJump(false);
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
        dj.setVisible(true);
        speedIt.setVisible(true);
        map.getMusic(4).play();
        player.getPlayerSprite().setPosition(200, 500);
        setGameState(4);
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