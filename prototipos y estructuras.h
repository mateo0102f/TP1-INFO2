#ifndef PROTOTIPOS_Y_ESTRUCTURAS_H
#define PROTOTIPOS_Y_ESTRUCTURAS_H

#define CANT_ARTICULOS 60

#define SUCURSAL_1 0
#define SUCURSAL_2 1
#define SUCURSAL_3 2

typedef struct {
    char descripcion[90];
    int cantidad_sucursal[3];    
    int total;
} articulos_t;

void cargar_articulo(articulos_t articulos[], char articulo[], int sucursal);
void imprimir_articulos(const articulos_t articulos[]);
void ordenar_articulos(articulos_t articulos[]);

#endif
