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

bool GameArchive::agregarRank(DataPlayer& dataWrite, DataPlayer* vec) {
    bool bandera = false;
    FILE* pData;
    pData = fopen(nombreArchivo, "wb");
    if (pData == NULL) return false;

    for (int i = 0; i < 5 && !bandera; i++) {
        if (dataWrite.getPuntaje() > vec[i].getPuntaje()) {
            dataWrite.setPosicion(i + 1);
            for (int j = 4; j > i; j--) {
                vec[j] = vec[j - 1];  // Desplazar elementos hacia abajo.
            }
            vec[i] = dataWrite;
            bandera = true;
        }
        // Escribir el vector ya actualizado al archivo
        for (int x = 0; x < 5; x++) {
            fwrite(&vec[x], sizeof(DataPlayer), 1, pData);        
        }
    }
    fclose(pData);
    return true;
}

bool GameArchive::leerRank(DataPlayer* vec) {
    int pos = 0;
    DataPlayer dataRead;
    FILE* pData;
    pData = fopen(nombreArchivo, "rb");
    if (pData == NULL) return false;
    while ((fread(&dataRead, sizeof(DataPlayer), 1, pData) == 1) && pos < 5) {
        vec[pos] = dataRead;
        pos++;
    }
    fclose(pData);
    return true;
}
