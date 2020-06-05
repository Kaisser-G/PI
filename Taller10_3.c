#include "Taller10_3.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct matrixCDT
{
    elementType **value;
    char **hasValue;     //1 si esta ocupado el espacio, 0 si no
    size_t rDim;        //cantidad de filas
    size_t *cDim;       //cantidad de columnas en cada fila
}matrixCDT;

matrixADT newMatrix(){
    matrixADT new = calloc(1, sizeof(matrixCDT));
}

void freeMatrix(matrixADT m){
    for(size_t i = 0; i < m->rDim; i++){
        free(m->value[i]);
        free(m->hasValue[i]);
    }
    free(m->cDim);
    free(m);
}

int setElement(matrixADT m, size_t row, size_t col, elementType elem){
    if(row >= m->rDim){
        elementType **auxValue = m->value;
        auxValue = realloc(m->value, sizeof(elementType *) * (row + 1));
        if(auxValue == NULL) return 0;
        char **auxHasValue = m->hasValue;
        auxHasValue = realloc(m->hasValue, sizeof(char *) * (row + 1));
        if(auxHasValue == NULL) return 0;
        for (size_t r = m->rDim; r <= row; r++){
            m->cDim[r] = 0;
        }
        m->rDim = row+1;
    }
    if(col >= m->cDim[row]){
        elementType * auxValue = m->value[row];
        auxValue = realloc(m->value[row], sizeof(elementType) * (col+1));
        if(auxValue == NULL) return 0;
        char * auxHasValue = m->hasValue[row];
        auxHasValue = realloc(m->hasValue[row], sizeof(char) * (col+1));
        if(auxHasValue == NULL) return 0;
        for (size_t c = m->cDim[row]; c <= col; c++){
            m->hasValue[row][col] = 0;
        }
        m->cDim[row] = col+1;
    }
    m->value[row][col] = elem;
    m->hasValue[row][col] = 1;
    return 1;
}

int getElement(const matrixADT m, size_t row, size_t col, elementType * out){
    if(row >= m->rDim || col >= m->cDim[row] || m->hasValue[row][col] == 0)
        return 0;
    *out = m->value[row][col];
    return 1;
}

size_t rows(matrixADT m){
    return m->rDim;
}