#include "DataPlayer.h"

// Setters
void DataPlayer::setPosicion(int pos) {
	posicion = pos;
}
void DataPlayer::setNombre(const char* name) {
	strcpy(nombre, name);
}
void DataPlayer::setPuntaje(int p) {
	puntaje = p;
}

// Getters
int DataPlayer::getPosicion() { return posicion; }
char* DataPlayer::getNombre() { return nombre; }
int DataPlayer::getPuntaje() { return puntaje; }

//
void DataPlayer::resetData(int pos) {
	posicion = pos;
	strcpy(nombre, "AAAAA");
	puntaje = 0;
}

void rankearPlayer(DataPlayer charged) {

}