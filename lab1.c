#include <stdlib.h>
#include <stdio.h>

#define SIZE 10


int
main(){
	char * supervector = superv();
	printf("%s\n", supervector);
	return 0;
}

char *
superv(){
	char c;
	char * aux = NULL;
	int size = SIZE;
	size_t i;
	for (i = 0; (c=getchar()) != EOF; ++i)
	{
		if(i%SIZE == 0){
			realloc(aux, size += SIZE);
			aux[i] = c;
		}
	}
	realloc(aux, i+1);
	aux[i] = 0;

	return aux;
}