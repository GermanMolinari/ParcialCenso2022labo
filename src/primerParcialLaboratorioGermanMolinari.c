/*
 ============================================================================
 Name        : primerParcialLaboratorioGermanMolinari.c
 Author      : German Molinari
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "cencistas.h"
#include "zonas.h"
#include "localidades.h"

#define TAM 2000
#define TAMZON 2000
#define TAMLOC 5

int main()
{
	setbuf(stdout, NULL);
	eLocalidades listaLocalidades [TAMLOC] =
	{
			{5000,"Avellaneda"},
			{5001,"Banfield"},
			{5002,"Gerli"},
			{5003,"Lomas"},
			{5004,"Lanus"},
	};
	char salir = 'n';
	eCencista listaCencistas [TAM];
	eZona listaZonas [TAMZON];
	int idCencista = 1000;
	int idZona = 4000;
	int flag = 0;
	int flagZona = 0;
	if(inicializarCencistas(listaCencistas, TAM) != 1)
	{
		printf("No se pudo inicializar \n");
	}
	if(inicializarZonas(listaZonas, TAMZON) != 1)
	{
		printf("No se pudo inicializar \n");
	}
	do {
			//system("pause");
			switch (menu())
			{
				case 1:
					if(altaCensista(&idCencista, listaCencistas, TAM) == 1)
					{
						printf("Se dio de alta!\n");
						flag = 1;
					}
					else
					{
						printf("No se pudo dar el alta\n");
					}
					break;

				case 2:
					if(flag == 1)
					{
						if(modificarCencista(listaCencistas, TAM) == 1)
						{
							printf("Se modifico correctamente!\n");
						}
						else
						{
							printf("No se pudo modificar\n");
						}
					}
					else
					{
						printf("No se puede modificar sin antes dar un alta \n");
					}
					break;

				case 3:
					if(flag == 1)
					{
						if(bajaCencista(listaCencistas, TAM) == 1)
						{
							printf("Se dio de baja correctamente !\n");
						}
						else
						{
							printf("No se pudo dar de baja \n");
						}
					}
					else
					{
						printf("No se puede dar de baja sin antes dar un alta \n");
					}
					break;

				case 4:
					if(altaZona(&idZona, listaZonas, TAMZON, listaLocalidades, TAMLOC) == 1)
					{
						printf("Se dio el alta!\n");
						flagZona = 1;

					}
					else
					{
						printf("No se pudo dar el alta\n");
					}
					break;

				case 5:
					if(flag == 1 && flagZona == 1)
					{
						if(asignarZona(listaCencistas, TAM, listaZonas, TAMZON, listaLocalidades, TAMLOC))
						{
							printf("Se asigno correctamente!\n");
						}
						else
						{
							printf("No se pudo asignar \n");
						}
					}
					else
					{
						printf("Antes de asignar debe dar de alta un cencista y una zona \n");
					}
					break;

				case 6:
					if(flag == 1 && flagZona == 1)
					{
						if(cargarDatosZona(listaZonas, TAMZON, listaCencistas, TAM, listaLocalidades, TAMLOC) ==1)
						{
							printf("Se cargo correctamente!\n");
						}
						else
						{
							printf("No se pudo cargar datos \n");
						}
					}
					else
					{
						printf("Antes de cargar datos debe dar de alta un cencista y una zona \n");
					}
					break;
				case 7:
						if(flag == 1)
						{
							if (mostrarCencistas(listaCencistas, TAM) != 1)
							{
								printf("No se pudo mostrar \n");
							}
						}
						else
						{
							printf("Para mostrar los cencistas primero debe cargar uno");
						}
					break;

				case 8:
					if(flagZona == 1)
					{
						if(mostrarZonas(listaZonas, TAMZON, listaCencistas, TAM, listaLocalidades, TAMLOC) != 1)
						{
							printf("No se pudo mostrar\n");
						}
					}
					else
					{
						printf("Para mostrar las zonas primero debe cargar una zona \n");
					}
					break;
				case 9:
						hardcodearCencistas(listaCencistas, &idCencista);
						hardcodearZonas(listaZonas,&idZona);
						flag = 1;
						flagZona =1;
						printf("Se hardcodearon 10 zonas y 10 cencistas\n");
					break;
				case 10:
					salir = 's';
					break;
			}
		} while(salir != 's');

		return 0;
}
