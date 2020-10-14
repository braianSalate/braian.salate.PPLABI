#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

void mostrarFecha(eFecha fecha)
{
    printf("Fecha: %2d/%2d/%d\n", fecha.dia, fecha.mes, fecha.anio);
}
