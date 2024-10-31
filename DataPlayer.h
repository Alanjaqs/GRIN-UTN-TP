#pragma once
#include <iostream>
#include <string>

class DataPlayer {
private:
	int posicion;
	std::string nombre;
	float puntaje;

public:
	// Setters
	void setPosicion(int pos);
	bool setNombre(std::string name);
	void setPuntaje(float p);
	// Getters
	int getPosicion();
	std::string getNombre();
	float getPuntaje();
};
