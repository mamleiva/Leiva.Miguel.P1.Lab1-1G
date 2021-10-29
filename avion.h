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

    // LA DOCUMENTACION DOXYGEN, ESTA EN LOS ARCHIVOS .C, PORQUE ASI RECOMENDABA EN EL DOCUMENTO DE FUNCIONES DEL CLASSROOM

int inicializarAviones(eAvion aviones[], int tam_aviones);
int buscarLibreAviones(eAvion aviones[], int tam_aviones);
int mostrarAviones(eAvion aviones[], int tam_aviones, eAerolinea aerolineas[], int tam_aerolineas, eTipo tipos[], int tam_tipos);
int altaAviones(eAvion aviones[], int tam_aviones, eAerolinea aerolineas[], int tam_aerolinea, eTipo tipos[], int tam_tipos, int *pId);
void mostrarAvion(eAvion unAvion, eAerolinea aerolineas[], int tam_aerolineas, eTipo tipos[], int tam_tipos);
int buscarAvionId(eAvion aviones[], int tam_aviones, int idRecibido);
int bajaAviones(eAvion aviones[], int tam_aviones, eAerolinea aerolineas[], int tam_aerolineas, eTipo tipos[], int tam_tipos);
int ordenarAviones(eAvion aviones[], int tam_aviones, eAerolinea aerolineas[], int tam_aerolineas);
int modificarAviones(eAvion aviones[], int tam_aviones, eAerolinea aerolineas[], int tam_aerolineas, eTipo tipos[], int tam_tipos);
int cargarDescripcionAvion(eAvion aviones[], int tam_aviones, char descripcion[], eAerolinea aerolineas[], int tam_aerolineas, int idRecibido);


#endif // AVION_H_INCLUDED
