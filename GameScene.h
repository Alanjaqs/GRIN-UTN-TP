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
	DataPlayer data;
	DataPlayer* vecData;
	GameArchive archive;
	Map map;
	MenuScene menu;
	Spike spike;
	Platform platform, platform2;
	DoubleJump dj;
	SpeedItem speedIt;
	Gem gemAnim, gem1, gem2, gem3, gem4, gem5, gem6, gem7, gem8, gem9, gem10, gem11, gem12;
	Enemy enemy, enemy2, enemy3, enemy4, enemy5, enemy6, enemy7, enemy8, enemy9, bossEnemy;
	sf::Texture fullHeartTex, emptyHeartTex;
	std::string nuevoNombre, puntaje;
	sf::Vector2f camPosition;
	sf::Text textPuntos, text, textNuevoNombre, textGracias, textPuntosFinal, textEnter;
	sf::Text textPos, textName, textPoints, textIngresarNombre, textNivel, textBorrado;
	sf::Font font;
	sf::Color color;
	sf::Clock clock, clockBoss;
	float bossDefeatedTime = 6.0f;
	float decrementIntervalo = 1.0f; // Reducir el puntaje cada 1 segundo
	float elapsedTime = 0.0f;
	float winWidth, winHeight;
	int cantReg = 5;
	bool enterReleased = true, agregado = false, keyReleased = true;
	bool menuMusicBD, tutoMusicBD, level1MusicBD, level2MusicBD, bossLevelMusicBD, winningMusicBD = true;
	int state;
public:
	// Constructor, set/get
	GameScene();
	void setGameState(int e);
	int getGameState();
	float getBossDefeatedTime();

	/* ESTRUCTURA Y GUIA DE CREACION DE NIVEL
	1. Manejo metodos player y view
	2. Sistema puntaje
	3. Render backgrounds
	4. Render chats (si los hay)
	5. Render grounds + colision
	6. Render platforms + colision
	7. Render spikes + colision
	8. Render gems + colision
	9.  Render enemies + colision
	10. Render double jump + colision
	11. Render speed item + colision
	12. Render portal
	13. Render player
	14. Render player name
	15. Render puntos decreciendo
	16. Render hearts
	17.	Fase game over
	18. Portal colision + reinicio de variables respectivamente
	*/

	// METODOS DE LA ESTRUCTURA DEL JUEGO
	
	// GameMenu
	void GameMenu(sf::RenderWindow& window, sf::View& view, sf::Event& event);
	// Tutorial
	void Tutorial(sf::RenderWindow& window, sf::View& view);
	// Level 1
	void Level1(sf::RenderWindow& window, sf::View& view);
	// Level 2
	void Level2(sf::RenderWindow& window, sf::View& view);
	// Boss Level
	void BossLevel(sf::RenderWindow& window, sf::View& view);
	// Data Screen
	void DataScreen(sf::RenderWindow& window, sf::View& view);
};