#include <stdio.h>
#include <string.h>
#include "prototipos_y_estructuras.h"

void cargar_articulo(articulos_t articulos[], char articulo[], int sucursal) {
    int i = 0;
    while (articulos[i].descripcion[0] && strcmp(articulo, articulos[i].descripcion)) i++;

    strcpy(articulos[i].descripcion, articulo);
    printf("Ingrese la cantidad del articulo para la sucursal %d: ", sucursal);
    scanf("%d", &articulos[i].cantidad_sucursal[sucursal - 1]);

    articulos[i].total = 0;
    for (int j = 0; j < 3; j++)
        articulos[i].total += articulos[i].cantidad_sucursal[j];
}

void imprimir_articulos(const articulos_t articulos[]) {
    int i = 0;
    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while (i < CANT_ARTICULOS && articulos[i].descripcion[0]) {
        printf("%s\t%d\t%d\t%d\t%d\n",
               articulos[i].descripcion,
               articulos[i].cantidad_sucursal[SUCURSAL_1],
               articulos[i].cantidad_sucursal[SUCURSAL_2],
               articulos[i].cantidad_sucursal[SUCURSAL_3],
               articulos[i].total);
        i++;
    }
}

void ordenar_articulos(articulos_t articulos[]) {
    articulos_t temp;
    for (int pass = 1; pass < CANT_ARTICULOS; pass++) {
        for (int i = 0; i < CANT_ARTICULOS - 1; i++) {
            if (articulos[i].total < articulos[i + 1].total) {
                temp = articulos[i];
                articulos[i] = articulos[i + 1];
                articulos[i + 1] = temp;
            }
        }
    }
}

void cargar_fichas_interactivamente(articulos_t articulos[]) {
    int opc = 0, sucursal;
    char articulo[90];

    do {
        printf("Ingrese la descripcion del articulo: ");
        scanf("%s", articulo);

        printf("Para que sucursal va a realizar la carga? (1,2,3): ");
        scanf("%d", &sucursal);

        cargar_articulo(articulos, articulo, sucursal);

        printf("Desea ingresar otro articulo? 1-Si, 2-No: ");
        scanf("%d", &opc);
    } while (opc == 1);
}
