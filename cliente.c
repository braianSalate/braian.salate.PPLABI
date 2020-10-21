#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cliente.h"
#include "fecha.h"
#include "arrayMascotas.h"
#include "dataStoreClientes.h"


int initClientes(eCliente clientes[],int tamcl )
{
    int error = -1;

    if(clientes != NULL && tamcl > 0)
    {
        for(int i=0; i<tamcl; i++)
        {
            clientes[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

/*int altaCliente(eCliente clientes[], int tamcl, eMascota mascotas[], int tam, int id)
{
    int error = -1;
    eCliente nuevoCliente;
    int freePlace;

    //int validacion;

    if(clientes != NULL && tamcl > 0 && id > 0)
    {
        printf("\033[2J");
        printf("  *** Alta de Cliente ***\n\n");
        freePlace = searchFreePlaceClientes(clientes, tamcl);
        if(freePlace == -1)
        {
            printf("Sistema completo, libere espacio para cargar una nueva mascota.\n");
        }
        else
        {
            nuevoCliente.idCliente = id;
            nuevoCliente.isEmpty = 0;
            printf("Ingrese nombre: ");
            fflush(stdin);
            scanf("%s", nuevoCliente.nombreCliente);
            /*while(validarCadena(nuevaMascota.name) == 1)
            {
                printf("Nombre invalido, por favor ingrese nuevo nombre: ");
                fflush(stdin);
                scanf("%s", nuevaMascota.name);
            }*/
/*
            printf("\033[2J");
            printMascotas(mascotas, tam);
            printf("ingrese id de mascota perteneciente a %s: ", nuevoCliente.nombreCliente);
            scanf("%d", &nuevoCliente.idMascota);
             while(validarIdMascotaCliente(nuevoCliente.idMascota)==0)
            {
                printf("Ingrese id existente: ");
                scanf("%f", &nuevoCliente.idMascota);
            }



            printf("\033[2J");
            printColores(colores, tamc);
            printf("ingrese color: ");
            scanf("%d", &nuevaMascota.idColor);
             while(validarColor(nuevaMascota.idColor)==0)
            {
                printf("Ingrese color valido(del 5000 al 5001): ");
                scanf("%f", &nuevaMascota.idTipo);
            }


            mascotas[freePlace] = nuevaMascota;
        }

        error = 0;
    }
    return error;
}

int searchFreePlaceCliente(eCliente clientes[],int tamcl)
{
    int freePlace = -1;
    for(int i=0; i<tamcl;i++)
    {
        if(clientes[i].isEmpty == 1)
        {
            freePlace = i;
            break;
        }
    }
    return freePlace;
}
*/

int hardcodearCliente(eCliente clientes[], int tamcl, int cant)
{
    int retorno = -1;

    if(clientes != NULL && tamcl > 0 && cant <= tamcl )
    {
        retorno = 0;
        for(int i=0; i<cant; i++)
        {
            clientes[i].idCliente = idClientes[i];
            strcpy(clientes[i].nombreCliente, nombreClientes[i]);
            clientes[i].idMascota = idMascotas[i];
            clientes[i].sexo = sexos[i];

            retorno++; // esto me devolvera la cantidad de empleados hardcodeados
        }
    }
    retorno = retorno + 1; // Esto lo hago para que el proximo empleado que de de alta me entre con el id correcto
    return retorno;
}


int cargarNombreCliente(eCliente clientes[], int tamcl, int id, char nombre[])
{
    int error =1;

    if(clientes != NULL && tamcl > 0 && id > 0 && nombre != NULL)
    {
        for(int i = 0; i < tamcl; i++)
        {
            if(clientes[i].idCliente == id)
            {
                strcpy(nombre, clientes[i].nombreCliente);
                error = 0;
                break;
             }

        }
        return error;
    }
}

