#include "vuelo.h"


/** \brief Inicializa los vuelos con isEmpty en 1.
 *
 * \param tipo struct vector de vuelos
 * \param int tamanio del vector de vuelos
 * \return "1" si salio ok, "0" si fallo.
 *
 */
int iniciarVuelos(eVuelo vuelos[], int tam){
	int todoOk = 0;

	if (vuelos != NULL && tam > 0){
		for (int i = 0; i < tam; i++){
			vuelos[i].isEmpty = VERDADERO;
			todoOk = 1;
		}
	}

	return todoOk;
}

/** \brief busca los vuelos libres, buscando el valor isEmpty en "1"
 *
 * \param tipo struct vector de vuelos
 * \param int tamanio del vector de vuelos
 * \return "-1" si fallo, o el numero de indice si salio ok.
 *
 */
int buscarVuelosLibres(eVuelo vuelos[], int tam){
	int index = -1;

	if (vuelos != NULL && tam > 0){
		for (int i = 0; i < tam; i++){
			if (vuelos[i].isEmpty == VERDADERO){
				index = i;
				break;
			}
		}
	}

	return index;
}

/** \brief Da de alta un vuelo.
 *
 * \param tipo struct vector de vuelos
 * \param int tamanio del vector de vuelo
 * \param tipo struct vector de aviones
 * \param int tamanio del vector de aviones
 * \param tipo struct vector de destinos
 * \param int tamanio del vector de destinos
 * \param tipo struct vector de aerolineas
 * \param int tamanio del vector de aerolineas
 * \param tipo struct vector de tipos
 * \param int tamanio del vector de tipos
 * \param puntero al int para el id de vuelo.
 * \return "1" si salio ok, "0" si fallo.
 *
 */
int altaVuelo(eVuelo vuelos[], int tam_vuelos, eAvion aviones[], int tam_aviones,
			eDestino destinos[], int tam_destinos, eAerolinea aerolineas[], int tam_aerolineas,
			eTipo tipos[], int tam_tipos, int* pId){
	int todoOk = 0;
	int index;
	eVuelo auxVuelo;

	if (vuelos != NULL && tam_vuelos > 0 && aviones != NULL && tam_aviones > 0 && destinos != NULL && tam_destinos > 0){

		index = buscarVuelosLibres(vuelos, tam_vuelos);

		if (index == -1){
			printf("No se pueden agregar mas vuelos\n");
		} else {
                //SETEO EL ID DE VUELO Y LUEGO LO INCREMENTO
			auxVuelo.id = *pId;
			(*pId)++;

                //MUESTRA LOS AVIONES
			mostrarAviones(aviones, tam_aviones, aerolineas, tam_aerolineas, tipos, tam_tipos);
			//pido id aviones
			utn_getNumero(&auxVuelo.idAvion, "Ingrese ID Avion: ",
								"\nError! reingrese ID Avion: ", INT_MIN, INT_MAX, 9);
                //VALIDACION DEL ID DEL AVION
			while(buscarAvionId(aviones, tam_aviones, auxVuelo.idAvion) == -1){
				utn_getNumero(&auxVuelo.idAvion, "\nError! invalido. Reingrese ID Avion: ",
												"\nError! reingrese ID Avion: ", INT_MIN, INT_MAX, 9);
			}

                // MUESTRO LOS DESTINOS
			mostrarDestinos(destinos, tam_destinos);

                // SOLICITO EL ID DE DESTINO
			utn_getNumero(&auxVuelo.idDestino, "Ingrese el ID Destino: ",
											"\nError! reingrese el ID Destino: ", INT_MIN, INT_MAX, 9);
                //valido destino
			while(!validarIdDestinos(auxVuelo.idDestino, destinos, tam_destinos)){
				utn_getNumero(&auxVuelo.idDestino, "\nError!, invalido. Reingrese el ID Destino: ",
															"\nError! reingrese el ID Destino: ", INT_MIN, INT_MAX, 9);
			}

                //  VALIDACION DE FECHAS

			validarFechas(&auxVuelo);
			auxVuelo.isEmpty = FALSO;
			vuelos[index] = auxVuelo;
			todoOk = 1;
		}
	}
	return todoOk;
}

/** \brief Muestra el vuelo
 *
 * \param campo de  un vuelo
 * \param tipo struct vector de aviones
 * \param int tamanio del vector de aviones
 * \param tipo struct vector de destinos
 * \param int tamanio del vector de destinos
 * \param tipo struct vector de aerolineas
 * \param int tamanio del vector de aerolineas
 * \return VOID no devuelve nada
 *
 */
