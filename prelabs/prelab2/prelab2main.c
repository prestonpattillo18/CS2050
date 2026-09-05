#include <stdio.h>
#include <stdlib.h>
#include "prelab2.h"

//test main!!
int main(){
    //anchors
    float array1[3] = {1, 2, 0.0};
    float array2[5] = {2.22, 8.9, 4, 5.432, 0.0};

    //gets them started
    int size1 = 0;
    int size2 = 0;

    //the copies
    float *copy1 = copyFloatArray(array1, &size1);
    float *copy2 = copyFloatArray(array2, &size2);
    if (copy1 == NULL || copy2 == NULL){
        printf("oopsies");
        return 1;
    }

    //this was only really here because the size function was working weird
    // printf("%d\n%d\n\n", size1, size2);

    //proof is in the pudding
    printf("array1: {");
    for (int i = 0; i < (size1 - 1); i++){
        printf("%f, ", array1[i]);
    } printf("%f}\n", array1[size1 - 1]);

    printf("copy1: {");
    for (int i = 0; i < (size1 - 1); i++){
        printf("%f, ", copy1[i]);
    } printf("%f}\n", copy1[size1 - 1]);

    printf("array2: {");
    for (int i = 0; i < (size2 - 1); i++){
        printf("%f, ", array2[i]);
    } printf("%f}\n", array2[size2 - 1]);

    printf("copy2: {");
    for (int i = 0; i < (size2 - 1); i++){
        printf("%f, ", copy2[i]);
    } printf("%f}\n", copy2[size2 - 1]);

    //copy of a copy
    float **copy1Ptr = &copy1;
    float **copy2Ptr = &copy2;

    //get rid of the copies
    freeFloatArray(copy1Ptr);
    freeFloatArray(copy2Ptr);

    return 0;
}
