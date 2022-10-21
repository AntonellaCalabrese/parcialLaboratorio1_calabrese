/*
 * tipo.c
 *
 *  Created on: 21 oct 2022
 *      Author: antonella
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "tipo.h"

int cargarDescripcionTipo(eTipos tipos[], int tamTipo,int idTipo, char descripcion[])
{
    int todoOk = 0;

    if(tipos != NULL && tamTipo > 0 && descripcion != NULL)
    {
        for(int i = 0; i < tamTipo; i++)
        {
            if(tipos[i].id == idTipo)
            {
                strcpy(descripcion,tipos[i].descripcion);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarTipos(eTipos tipos[], int tamTipo)
{
    int todoOk = 0;

    if(tipos != NULL && tamTipo > 0)
    {
        printf(" *** Listado de Tipos ***\n");
        printf("------------------------\n");
        printf("ID       |Tipos  \n");
        printf("------------------------\n");
        for(int i = 0; i < tamTipo; i++)
        {
            printf("%d       %s\n",tipos[i].id, tipos[i].descripcion);
        }
        todoOk = 1;
    }
    return todoOk;
}

