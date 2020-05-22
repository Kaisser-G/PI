#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ES_BASE(x) (2 <= x && x <= 10)
#define LIMP_BUFFER while(getchar()!='\n');
#define readto(string) scanf("%s", string)

void pedirBases(int *, int *);
void pedirNumero();

int setBases(char *, int *, int *);
long convertir(int, int, int);
int esValido(int num, int base);

int
main(){
	int baseFrom, baseTo;
	//pedirBases(&baseFrom, &baseTo);
  //printf("La base de entrada es: %d \nY la de salida: %d\n",baseFrom, baseTo);

  printf("Test de convertir:\n");
  int num = 25789, b1=10, b2=2;
  if(!esValido(num,b1))
  	printf("Ingrese un numero valido");
  else
  	printf("El numero %d en base %d es: %ld en base %d", num, b1, convertir(num, b1, b2), b2);

	return 0;
}

void pedirBases(int * baseFrom, int * baseTo){
	char input[30];
	do
	 {
	 	printf("Introduzca las bases:\n");
    int i;
    for(i = 0;(input[i]=getchar()) != '\n'; i++);
    input[i] = 0;
	 } while (!setBases(input, baseFrom, baseTo)); 
  //setBases(input, baseFrom, baseTo);
}

/*
void pedirNumero(){
	char c;
  int n = 0;
  printf("Ingrese el numero a convertir o \'e\' para salir:");
  if((c = getchar()) != 'e'){
    putc(c, stdin);
    do{
      scanf("%d", &n);
      LIMP_BUFFER
    }while(n==0);
    n = convertir(n, baseFrom, baseTo);
    printf("\nEl numero en base %d es: %d", baseTo, n);
  }
}
*/



int setBases(char * input, int * baseFrom, int * baseTo){
	sscanf(input,"<%d>%d", baseFrom, baseTo);
	return ES_BASE(*baseFrom) && ES_BASE(*baseTo);
}

long convertir(int num, int baseFrom, int baseTo){
	long result = 0;
	//convertir a base 10
	if(baseFrom != 10){
		for (int i = 0; num >= 1 ; ++i)
		{
			result += (num%10) * pow(baseFrom,i);
			num /= 10;
		}	
    num = result;
	}
	//convertir a base destino
	if(baseTo!=10){
		result = 0;
		for (int i = 0; num >= 1 ; ++i)
		{
			result += (num%baseTo) * pow(10,i);
			num /= baseTo;
		}	
	}

	return result;
}

int esValido(int num, int base){
	while(num>=1){
		if( (num%10) >= base )
			return 0;
		num/=10;
	}
	return 1;
}