#include "aerolinea.h"
#include "tipo.h"
#include "biblioteca_utn.h"
#include "inputs.h"
#include "piloto.h"

#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

typedef struct
{
    int idAvion;
    int idAerolinea;
    int idTipo;
    int capacidad;
    int isEmpty;
    ePiloto piloto;

} eAvion;

    // LA DOCUMENTACION DOXYGEN, ESTA EN LOS ARCHIVOS .C, PORQUE ASI RECOMENDABA EN EL DOCUMENTO DE FUNCIONES DEL CLASSROOM

int inicializarAviones(eAvion aviones[], int tam_aviones);
int buscarLibreAviones(eAvion aviones[], int tam_aviones);
int mostrarAviones(eAvion aviones[], int tam_aviones, eAerolinea aerolineas[], int tam_aerolineas, eTipo tipos[], int tam_tipos, ePiloto pilotos[], int tam_pilotos);
void mostrarAvion(eAvion unAvion, eAerolinea aerolineas[], int tam_aerolineas, eTipo tipos[], int tam_tipos,ePiloto piloto );


int altaAviones(eAvion aviones[], int tam_aviones, eAerolinea aerolineas[], int tam_aerolinea, eTipo tipos[], int tam_tipos, int *pId, ePiloto pilotos[],int tam_pilotos, int* pidPiloto);
int buscarAvionId(eAvion aviones[], int tam_aviones, int idRecibido);
int bajaAviones(eAvion aviones[], int tam_aviones, eAerolinea aerolineas[], int tam_aerolineas, eTipo tipos[], int tam_tipos, ePiloto pilotos[], int tam_pilotos);
int ordenarAviones(eAvion aviones[], int tam_aviones, eAerolinea aerolineas[], int tam_aerolineas);
int modificarAviones(eAvion aviones[], int tam_aviones, eAerolinea aerolineas[], int tam_aerolineas, eTipo tipos[], int tam_tipos, ePiloto pilotos[],int tam_pilotos);
int cargarDescripcionAvion(eAvion aviones[], int tam_aviones, char descripcion[], eAerolinea aerolineas[], int tam_aerolineas, int idRecibido);


#endif // AVION_H_INCLUDED