void mostrarVuelo(eVuelo unVuelo, eAvion aviones[], int tam_aviones, eDestino destinos[], int tam_destinos, eAerolinea aerolineas[], int tam_aerolineas){

	char descAvion[20];
	char descDestino[30];
	cargarDescripcionAvion(aviones, tam_aviones, descAvion, aerolineas, tam_aerolineas, unVuelo.idAvion);
	//printf("la descripcion que trajo cargardescavion es: %s\n", descAvion);
	//system("pause");

	cargarDescDestinos(destinos, tam_destinos, unVuelo.idDestino, descDestino);
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

/** \brief muestra todos los vuelos por pantalla
 *
 * \param tipo struct vector de vuelos
 * \param int tamanio del vector de vuelos
 * \param tipo struct vector de aviones
 * \param int tamanio del vector de aviones
 * \param tipo struct vector de destinos
 * \param int tamanio del vector de destinos
 * \param tipo struct vector de aerolineas
 * \param int tamanio del vector de aerolineas
 * \return "1" si salio ok, "0" si fallo.
 *
 */
int mostrarVuelos(eVuelo vuelos[], int tam_vuelos, eAvion aviones[], int tam_aviones, eDestino destinos[], int tam_destinos, eAerolinea aerolineas[], int tam_aerolineas){
	int todoOk = 0;
	int flag = 1;

	if (vuelos != NULL && tam_vuelos > 0 && aviones != NULL && tam_aviones > 0 && destinos != NULL && tam_destinos > 0 && aerolineas != NULL && tam_aerolineas > 0){


			printf("\n      ########## Listado de Vuelos ##########\n");
			printf("-----------------------------------------------------\n");
			printf("   Id          Compania          Destino        Fecha\n");
			printf("-----------------------------------------------------\n");

			for (int i = 0; i < tam_vuelos; i++){
				todoOk = 1;
				if (vuelos[i].isEmpty == FALSO){
					mostrarVuelo(vuelos[i], aviones, tam_aviones, destinos, tam_destinos, aerolineas, tam_aerolineas);
					flag = 0;
				}
			}

			if (flag){
				printf("No hay vuelos para mostrar");
			}
	}
	return todoOk;
}


/** \brief validacion de fechas con validacion de anios bisiestos
 *
 * \param puntero a struct que tiene vinculada la fecha
 * \return "-1" si fallo, "1" si salio ok.
 *
 */

int validarFechas(eVuelo* auxVuelo)
{
    int retorno = -1;
    eVuelo auxFecha; //vector donde se guardara despues de validar, es eVuelo.

    while(retorno != 1)
    {
        utn_getNumero(&auxFecha.fecha.dia, "Ingrese el dia: ", "Error! reingrese el dia: ", 1, 31, 10);
        utn_getNumero(&auxFecha.fecha.mes, "Ingrese el mes: ", "Error! reingrese el dia: ", 1, 12, 10);
        utn_getNumero(&auxFecha.fecha.anio, "Ingrese el anio: ", "Error! reingrese el anio: ", 1, 9999, 10);


        // Validacion de anio
        if(auxFecha.fecha.anio >= 1900 && auxFecha.fecha.anio <= 9999)
        {
            //validacion de mes
            if(auxFecha.fecha.mes>=1 && auxFecha.fecha.mes<=12)
            {
                //validacion de dia
                if((auxFecha.fecha.dia>=1 && auxFecha.fecha.dia<=31) && (auxFecha.fecha.mes==1 || auxFecha.fecha.mes==3 ||
                        auxFecha.fecha.mes==5 || auxFecha.fecha.mes==7 || auxFecha.fecha.mes==8 || auxFecha.fecha.mes==10 || auxFecha.fecha.mes==12))
                {
                    printf("la fecha es valida.\n");
                    auxVuelo->fecha.dia = auxFecha.fecha.dia; //despues de validar lo copio.
                    auxVuelo->fecha.mes = auxFecha.fecha.mes;
                    auxVuelo->fecha.anio = auxFecha.fecha.anio;
                    retorno = 1;
                }

                else if((auxFecha.fecha.dia>=1 && auxFecha.fecha.dia<=30) && (auxFecha.fecha.mes==4 || auxFecha.fecha.mes==6
                        || auxFecha.fecha.mes==9 || auxFecha.fecha.mes==11))
                {
                    printf("la fecha es valida.\n");
                    auxVuelo->fecha.dia = auxFecha.fecha.dia; //despues de validar lo copio.
                    auxVuelo->fecha.mes = auxFecha.fecha.mes;
                    auxVuelo->fecha.anio = auxFecha.fecha.anio;
                    retorno = 1;
                }

                else if((auxFecha.fecha.dia>=1 && auxFecha.fecha.dia<=28) && (auxFecha.fecha.mes==2))
                {
                    printf("la fecha es valida.\n");
                    auxVuelo->fecha.dia = auxFecha.fecha.dia; //despues de validar lo copio.
                    auxVuelo->fecha.mes = auxFecha.fecha.mes;
                    auxVuelo->fecha.anio = auxFecha.fecha.anio;
                    retorno = 1;
                }

                else if(auxFecha.fecha.dia==29 && auxFecha.fecha.mes==2 && (auxFecha.fecha.anio%400==0 ||(auxFecha.fecha.anio%4==0 && auxFecha.fecha.anio%100!=0)))
                {
                    printf("la fecha es valida.\n");
                    auxVuelo->fecha.dia = auxFecha.fecha.dia; //despues de validar lo copio.
                    auxVuelo->fecha.mes = auxFecha.fecha.mes;
                    auxVuelo->fecha.anio = auxFecha.fecha.anio;
                    retorno = 1;

                }
                else
                    printf("El dia es invalido.\n");
            }
            else
            {
                printf("El mes es invalido.\n");
            }
        }
        else
        {
            printf("El año es invalido.\n");
        }

    }//FIN DEL WHILE

    return retorno;

}
