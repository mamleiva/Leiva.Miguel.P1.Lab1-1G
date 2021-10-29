/*
 * UTN_Bibliotecas.h
 * funciones.c
 * cuerpo de las funciones
 *
 *  Created on: 14 oct. 2021
 *      Author: martinl
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define VERDADERO 1
#define FALSO 0
#define MIN 1
#define MAX 5

#ifndef BIBLIOTECA_UTN_H_INCLUDED
#define BIBLIOTECA_UTN_H_INCLUDED

// LA DOCUMENTACION DOXYGEN, ESTA EN LOS ARCHIVOS .C, PORQUE ASI RECOMENDABA EN EL DOCUMENTO DE FUNCIONES DEL CLASSROOM

//####################################### MENUS #######################################
//int menu();
//int subMenu();

//####################################### NUMEROS #######################################
//funciones de numeros enteros
int utn_getNumero(int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos); //ok
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos); //ok

//funciones de numeros float
int utn_getNumeroFlotanteConMinMax(float *pResultado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos);
int utn_getNumeroFlotanteSinMinMax(float *pResultado, char mensaje[], char mensajeError[]);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

//funciones de enteros con minimos y maximos
int getIntMinMax(char *mensaje, int min, int max);
int getValidIntMinMax(int* numero, char* mensaje, int min, int max);

//####################################### STRINGS #######################################
//funciones de Strings

int utn_getString(char *pResultado, int tam, char mensaje[], char mensajeError[], int reintentos); //esta es la del tp2
//utn_getString(cadenaCaracteres, TAM_CADENA, "Ingrese una palabra de caracteres: ", "Error! ingrese una cadena valida", 10);

int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos); //ok
//utn_getDescripcion(cadenaCaracteres, TAM_CADENA, "Ingrese la descripcion: ", "Error! ingrese una cadena valida", 10);

int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos); //ok
//utn_getNombre(cadenaCaracteres, TAM_CADENA, "Ingrese Nombre: ", "Error! reingrese: ", 10);


//confirmacion "S" "N"
char getConfirmacion(char mensaje[]); //corregir lo de scanf.

//funciones de char

int utn_pedirCaracter(char* caracter, char* mensaje, char* mensajeError, char caracter1, char caracter2); //corregir lo de scanf.
//utn_pedirCaracter(&caracter, "Ingrese 's' para si, 'n' para no: ", "Error! reingrese: ", 's', 'n');

int utn_getCaracteres(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

//funcion para sacar promedio
float my_sacarPromedio(int a, int b);


//######################PARA REVISAR###########################################

int my_getInt(char *mensaje);

char getChar(char mensaje[]);

void getString_tp(char mensaje[], char cadena[]);

int getStringLetras(char cadena[]);

void my_pedirCadenaSoloLetras (char mensaje[], char cadena[]);

void my_primerLetraAMayuscula(char cadena[]);


#endif // BIBLIOTECA_UTN_H_INCLUDED

/*#############################estructura y hardcodeo###############
typedef struct
{
    int id;
    char nombre[50];
    char tipo;
    float efectividad;
}eVacuna;


int hardcodeo(eVacuna lista[], int tam, int cant);
int ordenarMarcaPrecio(eVacuna list[], int len);
void mostrarVector(eVacuna lista);
int mostrarVectores(eVacuna lista[], int tam);

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#define TAM_CADENA 50
#define TAM 10
#include "hardcodeo.h"

//hardcodeo
int id[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


char nombre[10][50] =
{
    "nombre1",
    "nombre2",
    "nombre3",
    "nombre4",
    "nombre5",
    "nombre6",
    "nombre7",
    "nombre8",
    "nombre9",
    "nombre10"
};

char tipo[10] =
{
    'a',
    't',
    'r',
    'g',
    'r',
    'g',
    'f',
    'd',
    'c',
    'b'
};

float efectividad[10] = {90, 80, 70, 60, 90, 50, 40, 50, 80, 90};



int hardcodeo(eVacuna lista[], int tam, int cant)
{

    int contador = -1;
    if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam )
    {
        contador = 0;
        for(int i=0; i < cant; i++)
        {
            //strcpy(lista[i]., procesador[i]);
            strcpy(lista[i].nombre, nombre[i]);
            lista[i].id = id[i];
            lista[i].efectividad = efectividad[i];
            lista[i].tipo = tipo[i];
            contador++;
        }
    }
    return contador;
}//finhardcodeo

int ordenarMarcaPrecio(eVacuna list[], int len)
{
    int retorno = -1;
    eVacuna auxVacunas;
    if (list != NULL && len > 0)
    {
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                //si estan desordenadas las marcas.... o si el precio es mayor y son las mismas marcas.
                if( list[i].efectividad > list[j].efectividad  )
                {
                    auxVacunas = list[i];
                    list[i] = list[j];
                    list[j] = auxVacunas;
                }


            }
        }
        retorno = 0;
    }
    return retorno;
}

int mostrarVectores(eVacuna lista[], int tam)
{
    int todoOk = 0;
    int flag = 1;
    if(lista != NULL && tam > 0)
    {
        printf("   ***Listado de Vacunas***\n\n");
        printf("   id         Nombre       Tipo        Efectividad\n");
        printf("----------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            mostrarVector(lista[i]);
                flag = 0;
        }
        if(flag)
        {
            printf("   No hay vacunas para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

/// \brief imprime todos los datos de las personas y llama a la funcion que trae el string de la decripcion
/// y lo guarda en el vector "descLocalidad"
/// \param vector de persona con su numero de indice
/// \param vector tipo struct  de localidades
/// \param tam del vector de localidades
/// \return no devuelve nada
///
///

void mostrarVector(eVacuna lista)
{
    printf("   %d  %10s     %15c       %.2f\n",
           lista.id,
           lista.nombre,
           lista.tipo,
           lista.efectividad
          );
}



*/
