#include <string.h>
#include "dataWarehouse.h"
#include "vuelo.h"
#include "avion.h"
#include "piloto.h"

/*
typedef struct
{
    int id;
    int idAvion;
    int idDestino;
    eFecha fecha;
    int isEmpty;
} eVuelo;


typedef struct
{
    int idAvion;
    int idAerolinea;
    int idTipo;
    int capacidad;
    int isEmpty;
} eAvion;

  eTipo tipos[TAM_TIPOS] =
    {
        {5000, "Jet"},
        {5001, "Helice"},
        {5002, "Planeador"},
        {5003, "Carga"}
    };
*/

int dia[10]= {20, 8, 20, 21, 3, 2, 6, 12, 18, 29};
int mes[10]= {12, 8, 6, 7, 3, 2, 6, 12, 11, 10};
int anio[10]= {2021, 2020, 2022, 2021, 2021, 2021, 2020, 2021, 2010, 2021};

int tipos[10] = {5000, 5000, 5001, 5002, 5001, 5000, 5001, 5002, 5003, 5003};
int capacidad[10]= { 120, 10, 140, 200, 30, 250, 270, 54, 100, 120 };
int idAerolinea[10]= { 1000, 1001, 1002, 1004, 1003, 1002, 1004, 1003, 1002, 1000 };
int idAvion[10]= { 3001, 3002, 3003, 3004, 3005, 3006, 3007, 3008, 3009, 3010 };
int idDestino[10]= { 20000, 20000, 20002, 20001, 20003, 20002, 20001, 20003, 20002, 20000 };

int edadPiloto[10]= {20, 30, 24, 45, 46, 47, 48, 35, 48, 29};
char nombres[10][20] ={
//char nombres[10][20] = {
    "Juan",
    "Pedro",
    "Sofia",
    "Miguel",
    "Valentina",
    "Camila",
    "Andrea",
    "Luis",
    "Diego",
    "Analia"
};
char sexos[10] = {'m', 'm', 'f', 'm', 'f', 'f', 'f', 'm', 'm', 'f'};


int hardcodearAvion(eAvion lista[], int tam, int cant, int* pIdAvion, int* contadorAviones){
    int contador = -1;
    if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pIdAvion != NULL  )
    {
        contador = 0;
        for(int i=0; i < cant; i++)
        {
            lista[i].idAvion = *pIdAvion; //con el * accedemos al valor del puntero.
            (*pIdAvion)++;
            lista[i].idAerolinea = idAerolinea[i];
            lista[i].idTipo = tipos[i];
            lista[i].capacidad = capacidad[i];
            lista[i].isEmpty = 0;
            (*contadorAviones)++;
            contador++;
        }
    }

    return contador;
}

/*
typedef struct
{
    int id;
    int idAvion;
    int idDestino;
    eFecha fecha;
    int isEmpty;
} eVuelo;
*/
int hardcodearVuelos(eVuelo lista[], int tam, int cant, int* nextIdVuelo, int* contadorVuelos)
{
    int contador = -1;
    if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && nextIdVuelo != NULL && contadorVuelos != NULL)
    {
        contador = 0;
        for(int i=0; i < cant; i++)
        {
            lista[i].id = *nextIdVuelo; //con el * accedemos al valor del puntero.
            (*nextIdVuelo)++;
            lista[i].idAvion = idAvion[i];
            lista[i].idDestino = idDestino[i];
            lista[i].fecha.dia = dia[i];
            lista[i].fecha.mes = mes[i];
            lista[i].fecha.anio = anio[i];
            (*contadorVuelos)++;
            lista[i].isEmpty = 0;
            contador++;
        }
    }

    return contador;
}

int hardcodearPilotos(ePiloto lista[], int tam, int cant, int* nextIdPiloto, int* contadorPilotos)
{
    int contador = -1;
    if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && nextIdPiloto != NULL && contadorPilotos != NULL)
    {
        contador = 0;
        for(int i=0; i < cant; i++)
        {
            lista[i].idPiloto = *nextIdPiloto;
            //printf("el id del piloto en el harcodeo es: %d",lista[i].idPiloto );
            //system("pause");
            (*nextIdPiloto)++;
            strcpy(lista[i].nombre, nombres[i]);
            lista[i].sexo = sexos[i];
            lista[i].edad = edadPiloto[i];
            (*contadorPilotos)++;
            lista[i].isEmpty = 0;
            contador++;
        }
    }

    return contador;
}
