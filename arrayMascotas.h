#ifndef ARRAYMASCOTAS_H_INCLUDED
#define ARRAYMASCOTAS_H_INCLUDED
#include "tipo.h"
#include "color.h"
#include "cliente.h"



typedef struct{
    int idMascota;
    char name[20];
    int idColor;
    int idTipo;
    int idCliente;
    float edad;
    int isEmpty;  // 1 vacia 0 cargada
} eMascota;

#endif // ARRAYMASCOTAS_H_INCLUDED

int initMascotas(eMascota mascotas[],int tam );
void printMascota(eMascota mascota, eTipo tipos[], int tamt, eColor colores[], int tamc, eCliente clientes[], int tamcl);
int printMascotas(eMascota mascotas[], int tam, eTipo tipos[], int tams, eColor colores[], int tamc,eCliente clientes[], int tamcl);
int addMascota(eMascota mascotas[], int tam, eTipo tipos[], int tams, eColor colores[],int tamc, int id);
int searchFreePlace(eMascota mascotas[],int tam);
int buscarMascota(eMascota mascotas[], int tam, int id);
int removeMascota(eMascota mascotas[], int tam, eTipo tipos[], int tams, eColor colores[], int tamc, eCliente clientes[], int tamcl);
int validarOpcion(int a);
int modificarMascota(eMascota mascotas[], int tam, eTipo tipos[], tams, eColor colores[], int tamc, eCliente clientes[], int tamcl);
int validarTipo(int a);
int validarColor(int a);
int ordenarMascotasPorNombre(eMascota mascotas[], int tam);
int ordenarMascotaPorTipo(eMascota mascotas[], int tam);
int validarCadena(char cadena[20]);
int cargarNombreMascota(eMascota mascotas[], int tam, int id, char nombre[]);
void elegirColor(eMascota mascotas[], int tam, eTipo tipos[], int tamt, eColor colores[], int tamc, eCliente clientes[], int tamcl);
void elegirTipo(eMascota mascotas[], int tam, eTipo tipos[], int tamt, eColor colores[], int tamc, eCliente clientes[], int tamcl);
int validarOpcionSubmenu(int a);
void colorMasPresente(eMascota mascotas[], int tam, eTipo tipos[], int tamt, eColor colores[], int tamc, eCliente clientes[], int tamcl);
void ContarXcolorYtipo(eMascota mascotas[], int tam, eTipo tipos[], int tamt, eColor colores[], int tamc, eCliente clientes[], int tamcl);










