#include <SFML/Graphics.hpp>
#include "MenuScene.h"
#include <iostream>

// Constructor
MenuScene::MenuScene() {
	// Background
	MenuScene::menuTexture.loadFromFile("images\\backMenu.png");
	MenuScene::menuSprite.setTexture(menuTexture);
	MenuScene::menuTexture2.loadFromFile("images\\backMenu2.png");
	MenuScene::menuSprite2.setTexture(menuTexture2);
	MenuScene::gameOverTexture.loadFromFile("images\\gameOver.png");
	MenuScene::gameOverSprite.setTexture(gameOverTexture);
	// Buttons
	MenuScene::jugarTexture.loadFromFile("images\\jugarButton.png");
	MenuScene::jugarSprite.setTexture(jugarTexture);
	jugarSprite.setPosition(400, 400);
	MenuScene::salirTexture.loadFromFile("images\\salirButton.png");
	MenuScene::salirSprite.setTexture(salirTexture);
	salirSprite.setPosition(400, 520);
	MenuScene::comenzarTexture.loadFromFile("images\\comenzarButton.png");
	MenuScene::comenzarSprite.setTexture(comenzarTexture);
	comenzarSprite.setPosition(550, 100);
	MenuScene::rankTexture.loadFromFile("images\\rankButton.png");
	MenuScene::rankSprite.setTexture(rankTexture);
	rankSprite.setPosition(550, 260);
	MenuScene::volverTexture.loadFromFile("images\\volverButton.png");
	MenuScene::volverSprite.setTexture(volverTexture);
	volverSprite.setPosition(550, 400);
	// Selected Buttons
	MenuScene::jugarSelTexture.loadFromFile("images\\jugarSelected.png");
	MenuScene::jugarSelSprite.setTexture(jugarSelTexture);
	jugarSelSprite.setPosition(400, 400);
	MenuScene::salirSelTexture.loadFromFile("images\\salirSelected.png");
	MenuScene::salirSelSprite.setTexture(salirSelTexture);
	salirSelSprite.setPosition(400, 520);
	MenuScene::comenzarSelTexture.loadFromFile("images\\comenzarSelected.png");
	MenuScene::comenzarSelSprite.setTexture(comenzarSelTexture);
	comenzarSelSprite.setPosition(550, 100);
	MenuScene::rankSelTexture.loadFromFile("images\\rankSelected.png");
	MenuScene::rankSelSprite.setTexture(rankSelTexture);
	rankSelSprite.setPosition(550, 260);
	MenuScene::volverSelTexture.loadFromFile("images\\volverSelected.png");
	MenuScene::volverSelSprite.setTexture(volverSelTexture);
	volverSelSprite.setPosition(550, 400);

	// Audio
	soundSel.openFromFile("audio\\menuSel.mp3");
}

// Getters generales
int MenuScene::getOpc() { return opcionMenu; }
int MenuScene::getTipoMenu() { return tipoMenu; }
bool MenuScene::getSalir() { return salir; }
bool MenuScene::getComenzar() { return comenzar; }

// Getters sprites
sf::Sprite& MenuScene::getMenuBack() { return menuSprite; }
sf::Sprite& MenuScene::getMenu2Back() { return menuSprite2; }
sf::Sprite& MenuScene::getGameOver() { return gameOverSprite; }
sf::Sprite& MenuScene::getJugarSelButton() { return jugarSelSprite; }
sf::Sprite& MenuScene::getJugarButton() { return jugarSprite; }
sf::Sprite& MenuScene::getSalirButton() { return salirSprite; }
sf::Sprite& MenuScene::getSalirSelButton() { return salirSelSprite; }
sf::Sprite& MenuScene::getComenzarButton() { return comenzarSprite; }
sf::Sprite& MenuScene::getComenzarSelButton() { return comenzarSelSprite; }
sf::Sprite& MenuScene::getRankButton() { return rankSprite; }
sf::Sprite& MenuScene::getRankSelButton() { return rankSelSprite; }
sf::Sprite& MenuScene::getVolverButton() { return volverSprite; }
sf::Sprite& MenuScene::getVolverSelButton() { return volverSelSprite; }

// Setters
void MenuScene::setOpc(int v) {
	opcionMenu = v;
}
void MenuScene::setSalir(int v) {
	salir = v;
}
void MenuScene::setComenzar(int v) {
	comenzar = v;
}
void MenuScene::setTipoMenu(int v) {
	tipoMenu = v;
}

// Comando menu 1
// keyReleased y enterReleased validan que aunque se mantenga presionada la tecla, cuente como una sola accion
void MenuScene::MenuUpdate() {
	if (tipoMenu == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			opcionMenu = 1;
			soundSel.play();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			opcionMenu = 2;
			soundSel.play();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (opcionMenu == 1 && enterReleased) {
				setTipoMenu(2);
				opcionMenu = 3;
				enterReleased = false;
			}
			else if (opcionMenu == 2 && enterReleased) {
				setSalir(1);
				enterReleased = false;
			}
		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) enterReleased = true;
	}
	// Comando menu 2
	if (tipoMenu == 2) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && keyReleased) {
			if (opcionMenu != 3) opcionMenu--;
			soundSel.play();
			keyReleased = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && keyReleased) {
			if (opcionMenu != 5) opcionMenu++;
			soundSel.play();
			keyReleased = false;
		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			keyReleased = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (opcionMenu == 3 && enterReleased) {
				std::cout << "Comenzar" << std::endl;
				comenzar = true;
				enterReleased = false;
			}
			else if (opcionMenu == 4 && enterReleased) {
				std::cout << "Rank" << std::endl;
				enterReleased = false;
			}
			else if (opcionMenu == 5 && enterReleased) {
				opcionMenu = 1;
				tipoMenu = 1;
				enterReleased = false;
			}
		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) enterReleased = true;
	}
	if (tipoMenu == 6) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && enterReleased) {
			opcionMenu = 1;
			tipoMenu = 1;
			enterReleased = false;
		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) enterReleased = true;
	}
}