#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dataStore.h"
#include "arrayMascotas.h"


int initMascotas(eMascota mascotas[],int tam )
{
    int error = -1;

    if(mascotas != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            mascotas[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

void printMascota(eMascota mascota, eTipo tipos[], int tam)
{
    char descTipo[20];
    printf("%d\n", &mascota.idTipo);
    if(cargarDescripcionTipo(tipos, tam, mascota.idTipo, descTipo) == 0)
    {
        printf("    %4d   %10s  %10s  \n", mascota.id, mascota.name, descTipo);
    }

}

int printMascotas(eMascota mascotas[], int tam, eTipo tipos[], int tams)
{
     int error = -1;
     int flag = 0;

    if(mascotas != NULL && tam > 0 && tipos != NULL && tams > 0 )
    {
        //printf("\033[2J");
        printf("                   ***Listado de Mascotas***\n");
        printf("----------------------------------------------------------------------\n");
        printf("                   Legajo      Nombre     Tipo   \n");
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

int addMascota(eMascota mascotas[], int tam, eTipo tipos[], int tams, int id)
{
    int error = -1;
    eMascota nuevaMascota;
    int freePlace;
    //int validacion;

    if(mascotas != NULL && tam > 0 && id > 0)
    {
        printf("\033[2J");
        printf("  *** Alta de Mascota ***\n\n");
        freePlace = searchFreePlace(mascotas, tam);
        if(freePlace == -1)
        {
            printf("Sistema completo, libere espacio para cargar una nueva mascota.\n");
        }
        else
        {
            nuevaMascota.id = id;
            nuevaMascota.isEmpty = 0;
            printf("Ingrese nombre: ");
            fflush(stdin);
            scanf("%s", nuevaMascota.name);
            /*validacion = validarCadena(newEmployee.name);
            if(!validacion)
            {
                printf("Por favor ingrese un nombre valido: ");
                fflush(stdin);
                scanf("%s", newEmployee.name);
            }*/


            printTipos(tipos, tams);
            printf("ingrese tipo: ");
            scanf("%d", &nuevaMascota.idTipo);
             if(validarTipo(nuevaMascota.idTipo)==0)
            {
                printf("Ingrese tipo valido(del 1 al 5): ");
                scanf("%f", &nuevaMascota.idTipo);
            }

           /* printf("Ingrese fecha de nacimiento dd/mm/aaaa: \n");
            scanf("%d/%d/%d",&newEmployee.fNac.dia,&newEmployee.fNac.mes,&newEmployee.fNac.anio);
            printSectores(sectores,tams);
            printf("Ingrese el numero de id de sector : \n");
            scanf("%d",&newEmployee.idSector);*/

            mascotas[freePlace] = nuevaMascota;
        }

        error = 0;
    }
    return error;
}

int searchFreePlace(eMascota mascotas[],int tam)
{
    int freePlace = -1;
    for(int i=0; i<tam;i++)
    {
        if(mascotas[i].isEmpty == 1)
        {
            freePlace = i;
            break;
        }
    }
    return freePlace;
}

int buscarMascota(eMascota mascotas[], int tam, int id)
{
    int mascotaIndex = -1;
    for(int i=0; i<tam;i++)
    {
        if(mascotas[i].id == id && mascotas[i].isEmpty == 0)
        {
            mascotaIndex = i;
            break;
        }
    }
    return mascotaIndex;
}

int removeMascota(eMascota mascotas[], int tam, eTipo tipos[], int tams) //0 baja exitosa 1 hubo un problema 2 se cancela la baja
{
    int error = -1;
    int mascotaIndex;
    int id;
    int confirm;

   if(mascotas != NULL && tam > 0)
    {
        printf("\033[2J");
        printf("***Baja de mascotas\n");
        printMascotas(mascotas, tam, tipos, tams);
        printf("Ingrese legajo de la mascota que desea eliminar: \n");
        scanf("%d", &id);
        mascotaIndex = buscarMascota(mascotas, tam, id);
        if(mascotaIndex == -1)
        {
            printf("No hay ninguna mascota con ese legajo\n");
        }
        else
        {
            printf("\033[2J");
            printMascota(mascotas[mascotaIndex], tipos, tam);
            printf("Confirma la baja del empleado?\n -1 para confirmar\n -2 para cancelar la baja\n ");
           scanf("%d", &confirm);


            if(confirm == 1)
            {
                mascotas[mascotaIndex].isEmpty = 1;
                error = 0;
            }
            else
            {
               if(confirm == 2 )
               {
                    error = 2;
               }
               else
               {
                   printf("Opcion invalida por favor ingrese:\n -1 para confirmar\n -2 para cancelar la baja\n ");
                   scanf("%d", &confirm);
               }
            }
        }

    }
    return error;
}

int validarOpcion(int a)
{
    int rdo;
    if(a != 1 && a!= 2 && a !=3 && a != 4 && a != 5 && a != 6 && a!=7 && a != 8 && a != 9 && a!=10)
    {
        rdo = 0;
    }else{rdo=1;}
    return rdo;
}

int modificarMascota(eMascota mascotas[], int tam, eTipo tipos[], tams)
{
    int error = 1;
    int mascotaIndex;
    int id;
    int confirm;
    int opcion;
    eMascota nuevaMascota;
    char nuevoTipo[20];
    float nuevaEdad;


   if(mascotas != NULL && tam > 0)
    {
        printf("\033[2J");
        printf("***Modificar una mascota\n");
        printMascotas(mascotas, tam, tipos, tams);
        printf("Ingrese legajo de la mascota que desea modificar: \n");
        scanf("%d", &id);
        mascotaIndex = buscarMascota(mascotas, tam, id);
        if(mascotaIndex == -1)
        {
            printf("No hay ninguna mascota con ese legajo\n");
        }
        else
        {
            printf("\033[2J");
            printMascota(mascotas[mascotaIndex], tipos, tam);
            printf("***Opciones a modificar***\n");
            printf("1 tipo\n");
            printf("2 edad\n");
            printf("Elija que campo desea modificar: ");
            scanf("%d", &opcion);
            switch(opcion)
            {
                case 1:
                    printf("Ingrese nuevo tipo: ");
                    fflush(stdin);
                    scanf("%s", nuevaMascota.name);
                    printf("Confirma nuevo nombre?\n -1 para confirmar\n -2 para cancelar \n ");
                    scanf("%d", &confirm);


                    if(confirm == 1)
                    {
                        strcpy(mascotas[mascotaIndex].name, nuevaMascota.name);
                        error = 0;
                    }
                    else
                    {
                       if(confirm == 2 )
                       {
                            error = 2;
                       }
                       else
                       {
                           printf("Opcion invalida por favor ingrese:\n -1 para confirmar\n -2 para cancelar la baja\n ");
                           scanf("%d", &confirm);
                       }
                    }
                break;
                case 2:
                    printf("Ingrese nueva edad: ");
                    scanf("%f", nuevaMascota.edad);
                    printf("Confirma nueva edadd?\n -1 para confirmar\n -2 para cancelar \n ");
                    scanf("%d", &confirm);


                    if(confirm == 1)
                    {
                        mascotas[mascotaIndex].edad = nuevaMascota.edad;
                        error = 0;
                    }
                    else
                    {
                       if(confirm == 2 )
                       {
                            error = 2;
                       }
                       else
                       {
                           printf("Opcion invalida por favor ingrese:\n -1 para confirmar\n -2 para cancelar la baja\n ");
                           scanf("%d", &confirm);
                       }
                    }


                break;

                default:
                printf("Opcion invalida!");
            }
        }

    }
    return error;
}

int validarTipo(int a)
{
    int rdo;
    if(a != 1 && a!= 2 && a !=3 && a != 4 && a != 5 )
    {
        rdo = 0;
    }else{rdo=1;}
    return rdo;
}
/*int validarEdad(int a)
{
    int rdo;
    if(a <= 0 )
    {
        rdo = 0;
    }else{rdo=1;}
    return rdo;
}*/

int ordenarMascotasPorNombre(eMascota mascotas[], int tam)
{
    int error = 1;
    eMascota auxMascota;
    if(mascotas != NULL && tam >0)
    {
        for(int i = 0; i < tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(strcmp(mascotas[i].name, mascotas[j].name)>0)
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j]=auxMascota;
                }
            }
        }
        error = 0;
    }
    return error;
}

int ordenarMascotaPorTipo(eMascota mascotas[], int tam)
{
    int error = 1;
    eMascota auxMascota;
    if(mascotas != NULL && tam >0)
    {
        for(int i = 0; i < tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(mascotas[i].idTipo > mascotas[j].idTipo)
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j]= auxMascota;
                }
            }
        }
        error = 0;
    }
    return error;
}





