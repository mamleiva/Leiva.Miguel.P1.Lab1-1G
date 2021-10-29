/*
 * inputs.c
 *
 *  Created on: 14 oct. 2021
 *      Author: martinl
 */
#include "inputs.h"


//####################################### MENUS ##############################################

/** \brief MENU PRINCIPAL CON LAS OPCIONES.
 *
 * \return CHAR CON LA OPCION SELECCIONADA
 *
 */

char menu()
{
    char opcion;

    system("cls");
    printf("        *** Menu de Aviones ***          \n");
    printf("-------------------------------------------------\n");
    printf("   A- Alta de Avion\n");
    printf("   B- Baja de Avion\n");
    printf("   C- Modificar Avion\n");
    printf("   D- Listar los Aviones\n");
    printf("   E- Listar las Aerolineas\n");
    printf("   F- Listar los Tipos de Aviones\n");
    printf("   G- Listar los Destinos\n");
    printf("   H- Alta de Vuelo\n");
    printf("   I- Listar los Vuelos\n");
    printf("   X- Salir\n");

    utn_getCaracteres(&opcion, "Ingrese Opcion: ", "\nError!, ingrese opcion deseada: ", 'A', 'z', 10);
    opcion = toupper(opcion);
    while (opcion != 'A' && opcion != 'B' && opcion != 'C' &&  opcion != 'D' &&  opcion != 'E' &&  opcion != 'F' &&
			opcion != 'G' &&  opcion != 'H' &&  opcion != 'I' &&  opcion != 'X' )
			{
			    utn_getCaracteres(&opcion, "Error! Ingrese Opcion: ", "\n\nError! reingrese Opcion:: ", 'A', 'z', 10);
			}

    return opcion;
}

/** \brief SUBMENU DE MODIFICACIONES
 *
 * \return CHAR CON LA OPCION SELECCIONADA.
 *
 */

char menuModificacion(){
	char opcion;

	system("cls");
	printf("      *** Modificar Avion ***\n");
	printf("---------------------------------------\n");
	printf("A- Tipo\n");
	printf("B- Capacidad \n");
	printf("C- Salir \n");

	fflush(stdin);
	utn_getCaracteres(&opcion, "Ingrese Opcion a MODIFICAR: ", "\nError!, ingrese opcion a MODIFICAR: ", 'A', 'z', 10);
	opcion = tolower(opcion);

	while (opcion != 'a' && opcion != 'b' && opcion != 'c'){
		utn_getCaracteres(&opcion, "Ingrese Opcion a MODIFICAR: ", "\nError!, reingrese opcion a MODIFICAR: ", 'A', 'z', 10);
		opcion = tolower(opcion);
	}

	return opcion;

}
