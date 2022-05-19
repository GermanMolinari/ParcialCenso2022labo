/*
 * fecha.h
 *
 *  Created on: 15 may 2022
 *      Author: bolsi uwu
 */

#ifndef FECHA_H_
#define FECHA_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
} eFecha;

/**
 * TOMA UNA FECHA VALIDA
 * @return una fecha valida
 */eFecha tomarFecha();

#endif /* FECHA_H_ */
