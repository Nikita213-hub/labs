#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "validators.h"

int * initIntArray(int arrLength, int arrSize)
{
    srand(time(NULL));
    char validChars[2] = {'M', 'R'};
    char initMode = getValidatedCharInput("Choose initialization type manual (M) or with random values (R): ", validChars, 2);
    int * ptr = malloc(arrSize);
    if(toupper(initMode) == 'M')
    {
        for (int i = 0; i < arrLength; i++)
        {
            double val;
            char prompt[50];
            sprintf(prompt, "Insert value for element %d: ", i);
            val = getValidatedDoubleInput(prompt);
            ptr[i] = val;
        }
        
    }
    else
    {
        for (int i = 0; i < arrLength; i++)
        {
            ptr[i] = rand() % 101;
        }
    }
    return ptr;
}

void printIntArray(int * arr, int arrSize)
{
    printf("[");
    for (int i = 0; i < arrSize; i++)
    {
        if(i == arrSize - 1)
        {
            printf("%d", arr[i]);
        }
        else
        {
            printf("%d,", arr[i]);
        }
        
    }
    printf("] \n");
}