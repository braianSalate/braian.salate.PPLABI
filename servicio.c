#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "servicio.h"
#include "dataStore.h"

void printServicio(eServicio servicio)
{
    printf("    %4d      %10s    %.2f  \n", servicio.idServicio, servicio.descripcionServicio, servicio.precioServicio);
}




int printServicios(eServicio servicios[], int tamt)
{
     int error = -1;
     int flag = 0;

    if(tipos != NULL && tamt > 0)
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
            strcpy(servicios[i].descripcionServicio, serviciosDesc[i]);
            servicios[i].precioServicio = serviciosPrecio[i];

            retorno++; // esto me devolvera la cantidad de empleados hardcodeados
        }
    }
    retorno = retorno + 1; // Esto lo hago para que el proximo empleado que de de alta me entre con el id correcto
    return retorno;
}

int cargarDescripcionServicio(eServicio servicios[], int tams, int id, char desripcion[])
{
    int error =1;

    if(servicios != NULL && tams > 0 && descripcion!= NULL)
    {
        for(int i = 0;i<tams; i++)
        {
            if(servicios[i].idServicio == id)
            {
                strcpy(descripcion, servicios[i].descripcionServicio);
                error =0;
                puts(descripcion);
                break;
            }
        }
        return error;
    }
}
