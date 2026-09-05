#include <stdio.h>
#include <stdlib.h>
#include "prelab2.h"

float * copyFloatArray (float inputArray[], int * outputLength){
    //validity check!
    if (!inputArray || !outputLength){
        printf("Error (7)");
        return NULL;
    }

    //this section finds how long the input array is, assuming that the array actually has the sentinel value of '0.0'
    for (int i = 0; ; i++){
        if (inputArray[i] == 0.0){
            *outputLength = i + 1;
            break;
        }
    }
    
    //loop goes through each value of 
    float *outputArray;
    outputArray = malloc(sizeof(float) * (*outputLength));
    //hope it doesn't fail!
    if (!outputArray)
        return NULL;
    for (int i = 0; i < *outputLength; i++){
        outputArray[i] = inputArray[i];
    }

    return outputArray;
}

void freeFloatArray(float ** outputArray){
    if (!outputArray || !*outputArray){
        printf("Error (32)");
        return;
    }

    free(*outputArray);
    *outputArray = NULL;

    return;
}
