#include <stdio.h>

//this function takes an integer array, array size, and integer search query to
//return the number of values in the array which are greater than or equal to the query
int greaterOrEqual (const int *arr, int size, int query){
    //validity checker
    if (arr == NULL || size <= 0)
        return -1;

    //actual workings of the function. really basic for loop that checks each individual element
    int counter = 0;
    for (int i = 0; i < size; i++){
        if (*(arr + i) >= query)
            counter++;
    } return counter;
}
