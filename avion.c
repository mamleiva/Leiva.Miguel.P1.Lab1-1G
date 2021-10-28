#include "avion.h"
#include "inputs.h"
#include "biblioteca_utn.h"

//inicializar
int inicializarAviones(eAvion aviones[], int tamAvi)
{
    int todoOk = 0;

    if (aviones != NULL && tamAvi > 0)
    {
        for (int i = 0; i < tamAvi; i++)
        {
            aviones[i].isEmpty = VERDADERO;
        }
        todoOk = 1;
    }

    return todoOk;
}

//buscar libre
int buscarLibreAviones(eAvion aviones[], int tamAvi)
{
    int index = -1;

    if (aviones != NULL && tamAvi > 0)
    {
        for (int i = 0; i < tamAvi; i++)
        {
            if (aviones[i].isEmpty == VERDADERO)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}

//alta
int altaAviones(eAvion aviones[], int tamAvi, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT, int *pId)
{
    int todoOk = 0;
    int index;
    eAvion auxAvion;


    if (aviones != NULL && tamAvi > 0 && aerolineas != NULL && tamA > 0
            && tipos != NULL && tamT > 0)
    {

        index = buscarLibreAviones(aviones, tamAvi);

        if ( index == -1)
        {

            printf("No se pueden agregar mas aviones, no hay lugar disponible.\n");

        }
        else
        {
            system("cls");
            printf("    ### Alta  de Aviones ###***\n\n");

            auxAvion.idAvion = *pId;
            (*pId)++;

                    //Solicitud de Aerolinea
            mostrarAerolineas(aerolineas, tamA);
            utn_getNumero(&auxAvion.idAerolinea, "Ingrese ID Aerolinea: ",
                          "\nError, reingrese ID Aerolinea: ", 1, INT_MAX, 10);

                    //Validacion de Aerolinea
            while (!validarIdAerolineas(auxAvion.idAerolinea, aerolineas, tamA))
            {
                utn_getNumero(&auxAvion.idAerolinea, "Error. Id Aerolinea invalido, reingrese: ",
                              "\nError, reingrese ID Aerolinea: ", 1, INT_MAX, 10);
            }

                    //Solicitud de  tipo de avion
            mostrarTipos(tipos, tamT);
            utn_getNumero(&auxAvion.idTipo, "Ingrese ID de Tipo de Avion: ", "\nError, reingrese ID Tipo: ", 1, INT_MAX, 10);

                    //validacion de  tipo de avion
            while (!validarIdTipos(auxAvion.idTipo, tipos, tamT))
            {
                utn_getNumero(&auxAvion.idTipo, "Error. Id Tipo invalido, reingrese: ",
                              "\nError, reingrese ID Tipo: ", 1, INT_MAX, 10);
            }

                //Solicitud de Capacidad
            utn_getNumero(&auxAvion.capacidad, "Ingrese cantidad pasajeros (entre 10 y 300): ", "\nError, reingrese cantidad pasajeros (entre 10 y 300): ", 10, 300, 10);
            //validacion de capacidad incluida en la funcion utn_getNumero
            //ya que pide ingresar un numero entre 10 y 300


            //mostrarAvion(auxAvion, aerolineas, tamA, tipos, tamT);

            auxAvion.isEmpty = FALSO;

            aviones[index] = auxAvion;

            todoOk = 1;

        }

    }

    return todoOk;
}

//mostrar 1 solo avion
void mostrarAvion(eAvion unAvion, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT)
{

    char descripcionAerolinea[20];
    char descripcionTipo[20];

    cargarDescripcionAerolineas(aerolineas, tamA, unAvion.idAerolinea, descripcionAerolinea);
    cargarDescTipos(tipos, tamT, unAvion.idTipo, descripcionTipo);


    printf("%d       %11s      %10s        %d \n", unAvion.idAvion, descripcionAerolinea, descripcionTipo, unAvion.capacidad);

}



//mostrarTodos
int mostrarAviones(eAvion aviones[], int tamAvi, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int flag = 1;

    if (aviones != NULL && tamAvi > 0 && aerolineas != NULL && tamA > 0
            && tipos != NULL && tamT > 0)
    {

        todoOk = 1;

        printf("#############   Listado de Aviones ###################\n");
        printf("------------------------------------------------------\n");
        printf("  ID         Aerolinea            Tipo    Capacidad\n");
        printf("------------------------------------------------------\n");

        //ordenar aviones antes de mostrar
        ordenarAviones(aviones, tamAvi, aerolineas, tamA);

        for (int i = 0; i < tamAvi; i++)
        {
            if (aviones[i].isEmpty == FALSO)
            {
                mostrarAvion(aviones[i], aerolineas, tamA, tipos, tamT);
                flag = 0;
            }
        }

        if (flag)
        {
            printf("No se pudieron mostrar los aviones\n");
        }

    }

    return todoOk;
}


//buscarid
int buscarAvionId(eAvion aviones[], int tamAvi, int idRecibido)
{
    int index = -1;

    if (aviones != NULL && tamAvi > 0 && idRecibido > 0)
    {
        for(int i = 0; i < tamAvi; i++)
        {
            if (aviones[i].isEmpty == FALSO && aviones[i].idAvion == idRecibido)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}

//baja
int bajaAviones(eAvion aviones[], int tamAvi, eAerolinea aerolineas[], int tamA,
                eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int auxId;
    int index;

    if (aviones != NULL && tamAvi > 0 && aerolineas != NULL && tamA > 0
            && tipos != NULL && tamT > 0)
    {

        printf("    *** Baja Aviones ***\n");
        printf("--------------------------\n");

        //muestro
        mostrarAviones(aviones, tamAvi, aerolineas, tamA, tipos, tamT);

        //pido id
        utn_getNumero(&auxId, "Ingrese ID del avion a ELIMINAR: ",
                      "\nError, ID invalido, reingrese ID del avion a ELIMINAR: ",
                      INT_MIN, INT_MAX, 9);

        //busco que el id exista
        index = buscarAvionId(aviones, tamAvi, auxId);

        //elimino o no segun corresponda
        if (index == -1)
        {
            printf("El id ingresado no existe.\n");
        }
        else
        {
            aviones[index].isEmpty = VERDADERO;
            todoOk = 1;
            printf("El avion se dio de baja con exito.\n");
        }

    }

    return todoOk;
}

//modificar
int modificarAviones(eAvion aviones[], int tamAvi, eAerolinea aerolineas[], int tamA, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int auxId;
    int index;
    int auxTipo;
    int auxCapacidad;
    char opcionModificacion;
    char deseaSalir;
    char seguir = 's';

    if (aviones != NULL && tamAvi > 0 && aerolineas != NULL && tamA > 0
            && tipos != NULL && tamT > 0)
    {

        printf("    *** Modificar Aviones ***\n");
        printf("-----------------------------\n");

        //muestro aviones
        mostrarAviones(aviones, tamAvi, aerolineas, tamA, tipos, tamT);

        //pido id
        utn_getNumero(&auxId, "Ingrese ID del avion a MODIFICAR: ", "\nError, ID invalido, reingrese ID del avion a MODIFICAR: ", INT_MIN, INT_MAX, 10);

        //busco que el id exista
        index = buscarAvionId(aviones, tamAvi, auxId);

        //elimino o no segun corresponda
        if (index == -1)
        {
            printf("El id ingresado no existe.\n");
        }
        else
        {
            do
            {

                opcionModificacion = menuModificacion();

                switch (opcionModificacion)
                {
                case 'a':
                    //muestro y pido tipo
                    mostrarTipos(tipos, tamT);
                    utn_getNumero(&auxTipo, "Ingrese ID Tipo: ", "\nError, reingrese un ID Tipo valido: ", INT_MIN, INT_MAX, 10);


                    //valido tipo
                    while (!validarIdTipos(auxTipo, tipos, tamT))
                    {
                        utn_getNumero(&auxTipo, "Ingrese ID Tipo: ", "\nError, reingrese un ID Tipo valido: ", INT_MIN, INT_MAX, 10);
                    }

                    aviones[index].idTipo = auxTipo;

                    todoOk = 1;

                    break;
                case 'b':
                    //pido y valido modif capacidad
                    utn_getNumero(&auxCapacidad, "Ingrese nueva Capacidad(entre 10 y 300): ", "\nError, reingrese una capacidad valida (entre 10 y 300): ", 10, 300, 10);

                    //modifico
                    aviones[index].capacidad = auxCapacidad;

                    todoOk = 1;

                    break;
                case 'c':
                    printf("Esta seguro que desea salir? (s/n): ");
                    fflush(stdin);
                    scanf("%c", &deseaSalir);
                    deseaSalir = tolower(deseaSalir);

                    if (deseaSalir == 's')
                    {
                        seguir = 'n';
                    }
                    //exit
                    break;
                default:
                    printf("Opcion invalida!\n");
                    break;
                }
            }
            while (seguir == 's');

            system("pause");

        }

    }


    return todoOk;

}

//ordenamiento
int ordenarAviones(eAvion aviones[], int tamAvi, eAerolinea aerolineas[], int tamA)
{
    int todoOk = 0;
    char descripcionI[20];
    char descripcionJ[20];
    eAvion auxAvion;

    if (aviones != NULL && tamAvi > 0 && aerolineas != NULL && tamA > 0)
    {

        for (int i = 0; i < tamAvi - 1; i++)
        {

            for (int j = i + 1; j < tamAvi; j++)
            {

                cargarDescripcionAerolineas(aerolineas, tamA, aviones[i].idAerolinea, descripcionI);
                cargarDescripcionAerolineas(aerolineas, tamA, aviones[j].idAerolinea, descripcionJ);
                if (strcmp(descripcionI, descripcionJ) > 0 || (strcmp(descripcionI, descripcionJ) == 0
                        && aviones[i].idAvion > aviones[j].idAvion))
                {
                    auxAvion = aviones[i];
                    aviones[i] = aviones[j];
                    aviones[j] = auxAvion;

                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int cargarDescAvion(eAvion aviones[], int tamAvi, int idRecibido, char descripcion[], eAerolinea aerolineas[], int tamA)
{
    int todoOk = 0;

    char descAerolinea[20];

    if (idRecibido > 0 && aviones != NULL && tamAvi > 0)
    {
        for (int i = 0; i < tamAvi; i++)
        {
            if (aviones[i].idAvion == idRecibido)
            {
                cargarDescripcionAerolineas(aerolineas, tamA, aviones[i].idAerolinea, descAerolinea);
                strcpy(descripcion, descAerolinea);
            }
        }
    }

    return todoOk;
}




