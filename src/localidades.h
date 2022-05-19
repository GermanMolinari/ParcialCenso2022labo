/*
 * localidades.h
 *
 *  Created on: 17 may 2022
 *      Author: bolsi uwu
 */

#ifndef LOCALIDADES_H_
#define LOCALIDADES_H_

typedef struct
{
	int id;
	char descripcion [30];
}eLocalidades;

/** MUESTRA LAS LOCALIDADES Y SUS IDS
 *
 * @param localidades
 * @param tamLoc
 * @return 0 si no pudo hacerlo, 1 si tuvo exito
 */int mostrarLocalidades(eLocalidades localidades[], int tamLoc);

/**BUSCA LA POSICION DONDE COINCIDAN LOS ID
 *
 * @param id
 * @param localidades
 * @param tamLoc
 * @return -1 si no pudo hacerlo, la posicion si tuvo exito
 */int buscarIdLocalidad(int id ,eLocalidades localidades[], int tamLoc);

#endif /* LOCALIDADES_H_ */
