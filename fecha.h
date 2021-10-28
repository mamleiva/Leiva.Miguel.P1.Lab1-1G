//#include "vuelo.h"  //si agrego vuelo.h, explota, preguntarle al profe

#include "biblioteca_utn.h"


#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

//eVuelo auxVuelo; //esta struct tiene agregada la struc fecha
//validarFechas(&auxVuelo); //llamada
//int validarFechas(eVuelo* vecConFecha);

#endif // FECHA_H_INCLUDED
