#include "Taller10_3.h"
#include <stdlib.h>
#include <stdio.h>

int
main(void) {

 matrixADT m = newMatrix();

 int aux;

 setElement(m, 1, 2, 9);

 getElement(m, 1, 2, &aux);

 printf("m[1][2] = %d\n", aux); // m[1][2] = 9

 setElement(m, 1, 3, 11);

 getElement(m, 1, 3, &aux); 

 printf("m[1][3] = %d\n", aux); // m[1][3] = 11

 setElement(m, 1, 3, 12);

 getElement(m, 1, 3, &aux);

 printf("m[1][3] = %d\n", aux); // m[1][3] = 12

 setElement(m, 3, 3, 10); 

 getElement(m, 3, 3, &aux); 

 printf("m[3][3] = %d\n", aux); // m[3][3] = 10

 setElement(m, 3, 4, 23);

 getElement(m, 3, 4, &aux); 

 printf("m[3][4] = %d\n", aux); // m[3][4] = 23

 printf("m[2][7] = %d\n", getElement(m, 2, 7, &aux)); // m[2][7] vacío

 printf("%ld\n", rows(m)); // 3 filas: [1, 2, 3]

 freeMatrix(m);

return 0;
}

