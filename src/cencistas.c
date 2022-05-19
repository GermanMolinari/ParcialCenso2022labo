/*
 * cencistas.c
 *
 *  Created on: 15 may 2022
 *      Author: bolsi uwu
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cencistas.h"
#include "fecha.h"
#include "direccion.h"
#include "validaciones.h"
#include "zonas.h"
#include "localidades.h"//agregado


int hardcodearCencistas(eCencista listaCencistas [], int * pId)
{
	int todoOk = 0;
	char nombres[10][20] =
	{
	    "Juan",
	    "Pedro",
	    "Sofia",
	    "Miguel",
	    "Valentina",
	    "Camila",
	    "Andrea",
	    "Luis",
	    "Diego",
	    "Analia"
	};

	char direcciones[10][20] =
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

	char apellidos[10][20] =
		{
		    "Gomez",
		    "Molina",
		    "Guitierrez",
		    "Hernandez",
		    "Gomez",
		    "Colis",
		    "Andres",
		    "Lugones",
		    "Diaz",
		    "Gimenez"
		};
	int estados[10] = {1,1,-1,0,0,0,-1,-1,1,1};
	int edades[10] = {38,39,20,21,22,23,24,35,45,29};
	int alturas[10] = {3798,33459,2450,251,2342,2993,9284,4535,3545,1729};
	eFecha fechas[10] =
	{
			{1,1,1998},{1,2,1999},{2,5,1994},{5,8,1995},{15,12,1990},{12,12,2000},{26,11,1988},{20,4,1995},{11,5,1997},{14,6,1987}
	};

	if (listaCencistas != NULL && pId != NULL)
	    {
	        for (int i = 0; i < 10;  i++)
	        {
	            listaCencistas[i].id = *pId;
	            (*pId)++;
	            strcpy(listaCencistas[i].nombre, nombres[i]);
	            strcpy(listaCencistas[i].apellido, apellidos[i]);
	            strcpy(listaCencistas[i].direccion.calle, direcciones[i]);
	            listaCencistas[i].direccion.altura = alturas[i];
	            listaCencistas[i].edad = edades[i];
	            listaCencistas[i].fechaNacimiento = fechas[i];
	            listaCencistas[i].isEmpty = 0;
	            listaCencistas[i].estado = estados[i];
	            todoOk = 1;
	        }
	    }
		return todoOk;;
}

int menu()
{
    int opcion;

    system("cls");
    printf("****CENCISTAS**** \n\n");
    printf("1) CARGAR CENCISTA\n");
    printf("2) MODIFICAR CENCISTA\n");
    printf("3) DAR DE BAJA CENCISTA\n");
    printf("4) CARGAR ZONA\n");
    printf("5) ASIGNAR ZONA A CENSAR\n");
    printf("6) CARGA DE DATOS\n");
    printf("7) MOSTRAR CENSISTA\n");
	printf("8) MOSTRAR ZONA\n");
	printf("9) HARDCODEAR ZONAS Y CENCISTAS\n");
	printf("10) INFORMES\n");
	printf("11) SALIR\n");
    opcion = cargarInt("Ingrese una opcion: \n", 1, 10);

    return opcion;
}

int inicializarCencistas( eCencista listaCencistas[], int tam)
{
    int todoOk=0;

    if(listaCencistas != NULL && tam > 0)
    {
        for(int i= 0; i < tam; i++)
        {
            listaCencistas[i].isEmpty = 1;
        }
        todoOk = 1 ;
    }

    return todoOk;
}

int buscarLibre (eCencista listaCencistas [], int tam)
{
	int posicion=-1;

	if(listaCencistas != NULL && tam>0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(listaCencistas[i].isEmpty == 1)
			{
				posicion = i;
				break;
			}
		}
	}
   return posicion;
}

int altaCensista(int* id, eCencista listaCencistas[], int tam)
{
    eCencista data;
    char auxCadena[51];
    int todoOk = 1;
    int retornoValidacion;
    int posicion;


    if(id != NULL && listaCencistas != NULL && tam > 0)
    {
		system("cls");
		posicion = buscarLibre(listaCencistas, tam);
		if(posicion == -1)
		{
			printf("No hay lugar para mas cencistas en la lista \n");
		}
		else
		{
			printf("Ingrese nombre del cencista\n");
			fflush(stdin);
			scanf("%s", auxCadena);
			retornoValidacion = validarLetras(auxCadena);
			if(retornoValidacion == 1)
			{
				strncpy(data.nombre,auxCadena,sizeof(data.nombre));
			}
			else
			{

				printf("No se admiten numeros, espacios o simbolos en el nombre \n");
				todoOk = 0;
			}
			if(todoOk == 1)
			{

				printf("Ingrese apellido del cencista \n");
				fflush(stdin);
				scanf("%s", auxCadena);
				retornoValidacion = validarLetras(auxCadena);

				if(retornoValidacion == 1)
				{
					strncpy(data.apellido,auxCadena,sizeof(data.apellido));
				}
				else
				{
					printf("No se admiten numeros, espacios o simbolos en el apellido\n");
					todoOk = 0;

				}
				if (todoOk == 1)
				{
					data.fechaNacimiento = tomarFecha();

					printf("Ingrese la calle de su direccion\n");
					fflush(stdin);
					scanf("%s", auxCadena);
					retornoValidacion = validarLetras(auxCadena);
					if(retornoValidacion == 1)
					{
						strncpy(data.direccion.calle,auxCadena, sizeof(data.direccion));
					}
					else
					{
						printf("No se admiten numeros, espacios o simbolos en la calle\n");
						todoOk = 0;
					}

					if(todoOk == 1)
					{
						data.direccion.altura=cargarInt("Ingrese la altura de su calle", 1, 20000);

						if(todoOk == 1)
						{
							data.isEmpty = 0;
							data.estado = INACTIVO;
							data.id = *id;
							(*id)++;
							listaCencistas[posicion] = data;
						}
					}
				}
			}
		}
    }
    return todoOk;
}

void mostrarCencista(eCencista cencista)
{
	char descripcion[15];

	switch (cencista.estado)
	{
		case ACTIVO:
			strncpy(descripcion,"ACTIVO",sizeof(descripcion));
			break;

		case LIBERADO:
			strncpy(descripcion,"LIBERADO",sizeof(descripcion));
			break;

		case INACTIVO:
			strncpy(descripcion,"INACTIVO",sizeof(descripcion));
			break;
	}
    printf("%04d    %-13s      %-13s         %-8s %04d      %d		%d/%d/%d		%-13s\n", cencista.id, cencista.nombre, cencista.apellido, cencista.direccion.calle,cencista.direccion.altura , cencista.edad, cencista.fechaNacimiento.dia, cencista.fechaNacimiento.mes, cencista.fechaNacimiento.anio, descripcion);
}

int mostrarCencistas(eCencista listaCencistas[], int tam)
{
    int todoOk = 0;
    int flag = 0;

    if(listaCencistas != NULL && tam > 0)
    {
        system("cls");
        printf("      								***CENCISTAS***\n\n");
        printf("--------------------------------------------------------------------------------------------------------------------------------\n");
        printf("ID      NOMBRE      	APELLIDO       	 	DIRECCION 	   EDAD	  FECHA DE NACIMIENTO		ESTADO\n");
        printf("--------------------------------------------------------------------------------------------------------------------------------\n\n");

        for(int i=0; i<tam; i++)
        {
            if(listaCencistas[i].isEmpty == 0)
            {
                mostrarCencista(listaCencistas[i]);
                flag = 1;
                todoOk = 1;
            }
        }

        if(flag == 0)
        {
            system("cls");
            printf("No hay Cencistas registrados\n");
        }
    }
    return todoOk;
}

int buscarCencistaId(eCencista listaCencista[], int tam, int id)
{
    int posicion = -1;

    if(listaCencista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(id == listaCencista[i].id && listaCencista[i].isEmpty == 0)
            {
                posicion = i;
            }
        }
    }
    return posicion;
}

int modificarCencista(eCencista listaCencistas[], int tam)
{
    int todoOk = 0;
    char confirm;
    int idIngresado;
    int posicion;
    char auxCadena[51];
    int opcion;
    int retornoValidacion;
    int opcionSubmenu;

    mostrarCencistas(listaCencistas, tam);
    idIngresado = cargarInt("Ingrese id del cencista que desea modificar", 1000, 9999);
    posicion = buscarCencistaId(listaCencistas, tam, idIngresado);

    if(listaCencistas != NULL && tam > 0 && posicion != -1)
    {
        mostrarCencista(listaCencistas[posicion]);
        printf("Desea modificar al cencista? s/n \n");
        fflush(stdin);
        scanf("%c", &confirm);

        while(confirm != 's' && confirm != 'n')
        {
            printf("Error.. ingrese solo s/n \n");
            scanf("%c", &confirm);
            confirm = tolower(confirm);
        }
        if (confirm == 's')
        {
        	do{
				printf("//1. NOMBRE		//2. APELLIDO		//3. FECHA DE NACIMIENTO		//4. DIRECCION 		//5. EDAD		//6. SALIR\n");
				opcion= cargarInt("Elija el campo que desea cambiar:",1,6);
				switch(opcion)
				{
					case 1:
						printf("Ingrese nombre del cencista\n");
						fflush(stdin);
						scanf("%s", auxCadena);
						retornoValidacion = validarLetras(auxCadena);
						if(retornoValidacion == 1)
						{
							strncpy(listaCencistas[posicion].nombre,auxCadena,sizeof(listaCencistas[posicion].nombre));
							todoOk=1;
						}
						else
						{

							printf("No se admiten numeros, espacios o simbolos en el nombre \n");
						}
						break;

					case 2:
						printf("Ingrese apellido del cencista\n");
						fflush(stdin);
						scanf("%s", auxCadena);
						retornoValidacion = validarLetras(auxCadena);
						if(retornoValidacion == 1)
						{
							strncpy(listaCencistas[posicion].apellido,auxCadena,sizeof(listaCencistas[posicion].apellido));
							todoOk=1;
						}
						else
						{

							printf("No se admiten numeros, espacios o simbolos en el apellido \n");
						}
						break;

					case 3:
						opcionSubmenu = cargarInt("Seleccion que desea modificar \n1. Dia \n2. Mes \n 3.Anio \n", 1, 3);
						switch(opcionSubmenu)
						{
							case 1:
								listaCencistas[posicion].fechaNacimiento.dia = cargarInt("Ingrese un numero del 1 al 31", 1, 31);
								if(listaCencistas[posicion].fechaNacimiento.mes <= 5 && listaCencistas[posicion].fechaNacimiento.dia <= 18)
								{
									listaCencistas[posicion].edad = 2022 - listaCencistas[posicion].fechaNacimiento.anio;
								}
								else
								{
									listaCencistas[posicion].edad = 2022 - listaCencistas[posicion].fechaNacimiento.anio - 1;
								}
								todoOk=1;
								break;
							case 2:
								listaCencistas[posicion].fechaNacimiento.mes = cargarInt("Ingrese un numero del 1 al 12", 1, 12);
								if(listaCencistas[posicion].fechaNacimiento.mes <= 5 && listaCencistas[posicion].fechaNacimiento.dia <= 18)
								{
									listaCencistas[posicion].edad = 2022 - listaCencistas[posicion].fechaNacimiento.anio;
								}
								else
								{
									listaCencistas[posicion].edad = 2022 - listaCencistas[posicion].fechaNacimiento.anio - 1;
								}
								todoOk=1;
								break;
							case 3:
								listaCencistas[posicion].fechaNacimiento.anio = cargarInt("Ingrese un numero del 1965 al 2004", 1965, 2004);
								if(listaCencistas[posicion].fechaNacimiento.mes <= 5 && listaCencistas[posicion].fechaNacimiento.dia <= 18)
								{
									listaCencistas[posicion].edad = 2022 - listaCencistas[posicion].fechaNacimiento.anio;
								}
								else
								{
									listaCencistas[posicion].edad = 2022 - listaCencistas[posicion].fechaNacimiento.anio - 1;
								}
								todoOk=1;
								break;
						}
						break;
					case 4:
						opcionSubmenu = cargarInt("Seleccion que desea modificar \n1. Calle \n2. Altura \n", 1, 2);
						switch(opcionSubmenu)
						{
							case 1:
								printf("Ingrese la calle de su direccion\n");
								fflush(stdin);
								scanf("%s", auxCadena);
								retornoValidacion = validarLetras(auxCadena);
								if(retornoValidacion == 1)
								{
									strncpy(listaCencistas[posicion].direccion.calle,auxCadena, sizeof(listaCencistas[posicion].direccion.calle));
									todoOk = 1;
								}
								else
								{
									printf("No se admiten numeros, espacios o simbolos en la calle de la direccion, no se pudo modificar\n");
								}
								break;
							case 2:
								listaCencistas[posicion].direccion.altura = cargarInt("Ingrese un numero del 1 al 2000", 1, 2000);
								todoOk=1;
								break;
						}
						todoOk=1;
						break;

					case 5:
						listaCencistas[posicion].edad = cargarInt("Ingrese su edad", 18, 57);
						if(listaCencistas[posicion].fechaNacimiento.mes <= 5 && listaCencistas[posicion].fechaNacimiento.dia <= 18)
						{
							listaCencistas[posicion].fechaNacimiento.anio = 2022 - listaCencistas[posicion].edad;
						}
						else
						{
							listaCencistas[posicion].fechaNacimiento.anio = 2022 - listaCencistas[posicion].edad - 1;
						}
						break;
				}
			}while(opcion!=6);
        }
        else
        {
        	printf("No se encontro cencista con ese Id");
        }
    }
    return todoOk;
}

int bajaCencista(eCencista listaCencistas[], int tam)
{
    int todoOk = 0;
    char confirma;
    int idCencista;
    int posicion;

    if(listaCencistas != NULL && tam > 0)
    {
        system("cls");
    	mostrarCencistas(listaCencistas, tam);
    	idCencista = cargarInt("Ingrese id del cencista", 1000, 3000);
    	posicion=buscarCencistaId(listaCencistas, tam, idCencista);

    	if(posicion != -1)

    	{
			if (listaCencistas[posicion].estado != ACTIVO)
			{
				system("cls");
				mostrarCencista(listaCencistas[posicion]);
				printf("\n Desea eliminar cencista? s/n");
				fflush(stdin);
				scanf("%c", &confirma);

				while(confirma != 's' && confirma != 'n')
				{
					printf("Error.. ingrese solo s/n \n");
					scanf("%c", &confirma);
		            confirma = tolower(confirma);

				}

				if(confirma == 's')
				{
					listaCencistas[posicion].isEmpty = 1;
					todoOk = 1 ;
				}
			}
			else
			{
				listaCencistas[posicion].estado = INACTIVO;
				printf("No se puede dar de baja un cencista ACTIVO, se cambio su estado a INACTIVO\n");
			}

    	}
    }
    return todoOk;
}


