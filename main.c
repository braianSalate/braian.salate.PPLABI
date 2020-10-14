#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arrayMascotas.h"




#define TAM 1000
#define TAMT 5
#define TAMC 5
#define TAMS 3
#define TAMTR 10


char menu();


int main()
{
    int nextId = 1;

    eMascota listaMascotas[TAM];
    eTipo listaTipos[TAMT];
    eColor listaColores[TAMC];
    eServicio listaServicios[TAMS];
    eTrabaja listaTrabajos[TAMTR];
    char seguir = 's';
    char confirma;
    int flagAltaMascota = 0;
    int baja;
    int modificar;
    int opcionOrdenar;
    int opcionInformes;



    if(initMascotas(listMascotas, TAM))
    {
        printf("Inicializacion fallida");

    }
    else
    {
        printf("Se ha inicializado el alta\n");
        hardcodearTipo(listaTipos, TAMT, 5);
        hardcodearColor(listaColores, TAMC, 5);
        hardcodearServicios(listaServicios, TAMS, 3);
        flagAltaMascota = 1;
    }



    do
    {
        switch(menu())
        {

        case 1:
            if(addMascota(listaMascotas, TAM, listaTipos, TAMT, nextId) == 0)
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
                   baja = removeMascota(listaMascotas, TAM);
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
                    modificar = modificarMascota(listaMascotas, TAM);
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
                    printf("Desea ordenar por:\n 1-Nombre \n 2-Tipo");
                    scanf("%d", &opcionOrdenar);
                    if(opcionOrdenar)
                    {
                        ordenarMascotaPorNombre(listaMascotas, TAM);
                        printMascotas(listaMascotas, TAM, listaTipos, TAMT);
                    }
                    else
                    {
                        if(opcionOrdenar == 2)
                        {
                            ordenarMascotasPorTipo(listMascotas, TAM);
                            printEmployees(listaMascotas, TAM, listaTipos, TAMT);
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
                    printTipos(listaTipos, TAMt);
                }
                else
                {
                    printf("Aun no hay mascotas cargadas.");
                }

            break;
        case 6:
            if(flagAltaEmpleado)
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
            if(flagAltaEmpleado)
            {
                printf("\033[2J");
                printServicios(listaServicios, TAMS);

            }
             else
                {
                    printf("Aun no hay mascotas cargadas.");
                }

            break;


        case 10:
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
    printf("10 salir");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    while(validarOpcion(opcion) == 0 )
        {
            printf("Opcion elegida invalida, ingrese operacion a realizar: ");

            scanf("%d", &opcion);
        }

    return opcion;
}

