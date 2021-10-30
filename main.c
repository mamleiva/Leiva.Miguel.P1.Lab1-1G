#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "aerolinea.h"
#include "avion.h"
#include "biblioteca_utn.h"
#include "dataWarehouse.h"
#include "destino.h"
#include "vuelo.h"
#include "inputs.h"

#define TAM_AEROLINEA 5
#define TAM_TIPOS 4
#define TAM_AVIONES 50//8
#define TAM_DESTINOS 4
#define TAM_VUELOS 600
#define TAM_PILOTOS 30

int main()
{
    char seguir = 's';
    char confirmaSalir;
    int nextIdAvion= 3000;
    int nextIdVuelo = 2000;
    int nextIdPiloto = 8000;
    //int nextIdAerolinea = 1000;
    //int nextIdDestino = 20000;
    //int nextIdTipo = 5000;

    int contadorAviones = 0;
    int contadorVuelos = 0;
    int contadorPilotos = 0;

    eAerolinea aerolineas[TAM_AEROLINEA] =
    {
        {1000, "Iberia"},
        {1001, "LAN"},
        {1002, "Norweigan"},
        {1003, "Austral"},
        {1004, "American"}
    };

    eTipo tipos[TAM_TIPOS] =
    {
        {5000, "Jet"},
        {5001, "Helice"},
        {5002, "Planeador"},
        {5003, "Carga"}
    };

    eDestino destinos [TAM_DESTINOS]=
    {
        {20000, "Calafate", 22250 },
        {20001, "Miami", 103000},
        {20002, "Madrid", 84400},
        {20003, "Amsterdam", 95600}

    };

    eAvion aviones[TAM_AVIONES] =
    {
        {3000, 1003, 5000,50},
        {3001, 1002, 5003,200},
        {3002, 1001, 5001,30},
        {3003, 1004, 5003,40},
    };

    eVuelo vuelos[TAM_VUELOS];
    ePiloto pilotos[TAM_PILOTOS];

    if(!inicializarAviones(aviones, TAM_AVIONES))
    {
        printf("Ocurrio un problema al inicializar aviones");
    }
    if(!iniciarVuelos(vuelos, TAM_VUELOS))
    {
        printf("Ocurrio un problema al inicializar vuelos");
    }

    if(!inicializarPilotos(pilotos, TAM_PILOTOS))
    {
        printf("Ocurrio un problema al inicializar pilotos");
    }

    //HARDCODEO
    hardcodearAvion(aviones, TAM_AVIONES, 8, &nextIdAvion, &contadorAviones );
    hardcodearVuelos(vuelos, TAM_VUELOS, 8, &nextIdVuelo, &contadorVuelos);
    hardcodearPilotos(pilotos, TAM_PILOTOS, 8, &nextIdPiloto, &contadorPilotos);

    do
    {
        switch(menu())
        {
        case 'A': //ALTA DE AVIONES
            if(!altaAviones(aviones, TAM_AVIONES, aerolineas, TAM_AEROLINEA, tipos, TAM_TIPOS, &nextIdAvion, pilotos, TAM_PILOTOS, &nextIdPiloto))
            {
                printf("Hubo un problema al realizar el alta del avion\n");
            }
            else
            {
                printf("Alta Exitosa de avion!!!\n");
                contadorAviones++;
                contadorPilotos++;
            }
            break;
        case 'B': //BAJA DE AVIONES
            if (contadorAviones > 0)
            {
                system("cls");
                if (!bajaAviones(aviones, TAM_AVIONES, aerolineas, TAM_AEROLINEA, tipos, TAM_TIPOS, pilotos,TAM_PILOTOS))
                {
                    printf("No se pudo dar de baja el avion\n");
                }
                else
                {
                    printf("Baja exitosa!\n");
                    contadorAviones--;
                }
            }
            else
            {
                printf("Primero debe dar de alta algun avion\n");
            }
            break;
        case 'C': //MODIFICACION
            if (contadorAviones > 0)
            {
                system("cls");
                if (!modificarAviones(aviones, TAM_AVIONES, aerolineas, TAM_AEROLINEA, tipos, TAM_TIPOS, pilotos, TAM_PILOTOS))
                {
                    printf("No se pudo modificar el avion\n");
                }
                else
                {
                    printf("Modificacion exitosa!\n");
                }
            }
            else
            {
                printf("Primero debe dar de alta algun avion\n");
            }

            break;
        case 'D':  //MOSTRAR AVIONES
            system("cls");
            if (contadorAviones > 0)
            {
                if (!mostrarAviones(aviones, TAM_AVIONES, aerolineas, TAM_AEROLINEA, tipos,
                                    TAM_TIPOS, pilotos, TAM_PILOTOS))
                {
                    printf("No se pudieron mostrar los aviones\n");
                }
            }
            else
            {
                printf("No se han dado de alta aviones\n");
            }
            break;
        case 'E': //MOSTRAR AEROLINEAS
            system("cls");
            if (!mostrarAerolineas(aerolineas, TAM_AEROLINEA))
            {
                printf("No se pudieron mostrar las aerolineas\n");
            }
            break;

        case 'F': //MOSTRAR TIPOS
            system("cls");
            if (!mostrarTipos(tipos, TAM_TIPOS))
            {
                printf("No se pudieron mostrar los tipos\n");
            }
            break;

        case 'G'://MOSTRAR DESTINOS
            system("cls");
            if (!mostrarDestinos(destinos, TAM_DESTINOS))
            {
                printf("No se pudieron mostrar los destinos\n");
            }
            break;
        case 'H'://ALTA DE VUELOS
            system("cls");
            if (contadorAviones > 0)
            {
                //int altaVuelo(eVuelo vuelos[], int tam_vuelos, eAvion aviones[], int tam_aviones,eDestino destinos[], int tam_destinos, eAerolinea aerolineas[], int tam_aerolineas,eTipo tipos[], int tam_tipos, int* pId, ePiloto pilotos[],int tam_pilotos, int* idPiloto);
                if (!altaVuelo(vuelos, TAM_VUELOS, aviones, TAM_AVIONES, destinos, TAM_DESTINOS, aerolineas, TAM_AVIONES, tipos, TAM_TIPOS, &nextIdVuelo, pilotos, TAM_PILOTOS))
                {
                    printf("No se pudo dar de alta un nuevo vuelo\n");
                }
                else
                {
                    printf("Alta de vuelo exitosa!\n");
                    contadorVuelos++;
                }
            }
            break;
        case 'I':// MOSTRAR VUELOS
            //system("cls");
            if (contadorVuelos > 0)
            {
                if (!mostrarVuelos(vuelos, TAM_VUELOS, aviones, TAM_AVIONES, destinos, TAM_DESTINOS, aerolineas, TAM_AEROLINEA))
                {
                    printf("No se pudieron mostrar los vuelos\n");
                }
            }
            else
            {
                printf("Primero debe dar de alta algun vuelo\n");
            }

            break;
        case 'J':// LISTADO DE ORDENAMIENTO
            //system("cls");
            if (contadorVuelos > 0)
            {
               ordenarAviones(aviones, TAM_AVIONES, aerolineas, TAM_AEROLINEA);
               mostrarAviones(aviones, TAM_AVIONES, aerolineas, TAM_AEROLINEA, tipos, TAM_TIPOS, pilotos, TAM_PILOTOS);
            }
            else
            {
                printf("Primero debe dar de alta algun vuelo\n");
            }

            break;

        case 'X':  //SALIR
            utn_pedirCaracter(&confirmaSalir, "Confirma que desea salir? \"s\" para si, \"n\" para no. ", "Error! ", 's', 'n');
            if(confirmaSalir == 's')
            {
                seguir = 'n';
                printf("Chau! hasta pronto!\n");
            }
            break;
        default:
            printf("Error! Opcion Invalida!!\n\n");
            break;
        }//fin del switch
        system("pause");
    }
    while(seguir == 's'); //fin del do while

    return 0;
}
