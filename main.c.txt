#include <stdio.h>
#include <string.h>
#include "prototipos_y_estructuras.h"

int main(void) {
    int opc = 0, sucursal;
    char articulo[90];
    articulos_t articulos[CANT_ARTICULOS] = {0};

    printf("Bienvenido al final de Info 1\n\n");

    do {
        printf("Ingrese la descripcion del articulo: ");
        scanf("%s", articulo);

        printf("Para que sucursal va a realizar la carga? (1,2,3): ");
        scanf("%d", &sucursal);

        cargar_articulo(articulos, articulo, sucursal);

        printf("Desea ingresar otro articulo? 1-Si, 2-No: ");
        scanf("%d", &opc);
    } while (opc == 1);

    printf("\nArticulos cargados:\n");
    imprimir_articulos(articulos);

    ordenar_articulos(articulos);

    printf("\n\n###################################");
    printf("\n############## ORDENADO ###########");
    printf("\n###################################\n");
    imprimir_articulos(articulos);

    return 0;
}
