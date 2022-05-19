/*
 * zonas.c
 *
 *  Created on: 15 may 2022
 *      Author: bolsi uwu
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cencistas.h"
#include "localidades.h"
#include "validaciones.h"
#include "zonas.h"

int hardcodearZonas(eZona listaZonas [], int * pId)
{
	int todoOk = 0;
	char calleUno[10][20] =
	{
	    "Mitre",
	    "Avellaneda",
	    "Peron",
	    "Juncal",
	    "Malvinas",
	    "Mateu",
	    "Pringles",
	    "General Guido",
	    "Carlos Calvo",
	    "Anchorena"
	};

	char calleDos [10][20] =
		{
		    "Juncal",
		    "Deheza",
		    "Alvear",
		    "Pringles",
		    "Gaebeler",
		    "Malvinas",
		    "Mitre",
		    "Belgrano",
		    "Bolaños",
		    "Saavedra"
		};

	char calleTres[10][20] =
		{
		    "Oyuela",
		    "Centenario",
		    "Lacarra",
		    "Sarmiento",
		    "Ituzaingo",
		    "Pedernera",
		    "San Lorenzo",
		    "Lujan",
		    "Pergamino",
		    "Achaval"
		};

	char calleCuatro[10][20] =
			{
			    "Bueras",
			    "Roca",
			    "San Martin",
			    "Jose Hernandez",
			    "Cabrero",
			    "Arias",
			    "Guidi",
			    "Eva Peron",
			    "Lamadrid",
			    "Posadas"
			};
	int estados[10] = {0,0,0,0,0,0,0,0,0,0};
	int idLocalidades[10] ={5001,5001,5000,5002,5003,5002,5004,5003,5004,5000};
	int censadosInSitu [10] ={132,314,321,543,345,254,675,123,534,423};
	int censadosAusentes [10] ={35,34,21,53,35,54,65,12,54,13};
	int censadosVirtual [10] ={2332,3414,3621,5443,3745,2954,6775,1423,2534,1423};

	if (listaZonas != NULL && pId != NULL)
	    {
	        for (int i = 0; i < 10;  i++)
	        {
	            listaZonas[i].id = *pId;
	            (*pId)++;
	            strcpy(listaZonas[i].calleUno, calleUno[i]);
	            strcpy(listaZonas[i].calleDos, calleDos[i]);
	            strcpy(listaZonas[i].calleTres, calleTres[i]);
	            strcpy(listaZonas[i].calleCuatro, calleCuatro[i]);
	            listaZonas[i].estado = estados[i];
	            listaZonas[i].isEmpty = 0;
	            listaZonas[i].idLocalidad = idLocalidades[i];
	            listaZonas[i].censadosSitu=censadosInSitu[i];
			    listaZonas[i].censadosVirtual=censadosVirtual[i];
			    listaZonas[i].ausentes=censadosAusentes[i];
	            todoOk = 1;
	        }
	    }
		return todoOk;;
}

int inicializarZonas( eZona listaZonas[],int tamZon)
{
    int todoOk =0;

    if(listaZonas != NULL && tamZon>0)
    {
        for(int i=0; i<tamZon; i++)
        {
            listaZonas[i].isEmpty = 1;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarLibreZona(eZona listaZonas[], int tamZon)
{
    int posicion= -1;
    if(listaZonas != NULL && tamZon >0)
    {
        for(int i=0; i<tamZon; i++)
        {
            if(listaZonas[i].isEmpty)
            {
                posicion=i;
                break;
            }
        }
    }

    return posicion;
}

int altaZona (int* id, eZona listaZonas[], int tamZon, eLocalidades listaLocalidades[], int tamLoc)
{
    eZona data;
    char auxCadena[51];
    int todoOk = 1;
    int retornoValidacion;
    int posicion;
    int idLocalidad;


    if(id != NULL && listaZonas!= NULL && tamZon > 0)
    {
		system("cls");
		posicion = buscarLibreZona(listaZonas, tamZon);
		if(posicion == -1)
		{
			printf("No hay lugar para mas zonas en la lista \n");
		}
		else
		{

			printf("Ingrese Calle 1 \n");
			fflush(stdin);
			scanf("%s", auxCadena);
			retornoValidacion = validarLetras(auxCadena);

			if(retornoValidacion == 1)
				{
					strncpy(data.calleUno,auxCadena,sizeof(data.calleUno));
				}
			else
				{
					printf("No se admiten numeros, espacios o simbolos en el nombre de la calle\n");
					todoOk = 0;

				}

			printf("Ingrese Calle 2 \n");
			fflush(stdin);
			scanf("%s", auxCadena);
			retornoValidacion = validarLetras(auxCadena);

			if(retornoValidacion == 1)
				{
					strncpy(data.calleDos,auxCadena,sizeof(data.calleDos));
				}
			else
				{
					printf("No se admiten numeros, espacios o simbolos en el nombre de la calle\n");
					todoOk = 0;

				}
			printf("Ingrese Calle 3 \n");
			fflush(stdin);
			scanf("%s", auxCadena);
			retornoValidacion = validarLetras(auxCadena);

			if(retornoValidacion == 1)
				{
					strncpy(data.calleTres,auxCadena,sizeof(data.calleTres));
				}
			else
				{
					printf("No se admiten numeros, espacios o simbolos en el nombre de la calle\n");
					todoOk = 0;

				}
			printf("Ingrese Calle 4 \n");
			fflush(stdin);
			scanf("%s", auxCadena);
			retornoValidacion = validarLetras(auxCadena);

			if(retornoValidacion == 1)
				{
					strncpy(data.calleCuatro,auxCadena,sizeof(data.calleCuatro));
				}
			else
				{
					printf("No se admiten numeros, espacios o simbolos en el nombre de la calle\n");
					todoOk = 0;

				}

			mostrarLocalidades(listaLocalidades, tamLoc);
			idLocalidad = cargarInt("Ingrese id de la localidad \n", 5000, 5004);


			if(todoOk == 1)
			{
				data.isEmpty = 0;
				data.id = *id;
				data.idLocalidad = idLocalidad;
				data.estado= PENDIENTE;
				data.ausentes = -1;
				data.censadosSitu = -1;
				data.censadosVirtual = -1;
				(*id)++;
				listaZonas[posicion] = data;
			}
		}
    }
    return todoOk;
}

int buscarZonaId(eZona listaZonas[], int tamZon, int id)
{
    int posicion = -1;

    if(listaZonas != NULL && tamZon > 0)
    {
        for(int i = 0; i < tamZon; i++)
        {
            if(id == listaZonas[i].id && listaZonas[i].isEmpty == 0)
            {
                posicion = i;
            }
        }
    }
    return posicion;
}

void mostrarZona(eZona zona, eCencista listaCencistas [], int tam, eLocalidades listaLocalidades [], int tamLoc)
{
	int posicionCencista;
	int posicionLocalidades;
	char descripcionLocalidad[31];
	char descripcionEstado[31];

	if(zona.estado == PENDIENTE)
	{
		strncpy(descripcionEstado,"PENDIENTE",sizeof(descripcionEstado));
	}
	else
	{
		strncpy(descripcionEstado,"FINALIZADO",sizeof(descripcionEstado));
	}
	posicionCencista = buscarCencistaId(listaCencistas, tam, zona.idCencista);
	posicionLocalidades = buscarIdLocalidad(zona.idLocalidad, listaLocalidades, tamLoc);
	strncpy(descripcionLocalidad,listaLocalidades[posicionLocalidades].descripcion,sizeof(descripcionLocalidad));

	if(listaCencistas[posicionCencista].estado == ACTIVO)
	{
		printf("%04d   	%-13s	%-8s		%-13s		%-8s	    %-13s			%s %s		%s\n",zona.id, zona.calleUno, zona.calleDos, zona.calleTres, zona.calleCuatro, descripcionLocalidad,listaCencistas[posicionCencista].nombre,listaCencistas[posicionCencista].apellido,descripcionEstado);
	}
	else
	{
		printf("%04d   	%-13s	%-8s	   %-13s		%-8s 		%-13s		AUN NO SE A ASIGNADO A UN CENCISTA	%s\n",zona.id, zona.calleUno, zona.calleDos, zona.calleTres, zona.calleCuatro,descripcionLocalidad,descripcionEstado);
	}
}

int mostrarZonas(eZona listaZonas [], int tamZon, eCencista listaCencistas [], int tam, eLocalidades listaLocalidades [], int tamLoc)
{
	int todoOk = 0;
	int flag = 0;
	int opcion;

    if(listaCencistas != NULL && tam > 0 && listaZonas != NULL && tamZon>0 && listaLocalidades != NULL && tamLoc > 0)
    {
    	printf("Como desea mostrar de las zonas?\n1.POR ID-CALLES-LOCALIDAD-CENCISTA-ESTADO \n2. POR ID-CENSADOS IN SITU/VIRTUAL/AUSENTES-LOCALIDAD-CENCISTA-ESTADO\n");
    	opcion = cargarInt("Ingrese una opcion", 1, 2);

    	if(opcion == 1)
    	{
			system("cls");
			printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("ID      CALLE  1     	CALLE 2    	  CALLE 3 			CALLE 4   	 	LOCALIDAD	  		CENCISTA			  ESTADO\n");
			printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
			for(int i=0; i<tamZon; i++)
			{
				if(listaZonas[i].isEmpty == 0)
				{
					mostrarZona(listaZonas[i], listaCencistas, tam, listaLocalidades, tamLoc);
					flag = 1;
					todoOk = 1;
				}
			}
			if (flag == 0)
			{
				printf("No hay zonas registradas\n");
			}
    	}
    	else
    	{
			system("cls");
			printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("ID      IN SITU     		VIRTUALES		AUSENTES   	 	LOCALIDAD	  			CENCISTA			  	ESTADO\n");
			printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
			for(int i=0; i<tamZon; i++)
			{
				if(listaZonas[i].isEmpty == 0)
				{
					mostrarZonaCensados(listaZonas[i], listaCencistas, tam, listaLocalidades, tamLoc);
					flag = 1;
					todoOk = 1;
				}
			}
			if (flag == 0)
			{
				printf("No hay zonas registradas\n");
			}
    	}
    }
    return todoOk;
}

int asignarZona(eCencista listaCencistas [], int tam, eZona listaZonas[], int tamZon, eLocalidades listaLocalidades[], int tamLoc)
{
	int todoOk = 0;
	int idCencista;
	int idZona;
	int posicionCencista;
	int posicionZona;

	if(listaCencistas != NULL && tam > 0 && listaZonas != NULL && tamZon > 0 && listaLocalidades != NULL && tamLoc > 0)
	{
		mostrarCencistas(listaCencistas, tam);
		idCencista = cargarInt("Ingrese id del cencista que quiere asignar \n", 1000, 3000);
		posicionCencista = buscarCencistaId(listaCencistas, tam, idCencista);
		if(posicionCencista != -1)
		{
			if(listaCencistas[posicionCencista].estado != ACTIVO)
			{
				mostrarZonas(listaZonas, tamZon, listaCencistas, tam, listaLocalidades, tamLoc);
				idZona = cargarInt("Ingrese id de la zona que desea asignar al cencista \n", 4000, 5000);
				posicionZona = buscarZonaId(listaZonas, tamZon, idZona);
				if (posicionZona != -1)
				{
					listaZonas[posicionZona].idCencista = listaCencistas[posicionCencista].id;
					listaZonas[posicionZona].estado = PENDIENTE;
					listaCencistas[posicionCencista].estado = ACTIVO;
					todoOk = 1;
					printf("Se vinculo al cencista %s %s con la zona de ID %d \n",listaCencistas[posicionCencista].nombre, listaCencistas[posicionCencista].apellido, listaZonas[posicionZona].id);
				}
				else
				{
					printf("No se encontro zona con ese  ID \n");
				}
			}
			else
			{
				printf("A este cencista ya se le asigno una zona \n");
			}

		}
		else
		{
			printf("No se encontro cencista con ese  ID \n");
		}
	}
	return todoOk;
}

int cargarDatosZona(eZona listaZonas [], int tamZon, eCencista listaCencistas[], int tam, eLocalidades listaLocalidades[], int tamLoc)
{
	int todoOk = 0;
	int posicionZona;
	int idZona;
	int posicionCencista;
	char confirma;

	if(listaCencistas != NULL && tam > 0 && listaZonas != NULL && tamZon > 0)
	{
		system("cls");

		mostrarZonas(listaZonas, tamZon, listaCencistas, tam, listaLocalidades, tamLoc);
		idZona = cargarInt("Ingrese numero de id \n", 4000, 6000);
		posicionZona = buscarZonaId(listaZonas, tamZon, idZona);

		if(posicionZona != -1)
		{
			posicionCencista = buscarCencistaId(listaCencistas, tam, listaZonas[posicionZona].idCencista);
			system("cls");
			if(posicionCencista != -1 && listaCencistas[posicionCencista].estado==ACTIVO && listaZonas[posicionZona].idCencista == listaCencistas[posicionCencista].id)
			{
				if(listaZonas[posicionZona].estado == PENDIENTE)
				{
					printf("Bienvenido %s %s, desea cargar los datos de la zona de ID: %d? s/n \n", listaCencistas[posicionCencista].nombre, listaCencistas[posicionCencista].apellido, listaZonas[posicionZona].id);
					fflush(stdin);
					scanf("%c", &confirma);

					while(confirma != 's' && confirma != 'n')
					{
						printf("Error.. ingrese solo s/n \n");
						scanf("%c", &confirma);
					}

					if(confirma == 's')
					{
						listaZonas[posicionZona].censadosSitu = cargarInt("Ingrese cantidad de censados insitu \n", 1, 1000);
						listaZonas[posicionZona].censadosVirtual = cargarInt("Ingrese cantidad de censados virtualmente \n", 1, 1000);
						listaZonas[posicionZona].ausentes = cargarInt("Ingrese cantidad de ausentes \n", 1, 1000);
						listaZonas[posicionZona].estado = FINALIZADO;
						listaCencistas[posicionCencista].estado = LIBERADO;
						todoOk = 1;
					}
				}
				else
				{
					printf("No se puede cargar esta zona porque su estado es FINALIZADO \n");
				}
			}
			else
			{
				printf("No se encontro cencista vinculado a esta zona \n");
			}
		}
		else
		{
			printf("No se encontro zona con ese  ID \n");
		}
	}
	return todoOk;
}

void mostrarZonaCensados(eZona zona, eCencista listaCencistas [], int tam, eLocalidades listaLocalidades [], int tamLoc)
{
	int posicionCencista;
	int posicionLocalidades;
	char descripcionLocalidad[31];
	char descripcionEstado[31];


		if(zona.estado == PENDIENTE)
		{
			strncpy(descripcionEstado,"PENDIENTE",sizeof(descripcionEstado));
		}
		else
		{
			strncpy(descripcionEstado,"FINALIZADO",sizeof(descripcionEstado));
		}
		posicionCencista = buscarCencistaId(listaCencistas, tam, zona.idCencista);
		posicionLocalidades = buscarIdLocalidad(zona.idLocalidad, listaLocalidades, tamLoc);

		strncpy(descripcionLocalidad,listaLocalidades[posicionLocalidades].descripcion,sizeof(descripcionLocalidad));

		if(listaCencistas[posicionCencista].estado == ACTIVO)
		{
			if(zona.ausentes != -1 && zona.censadosSitu != -1 && zona.censadosVirtual != -1)
			{
				printf("%04d   	%d			%-d			%d	   		%-13s				%s %s				%s\n",zona.id, zona.censadosSitu, zona.censadosVirtual, zona.ausentes, descripcionLocalidad,listaCencistas[posicionCencista].nombre,listaCencistas[posicionCencista].apellido,descripcionEstado);
			}
			else
			{
				printf("%04d   	NO ASIGNADO		NO ASIGNADO		NO ASIGNADO	   		%-13s				%s %s				%s\n",zona.id, descripcionLocalidad,listaCencistas[posicionCencista].nombre,listaCencistas[posicionCencista].apellido,descripcionEstado);
			}
		}
		else
		{
			if(zona.ausentes != -1 && zona.censadosSitu != -1 && zona.censadosVirtual != -1)
			{
				printf("%04d   	%d			%d			%d	    		%-13s			AUN NO SE A ASIGNADO A UN CENCISTA		%s\n",zona.id, zona.censadosSitu, zona.censadosVirtual, zona.ausentes, descripcionLocalidad,descripcionEstado);
			}
			else
			{
				printf("%04d   	NO ASIGNADO		NO ASIGNADO		NO ASIGNADO    		%-13s			AUN NO SE A ASIGNADO A UN CENCISTA		%s\n",zona.id, descripcionLocalidad,descripcionEstado);
			}
		}

}
