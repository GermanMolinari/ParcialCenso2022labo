/*
 * localidades.c
 *
 *  Created on: 17 may 2022
 *      Author: bolsi uwu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "localidades.h"


int mostrarLocalidades(eLocalidades localidades[], int tamLoc)
{
    int todoOk = 0;
    if(localidades != NULL && tamLoc > 0)
    {
        system("cls");
        printf("    **** LISTA DE LOCALIDADES **** \n");
        printf("-----------------------------\n");
        printf("  ID        DESCRIPCION\n");
        printf("-----------------------------\n");
        for( int i = 0; i < tamLoc ; i++)
        {
            printf(" %d        %-15s \n", localidades[i].id, localidades[i].descripcion);
        }
        printf("\n\n");

        todoOk = 1;
    }

    return todoOk;
}

int buscarIdLocalidad(int id ,eLocalidades localidades[], int tamLoc)
{
    int posicion = -1;
    if(localidades != NULL && tamLoc > 0)
    {
        for(int i =0; i < tamLoc ; i++)
        {
            if(localidades[i].id == id)
            {
                posicion = i;
                break;
            }
        }
    }
    return posicion;
}
