#include "fecha.h"
#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"
#include "inputs.h"
#include "destino.h"
#include "biblioteca_utn.h"

#define VACIO 1
#define LLENO 0

#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED

typedef struct
{
    int id;
    int idAvion;
    int idDestino;
    eFecha fecha;
    int isEmpty;
} eVuelo;

// LA DOCUMENTACION DOXYGEN, ESTA EN LOS ARCHIVS .C, PORQUE ASI RECOMENDABA EN EL DOCUMENTO DE FUNCIONES DEL CLASSROOM

int iniciarVuelos(eVuelo vuelos[], int tam);
int buscarVuelosLibres(eVuelo vuelos[], int tam);
int altaVuelo(eVuelo vuelos[], int tam_vuelos, eAvion aviones[], int tam_aviones, eDestino destinos[], int tam_destinos, eAerolinea aerolineas[], int tam_aerolineas, eTipo tipos[], int tam_tipos, int* pId);
int mostrarVuelos(eVuelo vuelos[], int tam_vuelos, eAvion aviones[], int tam_aviones, eDestino destinos[], int tam_destinos, eAerolinea aerolineas[], int tam_aerolineas);
void mostrarVuelo(eVuelo unVuelo, eAvion aviones[], int tam_aviones, eDestino destinos[], int tam_destinos, eAerolinea aerolineas[], int tam_aerolineas);

//eVuelo auxVuelo; //esta struct tiene agregada la struc fecha
//validarFechas(&auxVuelo); //llamada
int validarFechas(eVuelo* vecConFecha);

#endif // VUELO_H_INCLUDED
