#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dataStore.h"
#include "tipo.h"



void printTipo(eTipo tipo)
{
    printf("               %4d                  %10s  \n", tipo.idTipo, tipo.descripcionTipo);
}




int printTipos(eTipo tipos[], int tams)
{
     int error = -1;
     int flag = 0;

    if(tipos != NULL && tams > 0)
    {
        //printf("\033[2J");
        printf("                   ***Listado de Tipos de mascotas***\n");
        printf("       -----------------------------------------------|\n");
        printf("       |        ID Tipo                  Descripcion    \n");
        printf("       -----------------------------------------------|\n");
        for(int i=0; i<tams; i++)
        {
                printTipo(tipos[i]);
                flag = 1;

        }

        if(!flag)
        {
            printf("No hay tipos en la lista\n");
        }
        else
        {
            printf("\n\n");
        }
        error = 0;
    }
    return error;
}


int hardcodearTipo(eTipo tipos[], int tam, int cant)
{
    int retorno = -1;

    if(tipos != NULL && tam > 0 && cant <= tam )
    {
        retorno = 0;
        for(int i=0; i<cant; i++)
        {
            tipos[i].idTipo = idTipos[i];
            strcpy(tipos[i].descripcionTipo, tiposDescripcion[i]);

            retorno++; // esto me devolvera la cantidad de empleados hardcodeados
        }
    }
    retorno = retorno + 1; // Esto lo hago para que el proximo empleado que de de alta me entre con el id correcto
    return retorno;
}



int cargarDescripcionTipo(eTipo tipos[], int tamt, int id, char descripcion[])
{
    int error =1;

    if(tipos != NULL && tamt > 0 && id > 0 && descripcion != NULL)
    {
        for(int i = 0; i < tamt; i++)
        {
            if(tipos[i].idTipo == id)
            {
                strcpy(descripcion, tipos[i].descripcionTipo);
                error = 0;
                break;
             }

        }
        return error;
    }
}


