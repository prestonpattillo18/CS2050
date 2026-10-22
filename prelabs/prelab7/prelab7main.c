#include <stdio.h>
#include <stdlib.h>
#include "prelab7.h"

int main(){
    Queue * q = queueInit();
        if (!q) return 1;

    printf("Num testing\n");
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        printf("Queueing... \n[");
        for (int i = 0; i < 10; i++){
            enqueue((void *)(arr + i), q);
            if (getQueueErrorCode(q)) return 1;
            printf("%d ", arr[i]);
        } printf("]\n\n");

        printf("Length = %d\n\n", getQueueSize(q));

        printf("Dequeueing... \n[");
        int error = getQueueErrorCode(q);
        while (error != 2){
            void * billy = dequeue(q);
            if (billy) printf("%d ", *(int *)billy);
            error = getQueueErrorCode(q);
        } printf("]\n\n");

        printf("Length = %d\n\n", getQueueSize(q));

        printf("Queueing... \n[");
        for (int i = 0; i < 5; i++){
            enqueue((void *)(arr + i), q);
            if (getQueueErrorCode(q)) return 1;
            printf("%d ", arr[i]);
        } printf("]\n\n");

        printf("Length = %d\n\n", getQueueSize(q));

        free(q);

    q = queueInit();
        if (!q) return 1;
    printf("Char testing\n");
    char ar[8] = {'a', 'p', 'p', 'e', 'n', 'd', 'i', 'x'};
        printf("Queueing... \n[");
        for (int i = 0; i < 9; i++){
            enqueue((void *)(ar + i), q);
            if (getQueueErrorCode(q)) return 1;
            printf("%c ", ar[i]);
        } printf("]\n\n");

        printf("Length = %d\n\n", getQueueSize(q));

        printf("Dequeueing... \n[");
        error = getQueueErrorCode(q);
        while (error != 2){
            void * billy = dequeue(q);
            if (billy) printf("%c ", *(int *)billy);
            error = getQueueErrorCode(q);
        } printf("]\n\n");

        printf("Length = %d\n\n", getQueueSize(q));

        printf("Queueing... \n[");
        for (int i = 0; i < 5; i++){
            enqueue((void *)(ar + i), q);
            if (getQueueErrorCode(q)) return 1;
            printf("%c ", ar[i]);
        } printf("]\n\n");

        printf("Length = %d\n\n", getQueueSize(q));

        free(q);    

    return 0;
}
