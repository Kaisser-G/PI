#include <stdlib.h>
#include <stdio.h>

//Input buffer: Archivo .cvs :    separador de casillas: ";", separador de filas: "???"
#define length 500
#define MAX_SIZE 300
#define COL_SEP ';'


int main(){
	char buff[length];

	for (int i = 0; (i < length) && buff[i]!= EOF; ++i)
	 {
	 	buff[i] = getchar();
	 } 

	 printf("%s", buff);
	return 0;
}