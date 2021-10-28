#include "vuelo.h"
#include "fecha.h"


int validarFechas(eVuelo* vecConFecha)
{
    int retorno = -1;
    eVuelo auxAlumno; //vector donde se guardara despues de validar, es eVuelo.

    while(retorno != 1)
    {
        utn_getNumero(&auxAlumno.fecha.dia, "Ingrese el dia: ", "Error! reingrese el dia: ", 1, 31, 10);
        utn_getNumero(&auxAlumno.fecha.mes, "Ingrese el mes: ", "Error! reingrese el dia: ", 1, 12, 10);
        utn_getNumero(&auxAlumno.fecha.anio, "Ingrese el anio: ", "Error! reingrese el anio: ", 1, 9999, 10);


        // Validacion de anio
        if(auxAlumno.fecha.anio >= 1900 && auxAlumno.fecha.anio <= 9999)
        {
            //validacion de mes
            if(auxAlumno.fecha.mes>=1 && auxAlumno.fecha.mes<=12)
            {
                //validacion de dia
                if((auxAlumno.fecha.dia>=1 && auxAlumno.fecha.dia<=31) && (auxAlumno.fecha.mes==1 || auxAlumno.fecha.mes==3 ||
                        auxAlumno.fecha.mes==5 || auxAlumno.fecha.mes==7 || auxAlumno.fecha.mes==8 || auxAlumno.fecha.mes==10 || auxAlumno.fecha.mes==12))
                {
                    printf("la fecha es valida 1.\n");
                    *vecConFecha = auxAlumno; //despues de validar lo copio.
                    retorno = 1;

                    //printf("la fecha de auxiliar es: %02d/%02d/%d\n", auxAlumno.fecha.dia, auxAlumno.fecha.mes, auxAlumno.fecha.anio);
                    //printf("la fecha la struct vecConFecha es: %02d/%02d/%d\n", vecConFecha->fecha.dia, vecConFecha->fecha.mes, vecConFecha->fecha.anio);
                    //system("pause");
                }

                else if((auxAlumno.fecha.dia>=1 && auxAlumno.fecha.dia<=30) && (auxAlumno.fecha.mes==4 || auxAlumno.fecha.mes==6
                        || auxAlumno.fecha.mes==9 || auxAlumno.fecha.mes==11))
                {
                    printf("la fecha es valida 2.\n");
                    *vecConFecha = auxAlumno; //despues de validar lo copio.
                    retorno = 1;
                }

                else if((auxAlumno.fecha.dia>=1 && auxAlumno.fecha.dia<=28) && (auxAlumno.fecha.mes==2))
                {
                    printf("la fecha es valida 3.\n");
                    *vecConFecha = auxAlumno; //despues de validar lo copio.
                    retorno = 1;
                }

                else if(auxAlumno.fecha.dia==29 && auxAlumno.fecha.mes==2 && (auxAlumno.fecha.anio%400==0 ||(auxAlumno.fecha.anio%4==0 && auxAlumno.fecha.anio%100!=0)))
                {
                    printf("la fecha es valida 4.\n");
                    *vecConFecha = auxAlumno; //despues de validar lo copio.
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
