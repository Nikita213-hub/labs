#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validators.c"
#include "bookStorage.c"

union code {
    int n;
    struct {
        unsigned a0:1;
    }bit;
};

void firstTask() {
    union code c;
    c.n = 10;
    printf("%d", c.bit.a0);
    int num = getValidatedIntInput("Insert any integer: ");
    if (num & 1) {
        printf("The number is odd\n");
    }
    else {
        printf("The number is even\n");
    }
} 

void secondTask() {
    runStorage();
}

int main() {
    char validChars[2] = {'1', '2'};
    char choice = getValidatedCharInput("Choose the task: 1-first taks, 2 - second task: ", validChars, 2);
    if (choice == '1') firstTask();
    else secondTask();
}