#include <stdio.h>
#include <stdlib.h>

struct _Queue {
    //holds the value, ezpz
    void * obj;

    //circular implementation
    struct _Queue * next;
    struct _Queue * prev;

    //this value holds the error code in the dummy node and the length of the list in the head (aka q->next)
    int err;
};
    typedef struct _Queue Queue;

/* This function returns the error code from the most recently executed queue operation. 0 implies success, 1 implies out-of-memory error.
Some functions may document additional error conditions. NOTE: All queue functions assign an error code. */
int getQueueErrorCode(Queue * q){
    if (!q) return 1;
    
    return q->err;
}

/* This function returns an initialized Queue variable.
Every queue variable must be initialized before applying subsequent queue functions. */
Queue * queueInit(){
    Queue * newQueue = malloc(sizeof(Queue));
        if (newQueue){
            newQueue->obj = NULL;
            newQueue->next = newQueue;
            newQueue->prev = newQueue;
            newQueue->err = 0;

            return newQueue;
        }

    printf("Error: Memory failure (queueInit)\n");
    return NULL;
}

/* This function enqueues an object into the queue.
For convenience, error code is returned directly (and also can be obtained via getQueueErrorCode) */
int enqueue(void * obj, Queue * q){
    if (!q || !obj){
        if (q) q->err = 1;
        return 1;
    }

    //initializing
    Queue * node = queueInit();
        if (!node){
            q->err = 1;
            return 1;
        }
        node->obj = obj;

    //linking
    if (q->next == q){
        node->next = q;
        node->prev = q;
        node->err = 1;
        q->next = node;
        q->prev = node;
    } else {
        node->next = q->next;
        node->prev = q;
        node->err = node->next->err + 1;
        q->next->prev = node;
        q->next = node;
    }

    q->err = 0;
    return 0;
}

/* This function performs dequeue and returns object at front of queue. NULL is returned if queue is empty and error code is set to 2.
NOTE: User should check error code if null objects are permitted in the queue. */
void * dequeue(Queue * q){
    if (!q || q->prev == q || q->prev == NULL){
        if (q) q->err = 2;
        return NULL;
    }

    Queue * held = q->prev;
    void * holding = q->prev->obj;

    //len adjustment
    if (q->next != q->prev) q->next->err -= 1;

    //unwrapping
    q->prev = q->prev->prev;
    q->prev->next = q;

    free(held);
    q->err = 0;
    return holding;
}

/* This function returns the number of objects in the queue. */
int getQueueSize(Queue * q){
    if (!q) return 0;

    q->err = 0;
    return q->next->err;
}

/* This function uninitializes a queue and frees all memory associated with it. NOTE: value of Queue variable is 
undefined after this function is applied, i.e., it should not be used unless initialized again using queueInit. */
void freeQueue(Queue * q){
    if (!q || q->next == NULL) return;

    //unravel, make q linear
    q->prev->next = NULL;

    while (q != NULL){
        Queue * temp = q;
        q = q->next;
        free(temp);
    }

    return;
}
