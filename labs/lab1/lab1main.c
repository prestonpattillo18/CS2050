#include <stdio.h>
#include "lab1.h"

int main(){

    //array names are listed as arrayAVG_NSUM_ESUM -- 'n' represents negative
    int array1_n5_8[6] = {2, 6, 1, 1, 1, -5};
    int array0_n19_n2[10] = {-6, -6, -7, 2, 4, 0, 4, 3, 3, 3};
  
    int avg = 0;
    int ngtv = 0;
    int evn = 0;
    int *avgPtr = &avg;
    int *ngtvPtr = &ngtv;
    int *evnPtr = &evn;

    //lab required that all functions return 0 for a success and 1 for a failure, so I figured this is a good way to test for errors & call the functions at the same time
    if (!getAverage(array1_n5_8, 6, avgPtr) && !sumNegative(array1_n5_8, 6, ngtvPtr) && !sumEven(array1_n5_8, 6, evnPtr))
        printf("array1_n5_8 (%d) (%d) (%d)\n", avg, ngtv, evn);
    else printf("Error 1\n");

    if (!getAverage(array0_n19_n2, 10, avgPtr) && !sumNegative(array0_n19_n2, 10, ngtvPtr) && !sumEven(array0_n19_n2, 10, evnPtr))
        printf("array0_n19_n2 (%d) (%d) (%d)\n", avg, ngtv, evn);
    else printf("Error 2\n\n");

    return 0;    
}
