/*
 * servicios.c
 *
 *  Created on: 21 oct 2022
 *      Author: antonella
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "servicios.h"
#include "tipo.h"
#include "fecha.h"
#include "vehiculos.h"


// /////////////////////// ALTA VOUCHER /////////////////////////

int inicializarServicio(eServicios* lista, int tam)
{
	int allOk = -1;
	if(lista != NULL && tam > 0)
	    {
	        for(int i = 0; i < tam; i++)
	        {
	        	(*(lista+i)).isEmpty=1;
	        }
	        allOk = 0;
	    }
	return allOk;
}

// ///////////////////ALTA VIVIENDA/////
int buscarLibreServicio(eServicios* lista, int tam)
{
	int indice= -1;
	if(lista != NULL && tam > 0)
	    {
	        for(int i = 0; i < tam; i++)
	        {
	            if((*(lista+i)).isEmpty)
	            {
	                indice = i;
	                break;
	            }
	        }
	    }
	return indice;
}


int altaServicio(eServicios* listaVehi,int tamVou, eVehiculo* listaVia,int tamVia, eTipos* tipo,int tamTipo, int* pId)
{
	int allOk=0;
	int indice;
	eServicios auxServicio;



		if(listaVehi != NULL && tamVou>0 && listaVia != NULL && tamVia>0 && tipo != NULL && tamTipo>0 && pId != NULL)
		{
			system("cls");
			printf("-----------------------------\n");
			printf("         ALTA servicios          \n");
			printf("-----------------------------\n");

			indice=buscarLibreVehiculo(listaVia, tamVia);
			if(indice== -1)
			{
				printf("No hay espacio en el sistema\n");
			}
			else
			{
				auxServicio.idHoja=*pId;
				(*pId)++;


				mostrarVehiculos(listaVia,  tamVia, tipo, tamTipo);
				printf("Ingrese el ID del vehiculo: \n");
				scanf("%d", &auxServicio.vehiculoId);
				fflush(stdin);
				while(!validarIdVehiculo(listaVia,tamVia,auxServicio.vehiculoId ))
				{
		               printf("Error. Ingrese el Id del vehiculo nuevamente: \n");
		               scanf("%d", &auxServicio.vehiculoId);
		               fflush(stdin);
				}

				listaVehi[indice].vehiculoId = auxServicio.vehiculoId;

				pedirFlotante(&auxServicio.precioServicio, "Ingrese precio del servicio: \n", "error", 10,1000000);

				validarFecha(&auxServicio.fecha);



				auxServicio.isEmpty=0;

				listaVehi[indice]=auxServicio;
				allOk=1;
				printf("alta de voucher exitosa!!");
			}

		}
	return allOk;
}


void mostrarUnServicio(eServicios unServicio,eVehiculo* unViaje,int tamViaje, eTipos* tipoVehi, int tamTipo)
{
	char descripcionTipo[30];
	int indiceVehiculoAMostrar;

	if(unViaje != NULL && tamViaje>0 && tipoVehi != NULL && tamTipo>0)
	{
		indiceVehiculoAMostrar=buscarVehiculoId( unViaje,  tamViaje,  unServicio.vehiculoId);
		cargarDescripcionTipo(tipoVehi, tamTipo, unViaje[indiceVehiculoAMostrar].modelo, descripcionTipo);


				printf(" %3d          %19d               %23s          %22f           %d /%d / %d       \n",
						unServicio.idHoja,
						unViaje[indiceVehiculoAMostrar].idVehiculo ,
						descripcionTipo,
						unServicio.precioServicio,
						unServicio.fecha.dia,
						unServicio.fecha.mes,
						unServicio.fecha.anio
				);
	}



}

int mostrarServicios(eServicios* listaVou, int tamVou, eVehiculo* listaVia, int tamVia, eTipos* listaTipo,int tamTipo )
{
	int allOk=0;
	int flag=1;

	if(listaVou != NULL && tamVou>0)
	{
		system("cls");
		printf("--------------------------------------------------------------------------\n");
		printf("                        ***LISTA SERVICIOS***                                \n");
		printf("--------------------------------------------------------------------------\n");
		printf("|  ID-Servicio   |   ID-vehiculo   |     Descripcion      |    Precio Serv    |    fecha     \n");
		for(int i=0; i<tamVou; i++)
		{
			if(!listaVou[i].isEmpty)
			{
				mostrarUnServicio( listaVou[i],listaVia , tamVia, listaTipo, tamTipo);
				flag=0;
			}
		}
		if(flag)
		{
			printf("No hay servicios para dar el alta. \n");
		}
		allOk=1;
	}
	return allOk;
}




