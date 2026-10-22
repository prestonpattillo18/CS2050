#include <stdio.h>
#include "prelab8.h"

void PrintPet(Pet * pet){
    printf("%s - %s (age %d)\n",pet->name,pet->species,pet->age);
}

void PrintPhoneNumber(PhoneNumber * phone){
    printf("%s - (%d) %d\n",phone->names,phone->areaCode,phone->number);
}

int main(void){
    Pet pets[] = {
        {"Murphy","dog",4},
        {"Cisco","dog",15},
        {"Mia","cat",3},
    };

    PhoneNumber phones[] = {
        {"Jim", 573, 5551234},
        {"Sally", 314, 5555678},
        {"Bob", 816, 5559012},
        {"Jane", 314, 5553456},
    };

    PrintPets(pets,3,(PRINTER)PrintPet);
    PrintPhoneNumbers(phones,4,(PRINTER)PrintPhoneNumber);

}
