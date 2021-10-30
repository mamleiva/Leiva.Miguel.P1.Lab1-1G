#include "biblioteca_utn.h"

#ifndef PILOTO_H_INCLUDED
#define PILOTO_H_INCLUDED

typedef struct
{
    int idPiloto;
    char nombre[20];
    char sexo;
    int edad;
    int isEmpty;
} ePiloto;

// LA DOCUMENTACION DOXYGEN, ESTA EN LOS ARCHIVOS .C, PORQUE ASI RECOMENDABA EN EL DOCUMENTO DE FUNCIONES DEL CLASSROOM
int buscarLibrePiloto(ePiloto lista[], int tam);
int inicializarPilotos(ePiloto lista[], int tam);
int altaPiloto(ePiloto lista[], int tam, int* pId);
#endif // PILOTO_H_INCLUDED
