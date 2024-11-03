#include "GameArchive.h"

GameArchive::GameArchive(const char *nombre) {
    strcpy(nombreArchivo, nombre);
}

bool GameArchive::iniciarRank() {
    FILE* pData;
    pData = fopen(nombreArchivo, "wb");
    if (pData == NULL) return false;
    DataPlayer data;
    for (int i = 1; i <= 5; i++) {
        data.resetData(i);
        fwrite(&data, sizeof(DataPlayer), 1, pData);
    }
    fclose(pData);
    return true;
}

bool GameArchive::leerRank() {
    DataPlayer data;
    FILE* pData;
    pData = fopen(nombreArchivo, "rb");
    if (pData == NULL) return false;
    /*while (fread(&data, sizeof(DataPlayer), 1, pData) == 1) {
        std::cout << "Posicion: " << data.getPosicion() << std::endl;
        std::cout << "Nombre: " << data.getNombre() << std::endl;
        std::cout << "Puntaje: " << data.getPuntaje() << std::endl;
    }*/
    fclose(pData);
    return true;
}
