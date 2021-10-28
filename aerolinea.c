#include "aerolinea.h"

/** \brief valida el id de la aerolinea.
 *
 * \param int ID aerolinea
 * \param tipo struct vector de campos.
 * \param tamanio del vector
 * \return int "1" si salio ok, "0" si fallo.
 *
 */
int validarIdAerolineas(int idRecibido, eAerolinea aerolineas[], int tam) {
	int todoOk = 0;

	if (idRecibido > 0 && aerolineas != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (aerolineas[i].id == idRecibido) {
				todoOk = 1;
				break;
			}
		}
	}

	return todoOk;
}
/** \brief muestra una aerolinea
 *
 * \param tipo struct var a un elemento
 * \return void
 *
 */

void mostrarAerolinea(eAerolinea unaAerolinea) {
	printf("%6d                %12s\n", unaAerolinea.id, unaAerolinea.descripcion);
}

/** \brief muestra el listado de las aerolines
 *
 * \param tipo struct, vector de campos
 * \param int tamanio de vector.
 * \return int "1" si salio ok, "0" si fallo.
 *
 */
int mostrarAerolineas(eAerolinea aerolineas[], int tam) {
	int todoOk = 0;

	printf("\n\n###### Listado de Aerolineas ######\n");
	printf("-----------------------------------\n");
	printf("   Id                  Descripcion\n");
	printf("-----------------------------------\n");

	if (aerolineas != NULL && tam > 0) {
		todoOk = 1;
		for (int i = 0; i < tam; i++) {
			mostrarAerolinea(aerolineas[i]);
		}
	}

	return todoOk;
}
/** \brief carga la descripcion de la aerolinea.
 *
 * \param tipo struct, vector de campos.
 * \param int tamanio del vector
 * \param int id de la aerolinea
 * \param char donde se copiara la descripcion.
 * \return int "1" si salio ok, "0" si fallo.
 *
 */
int cargarDescripcionAerolineas(eAerolinea aerolineas[], int tam, int idRecibido, char descripcion[]) {
	int todoOk = 0;
//    printf("el id recibido en cargarDescAerolineas de aerolinea.c es: %d\n", idRecibido);

	if (idRecibido > 0 && aerolineas != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (aerolineas[i].id == idRecibido) {
				strcpy(descripcion, aerolineas[i].descripcion);
				todoOk = 1;
				break;
			}
		}
	}

	return todoOk;
}
