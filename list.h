#include <stdio.h>
#ifndef list_h
#define list_h

struct node
{
    int elem;
    struct node * next;
}node;

typedef struct node * List;

List newList();

int isEmpty(List list);

List tail(List list);

//add
List add(List list, int elem);
//delete
List delete(List list, int elem);
//contains
int contains(List list, int elem);
//indexOf
size_t indexOf(List list, int elem);
//get
//size
size_t size(List list);
//toArray


void printList(List list);

#endif