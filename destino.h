#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;

} eDestino;

void mostrarDestino(eDestino unDestino);
int mostrarDestinos(eDestino destinos[], int tamD);
int cargarDescDestinos(eDestino destinos[], int tamD, int idRecibido, char descripcion[]);
int validarIdDestinos(int idRecibido, eDestino destinos[], int tamD);

#endif // DESTINO_H_INCLUDED
