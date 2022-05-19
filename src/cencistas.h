/*
 * cencistas.h
 *
 *  Created on: 15 may 2022
 *      Author: bolsi uwu
 */

#ifndef CENCISTAS_H_
#define CENCISTAS_H_
#include "fecha.h"
#include "direccion.h"
#include "localidades.h"
//#include "zonas.h" //agregado

#define ACTIVO 1
#define INACTIVO 0
#define LIBERADO -1


typedef struct
{
	int id;
	int edad;
	int estado;
	eFecha fechaNacimiento;
	int isEmpty;
	char nombre[51];
	char apellido[51];
	eDireccion direccion;

}eCencista;

/**
*  MENU DE OPCIONES
* @return la opcion que el usuario elije
*/int menu();

/**
* 	INCIALIZA EL ARRAY DE CENCISTAS
* @param listaCencistas
* @param tam
* @return 0 si no pudo hacerlo, 1 si tuvo exito
*/int inicializarCencistas( eCencista listaCencistas[], int tam);

/**
* BUSCA EL INDICE LIBRE
* @param listaCencistas
* @param tam
* @return 0 si no pudo hacerlo, 1 si tuvo exito
*/int buscarLibre (eCencista listaCencistas [], int tam);

/**
*  DA DE ALTA UN CENCISTA
* @param id
* @param listaCencistas
* @param tam
* @return 0 si no pudo hacerlo, 1 si tuvo exito
*/int altaCensista(int* id, eCencista listaCencistas[], int tam);

/**
*  MUESTRA UN CENCISTA
* @param cencista
*/void mostrarCencista(eCencista cencista);

/**
* MUESTRA LOS CENCISTAS
* @param listaCencistas
* @param tam
* @return 0 si no pudo hacerlo, 1 si tuvo exito
*/int mostrarCencistas(eCencista listaCencistas[], int tam);

/**
* BUSCA LA POSICICION EN EL ARRAY DE CENCISTAS X ID
* @param listaCencista
* @param tam
* @param id
* @return 0 si no pudo hacerlo, 1 si tuvo exito
*/int buscarCencistaId(eCencista listaCencista[], int tam, int id);

/**
* HARDCODEA 10 A LA LISTA DE CENCISTAS
* @param listaCencistas
* @param pId
* @return 0 si no pudo hacerlo, 1 si tuvo exito
*/int hardcodearCencistas(eCencista listaCencistas [], int * pId);

/**
* MODIFICA UN CENCISTA DEL ARRAY
* @param listaCencistas
* @param tam
* @return 0 si no pudo hacerlo, 1 si tuvo exito
*/int modificarCencista(eCencista listaCencistas[], int tam);

/**
* DA DE BAJA UN CENCISTA
* @param listaCencistas
* @param tam
* @return 0 si no pudo hacerlo, 1 si tuvo exito
*/int bajaCencista(eCencista listaCencistas[], int tam);

#endif /* CENCISTAS_H_ */
