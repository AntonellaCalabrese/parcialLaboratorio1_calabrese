/*
 * vehiculos.c
 *
 *  Created on: 21 oct 2022
 *      Author: antonella
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "tipo.h"
#include "vehiculos.h"
#include "fecha.h"
#include "validaciones.h"

int inicializarVehiculo(eVehiculo* lista, int tam)
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

int buscarVehiculoId(eVehiculo* lista, int tamVia , int idViaje)
{
    int seEncontro = -1;

    if(lista != NULL && tamVia > 0)
    {
        for(int i = 0; i < tamVia; i++)
        {
            if(lista[i].idVehiculo == idViaje && lista[i].isEmpty == 0)
            {
                seEncontro = i;
                break;
            }
        }
    }
    return seEncontro;
}


// ///////////////////ALTA VIVIENDA/////
int buscarLibreVehiculo(eVehiculo* lista, int tam)
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


int altaVehiculo(eVehiculo* lista,eTipos* tipos, int tamTipo, int tam, int* pId)
{
	int allOk=0;
	int indice;
	eVehiculo auxVehiculo;


		if(lista != NULL && tam>0 && pId != NULL)
		{
			system("cls");
			printf("-----------------------------\n");
			printf("         ALTA VEHICULO          \n");
			printf("-----------------------------\n");

			indice=buscarLibreVehiculo(lista, tam);
			if(indice== -1)
			{
				printf("No hay espacio en el sistema\n");
			}
			else
			{
				auxVehiculo.idVehiculo=*pId;
				(*pId)++;


				validarFecha(&auxVehiculo.modelo);

				pedirCadena(auxVehiculo.color, "ingrese Color : \n");
				validarLetras(auxVehiculo.color);
				primerLetraMayuscula(auxVehiculo.color);

		        mostrarTipos(tipos, tamTipo);
		        pedirEntero(&auxVehiculo.idTipo, "Ingrese el ID del tipo deseado.\n", "Error. Ingrese nuevamente el ID del tipo deseado\n", 1000, 1003);

		        auxVehiculo.isEmpty=0;

				lista[indice]=auxVehiculo;

			}
			allOk=1;
		}
	return allOk;
}

void mostrarVehiculo(eVehiculo unVehiculo, eTipos* tipoVehi, int tamTipo)
{
	char descTipo[30];

	cargarDescripcionTipo(tipoVehi, tamTipo, unVehiculo.idTipo, descTipo);


			printf(" %3d    %19s   %23d     %22s      \n",
					unVehiculo.idVehiculo,
					descTipo,
					unVehiculo.modelo,
					unVehiculo.color

			);

}




int mostrarVehiculos(eVehiculo* listaVehi, int tam, eTipos* tipo, int tamTipo)
{
	int allOk=0;
	int flag=1;

	if(listaVehi != NULL && tam>0 && tipo != NULL && tamTipo>0)
	{
		system("cls");
		printf("--------------------------------------------------------------------------\n");
		printf("                        ***LISTA VEHICULOS***                                \n");
		printf("--------------------------------------------------------------------------\n");
		printf("|  id vehiculo   |   descripcion   |     Modelo      |    Color    | \n");
		for(int i=0; i<tam; i++)
		{
			if(listaVehi[i].isEmpty == 0)
			{
				mostrarVehiculo(listaVehi[i],tipo,tamTipo);
				flag=0;
			}
		}
		if(flag)
		{
			printf("No hay Viajes para mostrar. \n");
		}
		allOk=1;
	}
	return allOk;
}

int menuDeModificaciones()
{
	int opcion;
	printf("----------------------------------------------\n");
	printf("  Ingrese una de las opciones para modificar: \n");
	printf("----------------------------------------------\n");
	printf("1. descripcion \n");
	printf("2. Precio Servicio \n");


	scanf("%d", &opcion);
	return opcion;
}



int modificacionVehiculo(eVehiculo* lista,eTipos* tipo,int tamTipo, int tam )
{
	int allOk=0;
	int id;
	int indice;

	char confirma;
	int opcion;

	char auxDestino[20];




	if(lista!=NULL && tam>0 && tipo != NULL && tamTipo>0)
	{
		system("cls");
		mostrarVehiculos(lista, tam,tipo,tamTipo);
		printf("  Ingrese el ID a modificar: \n");
		scanf("%d", &id);

		indice=buscarVehiculoId(lista, tam, id);

		if(indice==-1)
		{
			printf("no hay viajes con ID ingresado. %d\n", id);
		}else
		{
			mostrarVehiculo(lista[indice],tipo,tamTipo);

			printf("confirma modificacion?: s/n \n");
			fflush(stdin);
			scanf("%c", &confirma);

			while(confirma != 's' && confirma != 'n')
            {
                printf("\nError. Ingrese nuevamente la opcion correcta. Esta es la bicicleta que desea modificar? (s: SI y n: NO)\n");
                fflush(stdin);
                scanf("%c", &confirma);
            }

			if(confirma=='s')
			{
				opcion = menuDeModificaciones();
				switch(opcion)
				{
					case 1:
						pedirCadena(auxDestino, "Ingrese nuevo tipo de auto: \n");
						validarLetras(auxDestino);
						primerLetraMayuscula(auxDestino);
						strcpy(lista[indice].descripcion, auxDestino);
						break;
					case 2:
						//pedirFlotante(&auxPrecioServicio, "Ingrese nuevo precio de servicio: \n","error, ingrese un numero valido",1,100000);
					//	lista[indice]. =auxPrecioServicio;
						break;
					default:
						printf("opcion invalida. \n");
				}
				allOk=1;
			}else{
				printf("la modificacion se ha cancelado. \n");
			}
		}
	}
	return allOk;
}


int bajaVehiculo(eVehiculo* lista,eTipos* tipos, int tamTipo, int tam)
{
	int allOk;
	int id;
	int indice;
	char confirma;

	if(lista!=NULL && tam>0 && tipos != NULL && tamTipo>0)
	{
		system("cls");

		printf("Ingrese ID: \n");
		scanf("%d", &id);

		indice=buscarVehiculoId(lista, tam,id);

		if(indice==-1)
		{
			printf("No hay viajes ingresadas con ese ID %d\n", id);
		}else
		{
			mostrarVehiculo(lista[indice],tipos,tamTipo);
			printf("confirma Baja del viaje?: s/n");
			fflush(stdin);
			scanf("%c", &confirma);
			confirma=tolower(confirma);
		}
		if(confirma=='s')
		{
			lista[indice].isEmpty=1;
			printf("Baja Exitosa!!!!\n");
			allOk=1;
		}else
		{
			printf("La baja ha sido cancelada.");
		}

	}
	return allOk;

}


int flagReset(eVehiculo* lista, int tam, int* flag)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                *flag = 1;
                todoOk = 1;
                break;
            }
            else
            {
                *flag = 0;
            }
        }
    }
    return todoOk;
}


int validarIdVehiculo(eVehiculo* vehiculo, int tamVia, int idViaje)
{
    int todoOk = 0;

    if(vehiculo != NULL && tamVia > 0)
    {
        for(int i = 0; i < tamVia; i++)
        {
            if(vehiculo[i].idVehiculo == idViaje && vehiculo[i].isEmpty == 0)
            {
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}



int mostrarVehiculoSeleccionado(eVehiculo* listaVehi, int tamVia, eTipos* tipos, int tamTipo)
{

	int flag=1;
	int todoOk = 0;
	int idTipo;
	char descripcion[30];

	if(listaVehi != NULL && tamVia>0 && tipos != NULL && tamTipo>0)
	{
	        system("cls");
	        printf("             *** Listado de Cada Tipo ***                      \n");
	        printf("------------------------------------------------------------------\n");

	        mostrarTipos(tipos, tamTipo);
	        pedirEntero(&idTipo, "Ingrese el ID del tipo deseado.\n", "Error. Ingrese nuevamente el ID del tipo deseado\n", 1000, 1003);

	        cargarDescripcionTipo(tipos, tamTipo, idTipo, descripcion);

	        for(int i = 0; i < tamVia; i++)
	        {
	            if(listaVehi[i].idTipo == idTipo && listaVehi[i].isEmpty == 0)
	            {
	                mostrarVehiculo(listaVehi[i],tipos,tamTipo);
	                flag = 0;
	            }
	        }

	        if(flag)
	        {
	            system("cls");
	            printf("No hay viajes de tipo %s para mostrar.\n", descripcion);
	        }
	        todoOk = 1;

	}

	return todoOk;
}
