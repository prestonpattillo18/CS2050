#include "prelab8.h"
// You need to implement these functions.
// Remember, they must be recursive and use no loops!
void PrintPets(Pet * pets, int n, PRINTER printer){
    if (!pets || n <= 0 || !printer) return;

    PrintPets(pets + 1, n - 1, printer);
    printer(pets);
}

void PrintPhoneNumbers(PhoneNumber * phones, int n, PRINTER printer){
    if (!phones || n <= 0 || !printer) return;

    PrintPhoneNumbers(phones + 1, n - 1, printer);
    printer(phones);
}
