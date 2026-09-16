#include "prelab3.h"
#include <stdio.h>
#include <stdlib.h>

//This file contains array-related functions that allow a user to create any type of array with a specified length, find the length of that array later, and free that array using simple commands

//this function takes an integer length and the size of the size of the array data type the user wants to create (in bytes) to
//return a smart array in the form of a void pointer -- the size of the array is stored as an int directly before the "start" of the array, with this value being included in the malloc
void * createArray(int length, int dataTypeSize){
    if (length <= 0 || dataTypeSize <= 0){
        printf("Error: Invalid input -- createArray\n");
        return NULL;
    }

    void *p;
    p = malloc((length * dataTypeSize) + sizeof(int));
        if (!p){
            printf("Error: Malloc failure -- createArray\n");
            return NULL;
        }
    *((int *) p) = length;
    p = (int *) p + sizeof(int);

    // printf("createArray success!\n"); -- this was for testing purposes
    return p;
}

//this function takes any array created through the createArray function to
//return the integer number of elements that the array can hold
int arraySize(void *array){
    if (!array){
        printf("Error: Invalid input -- arraySize\n");
        return 0;
    }

    // printf("arraySize success!\n"); -- this was for testing purposes
    return *((int *)array - sizeof(int));
}

//this function simply frees any array created through createArray
void freeArray(void *array){
    if (!array){
        printf("Error: Invalid input -- freeArray\n");
        return;
    }

    array = (int *)array - sizeof(int);
    free(array);
    array = NULL;

    // printf("freeArray success!\n"); -- this was for testing purposes
    return;
}
