#include <stdio.h>
#include <stdlib.h>
#include "prelab6.h"

struct _List {
int object;
struct _List* next;
};

// typedef struct _List List; 

/*****************************

Error code guidesheet

0 - success
1 - memory failure
2 - invalid input

*****************************/

List * initializeList(int * ec){
    if (!ec){
        printf("Invalid reference to error code (initializeList)\n");
        return NULL;
    }

    List * newList = malloc(sizeof(List));
        if (newList){
            newList->object = 0;
            newList->next = NULL;
            *ec = 0;
            return newList;
        }

    *ec = 1;
    printf("Error: Memory failure (initializeList)\n");
    return NULL;
}


List * insertAtHead(int val, List * list, int * ec){
    if (!list || !ec){
        if (ec) *ec = 2;
        printf("Error: Invalid input (insertAtHead)\n");
        return list;
    }

    List * newNode = initializeList(ec);
        if (*ec) return list;

    newNode->next = list->next;
    list->next = newNode;
    newNode->object = val;

    *ec = 0;
    return list;
}


int getListLength(List * list, int * ec){
    if (!list || !ec){
        if (ec) *ec = 2;
        printf("Error: Invalid input (getListLength)\n");
        return -1;
    }

    for (int i = 0; list != NULL; i++){
        if (list->next == NULL){
            *ec = 0;
            return i;
        }
        else list = list->next;
    }

    *ec = 2;
    return -1;
}

int getAtIndex(int index, List * list, int * ec){
    if (!list || !ec || index < 0){
        if (ec) *ec = 2;
        printf("Error: invalid input (getAtIndex)\n");
        return -1234567890;
    }

    for (int i = -1; i != index; i++){
        list = list->next;
        
        if (list == NULL){
            *ec = 2;
            printf("Error: Invalid input (getAtIndex)\n");
            return -1234567890;
        }
    }

    *ec = 0;
    return list->object;
}


List * freeList(List * list, int * ec){
    if (!list || !ec){
        if (ec) *ec = 2;
        printf("Error: Invalid input (freeList)\n");
        return list;
    }

    while (list != NULL){
        List * temp = list;
        list = list->next;
        free(temp);
    }

    *ec = 0;
    return NULL;
}
