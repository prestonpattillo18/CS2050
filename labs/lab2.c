/**************************
Preston Pattillo
ppbbq
CS2050
Lab 2
**************************/

/*
The purpose of this file is to give a user the ability to seamlessly create/free int arrays, 
initialize one of our arrays to all '0's, and multiply all even values of the array by a given multiplicand
*/

#include <stdio.h>
#include <stdlib.h>
#include "lab2.h"

//this array takes a pointer to an int array pointer and an array size to
//store an memory allocated int array pointer in the address of 'pointer to an the int array pointer'
//returns a value of 0 on success and a value of 1 for on failure
int makeArray(int **array, int size){
    if (!array || size <= 0){
        printf("Error: invalid input - makeArray\n");
        return 1; //fail value of 1
    }

    //memory allocation block
    int *p;
    p = malloc(sizeof(int) * size);
    if (p == NULL){
        printf("Error: malloc failure - makeArray\n");
        return 1;
    }
    
    printf("makeArray success!\n");
    *array = p;
    return 0;
}

//this array takes an int array pointer and array size to
//fill the values of the array with 0s
void initArray(int *array, int size){
    if (array == NULL || size <= 0){
        printf("Error: invalid input - initArray\n");
        return;
    }

    //goes through every element of the array and sets its value to 0
    for (int i = 0; i < size; i++){
        array[i] = 0;
    } 
    
    printf("initArray success!\n");
    return;
}

//this array takes an int array pointer, array size, and multiplicand to
//multiply all even values stored within the pointed array by the multiplicand
//returns the count of multiplied values
int multiplyEven(int *array, int size, int multiplicand){
    if (!array || size <= 0){
        printf("Error: invalid input - multiplyEven\n");
        return 0;
    }

    //goes through every element and checks for even numbers (remainder of 0 with a divisor of 2)
    //increments the multCounter on multiplications
    int multCounter = 0;
    for (int i = 0; i < size; i++){
        if ((array[i] % 2) == 0){
            array[i] *= multiplicand;
            multCounter++;
        }
    }
    
    printf("multiplyEven success\n");
    return multCounter;
}

//this function frees any array created through this library
void freeArray(int **array){
    if (!array || !*array){
        printf("Error: invalid input - freeArray\n");
        return;
    }

    free(*array);
    *array = NULL;
    printf("freeArray success!\n");
    return;
}
