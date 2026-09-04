#include <stdio.h>

//this function takes an integer array, array size, and addresses for three integer variables to
//store the number of unique numbers in the array in *unique as well as the smallest and largest values of the array in *smallest and *largest, respectiely
int getArrayInfo(const int *array, int size, int * uniquest, int * smallest, int * largest){
    //validity checker
    if (!array || size <= 0 || !uniquest || !smallest || !largest){
        printf("Error\n");
        return 0;
    }

    //temporary local variables
    int unique = 1;
    int small = *array;
    int large = *array;

    //stores all separate unique values and the last next empty index
    int uniqueArray[size];
    uniqueArray[0] = *array;

    for (int i = 0; i < size; i++){
        //unique block
        for (int k = 0; k < unique; k++){
            //'fail' section -- if the loop matches a value in array to a stored unique value, the loop breaks
            if (array[i] == uniqueArray[k])
                break;
            //'success' section -- if the loop reaches the end, it'll increment the unique counter and store the unique value
            if (k == unique - 1){
                uniqueArray[unique] = *array[i];
                unique++;
            }
        }

        //small and large block
        if (array[i] < small)
            small = array[i];
        if (array[i] > large)
            large = array[i];
    }

    //final 'return' values
    *uniquest = unique;
    *smallest = small;
    *largest = large;

    return 1;
}
