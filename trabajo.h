#include "servicio.h"
#include "fecha.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int idTrabajo;
    int idServicio;
    int idMascota;
    eFecha fechaServ;
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED
int initTrabajos(etrabajo trabajos[],int tam );
int addTrabajo(eTrabajo trabajos[], int tamt, eServicio servicios[], int tams,eMascota mascotas[], int tam int id);
int searchFreePlace(eTrabajo trabajos[],int tam);
void printTrabajo(eTrabajo trabajo, eMascota mascotas[], int tam);
int printMascotas(eMascota mascotas[], int tam, eTipo tipos[], int tams);
