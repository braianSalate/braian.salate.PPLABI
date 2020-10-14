#include "tipo.h"
#include "color.h"
#include "servicio.h"
#ifndef ARRAYMASCOTAS_H_INCLUDED
#define ARRAYMASCOTAS_H_INCLUDED

typedef struct{
    int id;
    char name[20];
    int idTipo;
    int idColor;
    float edad;
    int isEmpty;  // 1 vacia 0 cargada
} eMascota;

#endif // ARRAYMASCOTAS_H_INCLUDED

int initMascotas(eMascota mascotas[],int tam );
