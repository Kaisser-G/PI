#include<stdio.h>
#include<stdlib.h>

#define FILS 2
#define COLS 2
#define BLOQUE 10
#define EnRangoFils(x) (0<=x&&x<=FILS)
#define EnRangoCols(x) (0<=x&&x<=COLS)

typedef enum {DER = 0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB}Tdireccion;

typedef struct posicion
{
    char * palabra;
    size_t fila;
    size_t columna;
    Tdireccion direccion;
}respuesta;

typedef struct coordenada
{
    size_t fil;
    size_t col
}coordenada;

typedef respuesta * solucion;

solucion resolverSopa(char sopa[FILS][COLS], char * diccionario[]);
//primero identificar posibles palabras
coordenada * buscarInicio(char sopa[FILS][COLS], char * letras, int *size);
//identificar posibles direcciones      vector de direcciones
Tdireccion * buscarDireccion(char sopa[FILS][COLS], coordenada coord, char * letras);
//revisar en esas direcciones

char esDir(char sopa[FILS][COLS], coordenada coord, char letra, Tdireccion dir);

int main(){
    Tdireccion d = IZQ;
    char sopa[FILS][COLS] = {
        "AB",
        "CD"
    };
    printf("h\n");
    char * letras = "AZ";
    int size;
    printf("h\n");
    coordenada * coordenadas = buscarInicio(sopa, letras, &size);
    printf("h\n");
    for(int i = 0; i < size; i++)
        printf("%d %d", coordenadas[i].fil, coordenadas[i].col);
    return 0;
}

coordenada * buscarInicio(char sopa[FILS][COLS], char * letras, int *size){
    coordenada * resp = NULL;
    char flag;
    int tam = 0;
    for (size_t f = 0; f < FILS; f++)
    {
        for ( size_t c = 0; c < COLS; c++)
        {
            printf("c\n");
            flag = 0;
            for (size_t v = 0; (letras+v) != 0 && flag == 0; v++)
            {
                printf("f: %d, c: %d\n",f,c);
                printf("sopa:%c\n", sopa[f][c]);
                printf("letra:%c\n", *(letras+v));
                if(letras[v] == sopa[f][c]){
                    printf("equals\n");
                    if(tam%BLOQUE == 0){
                        resp = realloc(resp, (tam + BLOQUE) * sizeof(resp[0]));
                    }
                    resp[tam].fil = f;
                    resp[tam].col = c;
                    tam++;
                    flag = 1;
                }
            }
               
        }
    }
    realloc(resp, tam);
    *size = tam;
    return resp;
}

Tdireccion * buscarDireccion(char sopa[FILS][COLS], coordenada coord, char * letras){
    Tdireccion * resp = NULL;
    int tam = 0;
    char flag = 0;
    for (Tdireccion d = IZQ ; d <= D_AB; d++)
    {
        flag = 0;
        for (size_t i = 0; letras[i] && !flag; i++)
        {
            if(esDir(sopa, coord, letras[i], d)){
                if(tam%BLOQUE == 0)
                    resp = realloc(resp, (tam + BLOQUE) * sizeof(resp[0]));
                resp[tam++] = d;
                flag = 1;
            }
        }
           
    }
    
}

char esDir(char sopa[FILS][COLS], coordenada coord, char letra, Tdireccion dir){
    int deltaFil, deltaCol;
    switch (dir)
    {
    case DER:
        deltaFil = 0;
        deltaCol = 1;       
        break;
    case IZQ:
        deltaFil = 0;
        deltaCol = -1; 
        break;
    case ABA:
        deltaFil = 1;
        deltaCol = 0;         
        break;
    case ARR:
        deltaFil = -1;
        deltaCol = 0;        
        break;
    case I_AR:
        deltaFil = -1;
        deltaCol = -1;         
        break;
    case I_AB:
        deltaFil = 1;
        deltaCol = -1;         
        break;
    case D_AR:
        deltaFil = -1;
        deltaCol = 1;        
        break;
    case D_AB:
        deltaFil = 1;
        deltaCol = 1;         
        break;
    }
    int f = coord.fil + deltaFil;
    int c = coord.col + deltaCol;
    if(!EnRangoFils(f) || !EnRangoCols(c))
        return 0;
    return letra == sopa[f][c];
}