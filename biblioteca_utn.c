/*
 * inputs.c
 *
 *  Created on: 14 oct. 2021
 *      Author: martinl
 */
#include "inputs.h"
static int esNumerica(char *input, int tam);
static int getInt(int *pResultado);
static int esFlotante(char* cadena);
static int getFloat(float* pResultado);
static int getString(char* cadena, int longitud); //ok
static int esNombre(char* cadena,int longitud); //ok
static int getNombre(char* pResultado,int longitud); //ok
static int getDni(char* pResultado, int longitud); //ok
static int esDescripcion(char* cadena,int longitud); //ok
static int getDescripcion(char* pResultado, int longitud); //ok

//para revisar
static int getValidInt(int *numero, char *mensaje);




//####################################### MENUS ##############################################
/*
int menu()
{
    char opcion;

    system("cls");
    printf("        *** Menu de la XXXXXXX ***          \n");
    printf("-------------------------------------------------\n");
    printf("   A- Alta XXXXXXX\n");
    printf("   B- Modificar XXXXXXX\n");
    printf("   C- Baja XXXXXXX\n");
    printf("   D- Listar XXXXXXX\n");
    printf("   E- Listar XXXXXXX\n");
    printf("   E- Listar XXXXXXX\n");
    printf("   E- Alta XXXXXXX\n");
    printf("   E- Listar XXXXXXX\n");
    printf("   Z- Salir\n");

    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = toupper(opcion);

    return opcion;
}

int subMenu()
{
    int opcion;

    system("cls");
    printf("        *** Submenu Menu de XXXXXXX ***          \n");
    printf("------------------------------------------------\n");
    printf("   1- XXXXXXX\n");
    printf("   2- XXXXXXX\n");
    printf("   3- XXXXXXX\n");

    printf("Ingrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}
*/
//####################################### SOLICITUD DE DATOS GENERAL ##############################################
/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		//__fpurge(stdin); // Linux
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}


//#############Funciones de Strings#######################################


