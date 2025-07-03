#include <stdio.h>
#include <string.h>
#include "prototipos_y_estructuras.h"

int main(void) {
    articulos_t articulos[CANT_ARTICULOS] = {0};

    printf("Bienvenido al final de Info 1\n\n");

    cargar_fichas_interactivamente(articulos);

    printf("\nArticulos cargados:\n");
    imprimir_articulos(articulos);

    ordenar_articulos(articulos);

    printf("\n\n###################################");
    printf("\n############## ORDENADO ###########");
    printf("\n###################################\n");
    imprimir_articulos(articulos);

    return 0;
}
