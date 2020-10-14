#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "color.h"
#include "dataStore.h"


void printColor(eColor color)
{
    printf("    %4d      %10s  \n", color.idColor, color.nombreColor);
}




int printColores(eColor colores[], int tamc)
{
     int error = -1;
     int flag = 0;

    if(colores != NULL && tamc > 0)
    {
        //printf("\033[2J");
        printf("                   ***Listado de Colores***\n");
        printf("----------------------------------------------------------------------\n");
        printf("              ID Color               Nombre color    \n");
        printf("----------------------------------------------------------------------\n");
        for(int i=0; i<tamc; i++)
        {
                printColor(colores[i]);
                flag = 1;

        }

        if(!flag)
        {
            printf("No hay colores en la lista\n");
        }
        else
        {
            printf("\n\n");
        }
        error = 0;
    }
    return error;
}

int hardcodearColor(eColor colores[], int tam, int cant)
{
    int retorno = -1;



    if(colores != NULL && tam > 0 && cant <= tam )
    {
        retorno = 0;
        for(int i=0; i<cant; i++)
        {
            colores[i].idColor = idColores[i];
            strcpy(colores[i].nombreColor, nombresColores[i]);

            retorno++; // esto me devolvera la cantidad de empleados hardcodeados
        }
    }
    retorno = retorno + 1; // Esto lo hago para que el proximo empleado que de de alta me entre con el id correcto
    return retorno;
}

int cargarDescripcionColor(eColor colores[], int tamc, int id, char descripcion[])
{
    int error =1;

    if(tipos != NULL && tamc > 0 && descripcion!= NULL)
    {
        for(int i = 0;i<tamc; i++)
        {
            if(colores[i].idColor == id)
            {
                strcpy(descripcion, colores[i].nombreColor);
                error =0;
                puts(descripcion);
                break;
            }
        }
        return error;
    }
}
