#include <stdio.h>
#include "utils.h"
#include "validators.h"
#define ARR_SIZE 100

void shiftArray(int * arr, int arrSize, int shiftStartInd);
void copyNegatives(int * arr, int *arrSize);

int main()
{
    int arr[ARR_SIZE];
    int customSize;
    int *customSizePtr = & customSize;
    customSize = getValidatedIntInput("How many elements u need to be in the array(int): ", 1, ARR_SIZE);
    char validChars[2] = {'M', 'R'};
    char initMode = getValidatedCharInput("Choose the mode of array initializing (M) manual or (R) random values: ", validChars, 2);
    initializeIntArray(initMode, arr, customSize);
    printIntArray(arr, customSize);
    copyNegatives(arr, customSizePtr);
    printIntArray(arr, customSize);
    return 0;
}

void copyNegatives(int * arr, int *arrSize)
{
    for (int i = *arrSize; i >= 0; i--)
    {
        if (arr[i] < 0 && *arrSize < 100)
        {
            *arrSize = *arrSize + 1;
            shiftArray(arr, *arrSize, i);
        }
    }  
}

void shiftArray(int * arr, int arrSize, int shiftStartInd)
{
    for (int i = arrSize - 1; i > shiftStartInd; i--)
    {
        arr[i] = arr[i - 1];
    }
}


// 0 2 -3 -1 4
// 0 2 -3 -3 -1 -1 4