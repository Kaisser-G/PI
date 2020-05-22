#include<stdio.h>

/////////////////////////////////
double sumaReciprocosRec(int n){
    if(n==1)
        return 1;
    return 1/(double)n + sumaReciprocosRec(n-1);
}
double sumaReciprocos(int n){
    if(n<1)
        return -1;
    return sumaReciprocosRec(n);
}
////////////////////////////////////

int esPotde3(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return n%3 && esPotde3(n/3);
}

int
main(){
    printf("%g\n",sumaReciprocos(5));
    printf("%g\n",sumaReciprocos(1));
    printf("%g\n",sumaReciprocos(0));
    printf("%g\n",sumaReciprocos(-3));

    return 0;
}