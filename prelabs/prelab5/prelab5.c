#include <stdio.h>
#include <stdlib.h>
#include "prelab5.h"

/********************************************************************************
For all functions with "int * ec" as a parameter, *ec refers 'error code', where:
    
    0 - success
    1 - memory failure
    2 - invalid input

********************************************************************************/

//this function returns an empty list in the form of a List pointer
List * initList(int* ec){
    if (!ec){
        printf("Error: Invalid input -- initList\n");
        *ec = 2;
        return NULL;
    }

    List * newList = malloc(sizeof(List));
    if (newList){
        newList->object = 0;
        newList->next = NULL;
        *ec = 0;
        return newList;
    }

    printf("Error: Malloc failure -- initList\n");
    *ec = 1;
    return NULL;
}

//this function takes a list and new object value to
//insert the new object to the start of the list and
//return the address of the new start of the list
List * insertAtHead(int object, List* list, int* ec){
    if (!list || !ec){
        printf("Error: Invalid input -- insertAtHead\n");
        *ec = 2;
        return NULL;
    }

    List * newNode = malloc(sizeof(List));
    if (newNode){
        newNode->object = object;
        newNode->next = list;
        *ec = 0;
        return newNode;
    }

    printf("Error: Malloc failure -- insertAtHead\n");
    *ec = 1;
    return NULL;
}

//this function takes a list and an index (where the first element is i = 1) to
//return the value of the object at that index
int getAtIndex(int i, List* list){
    if (!list || i <= 0){
        printf("Error: Invalid input -- getAtIndex\n");
        return 10000;
    }

    for (; list->next != NULL; i--){
        if (i == 1) return list->object;
        
        list = list->next;
    }

    return 0;
}

//this function takes a list to
//return the integer lenght of the list
int getListLength(List* list){
    if (!list){
        printf("Error: Invalid input -- getListLength\n");
        return -1;
    }

    for (int i = 1; ; i++){
        list = list->next;
        if (list->next == NULL) return i;
    }

    return -1;
}

//this function takes a list to
//free all objects held within the list and return NULL
List * freeList(List* list){
    if (!list){
        printf("Error: Invalid input -- freeList\n");
        return NULL;
    }

    while ((list->next) != NULL){
        List * currentP = list;
        list = list->next;
        free(currentP);
    } free(list);

    return NULL;
}