/// @fn int esString(char* input, int tam)
/// @brief verifica si la cadena es string
///
/// @param input puntero a donde se copia la cadena
/// @param tam tamanio de la cadena
/// @return
int esString(char *input, int tam)
{
    int i;
    int retorno = 0;

    if (input != NULL && tam > 0)
    {
        for (i = 0; input[i] != '\0' && i < tam; i++)
        {
            if (input[i] != ' ' && input[i] != '.' && (input[i] < 'A' || input[i] > 'Z') && (input[i] < 'a' || input[i] > 'z') && (input[i] < '0' || input[i] > '9'))
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

/// @brief pide una cadena al usuario, permite letras, numeros simbolos y espacios.
/// verifica llamando a la funcion getString(), y devuelve el resultado en *pResultado
/// @param pResultado puntero donde se dejara el resultado si salio ok
/// @param tam longitud del vector
/// @param mensaje mensaje a ser mostrado
/// @param mensajeError mensaje en caso de error
/// @param reintentos numero de veces que el usuario puede reintentar
/// @return 0 si obtiene un entero, -1 si no
int utn_getString(char *pResultado, int tam, char mensaje[], char mensajeError[], int reintentos)
{
    char bufferString[50];
    int retorno = -1;
    while (reintentos >= 0)
    {
        reintentos--;
        printf("%s", mensaje);
        if (getString(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < tam)
        {
            strncpy(pResultado, bufferString, tam);
            retorno = 0;
            break;
        }
        printf("%s", mensajeError);
    }
    return retorno;
}

/**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido solo letras, sin espacio.
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/**
 * \brief Obtiene un string valido como descripcion
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getDescripcion(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esDescripcion(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es una descripcion valida, solo letras, numeros, espacios y puntos SIN Simbolos.
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esDescripcion(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

//########################String con caracteres########################################



//##############Funciones de Numeros enteros#########################

/// @fn int getInt valida que sea numerico y si es numero lo guarda en *pResultado
/// @brief Obtener un numero entero desde la terminal
///
/// @param pResultado Puntero donde se guardara el resultado de la funcion
/// @return Retorna 0 (exito) si se obtiene un entero y -1 (error)
///
static int getInt(int *pResultado)
{
    int retorno = -1;
    char bufferString[50];
    if (pResultado != NULL &&
            getString(bufferString, sizeof(bufferString)) == 0 &&
            esNumerica(bufferString, sizeof(bufferString))) //valida numero que sea numero
    {
        retorno = 0;
        *pResultado = atoi(bufferString); //convierte a int
    }
    return retorno;
}

/// @fn int esNumerica(char* input, int tam);
/// @brief Verifica si la cadena ingresada es numerica, es llamada por la funcion getInt
///
/// @param input Puntero donde se dejara el resultado de la funcion
/// @param tam limite de la cadena
/// @return Retorna 1 si salio OK si la cadena es numero y -1 si no lo es.
///
static int esNumerica(char *input, int tam)
{
    int retorno = 1; //verdadero

    if (input[0] == '\0' || input[0] == ' ') //valido que no presione enter, ni espacio al principio
    {
        retorno = 0;
    }

    for (int i = 0; i < tam && input[i] != '\0'; i++)
    {
        if (i == 0 && (input[i] == '+' || input[i] == '-'))
        {
            continue;
        }
        if ( input[i] > '9' || input[i] < '0' )
        {
            retorno = 0;
            break;
        }

    }
    return retorno;
}

/// @fn int utn_getNumero(int* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);
/// @brief Solicita el ingreso de un entero por mensaje y lo retorna por puntero pResultado
///
/// @param pResultado  Numero a retoronar
/// @param mensaje		Mensaje
/// @param mensajeError Mensaje Error
/// @param minimo		Rango minimo de numeros que puede ingresar
/// @param maximo		Rango maximo de numeros que puede ingresar
/// @param reintentos   Cantidad de reintentos
/// @return   return (1) If ok,   (0) Error, se quedo sin reintentos
int utn_getNumero(int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int bufferInt;
    do
    {
        printf("%s", mensaje);
        if (getInt(&bufferInt) == 0 &&
                bufferInt >= minimo &&
                bufferInt <= maximo)
        {
            retorno = 0;
            *pResultado = bufferInt;
            break;
        }
        printf("%s", mensajeError);
        reintentos--;
    }
    while (reintentos >= 0);

    return retorno;
}

/**
 * \brief Obtiene un string valido como DNI
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getDni(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNumerica(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Solicita un DNI al usuario, luego de verificarlo devuelve el resultado en la var longitid poner la cant de digitos del dni.
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDni(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}


//###############funciones de numeros float###############

/// @fn int utn_getNumeroFlotanteConMinMax(float* pResultado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos);
/// @brief Solicita el ingreso de un numero y lo pasa a float por mensaje y lo retorna por puntero pResultado
///
/// @param pResultado  Numero a retoronar
/// @param mensaje		Mensaje
/// @param mensajeError Mensaje Error
/// @param minimo		Rango minimo de numeros que puede ingresar
/// @param maximo		Rango maximo de numeros que puede ingresar
/// @param reintentos   Cantidad de reintentos
/// @return   Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
int utn_getNumeroFlotanteConMinMax(float *pResultado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos)
{
    int retorno = -1;
    int bufferFloat;
    do
    {
        printf("%s", mensaje);
        if (getInt(&bufferFloat) == 0 && //si es numerico get int devuelve cero y lo guarda en bufferfloat
                bufferFloat >= minimo &&
                bufferFloat <= maximo)
        {
            retorno = 0;
            *pResultado = bufferFloat;
            break;
        }
        printf("%s", mensajeError);
        reintentos--;
    }
    while (reintentos >= 0);

    return retorno;
}

/// @fn pide numero float sin min y max, sin cantidad de reintentos
/// @brief Solicita el ingreso de un numero con la funcion getInt(), lo pasa a float y lo retorna por puntero pResultado
/// @param pResultado  Numero a retoronar
/// @param mensaje		Mensaje
/// @param mensajeError Mensaje Error
/// @return   Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
int utn_getNumeroFlotanteSinMinMax(float *pResultado, char mensaje[], char mensajeError[])
{
    int retorno = -1;
    int bufferFloat;
    int esNumero;
    do
    {
        printf("%s", mensaje);
        esNumero = getInt(&bufferFloat); //si es numerico get int devuelve cero y lo guarda en bufferfloat
        if (esNumero == 0 )
        {
            retorno = 0;
            *pResultado = bufferFloat;
            break;
        }
        printf("%s", mensajeError);
    }
    while (esNumero == -1);

    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
static int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
//#########################################

/** \brief Pide un caracter y lo valida con los enviados en los parametros 4 y 5
 *
 * \param puntero donde se guarda el caracter ingresado y validado.
 * \param mensaje a mostras
 * \param mensaje de error
 * \param primer caracter a validar
 * \param segundo caracter a validar
 * \return "0" si salio ok. "-1" si fallo.
 *
 */

int utn_pedirCaracter(char* caracter, char* mensaje, char* mensajeError, char caracter1, char caracter2)
{
	int todoOk = -1;
	char caracterIngresado;

	if(caracter != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c", &caracterIngresado);
		caracterIngresado = tolower(caracterIngresado);

		while(caracterIngresado != caracter1 && caracterIngresado != caracter2)
		{
			printf("%s ingrese \"%c\" o \"%c\"",mensajeError, caracter1, caracter2);
			fflush(stdin);
			scanf("%c", &caracterIngresado);
			caracterIngresado = tolower(caracterIngresado);
		}
		*caracter=caracterIngresado;
		todoOk=0;
	}
	return todoOk;
}

int utn_getCaracteres(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos){
	int retorno = 0;
	char auxChar;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){

		do {
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &auxChar);

			if (auxChar >= minimo && auxChar <= maximo){
				*pResultado = auxChar;
				retorno = 1;//salio tod0 bien
				break;

			}
			printf("%s", mensajeError);
			reintentos--;

		} while (reintentos >= 0);

	}

	return retorno;
}

//###############confirmacion#######################

/** \brief Esta funcion pide el ingreso de 's' o de 'n'  y lo pasa a minuscula
 *
 * \param mensaje[] char Mensaje de ingreso
 * \return char Devuelve el caracter validado "s" o "n"
 *
 */
char getConfirmacion(char mensaje[])
{
    char letter;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &letter);
    letter = tolower(letter);
    while (letter != 's' && letter != 'n')
    {
        printf("Error. Ingrese \"s\" para SI o \"n\" para NO: \n");
        fflush(stdin);
        scanf("%c", &letter);
        letter = tolower(letter);
    }
    return letter;
}

/** \brief saca promedio
 *
 * \param primer int a sacar promedio
 * \param segundo int a sacar promedio
 * \return -1 si fallo, o el resultado del promedio si salio ok.
 */

float my_sacarPromedio(int a, int b)
{
    float promedio = -1;

    if(b > 0 && a > 0)
    {
        promedio = (float) (a+b) / 2;

    }

    return promedio;
}



//######################PARA REVISAR###########################################




/** \brief Pide un entero  sin rango, ni max  ni min, y lo devuelve
 *
 * \param mensaje char* mensaje de ingreso
 * \return int Entero  validado
 *
 */
int my_getInt(char *mensaje)
{
    int numero;
    while ((getValidInt(&numero, mensaje)) == -1)
    {
        printf("Error. Ingrese solo numeros!\n");
    }
    return numero;
}

/** \brief Valida si el valor ingresado es un entero o no es llamada por getInt
 *
 * \param numero int* valor ingresado
 * \param mensaje char* mensaje recibido por param
 * \return int Devuelve "-1" si no es un int o es un entero con espacio, o "0" si es solo int.
 *
 */
static int getValidInt(int *numero, char *mensaje)
{
    int sePudo = 1;
    int esEspacio = 1;
    char cadenaCargada[20];
    int i;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadenaCargada); //leer todo hasta que se encuentre \n
    for (i = 0; i < strlen(cadenaCargada); i++)
    {
        if (cadenaCargada[i] != '\0')
        {
            if (cadenaCargada[i] < '0' || cadenaCargada[i] > '9')
            {
                sePudo = -1;
            }
            if (cadenaCargada[i] != ' ')
            {
                esEspacio = -1;
            }
        }
    }
    if (esEspacio == 1)
    {
        sePudo = -1;
    }
    if (sePudo == 1)
    {
        *numero = atoi(cadenaCargada);
    }
    return sePudo;
}


