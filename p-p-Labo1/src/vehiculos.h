/*
 * vehiculos.h
 *
 *  Created on: 21 oct 2022
 *      Author: antonella
 */

#ifndef VEHICULOS_H_
#define VEHICULOS_H_

#include "tipo.h"

#include "fecha.h"

typedef struct{
    int idVehiculo;
	char descripcion[25];
	int modelo;
	char color[10];
	int idTipo;
	int isEmpty;
}eVehiculo;

int inicializarVehiculo(eVehiculo* lista, int tam);

int buscarVehiculoId(eVehiculo* lista, int tamVia , int idViaje);

int buscarLibreVehiculo(eVehiculo* lista, int tam);

int altaVehiculo(eVehiculo* lista,eTipos* tipos, int tamTipo, int tam, int* pId);

void mostrarVehiculo(eVehiculo unVehiculo, eTipos* tipoViaje, int tamTipo);

int mostrarVehiculos(eVehiculo* listaVehi, int tam, eTipos* tipo, int tamTipo);

int menuDeModificaciones();

int modificacionVehiculo(eVehiculo* lista,eTipos* tipo,int tamTipo, int tam );

int bajaVehiculo(eVehiculo* lista,eTipos* tipos, int tamTipo, int tam);

int flagReset(eVehiculo* lista, int tam, int* flag);

int validarIdVehiculo(eVehiculo* vehiculo, int tamVia, int idViaje);

int mostrarVehiculoSeleccionado(eVehiculo* listaVehi, int tamVia, eTipos* tipos, int tamTipo);

#endif /* VEHICULOS_H_ */
