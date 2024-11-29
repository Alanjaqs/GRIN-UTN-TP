#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Player.h"
#include "Map.h"
#include "Platform.h"
#include "SpeedItem.h"
#include "DoubleJump.h"
#include "Enemy.h"
#include "DataPlayer.h"
#include "MenuScene.h"
#include "GameArchive.h"
#include "Gem.h"
#include "Spike.h"

class GameScene {
private:
	Player player;
	Enemy enemy, enemy2, enemy3, enemy4, enemy5, enemy6, enemy7, enemy8;
	Spike spike;
	Platform platform;
	DoubleJump dj;
	SpeedItem speedIt;
	Map map;
	Gem gem1, gem2, gem3, gem4, gem5, gem6, gem7;
	DataPlayer data;
	DataPlayer* vecData;
	GameArchive archive;
	MenuScene menu;
	sf::Texture fullHeartTex, emptyHeartTex;
	std::string nuevoNombre, puntaje;
	sf::Vector2f camPosition;
	sf::Clock clock;
	sf::Text textPuntos, text, textNuevoNombre, textGracias, textPuntosFinal, textEnter;
	sf::Text textPos, textName, textPoints, textIngresarNombre, textNivel;
	sf::Font font;
	sf::Color color;
	float decrementIntervalo = 1.0f; // Reducir el puntaje cada 1 segundo
	float elapsedTime = 0.0f;
	float winWidth, winHeight;
	int cantReg = 5;
	bool enterReleased = true, agregado = false, keyReleased = true;
	int state;
public:
	// Constructor
	GameScene();
	void setGameState(int e);
	int getGameState();

	/* ESTRUCTURA Y GUIA DE CREACION DE NIVEL
	1. Manejo metodos player y view
	2. Render backgrounds
	3. Render chats (si los hay)
	4. Render grounds + colision
	5. Render platforms + colision
	6. Render spikes + colision
	7. Render gems + colision
	8. Render double jump + colision
	9. Render speed item + colision
	10. Render portal
	11. Render player
	12. Sistema puntaje
	13. Render enemies + colision
	14. Portal colision + reinicio de variables respectivamente
	15. Render puntos decreciendo
	16. Render player name
	17. Render hearts
	18. Fase game over
	*/

	// METODOS DE LA ESTRUCTURA DEL JUEGO
	
	// GameMenu
	void GameMenu(sf::RenderWindow& window, sf::View& view, sf::Event& event);
	// Tutorial
	void Tutorial(sf::RenderWindow& window, sf::View& view);
	// Level 1
	void Level1(sf::RenderWindow& window, sf::View& view);
	// Data Screen
	void DataScreen(sf::RenderWindow& window, sf::View& view);
};