/** \brief Verifica que el string ingresado sea solo de letras.
 *
 * \param cadena[] char vector a validar
 * \return int Devuelve "-1" (si hay otros caracteres que no sean letras, o "0" si son solo letras):
 *
 */
int getStringLetras(char cadena[])
{
    int flag = 0;
    int esEspacio = 0;
    int tam = strlen(cadena);
    for (int i = 0; i < tam; i++)
    {
        if (cadena[i] != '\0')
        {
            if ((cadena[i] < 'a' || cadena[i] > 'z')
                    && (cadena[i] < 'A' || cadena[i] > 'Z')
                    && cadena[i] != ' ') //si es lo contrario a esto -1, (osea si no es: espacio, no es letra de "A" a "Z")
            {
                flag = -1;
            }

            if (cadena[i] != ' ')   // si NO ingresa SOLO espacio o enter, OK
            {
                esEspacio = 1;
            }

        }
    }

    if (esEspacio == 0)   //si es solo espacio, error.
    {
        flag = -1;
    }
    return flag;
}

/** \brief Pide una cadena de string y lo valida llamando la funcion "getStringLetras" y no permite otra
 * cosa que no sea letras y pasa cada primer letra despues de espacio a mayuscula con la funcion "my_primerLetraAMayuscula"
 * \param mensaje[] char Mensaje a mostrar
 * \param cadena[] char vector destino para el string validado
 * \return void
 *
 */
void my_pedirCadenaSoloLetras(char mensaje[], char cadena[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena); //leer todo hasta que se encuentre \n
    while (getStringLetras(cadena) == -1)
    {
        printf("Error. Ingrese solo letras!\n");
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", cadena);
    }
    my_primerLetraAMayuscula(cadena);
}

/** \brief Convierte el string a minuscula y despues la primera letra del string a mayuscula.
 *
 * \param cadena[] char vector con la cadena ingresada
 * \return void
 *
 */
void my_primerLetraAMayuscula(char cadena[])
{
    int tam = strlen(cadena);
    int i;
    strlwr(cadena);
    cadena[0] = toupper(cadena[0]); //primer letra a mayuscula
    for (i = 0; i < tam; i++)
    {
        if (cadena[i] != '\0')
        {
            if (isspace(cadena[i]))
            {
                cadena[i + 1] = toupper(cadena[i + 1]); //convierte lo siguiente a un espacio a mayuscula
            }
        }
    }
}
