#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "servicio.h"
#include "dataStoreServicios.h"

void printServicio(eServicio servicio)
{
    printf("                   %4d      %15s    %.2f  \n", servicio.idServicio, servicio.descripcionServicio, servicio.precioServicio);
}




int printServicios(eServicio servicios[], int tamt)
{
     int error = -1;
     int flag = 0;

    if(servicios != NULL && tamt > 0)
    {
        //printf("\033[2J");
        printf("                   ***Listado de Servicios***\n");
        printf("----------------------------------------------------------------------\n");
        printf("              ID servicio      NombreServicio      precio    \n");
        printf("----------------------------------------------------------------------\n");
        for(int i=0; i<tamt; i++)
        {
                printServicio(servicios[i]);
                flag = 1;

        }

        if(!flag)
        {
            printf("No hay servicios en la lista\n");
        }
        else
        {
            printf("\n\n");
        }
        error = 0;
    }
    return error;
}

int hardcodearServicios(eServicio servicios[], int tam, int cant)
{
    int retorno = -1;

    if(servicios != NULL && tam > 0 && cant <= tam )
    {
        retorno = 0;
        for(int i=0; i<cant; i++)
        {
            servicios[i].idServicio = idServicios[i];
            strcpy(servicios[i].descripcionServicio, descripcionServicios[i]);
            servicios[i].precioServicio = precioServicios[i];

            retorno++; // esto me devolvera la cantidad de empleados hardcodeados
        }
    }
    retorno = retorno + 1; // Esto lo hago para que el proximo empleado que de de alta me entre con el id correcto
    return retorno;
}

int cargarDescripcionServicio(eServicio servicios[], int tams, int id, char descripcion[], float precio)
{
    int error =1;

    if(servicios != NULL && tams > 0 && descripcion!= NULL)
    {
        for(int i = 0;i<tams; i++)
        {
            if(servicios[i].idServicio == id)
            {
                strcpy(descripcion, servicios[i].descripcionServicio);
                precio = precioServicios[i];


            }
            error =0;
        }
        return error;
    }
}
