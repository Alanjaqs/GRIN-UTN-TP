#pragma once
#include <iostream>
#include <string>

class DataPlayer {
private:
	int posicion;
	char nombre[6];
	int puntaje;

public:
	// Setters
	void setPosicion(int pos);
	void setNombre(char* name);
	void setPuntaje(int p);
	// Getters
	int getPosicion();
	char* getNombre();
	int getPuntaje();
	// Data player default
	void resetData(int pos);
};
