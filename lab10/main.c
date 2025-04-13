#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validators.c"
#include "bookStorage.c"

union code {
    int n;
    struct {
        unsigned int a0:1;
    }bit;
};

void checkIsOdd() {
    union code c;
    //int num = getValidatedIntInput("Insert any integer: ");
    c.n = getValidatedIntInput("Insert any integer: ");
    if (c.n & 1) {
        printf("The number is odd\n");
    }
    else {
        printf("The number is even\n");
    }
} 

int main() {
    char validChars[2] = {'1', '2'};
    char choice = getValidatedCharInput("Choose the task: 1-first taks, 2 - second task: ", validChars, 2);
    if (choice == '1') checkIsOdd();
    else runStorage();
}