#pragma once
#include <string>
#include "DataPlayer.h"

class GameArchive {
private:
	char nombreArchivo[50];
public:
	// Constructor con nombre de archivo hardcodeado
	GameArchive(const char *nombre = "dataPlayer.dat");
	// Inicio rank por default y agregar data player
	bool iniciarRank();
	bool agregarRank(DataPlayer& dataWrite, DataPlayer* vec);
	// Lectura rank 
	bool leerRank(DataPlayer* vec);
};