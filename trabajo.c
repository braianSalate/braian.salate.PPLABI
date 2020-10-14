#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dataStore.h"
#include "trabajo.h"


int initTrabajos(etrabajo trabajos[],int tam )
{
    int error = -1;

    if(trabajos != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}


int addTrabajo(eTrabajo trabajos[], int tamt, eServicio servicios[], int tams,eMascota mascotas[], int tam int id)
{
    int error = -1;
    eTrabajo nuevoTrabajo;
    int freePlace;
    //int validacion;

    if(trabajos != NULL && tamt > 0 && id > 0 && servicios != NULL && mascotas != NULL && tams >0)
    {
        printf("\033[2J");
        printf("  *** Alta de Trabajo ***\n\n");
        freePlace = searchFreePlace(trabajos, tam);
        if(freePlace == -1)
        {
            printf("Sistema completo, libere espacio para cargar un nuevo trabajo.\n");
        }
        else
        {
            nuevoTrabajo.idTrabajo = id;
            nuevotrabajo.isEmpty = 0;
            printServicios(servicios, tams);
            printf("Ingrese id del servicio a pedir: ");
            scanf("%d", nuevoTrabajo.idServicio);

            printMascotas(mascotas, tam);
            printf("Ingrese id de la mascota a hacerle el trabajo: ");
            fflush(stdin);
            scanf("%d", nuevoTrabajo.idMascota);






            trabajos[freePlace] = nuevotrabajo;
        }

        error = 0;
    }
    return error;
}

int searchFreePlace(eTrabajo trabajos[],int tam)
{
    int freePlace = -1;
    for(int i=0; i<tam;i++)
    {
        if(trabajos[i].isEmpty == 1)
        {
            freePlace = i;
            break;
        }
    }
    return freePlace;
}

void printTrabajo(eMascota mascota, eServicio servicios)
{

        printf("    %4d   %10s  %10s  \n", mascota.id, mascota.name, servicio.descripcionServicio, servicio.precioServicio);


}

int printMascotas(eMascota mascotas[], int tam, eTipo tipos[], int tams)
{
     int error = -1;
     int flag = 0;

    if(mascotas != NULL && tam > 0 && tipos != NULL && tams > 0 )
    {
        //printf("\033[2J");
        printf("                   ***Listado de Trabajos***\n");
        printf("----------------------------------------------------------------------\n");
        printf("              iD mascota      Nombre     Servicio   Precio   \n");
        printf("----------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(mascotas[i].isEmpty == 0)
            {
                printMascota(mascotas[i], tipos, tam);
                flag = 1;
            }
        }

        if(!flag)
        {
            printf("No hay mascotas en la lista\n");
        }
        else
        {
            printf("\n\n");
        }
        error = 0;
    }
    return error;
}
