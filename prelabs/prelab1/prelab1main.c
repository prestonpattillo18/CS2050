#include <stdio.h>
#include "prelab1.h"

//just a simple test block really
int main(){
    #define size 10

    //array names represent arrayUNIQUE_SMALL_LARGE
    int array3_4_8[size] = {5, 8, 4, 8, 8, 5, 4, 5, 4, 8};
    int array1_7_7[size] = {7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
    int array10_0_9[size] = {5, 2, 8, 4, 6, 1, 9, 3, 7, 0};

    int special = 0;
    int tiny = 0;
    int big = 0;
    int *sPtr = &special;
    int *tPtr = &tiny;
    int *bPtr = &big;
    int *aPtr = array10_0_9;

    //the next 4 sections are meant to return an error, this is really just to ensure that all parts of the validity checker work
    sPtr = NULL;
    if (getArrayInfo(aPtr, size, sPtr, tPtr, bPtr))
        printf("Array info: Unique: %d (NA); Smallest: %d (NA); Largest %d (NA)\n", special, tiny, big);
    
    sPtr = &special;
    tPtr = NULL;
    if (getArrayInfo(aPtr, size, sPtr, tPtr, bPtr))
        printf("Array info: Unique: %d (NA); Smallest: %d (NA); Largest %d (NA)\n", special, tiny, big);

    tPtr = &tiny;
    bPtr = NULL;
    if (getArrayInfo(aPtr, size, sPtr, tPtr, bPtr))
        printf("Array info: Unique: %d (NA); Smallest: %d (NA); Largest %d (NA)\n", special, tiny, big);

    bPtr = &big;
    aPtr = NULL;
    if (getArrayInfo(aPtr, size, sPtr, tPtr, bPtr))
        printf("Array info: Unique: %d (NA); Smallest: %d (NA); Largest %d (NA)\n", special, tiny, big);

    //this section tests the 3 premade arrays, ensuring that they return the correct values. all data should match the parenthesis
    aPtr = array3_4_8;
    if (getArrayInfo(aPtr, size, sPtr, tPtr, bPtr))
        printf("Array info: Unique: %d (3); Smallest: %d (4); Largest %d (8)\n", special, tiny, big);

    aPtr = array1_7_7;
    if (getArrayInfo(aPtr, size, sPtr, tPtr, bPtr))
        printf("Array info: Unique: %d (1); Smallest: %d (7); Largest %d (7)\n", special, tiny, big);

    aPtr = array10_0_9;
    if (getArrayInfo(aPtr, size, sPtr, tPtr, bPtr))
        printf("Array info: Unique: %d (10); Smallest: %d (0); Largest %d (9)\n", special, tiny, big);

    return 0;
}
