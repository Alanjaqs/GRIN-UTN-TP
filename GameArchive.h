#pragma once
#include <string>
#include "DataPlayer.h"

class GameArchive {
	// Manejo de archivos
	// Idea: que el juego genere al ejecutarse un archivo con:
	// Posicion 1, 2, 3, 4 y 5
	// Nombres: AAAAA (en las 5 posiciones)
	// Puntaje: 0 

	// Una vez el jugador elija un nombre se agregue a la lista y depende el puntaje sera la posicion
	// Ver Rank: ver la lista de los 5 con mas puntaje
	// Borrar Rank: volver a crear el archivo con AAAAA (con fwrite podria ser)
private:
	char nombreArchivo[50];

public:
	// Constructor con nombre de archivo hardcodeado
	GameArchive(const char *nombre = "dataPlayer.dat");

	// Inicio rank por default
	bool iniciarRank();
	// Lectura rank por consola temporalmente
	bool leerRank(DataPlayer* vec);
};