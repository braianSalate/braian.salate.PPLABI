#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arrayMascotas.h"
#include "dataStoreMascotas.h"
#include "tipo.h"
#include "color.h"
#include "cliente.h"
#include "servicio.h"
#include "trabajo.h"





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

void printMascota(eMascota mascota, eTipo tipos[], int tamt, eColor colores[], int tamc, eCliente clientes[], int tamcl)
{
    char tipo[20];
    char color[20];
    char nombre[20];
    if(cargarDescripcionTipo(tipos, tamt, mascota.idTipo, tipo) == 0 && cargarDescripcionColor(colores, tamc, mascota.idColor, color) == 0 && cargarNombreCliente(clientes, tamcl, mascota.idCliente, nombre) == 0)
    {
        printf("                %4d     %10s  %10s  %10s  %.2f %10s\n", mascota.idMascota, mascota.name, tipo, color,mascota.edad, nombre);
    }
    else
    {
        printf("Problema al recuperar");
    }


}




int printMascotas(eMascota mascotas[], int tam, eTipo tipos[], int tamt, eColor colores[], int tamc, eCliente clientes[], int tamcl)
{
     int error = -1;
     int flag = 0;

    if(mascotas != NULL && tam > 0 && tipos != NULL && tamt > 0 )
    {
        //printf("\033[2J");
        printf("                          ***Listado de Mascotas***\n");
        printf("               ---------------------------------------------------\n");
        printf("               Legajo         Nombre        Tipo    Color    Edad  Nombreduenio  \n");
        printf("               -----------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(mascotas[i].isEmpty == 0)
            {
                printMascota(mascotas[i], tipos, tamt, colores, tamc, clientes, tamcl);
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

int addMascota(eMascota mascotas[], int tam, eTipo tipos[], int tams, eColor colores[],int tamc, int id)
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
            nuevaMascota.idMascota = id;
            nuevaMascota.isEmpty = 0;
            printf("Ingrese nombre: ");
            fflush(stdin);
            scanf("%s", nuevaMascota.name);
            /*while(validarCadena(nuevaMascota.name) == 1)
            {
                printf("Nombre invalido, por favor ingrese nuevo nombre: ");
                fflush(stdin);
                scanf("%s", nuevaMascota.name);
            }*/

            printf("\033[2J");
            printTipos(tipos, tams);
            printf("ingrese tipo: ");
            scanf("%d", &nuevaMascota.idTipo);
             while(validarTipo(nuevaMascota.idTipo)==0)
            {
                printf("Ingrese tipo valido(del 1000 al 1004): ");
                scanf("%f", &nuevaMascota.idTipo);
            }



            printf("\033[2J");
            printColores(colores, tamc);
            printf("ingrese color: ");
            scanf("%d", &nuevaMascota.idColor);
             while(validarColor(nuevaMascota.idColor)==0)
            {
                printf("Ingrese color valido(del 5000 al 5004): ");
                scanf("%f", &nuevaMascota.idTipo);
            }


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
        if(mascotas[i].idMascota == id && mascotas[i].isEmpty == 0)
        {
            mascotaIndex = i;
            break;
        }
    }
    return mascotaIndex;
}

int removeMascota(eMascota mascotas[], int tam, eTipo tipos[], int tams, eColor colores[], int tamc, eCliente clientes[], int tamcl) //0 baja exitosa 1 hubo un problema 2 se cancela la baja
{
    int error = -1;
    int mascotaIndex;
    int id;
    int confirm;

   if(mascotas != NULL && tam > 0 && tipos !=NULL && tams > 0)
    {
        printf("\033[2J");
        printf("***Baja de mascotas\n");
        printMascotas(mascotas, tam, tipos, tams, colores, tamc, clientes, tamcl );
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
            printMascota(mascotas[mascotaIndex], tipos, tams, colores, tamc, clientes, tamcl);
            printf("Confirma la baja de la mascota?\n -1 para confirmar\n -2 para cancelar la baja\n ");
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
    if(a != 1 && a!= 2 && a !=3 && a != 4 && a != 5 && a != 6 && a!=7 && a != 8 && a != 9 && a!=10  && a!=20)
    {
        rdo = 0;
    }else{rdo=1;}
    return rdo;
}
int validarOpcionSubmenu(int a)
{
    int rdo;
    if(a != 50 && a!= 51 && a !=52 && a != 53 && a != 54 && a != 55 && a != 56 && a != 57 && a != 58 && a != 59)
    {
        rdo = 0;
    }else{rdo=1;}
    return rdo;
}

int modificarMascota(eMascota mascotas[], int tam, eTipo tipos[], tams, eColor colores[], int tamc, eCliente clientes[], int tamcl)
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
        printMascotas(mascotas, tam, tipos, tams, colores, tamc, clientes, tamcl);
        printf("Ingrese id de la mascota que desea modificar: \n");
        scanf("%d", &id);
        mascotaIndex = buscarMascota(mascotas, tam, id);
        if(mascotaIndex == -1)
        {
            printf("No hay ninguna mascota con ese legajo\n");
        }
        else
        {
            printf("\033[2J");
            printMascota(mascotas[mascotaIndex], tipos, tams, colores, tamc, clientes, tamcl);
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
                           printf("Opcion invalida por favor ingrese:\n -1 para confirmar\n -2 para cancelar la modificacion\n ");
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
                           printf("Opcion invalida por favor ingrese:\n -1 para confirmar\n -2 para cancelar la modificacion\n ");
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
    if(a != 1000 && a!= 1001 && a !=1002 && a != 1003 && a != 1004 )
    {
        rdo = 0;
    }else{rdo=1;}
    return rdo;
}

int validarColor(int a)
{
    int rdo;
    if(a != 5000 && a!= 5001 && a !=5002 && a != 5003 && a != 5004 )
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

int ordenarMascotaPorNombre(eMascota mascotas[], int tam)
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

int validarCadena(char cadena[20])
{
    int error = 1;
    int contador = 0;
    for(int i=0; i<strlen(cadena); i++)
    {
        if((cadena[i]<'a' || cadena[i]>'z') && (cadena[i] < 'A' || cadena[i] > 'Z' ))
        {
        contador++;
        }

    }
    if(contador == 0 )
    {
        error = 0;
    }

    return error;
}


int cargarNombreMascota(eMascota mascotas[], int tam, int id, char nombre[])
{
    int error =1;

    if(mascotas != NULL && tam > 0 && id > 0 && nombre != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(mascotas[i].idMascota == id)
            {
                strcpy(nombre, mascotas[i].name);
                error = 0;
                break;
             }

        }
    }
    return error;

}

void elegirColor(eMascota mascotas[], int tam, eTipo tipos[], int tamt, eColor colores[], int tamc, eCliente clientes[], int tamcl)
{
    int idColor;
    char colorElegido[20];
    char nombre[20];

    if(mascotas !=NULL && tam>0)
    {

        printColores(colores, tamc);
        printf("Ingrese id de color elegido: ");
        scanf("%d", &idColor);
        printf("\033[2J");


        printf("                          ***Listado de Mascotas por color***\n");
        printf("               ---------------------------------------------------\n");
        printf("               Legajo         Nombre        Tipo    Color    Edad  Nombreduenio  \n");
        printf("               -----------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(mascotas[i].idColor == idColor)
            {
                printMascota(mascotas[i], tipos, tamt, colores, tamc, clientes, tamcl);

            }
        }

    }
}

void elegirTipo(eMascota mascotas[], int tam, eTipo tipos[], int tamt, eColor colores[], int tamc, eCliente clientes[], int tamcl)
{
    int idTipo;



    if(mascotas !=NULL && tam>0)
    {

        printTipos(tipos, tamt);
        printf("Ingrese id de tipo elegido: ");
        scanf("%d", &idTipo);
        printf("\033[2J");


        printf("                          ***Listado de Mascotas por tipo***\n");
        printf("               ---------------------------------------------------\n");
        printf("               Legajo         Nombre        Tipo    Color    Edad  Nombreduenio  \n");
        printf("               -----------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(mascotas[i].idTipo == idTipo)
            {
                printMascota(mascotas[i], tipos, tamt, colores, tamc, clientes, tamcl);

            }
        }

    }
}


void mascotasMenorEdad(eMascota mascotas[], int tam, eTipo tipos[], int tamt, eColor colores[], int tamc, eCliente clientes[], int tamcl)
{
    float edadMinima = 0;
    eMascota auxMascota;

    if(mascotas !=NULL && tam > 0 && tipos !=NULL && tamt>0 && colores !=NULL && tamc >0 && clientes!=NULL &&tamcl>0)
    {
        printf("                          ***Listado de Mascotas menores***\n");
        printf("               ---------------------------------------------------\n");
        printf("               Legajo         Nombre        Tipo    Color    Edad  Nombreduenio  \n");
        printf("               -----------------------------------------------------\n");
        for(int i = 0; i < tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(mascotas[i].edad > mascotas[j].edad)
                {

                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j]= auxMascota;
                }
            }
        }

        /*
        for(int k=0; k<tam; k++)
        {
            if(mascotas[k].edad == edadMinima)
            {
                printMascota(mascotas[k], tipos, tamt, colores, tamc, clientes, tamcl);
            }
        }*/
    }
}

int listarPorTipo(eMascota mascotas[], int tam, eTipo tipos[], int tamt, eColor colores[], int tamc, eCliente clientes[], int tamcl)
{
     eMascota auxMascota;
     int error =1;
    if(mascotas !=NULL && tam > 0 && tipos !=NULL && tamt>0 && colores !=NULL && tamc >0 && clientes!=NULL &&tamcl>0)
    {
        printf("                          ***Listado de Mascotas***\n");
        printf("               ---------------------------------------------------\n");
        printf("               Legajo         Nombre        Tipo    Color    Edad  Nombreduenio  \n");
        printf("               -----------------------------------------------------\n");
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

void ContarXcolorYtipo(eMascota mascotas[], int tam, eTipo tipos[], int tamt, eColor colores[], int tamc, eCliente clientes[], int tamcl)
{
    int idColor;
    int idTipo;
    int contador = 0;
    if(mascotas !=NULL && tam > 0 && tipos !=NULL && tamt>0 && colores !=NULL && tamc >0 && clientes!=NULL &&tamcl>0)
    {

        printColores(colores, tamc);
        printf("Ingrese id de color elegido: ");
        scanf("%d", &idColor);
        printf("\033[2J");
        printTipos(tipos, tamt);
        printf("Ingrese id de tipo elegido: ");
        scanf("%d", &idTipo);
        printf("\033[2J");

        printf("                    ***Listado de Mascotas por color y tipo***\n");
        printf("               ---------------------------------------------------\n");
        printf("               Legajo         Nombre        Tipo    Color    Edad  Nombreduenio  \n");
        printf("               -----------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(mascotas[i].idColor == idColor && mascotas[i].idTipo == idTipo)
            {
                printMascota(mascotas[i], tipos, tamt, colores, tamc, clientes, tamcl);
            }
        }


    }

}

void colorMasPresente(eMascota mascotas[], int tam, eTipo tipos[], int tamt, eColor colores[], int tamc, eCliente clientes[], int tamcl)
{

    int contadorRojo = 0;
    int contadorNegro = 0;
    int contadorGris = 0;
    int contadorBlanco = 0;
    int contadorAzul = 0;
    if(mascotas !=NULL && tam > 0 && tipos !=NULL && tamt>0 && colores !=NULL && tamc >0 && clientes!=NULL &&tamcl>0)
    {
        for(int i=0; i<tam; i++)
        {

            if(mascotas[i].idColor == 5000)
            {
                contadorNegro++;
            }
            else
            {
                if(mascotas[i].idColor == 5001)
                {
                    contadorBlanco++;
                }
                else
                {
                    if(mascotas[i].idColor == 5002)
                    {
                        contadorGris++;
                    }
                    else
                    {
                        if(mascotas[i].idColor == 5003)
                        {
                            contadorRojo++;
                        }
                        else
                        {
                            if(mascotas[i].idColor == 5004)
                            {
                                contadorAzul++;
                            }
                        }
                    }
                }
            }
        }
    }
    if(contadorBlanco > contadorNegro && contadorBlanco >contadorAzul && contadorBlanco>contadorGris && contadorBlanco>contadorRojo)
    {
        printf("Hay mas mascotas blancas y en total son: %d", contadorBlanco);
    }
    else
    {
        if(contadorNegro > contadorBlanco && contadorNegro >contadorAzul && contadorNegro>contadorGris && contadorNegro>contadorRojo)
        {
            printf("Hay mas mascotas negras y en total son: %d", contadorNegro);
        }
        else
        {
            if(contadorAzul > contadorBlanco && contadorAzul >contadorNegro && contadorAzul>contadorGris && contadorAzul>contadorRojo)
            {
                printf("Hay mas mascotas azules y en total son: %d", contadorAzul);
            }
            else
            {
                if(contadorGris > contadorBlanco && contadorGris >contadorNegro && contadorGris>contadorAzul && contadorAzul>contadorRojo)
                {
                    printf("Hay mas mascotas grises y en total son: %d", contadorGris);
                }
                else
                {
                    if(contadorRojo > contadorBlanco && contadorRojo >contadorNegro && contadorRojo>contadorAzul && contadorRojo>contadorGris)
                    {
                        printf("Hay mas mascotas rojas y en total son: %d", contadorRojo);
                    }
                }
            }

        }
    }

}

int mostrarImporteTotalTrabajosPorMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamt, eColor colores[], int tamc, eServicio servicios[], int tams, eTrabajo trabajos[], int tamtr, eCliente clientes[], int tamcl)
{
    int error =1;
    int idMascota;
    float total = 0;
    if(mascotas != NULL && tam > 0 )
    {
        printf("\033[2J");
        printf("Informe total de trabajos por mascota\n");
        printMascotas(mascotas, tam, tipos, tamt, colores, tamc, clientes, tamcl);
        printf("ingrese legajo de mascota: ");
        scanf("%d", &idMascota);
        for(int i=0; i<tamtr; i++)
        {
            if(trabajos[i].isEmpty == 0 && trabajos[i].idMascota == idMascota)
            {
                for(int j=0; j<tams;j++)
                {
                    if(servicios[j].idServicio == trabajos[j].idServicio)
                    {
                        total += servicios[j].precioServicio;
                    }
                }
            }
        }
        error = 0;
        printf("Total a pagar: %.2f", total);
    }
    return error;
}

int mostrarTrabajosPorMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamt, eColor colores[], int tamc, eServicio servicios[], int tams, eTrabajo trabajos[], int tamtr, eCliente clientes[], int tamcl)
{
    int error =1;
    int idMascota;
    float total = 0;
    if(mascotas != NULL && tam > 0 && tipos != NULL && tamt > 0 && colores != NULL && tamc > 0 && servicios != NULL && tams > 0)
    {
        printf("\033[2J");
        printf("Informe total de trabajos por mascota\n");
        printMascotas(mascotas, tam, tipos, tamt, colores, tamc, clientes, tamcl);
        printf("ingrese legajo de mascota: ");
        scanf("%d", &idMascota);
        printf("\033[2J");
        printf("          ***Listado de Trabajos por mascota***\n");
        printf("----------------------------------------------------------------------\n");
        printf("             iD trabajo      Nombre     Servicio      Fecha\n");
        printf("----------------------------------------------------------------------\n");
        for(int i=0; i<tamtr; i++)
        {
            if(trabajos[i].isEmpty == 0 && trabajos[i].idMascota == idMascota)
            {

                for(int j=0; j<tams;j++)
                {
                    if(servicios[j].idServicio == trabajos[j].idServicio)
                    {
                        printTrabajo(trabajos[i], tamt, mascotas, tam, servicios, tams );
                    }
                }
            }
        }
        error = 0;
        printf("Total a pagar: %.2f", total);
    }
    return error;
}

int mostrarMascotasPorServicio(eMascota mascotas[], int tam, eTipo tipos[], int tamt, eColor colores[], int tamc, eServicio servicios[], int tams, eTrabajo trabajos[], int tamtr, eCliente clientes[], int tamcl)
{
    int error =1;
    int idServicio;
    if(mascotas != NULL && tam > 0 && tipos != NULL && tamt > 0 && colores != NULL && tamc > 0 && servicios != NULL && tams > 0)
    {
        printf("\033[2J");
        printf("Informe total de trabajos por mascota\n");
        printServicios(servicios,  tams);
        printf("ingrese id de servicio elegido: ");
        scanf("%d", &idServicio);
         printf("\033[2J");
        printf("          ***Listado de Servicios por mascota***\n");
        printf("----------------------------------------------------------------------\n");
        printf("             iD trabajo      Nombre     Servicio      Fecha\n");
        printf("----------------------------------------------------------------------\n");
        for(int i=0;i<tamtr;i++)
        {
            if(trabajos[i].idServicio == idServicio)
            {
                 printTrabajo(trabajos[i], tamt, mascotas, tam, servicios, tams);
            }
        }
         error = 0;
    }
    return error;
}


