#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PALABRA 15
#define FILS 4
#define COLS 4
#define BLOQUE 5
#define EndCoord -1
#define EndSolString ""
#define EnRangoFils(x) (0<=x&&x<=FILS)
#define EnRangoCols(x) (0<=x&&x<=COLS)

#define debug printf("debug\n");

typedef enum {DER = 0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB}Tdireccion;

typedef struct posicion
{
    char * palabra;
    size_t fila;
    size_t columna;
    Tdireccion direccion;
}respuesta;

typedef struct coorde
{
    int fil;
    int col;
} coordenada;

typedef respuesta * solucion;

coordenada * buscarLetras(char sopa[FILS][COLS], char primerasLetras[], int * size);

char * segundasLetras(char sopa[FILS][COLS], coordenada coord, char diccionario[][MAX_PALABRA]);

char validarDir(char sopa[FILS][COLS], coordenada coord, int deltaFil, int deltaCol);

void dirToDelta(Tdireccion dir, int * deltaFil, int * deltaCol);

char obtenerDir(char Sopa[FILS][COLS], coordenada coord, char * segundasLetras, int deltaFil, int deltaCol);

Tdireccion * buscarDir(char sopa[FILS][COLS], coordenada coord, char * segundasLetras, int * size);

char buscarPalabra(char sopa[FILS][COLS], coordenada coord, int deltaFil, int deltaCol, char diccionario[][MAX_PALABRA], char palabra[]);

int main(){
    /*
    Tdireccion d = IZQ;
    char diccionario[][MAX_PALABRA] = {"VACA","ASAR","ASEDIAR","BUSCAR","HERIR","AMAR","SANAR", ""};
    char sopa[FILS][COLS] = {
        "ASPD",
        "MSRT",
        "AOLA",
        "RDEE"
    };
    
    char * letras = "AZ";
    coordenada * coordenadas = buscarLetras(sopa, letras);
    for(int i = 0; coordenadas[i].fil != -2; i++)
        printf("%d %d;", coordenadas[i].fil, coordenadas[i].col);

    char * seg = segundasLetras(sopa, coordenadas[0], diccionario);
    printf("\n%s\n", seg);

    int size;
    Tdireccion * dirs = buscarDir(sopa, coordenadas[0], seg, &size);
    for (size_t i = 0; i < size; i++)
    {
        putchar('\n');
        printf("%d\n", dirs[i]);
    }
    int deltaFil, deltaCol;
    dirToDelta(dirs[1], &deltaFil, &deltaCol);
    printf("\n deltaFil: %d , deltaCol: %d\n", deltaFil, deltaCol);
    printf("\nEs solucion: %d", buscarPalabra(sopa, coordenadas[0], deltaFil, deltaCol, diccionario));
*/
    
    char diccionario[][MAX_PALABRA] = {"VACA","ASAR","ASEDIAR","BUSCAR","HERIR","AMAR","SANAR", ""};
    char sopa[FILS][COLS] = {
        "ASAR",
        "MSRT",
        "AOLA",
        "RDEE"
    };

    solucion sol = NULL;
    int s = 0; //posicion del vector sol
    char * pal = malloc(MAX_PALABRA+1);

    char *primerasLetras = NULL;
    int tam = 0;

    for (size_t i = 0; diccionario[i][0] != 0; i++)
    {
        if(tam%BLOQUE == 0)
            primerasLetras = realloc(primerasLetras, tam + BLOQUE);
        primerasLetras[tam++] = diccionario[i][0];
    }
    primerasLetras[tam] = 0;
    primerasLetras = realloc(primerasLetras, tam + 1);

    int posTam;
    coordenada * posiciones = buscarLetras(sopa, primerasLetras, &posTam);
    char * segundasLtr = NULL;
    Tdireccion * dirsABuscar = NULL;
    int deltaFil, deltaCol;

    for (size_t p = 0; p < posTam; p++)
    {
        segundasLtr = segundasLetras(sopa, posiciones[p], diccionario);
        dirsABuscar = buscarDir(sopa, posiciones[p], segundasLtr,&tam); //reutilizo tam
        for (size_t d = 0; d < tam; d++)
        {
            dirToDelta(dirsABuscar[d], &deltaFil, &deltaCol);
            if(buscarPalabra(sopa, posiciones[p], deltaFil, deltaCol, diccionario, pal)){ //si hay una palabra la agrego
                if(s%BLOQUE == 0)
                    sol = realloc(sol, (s+BLOQUE) * sizeof(solucion));
                sol[s].fila = posiciones[p].fil;
                sol[s].columna = posiciones[p].col;
                sol[s].direccion = dirsABuscar[d];
                sol[s].palabra = malloc(MAX_PALABRA+1);
                strcpy(sol[s].palabra, pal);
                sol[s].palabra = realloc(sol[s].palabra, strlen(sol[s].palabra));
                printf("-%s\n", sol[s].palabra);

                s++;
            }
        }
        
    }
    sol = realloc(sol, (s+1)*sizeof(respuesta));
    sol[s].palabra = malloc(1);
    strcpy(sol[s].palabra, "");


    printf("\n\nSoluciones:\n");
    for (int i = 0; sol[i].palabra[0] != 0; i++)
    {
        printf("-%s\n", sol[i].palabra);
    }
    
   
    return 0;
}


