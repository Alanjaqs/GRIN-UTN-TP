#include <SFML/Graphics.hpp>
#include "MenuScene.h"
#include <iostream>

// Constructor
MenuScene::MenuScene() {
	// Background
	MenuScene::menuTexture.loadFromFile("images\\backMenu.png");
	MenuScene::menuSprite.setTexture(menuTexture);
	// Jugar Button
	MenuScene::jugarTexture.loadFromFile("images\\jugarButton.png");
	MenuScene::jugarSprite.setTexture(jugarTexture);
	jugarSprite.setPosition(400, 400);
	// Jugar Selected
	MenuScene::jugarSelTexture.loadFromFile("images\\jugarSelected.png");
	MenuScene::jugarSelSprite.setTexture(jugarSelTexture);
	jugarSelSprite.setPosition(400, 400);
	// Salir Button
	MenuScene::salirTexture.loadFromFile("images\\salirButton.png");
	MenuScene::salirSprite.setTexture(salirTexture);
	salirSprite.setPosition(400, 520);
	// Salir Selected
	MenuScene::salirSelTexture.loadFromFile("images\\salirSelected.png");
	MenuScene::salirSelSprite.setTexture(salirSelTexture);
	salirSelSprite.setPosition(400, 520);
	// Audio
	soundSel.openFromFile("audio\\menuSel.mp3");
}

// Getters generales
int MenuScene::getOpc() { return opcionMenu; }
bool MenuScene::getJugar() { return jugar; }
bool MenuScene::getSalir() { return salir; }
// Getters sprites
sf::Sprite& MenuScene::getMenuBack() { return menuSprite; }
sf::Sprite& MenuScene::getJugarSelButton() { return jugarSelSprite; }
sf::Sprite& MenuScene::getJugarButton() { return jugarSprite; }
sf::Sprite& MenuScene::getSalirButton() { return salirSprite; }
sf::Sprite& MenuScene::getSalirSelButton() { return salirSelSprite; }

// Setters
void MenuScene::setJugar(int v) {
	jugar = v;
}
void MenuScene::setSalir(int v) {
	salir = v;
}

// Comando
void MenuScene::MenuUpdate() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		opcionMenu = 1;
		soundSel.play();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		opcionMenu = 0;
		soundSel.play();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		if (opcionMenu == 1) {
			setJugar(1);
		}
		else if (opcionMenu == 0) {
			setSalir(1);
		}
	}

}