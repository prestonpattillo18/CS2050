struct _List {
int object;
struct _List *next;
};
typedef struct _List List;

/* This function returns an empty List object, i.e., this must
be called before operations are performed on the list. The
parameter is a reference to an error code. 0 signifies the
operation was performed correctly, 1 means there was
insufficient memory available to initialize the list. */
List * initList(int* ec);
/* This function inserts the int object of the first parameter
at the head of the list. The last parameter is an error
code (0 implies success, 1 implies insufficient memory).
Returns pointer to updated list if there is no error;
otherwise returns the given list without change. */
List * insertAtHead(int, List* l, int* ec);
/* This function returns the int object at the index location
(starting at 1 for the head) of the first parameter. */
int getAtIndex(int i, List* l);
/* This function returns the number of objects in the list. */
int getListLength(List* l);
/* This function frees all memory allocated for a list and
returns NULL. */
List * freeList(List* l);
