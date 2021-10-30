#include "piloto.h"


/** \brief inicializa el vector de pilotos, marcando isEmpty en "1"
 *
 * \param vector tipo struct de personas
 * \param tam del vector  de personas
 * \return "1" si salio todo ok, "0" si fallo
 *
 */
int inicializarPilotos(ePiloto lista[], int tam)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0)
    {
        for(int i =0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;

    }
    return todoOk;
}


/** \brief alta de piloto
 *
 * \param struct del vector piloto
 * \param tamanio del vector de piloto.
 * \param int puntero con el id del piloto.
 * \return "1" si salio ok, "0" si fallo.
 *
 */

int altaPiloto(ePiloto lista[], int tam, int* pId)
{
     int todoOk = 0;
    int indice;
    ePiloto auxPersona;
    if(lista != NULL && tam > 0 && pId != NULL)
    {
        system("cls");
        printf("          ***Alta Piloto ****\n");
        indice = buscarLibrePiloto(lista, tam);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            auxPersona.idPiloto = *pId;
            (*pId)++;

            utn_getNombre(auxPersona.nombre, 20, "Ingrese el nombre del piloto: ", "Error! reingrese el nombre, solo letras sin espacio", 10);

            utn_pedirCaracter(&auxPersona.sexo, "Ingrese el sexo \"m\" o \"f\": ", "Error reingrese \"m\" o \"f\"", 'm', 'f');

            utn_getNumero(&auxPersona.edad, "Ingrese la edad del piloto: ", "Error! reingrese la edad", 1, 120, 10);

            auxPersona.isEmpty = FALSO; // marca como ocupado ese indice

            lista[indice] = auxPersona;
            todoOk = 1;
        }
    }
    return todoOk;

}

/** \brief busca posicion libre para piloto
 *
 * \param tipo struct vector de piloto
 * \param tam del del vector
 * \return -1 si fallo, o el numero de indice si salio ok.
 *
 */

int buscarLibrePiloto(ePiloto lista[], int tam)
{
    int indice = -1;
    if(lista != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if(lista[i].isEmpty ==1) // el primer indice que esta marcado como vacio, lo usa,
                //en la vida real, no se reutilizan los campos, solo se marcan como disable y no se los muestra.
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}


