#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct producto
{
    int ID;               // Numerado en ciclo iterativo
    int cantidad;         // Entre 1 y 10
    char *tipo;           // Algún valor del arreglo tiposProductos
    float precioUnitario; // Entre 10 y 100
} typedef producto;

struct cliente
{
    int ID;                // Numerado en el ciclo iterativo
    char *nombre;          // Ingresado por usuario
    int cantidadProductos; // Aleatorio entre 1 y 10
    producto *productos;   // El tamaño de este arreglo depende de la variable “cantidadProductos”
} typedef cliente;

void ingresarClientes(cliente *pClientes, int cantidad);
void cargarProductos(cliente *pClientes, int numeroCliente);
void mostrarClientes(cliente *pClientes, int cantidad);
float subtotalProducto(producto productos);
void liberarMemoria(cliente *pClientes, int cantidad);

void main()
{
    int cantidadClientes;
    cliente *pClientes;
    srand(time(NULL));
    printf("============================================================");
    printf("\n=========================BIENVENIDO=========================");
    printf("\n============================================================");
    printf("\n\nIngrese la cantidad de clientes: ");
    scanf("%i", &cantidadClientes);
    getchar();
    pClientes = (cliente *)malloc(sizeof(cliente)*cantidadClientes);
    ingresarClientes(pClientes, cantidadClientes);
    mostrarClientes(pClientes, cantidadClientes);
    liberarMemoria(pClientes, cantidadClientes);
    printf("\n============================FIN=============================");
}

void ingresarClientes(cliente *pClientes, int cantidad)
{
    char *tiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
    int indice;
    printf("------------------------------------------------------------");
    printf("\nCargando clientes:\n");
    for (int i = 0; i < cantidad; i++)
    {
        char *buffer = (char *)malloc(100*sizeof(char));
        printf("\n-Cliente [%i]:",i+1);
        printf("\n\tIngrese el ID:\t\t");
        scanf("%i",&pClientes[i].ID);
        getchar();
        printf("\tIngrese el nombre:\t");
        gets(buffer);
        pClientes[i].nombre = (char *)malloc((strlen(buffer)+1)*sizeof(char));
        strcpy(pClientes[i].nombre, buffer);
        free(buffer);
        pClientes[i].cantidadProductos = rand()%10+1;
        pClientes[i].productos = (producto *)malloc(sizeof(producto)*pClientes[i].cantidadProductos);
        for (int j = 0; j < pClientes[i].cantidadProductos; j++)
        {
            pClientes[i].productos[j].ID = j+1;
            pClientes[i].productos[j].cantidad = rand()%10+1;
            indice = rand()%5;
            pClientes[i].productos[j].tipo = (char *)malloc((strlen(tiposProductos[indice])+1)*sizeof(char));
            strcpy(pClientes[i].productos[j].tipo,tiposProductos[indice]);
            pClientes[i].productos[j].precioUnitario = rand()%91+10;
        }
        printf("------------------------------------------------------------");
    }
}

void mostrarClientes(cliente *pClientes, int cantidad)
{
    printf("\nMostrando clientes:\n");
    for (int i = 0; i < cantidad; i++)
    {
        float totalCliente=0;
        printf("\nCliente [%i]:", i+1);
        printf("\n\tID:\t\t\t%i", pClientes[i].ID);
        printf("\n\tNombre:\t\t\t%s", pClientes[i].nombre);
        printf("\n\tCantidad de productos:\t%i", pClientes[i].cantidadProductos);
        printf("\n\tListado de productos:");
        for (int j = 0; j < pClientes[i].cantidadProductos; j++)
        {
            printf("\n\t\tProducto [%i]:", j+1);
            printf("\n\t\t\tID:\t\t\t%i", pClientes[i].productos[j].ID);
            printf("\n\t\t\tCantidad:\t\t%i", pClientes[i].productos[j].cantidad);
            printf("\n\t\t\tTipo:\t\t\t%s", pClientes[i].productos[j].tipo);
            printf("\n\t\t\tPrecio unitario:\t%.2f", pClientes[i].productos[j].precioUnitario);
            printf("\n\t\t\tSubtotal producto:\t%.2f", subtotalProducto(pClientes[i].productos[j]));
            totalCliente += subtotalProducto(pClientes[i].productos[j]);
        }
        printf("\n\tTotal cliente:\t\t\t\t%.2f", totalCliente);
        printf("\n------------------------------------------------------------");
    }
}

float subtotalProducto(producto productos)
{
    return(productos.cantidad * productos.precioUnitario);
}

void liberarMemoria(cliente *pClientes, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        free(pClientes[i].nombre);
        free(pClientes[i].productos);
        for (int j = 0; j < pClientes[i].cantidadProductos; j++)
        {
            free(pClientes[i].productos[j].tipo);
        }
    }
    free(pClientes);
}