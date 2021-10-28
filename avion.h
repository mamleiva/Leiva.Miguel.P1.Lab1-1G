#include "aerolinea.h"
#include "tipo.h"
#include "biblioteca_utn.h"
#include "inputs.h"

#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

typedef struct
{
    int idAvion;
    int idAerolinea;
    int idTipo;
    int capacidad;
    int isEmpty;
} eAvion;

int inicializarAviones(eAvion aviones[], int tamAvi);
int buscarLibreAviones(eAvion aviones[], int tamAvi);
int mostrarAviones(eAvion aviones[], int tamAvi, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT);
int altaAviones(eAvion aviones[], int tamAvi, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, int *pId);
void mostrarAvion(eAvion unAvion, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT);
int buscarAvionId(eAvion aviones[], int tamAvi, int idRecibido);
int bajaAviones(eAvion aviones[], int tamAvi, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT);
int ordenarAviones(eAvion aviones[], int tamAvi, eAerolinea aerolineas[], int tamA);
int modificarAviones(eAvion aviones[], int tamAvi, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT);
int cargarDescAvion(eAvion aviones[], int tamAvi, int idRecibido, char descripcion[], eAerolinea aerolineas[], int tamA);

#endif // AVION_H_INCLUDED
