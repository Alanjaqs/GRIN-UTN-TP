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

bool GameArchive::leerRank(DataPlayer* vec) {
    int i = 0;
    DataPlayer dataRead;
    FILE* pData;
    pData = fopen(nombreArchivo, "rb");
    if (pData == NULL) return false;
    while (fread(&dataRead, sizeof(DataPlayer), 1, pData) == 1) {
        vec[i] = dataRead;
        i++;
    }
    fclose(pData);
    return true;
}
