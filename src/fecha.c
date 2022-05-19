/*
 * fecha.c
 *
 *  Created on: 15 may 2022
 *      Author: bolsi uwu
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fecha.h"

eFecha tomarFecha()
{
    eFecha fechaIngresada;
    int retorno;

    printf("ingrese fecha de nacimiento (dd/mm/aaaa) \n");
    fflush(stdin);
    retorno = scanf("%d/%d/%d", &fechaIngresada.dia,&fechaIngresada.mes, &fechaIngresada.anio);

    while(!(retorno == 3 && (fechaIngresada.dia >= 1 && fechaIngresada.dia <= 31) &&
            (fechaIngresada.mes >= 1 && fechaIngresada.mes <= 12) &&
            (fechaIngresada.anio >= 1965 && fechaIngresada.anio <= 2004)))
    {
        printf("Error, reingrese la fecha en el formato correcto (dd/mm/aaaa)");
        fflush(stdin);
        retorno = scanf("%d/%d/%d", &fechaIngresada.dia,&fechaIngresada.mes, &fechaIngresada.anio);
    }
    return fechaIngresada;
}

