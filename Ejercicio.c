#include<stdio.h>
#include<string.h>

int
main(){

    return 0;
}

double * leerArreglo(){
    int cant = -1;
    do {
        printf("Ingrese la cantidad de numeros: \n");
        scanf("%d", &cant);
        BORRAR_BUFF
    }while (size <= 0);

    double * vec = malloc(cant*sizeof(double));

    for (int i = 0; i < cant; i++)
    {
       printf("\nIngrese el valor %d: ", i);
       scanf("%f", vec[i]);
    }
    
    return vec;
}