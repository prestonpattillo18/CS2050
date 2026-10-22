/*****************************

Error code guidesheet

0 - success
1 - memory failure
2 - invalid input

*****************************/

typedef struct _List List; 

//this function takes a pointer to an int error code variable to
//return a new list with 0 elements
List* initializeList(int * errorCode);

//this function takes an integer value, a list created through initializeList, and a pointer to an int error code variable to
//return the same list with the value inserted as the first element of the list
List* insertAtHead(int value, List*, int * errorCode);

//this function takes an integer index, a list created through initializeList, and a pointer to an int error code variable to
//return the value stored inside of the element stored inside the list at that index
//returns "-1234567890" on failure
int getAtIndex(int index, List*, int * errorCode);

//this function takes a list created through initializeList and a pointer to an int error code variable to
//return the integer length of the list (in terms of elements)
//returns "-1234567890" on failure
int getListLength(List*, int * errorCode);

//this function takes a list created through initializeList and a pointer to an int error code variable to
//free the entire list and return NULL
List * freeList(List*, int * errorCode);
