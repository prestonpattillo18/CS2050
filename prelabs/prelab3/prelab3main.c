#include "prelab3.h"
#include <stdio.h>
#include <stdlib.h>

//this file is an interactive test for 'prelab3.c' -- features switch menus as the main mechanic

int main(){

    //variable declarations -- want these to have a "global" scope within main
    int choice;
    void *array = NULL;
    int dataType = 0;
    int length = 0;

    //meat and potatoes block
    //holds all of the switch cases to test each function
    do {
        printf("\n      -- Menu --\n\n");
        printf("(1) Create new array\n");
        printf("(2) Find array size\n");
        printf("(3) Enter array values\n");
        printf("(4) Print array\n");
        printf("(5) Exit\n");
        printf("Enter the number corresponding to what selection you want (eg, '1' for Create new array)\n");
        scanf("%d", &choice);

        //main mechanic switch block
        switch (choice){
            //create new array case
            case 1:
                if (array) freeArray(array);

                do{
                    printf("\nWhat data type will the array be?\n(1) Int\n(2) Long\n(3) Float\n(4) Double\n(5) Char\n\n");
                    scanf("%d", &dataType);
                } while (choice < 1 || choice > 5);
                printf("Enter the number of elements you want in the array: ");
                scanf("%d", &length);
                switch (choice){
                    case 1:
                        array = createArray(length, sizeof(int));
                        break;
                    case 2:
                        array = createArray(length, sizeof(long));
                        break;
                    case 3:
                        array = createArray(length, sizeof(float));
                        break;
                    case 4:
                        array = createArray(length, sizeof(double));
                        break;
                    case 5:
                        array = createArray(length + 1, sizeof(char));
                        break;
                    default:
                        printf("Something catastrophic has occurred -- shutting down\n"); //really just here because there are safeguards against the default case needing to be used
                        break;
                } break;
            //find array size case
            case 2:
                //ensures the user doesn't skip the array creation & break something
                if (!array){
                    printf("You must create an array first!\n");
                    break;
                }

                printf("The array has enough space for %d elements\n", arraySize(array));
                break;
            //enter array values case
            case 3:
                //ensures the user doesn't skip the array creation & break something
                if (!array){
                    printf("You must create an array first!\n");
                    break;
                }
                
                printf("Enter the elements of your array, separating each item with a space (' '): ");
                switch (dataType){
                    case 1:
                        for (int i = 0; i < arraySize(array); i++){
                            scanf(" %d", ((int *)array + (i * sizeof(int))));
                        } break; 
                    case 2:
                        for (int i = 0; i < arraySize(array); i++){
                            scanf(" %ld", ((long *)array + (i * sizeof(long))));
                        } break;
                    case 3:
                        for (int i = 0; i < arraySize(array); i++){
                            scanf(" %f", ((float *)array + (i * sizeof(float))));
                        } break;
                    case 4:
                        for (int i = 0; i < arraySize(array); i++){
                            scanf(" %lf", ((double *)array + (i * sizeof(double))));
                        } break;
                    case 5:
                        for (int i = 0; i < arraySize(array); i++){
                            scanf(" %c", ((char *)array + (i * sizeof(char))));
                        } break;
                    default:
                        printf("Something catastrophic has occurred -- shutting down\n"); //really just here because there are safeguards against the default case needing to be used
                        break;
                } break;
            //print array case
            case 4:
                //ensures the user doesn't skip the array creation & break something
                if (!array){
                    printf("You must create an array first!\n");
                    break;
                }

                printf("Printing...\n\n");
                switch(dataType){
                    case 1: //int
                        for (int i = 0; i < arraySize(array); i++){
                            printf("%d ", *((int *)array + (i * sizeof(int))));
                        } printf("\n");
                        break;
                    case 2: //long
                        for (int i = 0; i < arraySize(array); i++){
                            printf("%ld ", *((long *)array + (i * sizeof(long))));
                        } printf("\n");
                        break;
                    case 3: //float
                        for (int i = 0; i < arraySize(array); i++){
                            printf("%f ", *((float *)array + (i * sizeof(float))));
                        } printf("\n");
                        break;
                    case 4: //double
                        for (int i = 0; i < arraySize(array); i++){
                            printf("%lf ", *((double *)array + (i * sizeof(double))));
                        } printf("\n");
                        break;
                    case 5: //char
                        for (int i = 0; i < arraySize(array); i++){
                            printf("%c", *((char *)array + (i * sizeof(char))));
                        } printf("\n");
                        break;
                    default:
                        printf("Something catastrophic has occurred -- shutting down\n"); //really just here because there are safeguards against the default case needing to be used
                        break;
                } break;
            //exit case
            case 5:
                if (array) freeArray(array); //the user can still exit, even if they haven't used any of the functions

                printf("Exiting...\n\n");
                return 0;
            default:
                printf("\nEnter a number 1-5 correlating to what option you want\n");
                break; //just spits the user back into the menu
        }
    } while (choice != 5); //loops the menu until

    return 0;
}