coordenada * buscarLetras(char sopa[FILS][COLS], char primerasLetras[], int * size){
    coordenada * resp = NULL;
    char flag;
    int tam = 0;
    debug
    for (size_t f = 0; f < FILS; f++)
    {
        for ( size_t c = 0; c < COLS; c++)
        {
            flag = 0;
            for (size_t v = 0; primerasLetras[v] != 0 && flag == 0; v++)
            {
                if(primerasLetras[v] == sopa[f][c]){
                    if(tam%BLOQUE == 0){
                        resp = realloc(resp, (tam + BLOQUE) * sizeof(coordenada));
                    }
                    resp[tam].fil = f;
                    resp[tam].col = c;
                    tam++;
                    flag = 1;
                }
            }
               
        }
    }
    resp = realloc(resp, tam * sizeof(coordenada));
    *size = tam;
    return resp;
} 

char * segundasLetras(char sopa[FILS][COLS], coordenada coord, char diccionario[][MAX_PALABRA]){
    char * resp = NULL;
    int f = coord.fil;
    int c = coord.col;
    int tam = 0;
    for (size_t i = 0; diccionario[i][0] != 0; i++)
    {
        if(sopa[f][c] == diccionario[i][0]){
            if(tam%BLOQUE == 0){
                resp = realloc(resp, tam+BLOQUE);
            }
            resp[tam++] = diccionario[i][1];
        }
    }
    resp[tam] = 0;
    resp = realloc(resp, tam+1);
    return resp;
}

char validarDir(char sopa[FILS][COLS], coordenada coord, int deltaFil, int deltaCol){
    int f = coord.fil + deltaFil;
    int c = coord.col + deltaCol;
    return (EnRangoFils(f) && EnRangoCols(c));
}

void dirToDelta(Tdireccion dir, int * deltaFil, int * deltaCol){
    switch (dir)
    {
    case DER:
        *deltaFil = 0;
        *deltaCol = 1;       
        break;
    case IZQ:
        *deltaFil = 0;
        *deltaCol = -1; 
        break;
    case ABA:
        *deltaFil = 1;
        *deltaCol = 0;         
        break;
    case ARR:
        *deltaFil = -1;
        *deltaCol = 0;        
        break;
    case I_AR:
        *deltaFil = -1;
        *deltaCol = -1;         
        break;
    case I_AB:
        *deltaFil = 1;
        *deltaCol = -1;         
        break;
    case D_AR:
        *deltaFil = -1;
        *deltaCol = 1;        
        break;
    case D_AB:
        *deltaFil = 1;
        *deltaCol = 1;         
        break;
    }
}

char obtenerDir(char Sopa[FILS][COLS], coordenada coord, char * segundasLetras, int deltaFil, int deltaCol){
    int f = coord.fil + deltaFil;
    int c = coord.col + deltaCol;
    for (size_t i = 0; segundasLetras[i] != 0; i++)
    {
        if(Sopa[f][c] == segundasLetras[i])
            return 1;
    }
    return 0;
}

Tdireccion * buscarDir(char sopa[FILS][COLS], coordenada coord, char * segundasLetras, int * size){
    Tdireccion * resp = NULL;
    int tam = 0;
    int deltaFil, deltaCol;
    
    for (Tdireccion i = DER; i <= D_AB; i++)
    {
        dirToDelta(i, &deltaFil, &deltaCol);
        if(validarDir(sopa, coord, deltaFil, deltaCol)){
            if(obtenerDir(sopa, coord, segundasLetras, deltaFil, deltaCol)){
                if(tam%BLOQUE == 0)
                    resp = realloc(resp, (tam+BLOQUE) * sizeof(Tdireccion));
                resp[tam++] = i;
            }
        }
    }
    resp = realloc(resp, tam * sizeof(Tdireccion));
    *size = tam;
    return resp;
}

char buscarPalabra(char sopa[FILS][COLS], coordenada coord, int deltaFil, int deltaCol, char diccionario[][MAX_PALABRA], char * palabra){
    int f = coord.fil;
    int c = coord.col;
    coordenada actualCoord;

    for (size_t i = 0; diccionario[i][0] != 0; i++) //recorro el diccionario
    {
        if(diccionario[i][0] == sopa[f][c]){
            for (size_t p = 0; diccionario[i][p] == sopa[f+p*deltaFil][c+p*deltaCol] ; p++)
            {
                if(diccionario[i][p+1] == 0){
                    strcpy(palabra, diccionario[i]);
                    return 1;
                }

                actualCoord.fil = f+p*deltaFil;
                actualCoord.col = c+p*deltaCol;
                if(!validarDir(sopa, actualCoord, deltaFil, deltaCol))
                    return 0;
            }
            
        }
    }
    return 0;
}