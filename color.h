#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int idColor;
    char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED
void printColor(eColor color);
int printColores(eColor colores[], int tamc);
int hardcodearColor(eColor colores[], int tam, int cant);
