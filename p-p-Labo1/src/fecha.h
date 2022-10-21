/*
 * fecha.h
 *
 *  Created on: 21 oct 2022
 *      Author: antonella
 */

#ifndef FECHA_H_
#define FECHA_H_

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;


int validarFecha(eFecha* unaFecha);
int validarFechaVehiculo(eFecha* unaFecha);

#endif /* FECHA_H_ */
