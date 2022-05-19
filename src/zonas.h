/*
 * zonas.h
 *
 *  Created on: 15 may 2022
 *      Author: bolsi uwu
 */

#ifndef ZONAS_H_
#define ZONAS_H_
#define PENDIENTE 0
#define FINALIZADO 1
#include "localidades.h" //agregado
#include "cencistas.h"//agregad2
typedef struct
{
	int id;
	char nombre[51];
	int estado;
	char calleUno[51];
	char calleDos[51];
	char calleTres[51];
	char calleCuatro[51];
	int censadosSitu;
	int censadosVirtual;
	int ausentes;
	int idLocalidad;
	int idCencista;
	int isEmpty;
}eZona;


/**
 * Incializa el array de zona
 * @param listaZonas
 * @param tamZon
 * @return la validacion
 */int inicializarZonas( eZona listaZonas[],int tamZon);

/**
 * busca la posicion libre de las zonas
 * @param listaZonas
 * @param tamZon
 * @return la posicion
 */int buscarLibreZona(eZona listaZonas[], int tamZon);

/**
 * da de alta la zona
 * @param id
 * @param listaZonas
 * @param tamZon
 * @return validacion si pudo o no
 */int altaZona (int* id, eZona listaZonas[], int tamZon, eLocalidades listaLocalidades[], int tamLoc);

/**
 * busca la posicion de una zona por su id
 * @param listaZonas
 * @param tamZon
 * @param id
 * @return la posicion
 */int buscarZonaId(eZona listaZonas[], int tamZon, int id);

/**
 * muestra una zona
 * @param zona
 * @param listaCencistas
 * @param tam
 * @param listaLocalidades
 * @param tamLoc
 */void mostrarZona(eZona zona, eCencista listaCencistas [], int tam, eLocalidades listaLocalidades [], int tamLoc);

/**
 * muestra las zonas cargadas si es que estan
 * @param listaZonas
 * @param tamZon
 * @param listaCencistas
 * @param tam
 * @param listaLocalidades
 * @param tamLoc
 * @return validacion si pudo o no
 */int mostrarZonas(eZona listaZonas [], int tamZon, eCencista listaCencistas [], int tam, eLocalidades listaLocalidades [], int tamLoc);

 /**
  * vincula una zona con un cencista
  * @param listaCencistas
  * @param tam
  * @param listaZonas
  * @param tamZon
  * @param listaLocalidades
  * @param tamLoc
  * @return si pudo o no pudo
  */int asignarZona(eCencista listaCencistas [], int tam, eZona listaZonas[], int tamZon, eLocalidades listaLocalidades[], int tamLoc);

  /**
   * harcodea zonas
   * @param listaZonas
   * @param pId
   * @return si puedo o no
   */int hardcodearZonas(eZona listaZonas [], int * pId);

   /**
    * carga los datos de un cencista en la zona
    * @param listaZonas
    * @param tamZon
    * @param listaCencistas
    * @param tam
    * @param listaLocalidades
    * @param tamLoc
    * @return si pudo o no
    */int cargarDatosZona(eZona listaZonas [], int tamZon, eCencista listaCencistas[], int tam, eLocalidades listaLocalidades[], int tamLoc);

    /**
     *	muestra otros datos de la zona
     * @param zona
     * @param listaCencistas
     * @param tam
     * @param listaLocalidades
     * @param tamLoc
     */void mostrarZonaCensados(eZona zona, eCencista listaCencistas [], int tam, eLocalidades listaLocalidades [], int tamLoc);
#endif /* ZONAS_H_ */
