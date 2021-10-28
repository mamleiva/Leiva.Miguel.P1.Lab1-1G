#include "destino.h"

/*
typedef struct
{
    int id;
    char descripcion[25];
    float precio;

} eDestino;
*/

//mostrar
void mostrarDestino(eDestino unDestino) {
	printf("%d        %10s    %10.2f\n", unDestino.id, unDestino.descripcion, unDestino.precio);
}

//mostrartodos
int mostrarDestinos(eDestino destinos[], int tamD) {
	int todoOk = 0;

	printf("######### Listado de Destinos #########\n");
	printf("-------------------------------------\n");
	printf(" Id             Destino        Precio\n");
	printf("-------------------------------------\n");

	if (destinos != NULL && tamD > 0) {
		todoOk = 1;
		for (int i = 0; i < tamD; i++) {
			mostrarDestino(destinos[i]);
		}
	}

	return todoOk;
}

//cargar descripcion
int cargarDescDestinos(eDestino destinos[], int tamD, int idRecibido, char descripcion[]) {
	int todoOk = 0;

	if (idRecibido > 0 && destinos != NULL && tamD > 0) {
		for (int i = 0; i < tamD; i++) {
			if (destinos[i].id == idRecibido) {
				strcpy(descripcion, destinos[i].descripcion);
				todoOk = 1;
				break;
			}
		}
	}

	return todoOk;
}

//validarid
int validarIdDestinos(int idRecibido, eDestino destinos[], int tamD) {
	int todoOk = 0;

	if (idRecibido > 0 && destinos != NULL && tamD > 0) {
		for (int i = 0; i < tamD; i++) {
			if (destinos[i].id == idRecibido) {
				todoOk = 1;
				break;
			}
		}
	}

	return todoOk;
}
