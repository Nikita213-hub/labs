#include <stdio.h>
#include "validators.h"
#include <stdlib.h>
#include <ctype.h>
void initializeDoubleArray(char initMode, double *arr, int arrSize)
{
    if(toupper(initMode) == 'M')
    {
        for (int i = 0; i < arrSize; i++)
        {
            double val;
            char prompt[50];
            sprintf(prompt, "Insert value for element %d: ", i);
            val = getValidatedDoubleInput(prompt);
            arr[i] = val;
        }
        
    }
    else
    {
        for (int i = 0; i < arrSize; i++)
        {
            arr[i] = rand() % 101;
        }
    }
}

void initializeIntArray(char initMode, int *arr, int arrSize)
{
    if(toupper(initMode) == 'M')
    {
        for (int i = 0; i < arrSize; i++)
        {
            double val;
            char prompt[50];
            sprintf(prompt, "Insert value for element %d: ", i);
            val = getValidatedDoubleInput(prompt);
            arr[i] = val;
        }
        
    }
    else
    {
        for (int i = 0; i < arrSize; i++)
        {
            arr[i] = rand() % 201-100;
        }
    }
}


void printDoubleArray(double * arr, int arrSize)
{
    printf("[");
    for (int i = 0; i < arrSize; i++)
    {
        if(i == arrSize - 1)
        {
            printf("%lf", arr[i]);
        }
        else
        {
            printf("%lf,", arr[i]);
        }
        
    }
    printf("] \n");
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