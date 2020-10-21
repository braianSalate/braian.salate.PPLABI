#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
#include "arrayMascotas.h"
#include "servicio.h"
#include "tipo.h"
#include "cliente.h"

typedef struct{
    int idTrabajo;
    int idServicio;
    int idMascota;
    eFecha fechaServ;
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED
int initTrabajos(eTrabajo trabajos[],int tam);
int searchFreePlaceTrabajo(eTrabajo trabajos[], int tamt);
void printTrabajo(eTrabajo trabajo, int tamtr, eMascota mascotas[], int tam, eServicio servicios[], int tams);
int printTrabajos(eTrabajo trabajos[], int tam, eServicio servicios[], int tams, eMascota mascotas[], int tamm);
int altaTrabajo(eTrabajo trabajos[], int tamt, eServicio servicios[], int tams, eTipo tipos[], int tamti, int id, eMascota mascotas[], int tam, eColor colores[], int tamc, eCliente clientes[], int tamcl);int validarIdMascota(int a, eMascota mascotas[], int tam);

