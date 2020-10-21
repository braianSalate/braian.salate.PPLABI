#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int idTipo;
    char descripcionTipo[20];
}eTipo;

#endif // TIPO_H_INCLUDED
void printTipo(eTipo tipo);

int printTipos(eTipo tipos[], int tams);
int hardcodearTipo(eTipo tipos[], int tam, int cant);
int cargarDescripcionTipo(eTipo tipos[], int tamt, int id, char descripcion[]);
