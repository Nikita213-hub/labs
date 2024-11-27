#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "validators.h"

int addSquares(int * arr, int arrLength);
void shiftArray(int * arr, int arrLength, int startInd);


int main()
{
    int arrLength = getValidatedIntInput("Insert array length from 1 to 100: ", 1, 100);
    int arrSize = sizeof(int) *  2*arrLength;
    int *arr = initIntArray(arrLength, arrSize);
    printIntArray(arr, arrLength);
    addSquares(arr, arrLength);
    printIntArray(arr, arrLength * 2); 
    free(arr);
}                       


void shiftArray(int * arr, int arrLength, int startInd)
{
    int temp = arr[0];
    for (int i = arrLength*2-1; i >= startInd; i--)
    {
        arr[i + 1] = arr[i];
    }
}

   
    
int addSquares(int * arr, int arrLength)
{
    for (int i = 0; i < arrLength * 2; i+=2)
    {
        shiftArray(arr, arrLength, i);
        arr[i + 1] = arr[i] * arr[i];
    } 
}

// [1, 4, 3]
// [1, 1, 4, 3]
// [1, 1, 4, 4, 3]
// [1, 1, 4, 16, 3]
// [1, 1, 4, 16, 3, 3]
// [1, 1, 4, 16, 3, 9]