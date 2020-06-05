#include <stdlib.h>
#include <stdio.h>

#ifndef Taller10_3_h
#define Taller10_3_h

typedef struct matrixCDT * matrixADT;
 
typedef int elementType;

/* Crea una nueva matriz de elementos enteros 
** Inicialmente la matriz está vacía
** Si no se pudo crear retorna NULL.
 */
matrixADT newMatrix();
 
/* Libera todos los recursos reservados por el TAD */
void freeMatrix(matrixADT m);
 
/* Agrega un elemento a la matriz. Si no lo pudo agregar o los parámetros 
** son incorrectos retorna cero, caso contrario 1
** Si la posición estaba ocupada pisa el elemento que había
** De ser necesario agranda la matriz
** m: matriz
** row: fila (mayor o igual a cero)
** col: columna ( mayor o igual a cero)
** elem: valor a insertar.
 */
int setElement(matrixADT m, size_t row, size_t col, elementType elem);
 
/* Si existe un elemento en la posición [row][col], lo deja en out y retorna 1. 
** Si no había un elemento en esa posición retorna 0.
 */
int getElement(const matrixADT m, size_t row, size_t col, elementType * out);
 
/* Cantidad de filas que tiene la matriz */
size_t rows(matrixADT m);

#endif