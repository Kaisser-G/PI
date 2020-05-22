#include "list.h"
#include <stdio.h>

int
main(){
    List lista = newList();
    for (int i = 0; i < 10; i++)
    {
        /* code */
        lista = add(lista, i);
    }
    printList(lista);
    lista = delete(lista, 5);
    printList(lista);
    return 0;
}