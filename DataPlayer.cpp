#include "DataPlayer.h"

// Setters
void DataPlayer::setPosicion(int pos) {
	posicion = pos;
}

bool DataPlayer::setNombre(std::string name) {
	if (name.length() >= 1 && name.length() <= 5) {
		nombre = name;
		return true;
	}
	else return false;
}

void DataPlayer::setPuntaje(float p) {
	puntaje = p;
}

// Getters
int DataPlayer::getPosicion() { return posicion; }
std::string DataPlayer::getNombre() { return nombre; }
float DataPlayer::getPuntaje() { return puntaje; }