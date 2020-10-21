#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arrayMascotas.h"
#include "tipo.h"
#include "trabajo.h"
#include "servicio.h"
#include "color.h"
#include "cliente.h"


#define TAM 50
#define TAMT 5
#define TAMC 5
#define TAMS 3
#define TAMTR 10
#define TAMCL 50

int mostrarTotalTrabajosPorMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamt, eColor colores[], int tamc, eServicio servicios[], int tams, eTrabajo trabajos[], int tamtr, eCliente clientes[], int tamcl);
int mostrarTrabajosPorMascota(eMascota mascotas[], int tam, eTipo tipos[], int tamt, eColor colores[], int tamc, eServicio servicios[], int tams, eTrabajo trabajos[], int tamtr, eCliente clientes[], int tamcl);
int mostrarMascotasPorServicio(eMascota mascotas[], int tam, eTipo tipos[], int tamt, eColor colores[], int tamc, eServicio servicios[], int tams, eTrabajo trabajos[], int tamtr, eCliente clientes[], int tamcl);

char menu();


int main()
{
    int nextId = 1;
    int nextIdTrabajo = 100;
    eCliente listaClientes[TAMCL];
    eMascota listaMascotas[TAM];
    eTipo listaTipos[TAMT];
    eColor listaColores[TAMC];
    eServicio listaServicios[TAMS]; /*=
    {
        {20000, "Corte", 250},
        {20001, "Desparasitado", 300},
        {20002, "Castrado", 400},
    }*/
    eTrabajo listaTrabajos[TAMTR];
    char seguir = 's';
    char confirma;
    int flagAltaMascota = 0;
    int flagAltaTrabajo = 0;
    int baja;
    int modificar;
    int opcionOrdenar;
    int opcionInformes;



    if(initMascotas(listaMascotas, TAM))
    {
        printf("Inicializacion fallida");

    }
    else
    {

        printf("Se ha inicializado el alta\n");
        hardcodearTipo(listaTipos, TAMT, 5);
        hardcodearColor(listaColores, TAMC, 5);
        hardcodearServicios(listaServicios, TAMS, 3);
        hardcodearCliente(listaClientes, TAMCL, 6);
        flagAltaMascota = 1;
    }
      if(initTrabajos(listaTrabajos, TAMTR))
    {
        printf("Inicializacion fallida");

    }
    else
    {

        printf("Se ha inicializado el alta\n");
    }

 if(initClientes(listaClientes, TAMCL))
    {
        printf("Inicializacion fallida");

    }
    else
    {

        printf("Se ha inicializado el alta\n");

    }
     int idMascota;
    char name[20];
    int idColor;
    int idTipo;
    int idCliente;
    float edad;
    int isEmpty;
    listaMascotas[0] = (eMascota){1, "pepe", 5001, 1001, 50, 3, 0};
    listaMascotas[1] = (eMascota){2, "zipo", 5000, 1000, 51, 4, 0};
    listaMascotas[2] = (eMascota){3, "luna", 5000, 1002, 50, 6, 0};
    listaMascotas[3] = (eMascota){4, "morena", 5003, 1003, 50, 1, 0};
    listaMascotas[4] = (eMascota){5, "oso", 5004, 1004, 52, 1, 0};
    listaMascotas[5] = (eMascota){6, "marito", 5002, 1001, 54, 4, 0};
    listaMascotas[6] = (eMascota){7, "gasper", 5001, 1000, 50, 3, 0};
    listaMascotas[7] = (eMascota){8, "emma", 5001, 1001, 50, 7, 0};
    listaMascotas[8] = (eMascota){9, "moreira", 5001, 1001, 50, 3, 0};
    nextId+=9;

    listaTrabajos[0] = (eTrabajo){100, 20000, 2, {2,3,2020}, 0};
    listaTrabajos[1] = (eTrabajo){101, 20002, 1, {20,3,2020}, 0};
    listaTrabajos[2] = (eTrabajo){102, 20001, 3, {4,11,2020}, 0};
    listaTrabajos[3] = (eTrabajo){103, 20000, 5, {25,7,2020}, 0};
    listaTrabajos[4] = (eTrabajo){104, 20001, 4, {19,4,2020}, 0};
    listaTrabajos[5] = (eTrabajo){105, 20000, 5, {25,7,2020}, 0};
    listaTrabajos[6] = (eTrabajo){106, 20001, 7, {19,4,2020}, 0};
    nextIdTrabajo += 7;
    flagAltaTrabajo = 1;


    do
    {
        switch(menu())
        {

        case 1:
            if(addMascota(listaMascotas, TAM, listaTipos, TAMT, listaColores, TAMC, nextId) == 0)
            {
                nextId++;
                printf("Mascota agregada exitosamente\n");
                flagAltaMascota = 1;
            }
            else
            {
                printf("no se pudo agregar la mascota\n");
            }

            break;
        case 2:
                if(flagAltaMascota)
                {
                   baja = removeMascota(listaMascotas, TAM, listaTipos, TAMT, listaColores, TAMC, listaClientes, TAMCL);
                   if(baja == -1)
                   {
                       printf("Problema al intentar la baja");
                   }
                   else
                   {
                       if(baja == 0)
                       {
                           printf("Se ha realizado la baja con exito!");
                       }
                       else
                       {
                           if(baja == 2)
                           {
                               printf("Has cancelado la baja!");
                           }
                       }
                   }
                }
                else
                {
                    printf("Aun no hay mascotas cargados.");
                }


            break;
        case 3:
               if(flagAltaMascota)
                {
                    modificar = modificarMascota(listaMascotas, TAM, listaTipos, TAMT, listaColores, TAMC, listaClientes, TAMCL);
                    if(modificar)
                    {
                        printf("Hubo un problema al intentar modificar");
                    }
                    else
                    {
                        if(modificar == 0)
                        {
                            printf("modificacion exitosa");
                        }
                        else
                        {
                            if(modificar == 2)
                            {
                                printf("modificacion cancelada");
                            }
                        }
                    }
                }
                else
                {
                    printf("Aun no hay mascotas");
                }
            break;
        case 4:
               if(flagAltaMascota)
                {
                    printf("\033[2J");
                    printf("Desea ordenar por:\n 1-Nombre \n 2-Tipo\n");
                    printf("Opcion elegida: ");
                    scanf("%d", &opcionOrdenar);
                    if(opcionOrdenar)
                    {
                        if(ordenarMascotaPorNombre(listaMascotas, TAM) == 0)
                        {
                            printMascotas(listaMascotas, TAM, listaTipos, TAMT, listaColores, TAMC, listaClientes, TAMCL);

                        }
                    }
                    else
                    {
                        if(opcionOrdenar == 2)
                        {
                            if(ordenarMascotaPorTipo(listaMascotas, TAM) == 0)
                            {
                                printMascotas(listaMascotas, TAM, listaTipos, TAMT, listaColores, TAMC,listaClientes, TAMCL);

                            }
                        }
                    }
                }
                else
                {
                    printf("Aun no hay masctas cargadas.");
                }

            break;

            break;
        case 5:
                if(flagAltaMascota)
                {
                    printf("\033[2J");
                    printTipos(listaTipos, TAMT);
                }
                else
                {
                    printf("Aun no hay mascotas cargadas.");
                }

            break;
        case 6:
            if(flagAltaMascota)
            {
                printf("\033[2J");
                printColores(listaColores, TAMC);

            }
             else
                {
                    printf("Aun no hay mascotas cargadas.");
                }

            break;
            case 7:
            if(flagAltaMascota)
            {
                printf("\033[2J");
                printServicios(listaServicios, TAMS);

            }
             else
                {
                    printf("Aun no hay mascotas cargadas.");
                }

            break;
            case 8:
                 if(altaTrabajo(listaTrabajos, TAMTR, listaServicios, TAMS, listaTipos, TAMT, nextIdTrabajo, listaMascotas, TAM, listaColores, TAMC, listaClientes, TAMCL) == 0)
                {
                    nextIdTrabajo++;
                    printf("trabajo agregado exitosamente\n");
                    flagAltaTrabajo = 1;
                }
                else
                {
                    printf("no se pudo agregar el trabajo \n");
                }
            break;
            case 9:
                if(flagAltaTrabajo == 1)
                {
                    printTrabajos(listaTrabajos, TAMTR, listaServicios, TAMS, listaMascotas, TAM);
                }
                else
                {
                    printf("No hay mascotas a la cual hacerle un trabajo...");
                }
            break;
            case 10:
                printf("\033[2J");

                printf("*****INFORMES*****\n");
                printf("Que quiere informar?\n");
                printf("50 Informar mascotas por color\n");
                printf("51 Informar mascotas por tipo\n");
                printf("52 Informar mascotas de menor edad\n");
                printf("53 Informar mascotas por tipo\n");
                printf("54 Informar cantidad de mascotas por color y tipo\n");
                printf("55 Informar color predominante\n");
                printf("56 Informar trabajos por mascota\n");
                printf("57 Informar importe total por trabajo por mascota\n");
                printf("Ingrese que desea informar: ");
                scanf("%d", &opcionInformes);
                while(validarOpcionSubmenu(opcionInformes) == 0 )
                {
                    printf("Opcion elegida invalida, ingrese operacion a realizar: ");

                    scanf("%d", &opcionInformes);
                }
                switch(opcionInformes)
                {
                    case 50:
                         printf("\033[2J");
                         elegirColor(listaMascotas, TAM, listaTipos, TAMT, listaColores,  TAMC, listaClientes, TAMCL);
                    break;
                    case 51:
                        printf("\033[2J");
                        elegirTipo(listaMascotas, TAM, listaTipos, TAMT, listaColores,  TAMC, listaClientes, TAMCL);
                    break;
                    case 52:
                         printf("\033[2J");
                         mascotasMenorEdad(listaMascotas, TAM,listaTipos, TAMT,listaColores, TAMC, listaClientes, TAMCL);
                    break;
                    case 53:
                         printf("\033[2J");
                          if(listarPorTipo(listaMascotas, TAM,listaTipos, TAMT,listaColores, TAMC, listaClientes, TAMCL) == 0)
                        {
                            printMascotas(listaMascotas, TAM, listaTipos, TAMT, listaColores, TAMC, listaClientes, TAMCL);

                        }
                    case 54:
                         printf("\033[2J");
                         ContarXcolorYtipo(listaMascotas, TAM,listaTipos, TAMT,listaColores, TAMC, listaClientes, TAMCL);
                    break;

                    break;
                    case 55:
                        printf("\033[2J");
                        colorMasPresente(listaMascotas, TAM,listaTipos, TAMT,listaColores, TAMC, listaClientes, TAMCL);
                    break;
                    case 56:
                        mostrarTrabajosPorMascota(listaMascotas,TAM, listaTipos,  TAMT, listaColores,  TAMC, listaServicios,  TAMS, listaTrabajos,  TAMTR, listaClientes,  TAMCL);
                    break;
                    case 57:
                        printf("\033[2J");
                        mostrarImporteTotalTrabajosPorMascota(listaMascotas,TAM, listaTipos,  TAMT, listaColores,  TAMC, listaServicios,  TAMS, listaTrabajos,  TAMTR, listaClientes,  TAMCL);
                    break;
                    case 58:
                        mostrarMascotasPorServicio(listaMascotas,TAM, listaTipos,  TAMT, listaColores,  TAMC, listaServicios,  TAMS, listaTrabajos,  TAMTR, listaClientes,  TAMCL);
                    break;
                    default:
                        printf("opcion invalida...");

                }




            break;


        case 20:
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }

            break;
        }

        getchar();
        getchar();

    }
    while( seguir == 's');


    return 0;
}


char menu()
{
    int opcion;
    printf("\033[2J");

    printf("*** ABM Personas ***\n\n");
    printf("1 Alta\n");
    printf("2 Baja\n");
    printf("3 Modificion\n");
    printf("4 Listar mascotas ordenadas\n");
    printf("5 Listas tipos\n");
    printf("6 Listar colores\n");
    printf("7 Listar servicios\n");
    printf("8 Alta trabajo\n");
    printf("9 Listar trabajo\n");
    printf("10 Informes\n");
    printf("20 Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    while(validarOpcion(opcion) == 0 )
        {
            printf("Opcion elegida invalida, ingrese operacion a realizar: ");

            scanf("%d", &opcion);
        }

    return opcion;
}


