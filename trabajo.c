#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "trabajo.h"
#include "cliente.h"





int initTrabajos(eTrabajo trabajos[],int tam )
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


int altaTrabajo(eTrabajo trabajos[], int tamt, eServicio servicios[], int tams, eTipo tipos[], int tamti, int id, eMascota mascotas[], int tam, eColor colores[], int tamc, eCliente clientes[], int tamcl)
{
    int error = -1;
    eTrabajo nuevoTrabajo;
    int freePlaceTrabajo;
    int idMascota;
    int idServicio;
    int dia;
    int mes;
    int anio;

    if(trabajos != NULL && tamt > 0 && id > 0)
    {
        printf("\033[2J");
        printf("  *** Alta de Trabajo ***\n\n");
        freePlaceTrabajo = searchFreePlaceTrabajo(trabajos, tams);
        if(freePlaceTrabajo == -1)
        {
            printf("Sistema completo, libere espacio para cargar una nueva mascota.\n");
        }
        else
        {
            printf("\033[2J");
            nuevoTrabajo.idTrabajo = id;
            nuevoTrabajo.isEmpty = 0;
            //pido
            printMascotas(mascotas, tam, tipos, tamti, colores, tamc, clientes, tamcl);
            printf("Ingrese id de mascota que quiere hacerle el trabajo: ");
            scanf("%d", &idMascota);
            while(validarIdMascota(idMascota, mascotas, tam))
            {
                printf("Id inexistente, por favor ingrese un id valido: ");
                scanf("%d", &idMascota);
            }
            printf("\033[2J");
            //pido servicio
            printServicios(servicios, tams);
            printf("Ingrese id del servicio a adquirir: ");
            fflush(stdin);
            scanf("%d", &idServicio);
            while(validarIdServicio(idServicio, servicios, tams))
            {
                printf("Id inexistente, por favor ingrese un id valido: ");
                scanf("%d", &idServicio);
            }


            printf("\033[2J");
            printf("Ingrese fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d", &dia,&mes,&anio);



            nuevoTrabajo.idMascota = idMascota;
            nuevoTrabajo.idServicio = idServicio;
            nuevoTrabajo.fechaServ.dia = dia;
            nuevoTrabajo.fechaServ.mes = mes;
            nuevoTrabajo.fechaServ.anio = anio;
            trabajos[freePlaceTrabajo] = nuevoTrabajo;
        }

        error = 0;
    }
    return error;
}

int searchFreePlaceTrabajo(eTrabajo trabajos[],int tam)
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

void printTrabajo(eTrabajo trabajo, int tamtr, eMascota mascotas[], int tam, eServicio servicios[], int tams)
{
        char servicio[20];
        char nombre[20];
        float precio;
        if(cargarDescripcionServicio(servicios, tams, trabajo.idServicio, servicio,precio) == 0 && cargarNombreMascota(mascotas, tam, trabajo.idMascota, nombre) == 0)
        {
            printf("                  %4d   %10s  %15s    %d/%d/%d\n", trabajo.idTrabajo, nombre, servicio, trabajo.fechaServ.dia, trabajo.fechaServ.mes, trabajo.fechaServ.anio);
        }
        else
        {
            printf("problemas con la carga de la descripcion");
        }

}



int printTrabajos(eTrabajo trabajos[], int tam, eServicio servicios[], int tams, eMascota mascotas[], int tamm)
{
     int error = -1;
     int flag = 0;

    if(trabajos != NULL && tam > 0 && servicios != NULL && tams > 0 )
    {
        //printf("\033[2J");
        printf("                   ***Listado de Trabajos***\n");
        printf("----------------------------------------------------------------------\n");
        printf("             iD trabajo      Nombre        Servicio    Fecha\n");
        printf("----------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(trabajos[i].isEmpty == 0)
            {
                printTrabajo(trabajos[i], tam, mascotas, tamm, servicios, tams );
                flag = 1;
            }
        }

        if(!flag)
        {
            printf("No hay trabajos en la lista\n");
        }
        else
        {
            printf("\n\n");
        }
        error = 0;
    }
    return error;
}


int validarIdMascota(int a, eMascota mascotas[], int tam)
{
    int error = 1;
    for(int i=0; i<tam; i++)
    {
        if(mascotas[i].idMascota == a)
        {
            error = 0;
            break;
        }
    }
    return error;
}

int validarIdServicio(int a, eServicio servicios[], int tam)
{
    int error = 1;
    for(int i=0; i<tam; i++)
    {
        if(servicios[i].idServicio == a)
        {
            error = 0;
            break;
        }
    }
    return error;
}

/*int hardcodearTrabajos(eTrabajo trabajos[], int tam, int cant)
{
    int retorno = -1;

    if(trabajos != NULL && tam > 0 && cant <= tam )
    {
        retorno = 0;
        for(int i=0; i<cant; i++)
        {
            trabajos[i].idTrabajo = idTrabajos[i];
            trabajos[i].idServicio = idServiciosTrabajo[i];
            trabajos[i].idMascota = idMascotasTrabajo[i];
            trabajos[i].fechaServ = fechas[i];

            retorno++; // esto me devolvera la cantidad de empleados hardcodeados
        }
    }
    retorno = retorno + 1; // Esto lo hago para que el proximo empleado que de de alta me entre con el id correcto
    return retorno;
}*/


