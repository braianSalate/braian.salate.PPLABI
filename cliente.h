#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int idCliente;
    int idMascota;
    char nombreCliente[20];
    char sexo;
    int isEmpty;
}eCliente;

#endif // CLIENTE_H_INCLUDED
int hardcodearCliente(eCliente clientes[], int tamcl, int cant);
int initClientes(eCliente clientes[],int tamcl );
int cargarNombreCliente(eCliente clientes[], int tamcl, int id, char nombre[]);
