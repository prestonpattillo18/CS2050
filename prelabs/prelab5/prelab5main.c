#include <stdio.h>
#include <stdlib.h>
#include "prelab5.h"

//quick and easy testing
int main(){
    #define min 1
    #define max 8

    int * ec = malloc(sizeof(int));
    *ec = 0;
    List * myList = initList(ec);

    for (int i = min; i <= max; i++){
        myList = insertAtHead(i, myList, ec);
        printf("%d inserted...\n", getAtIndex(1, myList));
    }

    for (int i = getListLength(myList); i >= min; i--){
        printf("%d @ index %d\n", getAtIndex(i, myList), i);
    }

    if (!freeList(myList)) printf("Success\n");
    else printf("you suck\n");
    
    return 0;
}
