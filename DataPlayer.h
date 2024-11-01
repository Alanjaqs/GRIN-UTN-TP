#pragma once
#include <iostream>
#include <string>

class DataPlayer {
private:
	int posicion;
	char nombre[6];
	float puntaje;

public:
	// Setters
	void setPosicion(int pos);
	void setNombre(char* name);
	void setPuntaje(float p);
	// Getters
	int getPosicion();
	char* getNombre();
	float getPuntaje();
	// Data player default
	void resetData(int pos);
};
