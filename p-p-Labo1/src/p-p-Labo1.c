/*
 ============================================================================
 Name        : p-p-Labo1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hardcodeo.h"

#include "validaciones.h"
#include "servicios.h"
#include "vehiculos.h"
#include "tipo.h"


#define TAM_SERV 2000

#define TAM_TIPO 3

#define TAM_VEHI 50

int main(void)
{
	setbuf(stdout, NULL);

	eVehiculo listaVehi[TAM_VEHI];
	eServicios listaServicio[TAM_SERV];

	int respuestaMenuPrincipal;
	int opcionElegida;
	int seguir='s';
	int nextIdViaje=100;
	int nextIdVoucher=2000;

	int flag=0;

    eTipos tipoVehiculo[TAM_TIPO] = {
        {1000, "Sedan3ptas"},
        {1001, "Sedan5ptas"},
        {1002, "camioneta"},
    };

	if(inicializarVehiculo(listaVehi, TAM_VEHI) == -1)
	{
	    printf("Hubo un problema al inicializar el VEHICULO.");
	}

	if(inicializarServicio(listaServicio, TAM_SERV) == -1)
	{
		printf("Hubo un problema al inicializar el servicio.");
	}


	do{
		respuestaMenuPrincipal=getNumero(&opcionElegida, " ***Ingrese una de las opciones: *** \n >>1. Alta   \n >>2. Modificar  \n >>3. Baja : \n >>4. Listar :  \n >>5. Listar Tipos: \n >>6. Alta servicio \n >>7. listar servicios \n >>8. Informes: \n >>9. salir \n", "reingrese la opcion elegida",1,9,3);
		if(respuestaMenuPrincipal==0)
		{
			switch(opcionElegida)
			{
	    		case 1:
	    			if(altaVehiculo(listaVehi,tipoVehiculo,TAM_TIPO, TAM_VEHI, &nextIdViaje))
	    			{
	    			   mostrarVehiculos(listaVehi,TAM_VEHI,tipoVehiculo,TAM_TIPO);
	    			   printf("Alta exitosa!!\n");
	    			   flag=1;
	    			}else
	    			{
	    			   printf("No hay vehiculos para registrar\n");
	    			}
	    		break;
	    		case 2:
	    			if(flag==0)
	    			{
	    			   printf("Debe ingresar un vehiculo primero para modificar. \n");
	    			}
	    			else
	    			{
	    			    if(modificacionVehiculo(listaVehi,tipoVehiculo, TAM_TIPO, TAM_VEHI))
	    			    {
	    			    	printf("Modificacion Exitosa \n");
	    			    }
	    			    else
	    			    {
	    			    	printf("Hubo un problema haciendo la modificacion. \n");
	    			    }
	    			}
	    			break;
	    		case 3:
    				if(flag==0)
    				{
    					printf("Debe ingresar un vehiculo primero para dar de Baja\n");
    				}
    				else
    				{
    					if(bajaVehiculo(listaVehi,tipoVehiculo,TAM_TIPO,TAM_VEHI))
    					{
    						flagReset(listaVehi, TAM_VEHI, &flag);
    					}
    					else
    					{
    						printf("Hubo un problema al hacer la Baja. \n");
    					}
    				}
	    			break;
	    		case 4:
	                if(flag==0)
	                 {
	                	 printf("Al menos debe dar de alta un viaje para poder mostrar todos los viajes\n");

	                 }
	                 else
	                 {
	                	 if(mostrarVehiculos(listaVehi,TAM_VEHI,tipoVehiculo,TAM_TIPO))
	                     {
	                         printf("lista mostrada.\n");
	                     }
	                	 else{
	                		 printf("Hubo un problema al informar");
	                	 }
	                 }
	                 break;
	    		case 5:
	                if(!mostrarTipos(tipoVehiculo, TAM_TIPO))
	                {
	                    printf("Hubo un problema al listar los tipos.\n");
	                }
	                break;

	    			break;
	    		case 6:
	    			if(flag==0)
	    			{
	    				printf("debe dar de alta un viaje primero para dar de alta un voucher\n");
	    			}
	    			else
	    			{
						if(altaServicio(listaServicio, TAM_SERV, listaVehi, TAM_VEHI,  tipoVehiculo, TAM_TIPO, &nextIdVoucher))
						{
						   mostrarServicios(listaServicio,TAM_SERV, listaVehi,TAM_VEHI,tipoVehiculo,TAM_TIPO);
						   printf("Alta exitosa!!\n");
						   flag=1;
						}else
						{
						   printf("No hay viajes para registrar\n");
						}
	    			}

	    			break;
	    		case 7:
	    			if(flag==0)
	    			{
	    				printf("primero debe dar de alta un viaje y luego dar de alta un voucher para listar vouchers \n");
	    			}
	    			else
	    			{
					   if(mostrarServicios(listaServicio,TAM_SERV, listaVehi,TAM_VEHI,tipoVehiculo,TAM_TIPO))
						{
							printf("el voucher fue mostrado exitosamente \n");
						}
						else
						{
							printf("Hubo un problema al mostrar el voucher. \n");
						}
	    			}

	    	    	break;
	    		case 8:

	    			switch(menuDeInformes())
	    			{
	    				case 1:
	    					mostrarVehiculoSeleccionado(listaVehi, TAM_VEHI, tipoVehiculo , TAM_TIPO);
	    					break;
	    				case 2:
	    					//mostrarVouFechaSeleccionada( listaVou,TAM_VOU, listaViaje, TAM_VIA,tipoViaje,TAM_TIPO );
	    					break;
	    				case 3:
	    					//mostrarVoucherViajeSeleccionado( listaVou,  TAM_VOU,  listaViaje,  TAM_VIA,  tipoViaje,  TAM_TIPO);
							break;
	    			}

	    			flag=1;
	    			break;
	    		case 9:
	    			seguir='n';
	    		break;
	    			default:
	    			printf("opcion invalida\n\n");
	    		}
			}
	    }
	    while(seguir == 's');
		return EXIT_SUCCESS;
}
