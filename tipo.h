#include <stdio.h>
#include <stdlib.h>

#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
    int isEmpty;
}eTipo;

void mostrarTipo(eTipo unTipo);
int mostrarTipos(eTipo tipos[], int tamT);
int cargarDescTipos(eTipo tipos[], int tamT, int idRecibido, char descripcion[]);
int validarIdTipos(int idRecibido, eTipo tipos[], int tamT);

#endif // TIPO_H_INCLUDED
