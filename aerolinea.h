#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#ifndef AEROLINEA_H_INCLUDED
#define AEROLINEA_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[20];
}eAerolinea;


// LA DOCUMENTACION DOXYGEN, ESTA EN LOS ARCHIVOS .C, PORQUE ASI RECOMENDABA EN EL DOCUMENTO DE FUNCIONES DEL CLASSROOM
//funciones
void mostrarAerolinea(eAerolinea unaAerolinea);
int mostrarAerolineas(eAerolinea aerolineas[], int tam);
int cargarDescripcionAerolineas(eAerolinea aerolineas[], int tam, int idRecibido, char descripcion[]);
int validarIdAerolineas(int idRecibido, eAerolinea aerolineas[], int tam);

#endif // AEROLINEA_H_INCLUDED
