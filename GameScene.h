#pragma once

class GameScene {
private:
	// Lista de estados del juego
	// 1 - Menu
	// 2 - SubMenu ( Dentro de esto hay que hacer una opcion para lista de puntajes, save state, y cuando de jugar , seleccion de nombre)
	// 3 - Tutorial
	// 4 - Nivel 1
	// 5 - Nivel 2

	int state;

public:
	void setGameState(int e);
	int getGameState();

};