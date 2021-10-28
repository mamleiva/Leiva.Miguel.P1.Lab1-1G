#include "vuelo.h"

//iniciar
int iniciarVuelos(eVuelo vuelos[], int tamV){
	int todoOk = 0;

	if (vuelos != NULL && tamV > 0){
		for (int i = 0; i < tamV; i++){
			vuelos[i].isEmpty = VACIO;
			todoOk = 1;
		}
	}

	return todoOk;
}

//buscarLibre
int buscarLibreVuelos(eVuelo vuelos[], int tamV){
	int index = -1;

	if (vuelos != NULL && tamV > 0){
		for (int i = 0; i < tamV; i++){
			if (vuelos[i].isEmpty == VACIO){
				index = i;
				break;
			}
		}
	}

	return index;
}

int altaVuelo(eVuelo vuelos[], int tamV, eAvion aviones[], int tamAvi,
			eDestino destinos[], int tamD, eAerolinea aerolineas[], int tamA,
			eTipo tipos[], int tamT, int* pId){
	int todoOk = 0;
	int index;
	eVuelo auxVuelo;

	if (vuelos != NULL && tamV > 0 && aviones != NULL && tamAvi > 0 && destinos != NULL && tamD > 0){

		index = buscarLibreVuelos(vuelos, tamV);

		if (index == -1){
			printf("No se pueden agregar mas vuelos\n");
		} else {
			//id vuelo
			auxVuelo.id = *pId;
			(*pId)++;

			//mostrar aviones
			mostrarAviones(aviones, tamAvi, aerolineas, tamA, tipos, tamT);
			//pido id aviones
			utn_getNumero(&auxVuelo.idAvion, "Ingrese ID Avion: ",
								"\nError, reingrese ID Avion: ", INT_MIN, INT_MAX, 9);
			//VALIDACION DEL ID DEL AVION
			while(buscarAvionId(aviones, tamAvi, auxVuelo.idAvion) == -1){
				utn_getNumero(&auxVuelo.idAvion, "\nError, invalido. Reingrese ID Avion: ",
												"\nError, reingrese ID Avion: ", INT_MIN, INT_MAX, 9);
			}

			// MUESTRO LOS DESTINOS
			mostrarDestinos(destinos, tamD);

			// SOLICITO EL ID DE DESTINO
			utn_getNumero(&auxVuelo.idDestino, "Ingrese el ID Destino: ",
											"\nError, reingrese el ID Destino: ", INT_MIN, INT_MAX, 9);
			//valido destino
			while(!validarIdDestinos(auxVuelo.idDestino, destinos, tamD)){
				utn_getNumero(&auxVuelo.idDestino, "\nError!, invalido. Reingrese el ID Destino: ",
															"\nError, reingrese el ID Destino: ", INT_MIN, INT_MAX, 9);
			}

			//VALIDACION DEL ID DEL DIA

			utn_getNumero(&auxVuelo.fecha.dia, "Dia: ", "\nError, reingrese dia: ", 1, 31, 9);
			utn_getNumero(&auxVuelo.fecha.mes, "Mes: ","\nError, reingrese mes: ", 1, 12, 9);
			utn_getNumero(&auxVuelo.fecha.anio, "Anio: ","\nError, reingrese anio: ", 0, 9999, 9);

            //validarFechas(&auxVuelo); //me tiraba muchos errores con fecha.h cuando hacia include de vuelo.h

			auxVuelo.isEmpty = LLENO;

			vuelos[index] = auxVuelo;


			todoOk = 1;


		}

	}


	return todoOk;

}

//mostrar
void mostrarVuelo(eVuelo unVuelo, eAvion aviones[], int tamAvi, eDestino destinos[], int tamD, eAerolinea aerolineas[], int tamA){

	char descAvion[20];
	char descDestino[30];



	cargarDescAvion(aviones, tamAvi, unVuelo.idAvion, descAvion, aerolineas, tamA);
	//printf("la descripcion que trajo cargardescavion es: %s\n", descAvion);
	//system("pause");

	cargarDescDestinos(destinos, tamD, unVuelo.idDestino, descDestino);
    //printf("la destinoque trajo cargardescdestinos es: %s\n", descDestino);
	//system("pause");

	printf("%5d    %14s   %14s   %02d/%02d/%4d  \n",
			unVuelo.id,
			descAvion,
			descDestino,
			unVuelo.fecha.dia,
			unVuelo.fecha.mes,
			unVuelo.fecha.anio);

}

//mostrarTodos
int mostrarVuelos(eVuelo vuelos[], int tamV, eAvion aviones[], int tamAvi, eDestino destinos[], int tamD, eAerolinea aerolineas[], int tamA){
	int todoOk = 0;
	int flag = 1;

	if (vuelos != NULL && tamV > 0 && aviones != NULL && tamAvi > 0 && destinos != NULL && tamD > 0 && aerolineas != NULL && tamA > 0){


			printf("\n      ########## Listado de Vuelos ##########\n");
			printf("-----------------------------------------------------\n");
			printf("   Id          Compania          Destino        Fecha\n");
			printf("-----------------------------------------------------\n");

			for (int i = 0; i < tamV; i++){
				todoOk = 1;
				if (vuelos[i].isEmpty == LLENO){
					mostrarVuelo(vuelos[i], aviones, tamAvi, destinos, tamD, aerolineas, tamA);
					flag = 0;
				}
			}

			if (flag){
				printf("No hay vuelos para mostrar");
			}

	}
	return todoOk;
}
