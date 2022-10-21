/*
 * tipo.h
 *
 *  Created on: 21 oct 2022
 *      Author: antonella
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct
{
    int id;
    char descripcion[20];
}eTipos;

int cargarDescripcionTipo(eTipos tipos[], int tamTipo,int idTipo, char descripcion[]);
int mostrarTipos(eTipos tipos[], int tamTipo);

#endif /* TIPO_H_ */
