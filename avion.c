#include "avion.h"
#include "inputs.h"
#include "biblioteca_utn.h"

/** \brief inicializa los aviones
 *
 * \param tipo struct vector de aviones
 * \param int tamanio del vector de aviones
 * \return "1" si salio ok, "0" si fallo.
 *
 */
int inicializarAviones(eAvion aviones[], int tam_aviones)
{
    int todoOk = 0;

    if (aviones != NULL && tam_aviones > 0)
    {
        for (int i = 0; i < tam_aviones; i++)
        {
            aviones[i].isEmpty = VERDADERO;
        }
        todoOk = 1;
    }

    return todoOk;
}

/** \brief busca lugar libre, viendo el valor de isEmpty en 1
 *
 * \param tipo struct vector de aviones
 * \param int tamanio del vector de aviones
 * \return "-1" si fallo o no encontro lugar, indice del avion si salio ok.
 *
 */
int buscarLibreAviones(eAvion aviones[], int tam_aviones)
{
    int index = -1;

    if (aviones != NULL && tam_aviones > 0)
    {
        for (int i = 0; i < tam_aviones; i++)
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

/** \brief Da de alta un avion
 *
 * \param tipo struct vector de aviones
 * \param int tamanio del vector de aviones
 * \param tipo struct vector de aerolinea
 * \param int tamanio del vector de aerolinea
 * \param tipo struct vector de tipos
 * \param int tamanio del vector de tipos
 * \param int puntero al id del avion.
 * \return "1" si salio ok, "0" si fallo.
 *
 */
int altaAviones(eAvion aviones[], int tam_aviones, eAerolinea aerolineas[], int tam_aerolinea, eTipo tipos[], int tam_tipos, int *pId)
{
    int todoOk = 0;
    int index;
    eAvion auxAvion;

    if (aviones != NULL && tam_aviones > 0 && aerolineas != NULL && tam_aerolinea > 0
            && tipos != NULL && tam_tipos > 0)
    {

        index = buscarLibreAviones(aviones, tam_aviones);

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
            mostrarAerolineas(aerolineas, tam_aerolinea);
            utn_getNumero(&auxAvion.idAerolinea, "Ingrese ID Aerolinea: ",
                          "\nError, reingrese ID Aerolinea: ", 1, INT_MAX, 10);

                    //Validacion de Aerolinea
            while (!validarIdAerolineas(auxAvion.idAerolinea, aerolineas, tam_aerolinea))
            {
                utn_getNumero(&auxAvion.idAerolinea, "Error. Id Aerolinea invalido, reingrese: ",
                              "\nError, reingrese ID Aerolinea: ", 1, INT_MAX, 10);
            }

                    //Solicitud de  tipo de avion
            mostrarTipos(tipos, tam_tipos);
            utn_getNumero(&auxAvion.idTipo, "Ingrese ID de Tipo de Avion: ", "\nError, reingrese ID Tipo: ", 1, INT_MAX, 10);

                    //validacion de  tipo de avion
            while (!validarIdTipos(auxAvion.idTipo, tipos, tam_tipos))
            {
                utn_getNumero(&auxAvion.idTipo, "Error. Id Tipo invalido, reingrese: ",
                              "\nError, reingrese ID Tipo: ", 1, INT_MAX, 10);
            }

                //Solicitud de Capacidad
            utn_getNumero(&auxAvion.capacidad, "Ingrese cantidad pasajeros (entre 10 y 300): ", "\nError, reingrese cantidad pasajeros (entre 10 y 300): ", 10, 300, 10);
            //validacion de capacidad incluida en la funcion utn_getNumero
            //ya que pide ingresar un numero entre 10 y 300

            auxAvion.isEmpty = FALSO;

            aviones[index] = auxAvion;

            todoOk = 1;

        }

    }

    return todoOk;
}

/** \brief muestra un avion que recibe con si indice
 *
 * \param campo de un aviones
 * \param tipo struct vector de aerolinea
 * \param int tamanio del vector de aerolinea
 * \param tipo struct vector de tipos
 * \param int tamanio del vector de tipos
 * \return VOID no devuelve nada
 *
 */
void mostrarAvion(eAvion unAvion, eAerolinea aerolineas[], int tam_aerolineas, eTipo tipos[], int tam_tipos)
{

    char descripcionAerolinea[20];
    char descripcionTipo[20];

    cargarDescripcionAerolineas(aerolineas, tam_aerolineas, unAvion.idAerolinea, descripcionAerolinea);
    cargarDescTipos(tipos, tam_tipos, unAvion.idTipo, descripcionTipo);


    printf("%d       %11s      %10s        %d \n", unAvion.idAvion, descripcionAerolinea, descripcionTipo, unAvion.capacidad);

}

/** \brief muestra por pantalla todos los aviones
 *
 * \param tipo struct vector de aviones
 * \param int tamanio del vector de aviones
 * \param tipo struct vector de aerolineas
 * \param int tamanio del vector de aerolineas
 * \param tipo struct vector de tipos
 * \param int tamanio del vector de tipos
 * \return "1" si salio ok, "0" si fallo.
 *
 */
int mostrarAviones(eAvion aviones[], int tam_aviones, eAerolinea aerolineas[], int tam_aerolineas, eTipo tipos[], int tam_tipos)
{
    int todoOk = 0;
    int flag = 1;

    if (aviones != NULL && tam_aviones > 0 && aerolineas != NULL && tam_aerolineas > 0
            && tipos != NULL && tam_tipos > 0)
    {

        todoOk = 1;

        printf("#############   Listado de Aviones ###################\n");
        printf("------------------------------------------------------\n");
        printf("  ID         Aerolinea            Tipo    Capacidad\n");
        printf("------------------------------------------------------\n");

        //ordenar aviones antes de mostrar
        ordenarAviones(aviones, tam_aviones, aerolineas, tam_aerolineas);

        for (int i = 0; i < tam_aviones; i++)
        {
            if (aviones[i].isEmpty == FALSO)
            {
                mostrarAvion(aviones[i], aerolineas, tam_aerolineas, tipos, tam_tipos);
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

/** \brief busca un avion con el id que recibe por parametro
 *
 * \param tipo struct vector de aviones
 * \param int tamanio del vector de aviones
 * \param int con el id a buscar
 * \return "-1" si fallo, o el numero de indice si salio ok.
 *
 */
int buscarAvionId(eAvion aviones[], int tam_aviones, int idRecibido)
{
    int index = -1;

    if (aviones != NULL && tam_aviones > 0 && idRecibido > 0)
    {
        for(int i = 0; i < tam_aviones; i++)
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

/** \brief
 *
 * \param tipo struct vector de aviones
 * \param int tamanio del vector de aviones
 * \param tipo struct vector de aerolineas
 * \param int tamanio del vector de aerolineas
 * \param tipo struct vector de tipos
 * \param int tamanio del vector de tipos
 * \return "1" si salio ok, "0" si fallo.
 *
 */
int bajaAviones(eAvion aviones[], int tam_aviones, eAerolinea aerolineas[], int tam_aerolineas,
                eTipo tipos[], int tam_tipos)
{
    int todoOk = 0;
    int auxId;
    int index;

    if (aviones != NULL && tam_aviones > 0 && aerolineas != NULL && tam_aerolineas > 0
            && tipos != NULL && tam_tipos > 0)
    {

        printf("    *** Baja Aviones ***\n");
        printf("--------------------------\n");

        //muestro
        mostrarAviones(aviones, tam_aviones, aerolineas, tam_aerolineas, tipos, tam_tipos);

        //pido id
        utn_getNumero(&auxId, "Ingrese ID del avion a ELIMINAR: ",
                      "\nError, ID invalido, reingrese ID del avion a ELIMINAR: ",
                      INT_MIN, INT_MAX, 9);

        //busco que el id exista
        index = buscarAvionId(aviones, tam_aviones, auxId);

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

/** \brief Modifica los aviones, segun el id que recibe por parametro y abre un submenu
 *
 * \param tipo struct vector de aviones
 * \param int tamanio del vector de aviones
 * \param tipo struct vector de aerolineas
 * \param int tamanio del vector de aerolineas
 * \param tipo struct vector de tipos
 * \param int tamanio del vector de tipos
 * \return "1" si salio ok, "0" si fallo.
 *
 */
int modificarAviones(eAvion aviones[], int tam_aviones, eAerolinea aerolineas[], int tam_aerolineas, eTipo tipos[], int tam_tipos)
{
    int todoOk = 0;
    int auxId;
    int index;
    int auxTipo;
    int auxCapacidad;
    char opcionModificacion;
    char deseaSalir;
    char seguir = 's';

    if (aviones != NULL && tam_aviones > 0 && aerolineas != NULL && tam_aerolineas > 0
            && tipos != NULL && tam_tipos > 0)
    {

        printf("    *** Modificar Aviones ***\n");
        printf("-----------------------------\n");

        //muestro aviones
        mostrarAviones(aviones, tam_aviones, aerolineas, tam_aerolineas, tipos, tam_tipos);

        //pido id
        utn_getNumero(&auxId, "Ingrese ID del avion a MODIFICAR: ", "\nError, ID invalido, reingrese ID del avion a MODIFICAR: ", INT_MIN, INT_MAX, 10);

        //busco que el id exista
        index = buscarAvionId(aviones, tam_aviones, auxId);

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
                    mostrarTipos(tipos, tam_tipos);
                    utn_getNumero(&auxTipo, "Ingrese ID Tipo: ", "\nError, reingrese un ID Tipo valido: ", INT_MIN, INT_MAX, 10);


                    //valido tipo
                    while (!validarIdTipos(auxTipo, tipos, tam_tipos))
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

/** \brief ordena ascendente, los aviones por descripcion de aerolinea y por id de avion , es llamada por mostrar aviones
 *
 * \param tipo struct vector de aviones
 * \param int tamanio del vector de aviones
 * \param tipo struct vector de aerolineas
 * \param int tamanio del vector de aerolinea
 * \return "1" si salio ok, "0" si fallo.
 *
 */
int ordenarAviones(eAvion aviones[], int tam_aviones, eAerolinea aerolineas[], int tam_aerolineas)
{
    int todoOk = 0;
    char descripcionIndiceI[20];
    char descripcionIndiceJ[20];
    eAvion auxAvion;

    if (aviones != NULL && tam_aviones > 0 && aerolineas != NULL && tam_aerolineas > 0)
    {

        for (int i = 0; i < tam_aviones - 1; i++)
        {

            for (int j = i + 1; j < tam_aviones; j++)
            {

                cargarDescripcionAerolineas(aerolineas, tam_aerolineas, aviones[i].idAerolinea, descripcionIndiceI);
                cargarDescripcionAerolineas(aerolineas, tam_aerolineas, aviones[j].idAerolinea, descripcionIndiceJ);
                if (strcmp(descripcionIndiceI, descripcionIndiceJ) > 0 || (strcmp(descripcionIndiceI, descripcionIndiceJ) == 0
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

/** \brief carga la descripcion de la aerolinea en el vector descripcionAerolinea
 *
 * \param tipo struct vector de aviones
 * \param int tamanio del vector de aviones
 * \param tipo struct vector de aerolineas
 * \param int tamanio del vector de aerolinea
 * \param int con el id a buscar para cargar la descripcion
 * \return "1" si salio ok, "0" si fallo.
 *
 */
int cargarDescripcionAvion(eAvion aviones[], int tam_aviones, char descripcion[], eAerolinea aerolineas[], int tam_aerolineas, int idRecibido)
{
    int todoOk = 0;

    char descripcionAerolinea[20];

    if (idRecibido > 0 && aviones != NULL && tam_aviones > 0)
    {
        for (int i = 0; i < tam_aviones; i++)
        {
            if (aviones[i].idAvion == idRecibido)
            {
                cargarDescripcionAerolineas(aerolineas, tam_aerolineas, aviones[i].idAerolinea, descripcionAerolinea);
                strcpy(descripcion, descripcionAerolinea);
                todoOk = 1;
            }
        }
    }
    return todoOk;
}




