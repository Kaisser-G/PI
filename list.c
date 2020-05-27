#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List newList(){
    return NULL;
}

int isEmpty(List list){
    return list == NULL;
}

List tail(List list){
    if(list == NULL){
        fprintf(stderr,"Listas vacias no tienen cola");
        exit(1);
    }
    return list->next;
}

int head(List list){
    if(list == NULL){
        fprintf(stderr,"Listas vacias no tienen cabeza");
        exit(1);
    }
    return list->elem;
}

size_t size(List list){
    if(isEmpty(list))
        return 0;
    else
        return 1 + size(tail(list));
}

int contains(List list, int elem){
    if(list == NULL || elem < list->elem)
        return 0;
    if(list->elem == elem)
        return 1;
    return contains(tail(list));
}

List add(List list, int elem){
    if(list == NULL || elem < list->elem){
        List aux = malloc(sizeof(node));
        aux->elem = elem;
        aux->next = list;
        return aux; 
    }

    if(list->elem == elem)
        return list;

    if(list->elem < elem)
     list->next = add(list->next, elem);
     return list;
}

List delete(List list, int elem){
    if(list == NULL || elem < list->elem)
        return list;
    if(list->elem == elem){
        List aux = list->next;
        free(list);          //////////////////////LIBERAR LOS ELEMENTOS CUANDO NO LOS USAS MAS
        return aux;
    }
    if(list->elem < elem){
     list->next = delete(list->next, elem);
     return list;
    }
}

int indexOf(List list, int elem){
    if(!contains(list, elem))
        return -1;
    
}

int get(List list, size_t index){
    if(list == NULL){
        fprintf(stderr,"Indice invalido en la lista");
        exit(404);
    }
    if(index == 0)
        return list->elem;
    return get(list->next, index-1);
}

//////////
void printList(List list){
    if(list != NULL){
        printf("%d ", list->elem);
        printList(list->next);
    }
}