#include <stdio.h>
#include "lab0.h"

//this function takes an integer array, array size, and integer search query to
//return the number of times that the query occurs in the array
int countOccurrences(int size, int array[], int query){
    //invalid input checker -- backs out and returns an error value
    if (size <= 0 || array == NULL){
        return -2;
    }

    //counter variable -- this is what the function returns
    int counter = 0;

    for (int i = 0; i < size; i++){
        if (*(array + i) == query){
            counter++;
        } 
    }

    return counter;
}
