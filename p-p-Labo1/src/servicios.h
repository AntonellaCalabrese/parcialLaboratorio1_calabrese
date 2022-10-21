/*
 * servicios.h
 *
 *  Created on: 21 oct 2022
 *      Author: antonella
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_


#include "tipo.h"
#include "fecha.h"
#include "vehiculos.h"

typedef struct{
	int idHoja;
	int vehiculoId;
	eTipos descripcion;
	float precioServicio;
	eFecha fecha;
	int isEmpty;
}eServicios;

int inicializarServicio(eServicios* lista, int tam);
int buscarLibreServicio(eServicios* lista, int tam);
int altaServicio(eServicios* listaVehi,int tamVou, eVehiculo* listaVia,int tamVia, eTipos* tipo,int tamTipo, int* pId);
void mostrarUnServicio(eServicios unServicio,eVehiculo* unViaje,int tamViaje, eTipos* tipoViaje, int tamTipo);
int mostrarServicios(eServicios* listaVou, int tamVou, eVehiculo* listaVia, int tamVia, eTipos* listaTipo,int tamTipo );



#endif /* SERVICIOS_H_ */
