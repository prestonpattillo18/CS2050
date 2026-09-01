#include <stdio.h>
#include "prelab1.h"

//just a simple test block really
int main(){
    #define size 10

    int arrayUnique3Small4Large8[size] = {5, 8, 4, 8, 8, 5, 4, 5, 4, 8};
    int arrayUnique1Small7Large7[size] = {7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
    int arrayUnique10small0Large9[size] = {5, 2, 8, 4, 6, 1, 9, 3, 7, 0};

    int special = 0;
    int tiny = 0;
    int big = 0;
    int *specialPtr = &special;
    int *tinyPtr = &tiny;
    int *bigPtr = &big;
    int *arrayPtr = arrayUnique10small0Large9;
    
    specialPtr = NULL;
    if (getArrayInfo(arrayPtr, size, specialPtr, tinyPtr, bigPtr))
        printf("Array info: Unique: %d (NA); Smallest: %d (NA); Largest %d (NA)\n", special, tiny, big);
    
    specialPtr = &special;
    tinyPtr = NULL;
    if (getArrayInfo(arrayPtr, size, specialPtr, tinyPtr, bigPtr))
        printf("Array info: Unique: %d (NA); Smallest: %d (NA); Largest %d (NA)\n", special, tiny, big);

    tinyPtr = &tiny;
    bigPtr = NULL;
    if (getArrayInfo(arrayPtr, size, specialPtr, tinyPtr, bigPtr))
        printf("Array info: Unique: %d (NA); Smallest: %d (NA); Largest %d (NA)\n", special, tiny, big);

    bigPtr = &big;
    arrayPtr = NULL;
    if (getArrayInfo(arrayPtr, size, specialPtr, tinyPtr, bigPtr))
        printf("Array info: Unique: %d (NA); Smallest: %d (NA); Largest %d (NA)\n", special, tiny, big);

    arrayPtr = arrayUnique3Small4Large8;
    if (getArrayInfo(arrayPtr, size, specialPtr, tinyPtr, bigPtr))
        printf("Array info: Unique: %d (3); Smallest: %d (4); Largest %d (8)\n", special, tiny, big);

    arrayPtr = arrayUnique1Small7Large7;
    if (getArrayInfo(arrayPtr, size, specialPtr, tinyPtr, bigPtr))
        printf("Array info: Unique: %d (1); Smallest: %d (7); Largest %d (7)\n", special, tiny, big);

    arrayPtr = arrayUnique10small0Large9;
    if (getArrayInfo(arrayPtr, size, specialPtr, tinyPtr, bigPtr))
        printf("Array info: Unique: %d (10); Smallest: %d (0); Largest %d (9)\n", special, tiny, big);

    return 0;
}
