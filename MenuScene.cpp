#include <SFML/Graphics.hpp>
#include "MenuScene.h"

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
}

// Getters
// Getters sprites
sf::Sprite& MenuScene::getMenuBack(){
	return menuSprite;
}
sf::Sprite& MenuScene::getJugarButton(int opc) {
	if(opc == 0) return jugarSprite;
	if(opc == 1) return jugarSelSprite;
}
sf::Sprite& MenuScene::getSalirButton(int opc) {
	if(opc == 0) return salirSprite;
	if (opc == 1) return salirSelSprite;
}

// Setters