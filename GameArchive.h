#pragma once
#include <string>
#include "DataPlayer.h"

class GameArchive {
private:
	char nombreArchivo[50];

public:
	// Constructor con nombre de archivo hardcodeado
	GameArchive(const char *nombre = "dataPlayer.dat");

	// Inicio rank por default
	bool iniciarRank();
	// Lectura rank 
	bool leerRank(DataPlayer* vec);
};