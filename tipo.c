#include "tipo.h"


void mostrarTipo(eTipo unTipo) {
	printf("%5d         %16s\n", unTipo.id, unTipo.descripcion);
}

//mostrartodos
int mostrarTipos(eTipo tipos[], int tamT) {
	int todoOk = 0;

	printf("  ####### Listado de Tipos de Aviones #########\n");
	printf("-----------------------------------------------\n");
	printf("   Id              Descripcion\n");
	printf("-----------------------------------------------\n");

	if (tipos != NULL && tamT > 0) {
		todoOk = 1;
		for (int i = 0; i < tamT; i++) {
			mostrarTipo(tipos[i]);
		}
	}

	return todoOk;
}

//cargar descripcion
int cargarDescTipos(eTipo tipos[], int tamT, int idRecibido, char descripcion[]) {
	int todoOk = 0;

	if (idRecibido > 0 && tipos != NULL && tamT > 0) {
		for (int i = 0; i < tamT; i++) {
			if (tipos[i].id == idRecibido) {
				strcpy(descripcion, tipos[i].descripcion);
				todoOk = 1;
				break;
			}
		}
	}

	return todoOk;
}

//validarid
int validarIdTipos(int idRecibido, eTipo tipos[], int tamT) {
	int todoOk = 0;

	if (idRecibido > 0 && tipos != NULL && tamT > 0) {
		for (int i = 0; i < tamT; i++) {
			if (tipos[i].id == idRecibido) {
				todoOk = 1;
				break;
			}
		}
	}

	return todoOk;
}

