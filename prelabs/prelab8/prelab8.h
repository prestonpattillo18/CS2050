struct _Pet {
    char name[256];
    char species[256];
    int age;
};
    typedef struct _Pet Pet;

struct _PhoneNumber {
    char names[256];
    int areaCode;
    int number;
};
    typedef struct _PhoneNumber PhoneNumber;
 
typedef void (*PRINTER)(void *);

// Function

void PrintPets(Pet *, int, PRINTER);
void PrintPhoneNumbers(PhoneNumber *, int, PRINTER);
