#include <stdio.h>
#include "list.h"

List newList(){
    return NULL;
}

int isEmpty(List list){
    return list == NULL;
}

List tail(List list){
    return list->next;
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
        return list->next;
    }
    if(list->elem < elem)
     list->next = delete(list->next, elem);
     return list;
}

int indexOf(List list, int elem){
    if(!contains(list, elem))
        return -1;
}


//////////
void printList(List list){
    if(list != NULL){
        printf("%d ", list->elem);
        printList(list->next);
    }
}