#include <stdio.h>
#include "lab1.h"

static int invalidInput(int array[], int size, int *result){
    if (!array || size <= 0 || !result)
        //invalid inputs
        return 1;

    //valid
    return 0;
}

int getAverage(int array[], int size, int *result){
    if (invalidInput(array, size, result))
        //invalid / failure
        return 1;

    //calculates the total of all elements in the array
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += array[i];
    }

    //places the average in the address of 'result'
    *result = (sum / size);

    //success
    return 0;
}

int sumNegative(int array[], int size, int *result){
    if (invalidInput(array, size, result)){
        //invalid / failure
        return 1;    
    }

    //calculates the total of all negative elements in the array
    int sum = 0;
    for (int i = 0; i < size; i++){
        if (array[i] < 0)
            sum += array[i];
    }

    //i'm not totally sure why this is necessary? -- i'm awaiting the JimR speech on this
    if (sum == 0){
        //failure
        return 1;
    }

    //places the sum in the address of 'result'
    *result = sum;

    //success
    return 0;
}

int sumEven(int array[], int size, int *result){
    if (invalidInput(array, size, result)){
        //invalid / failure
        return 1;    
    }

    //calculates the total of all even elements in the array
    int sum = 0;
    for (int i = 0; i < size; i++){
        if ((array[i] % 2) == 0)
            sum += array[i];
    }

    //places the sum in the address of 'result'
    *result = sum;

    //success
    return 0;
}
