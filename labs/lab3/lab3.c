/**************************
Preston Pattillo
ppbbq
CS2050
Lab 2
**************************/

//this library file focuses on creating smart arrays, mainly focusing on storing the length in a "hidden" section

#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"

//this function takes the size in bytes of the wanted data type & the wanted # of elements to
//dynamically allocate a smart array and return it as a (void *)
void * allocateSmartArray(int elementSize, int elementCount){
    if (elementSize <= 0 || elementCount <= 0){
        printf("Error: Invalid input -- allocateSmartArray\n");
        return NULL;
    } 

    //creation of the array
    void *p;
    //i genuinely do not understand why I have to add 4 * sizeof(int) instead of just sizeof(int) -- my ./a.out has no valgrind errors and I can't seem to recreate the issue in my main file
    p = malloc((elementCount * elementSize) + 4 * sizeof(int));
    if (p == NULL){
        printf("Error: malloc failure -- allocateSmartArray\n");
        return NULL;
    }


    //stores the length of the array and redefines the "beginning" of the array so that the length is hidden exactly one int size behind p[0]
    *((int *) p) = elementCount;
    p = (int *) p + sizeof(int);

    return p;
}

//this function takes an array created through the allocateSmartArray function to
//free its held memory & set the pointer to NULL
void freeSmartArray(void * smartArray){
    if (!smartArray){
        printf("Error: Invalid input -- freeSmartArray\n");
        return;
    }

    smartArray = (int *) smartArray - sizeof(int);
    free(smartArray);
    smartArray = NULL;

    return;
}

//this function takes an array created through the allocateSmartArray function to
//return the integer # of elements that can fit in the array
int getElementCount(void * smartArray){
    if (!smartArray){
        printf("Error: Invalid input -- getElementCount\n");
        return -1;
    }

    return *((int *)smartArray - sizeof(int));
}
