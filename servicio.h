#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int idServicio;
    char descripcionServicio[25];
    float precioServicio;
}eServicio;

#endif // SERVICIO_H_INCLUDED
void printServicio(eServicio servicio);
int printServicios(eServicio servicios[], int tamt);
int hardcodearServicios(eServicio servicios[], int tam, int cant);
