#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "validators.h"

int addSquares(double * arr, int arrLength);
void shiftArray(double * arr, int arrLength, int startInd);


int main()
{
    
    int arrLength = getAwesomeValidatedIntInput("Insert array length from 1 to 100: ", 1, 100);
    int arrSize = sizeof(double) *  2*arrLength;
    double *arr = initDoubleArray(arrLength, arrSize);
    printDoubleArray(arr, arrLength);
    addSquares(arr, arrLength);
    printDoubleArray(arr, arrLength * 2); 
    free(arr);
}                       


void shiftArray(double * arr, int arrLength, int startInd)
{
    int temp = arr[0];
    for (int i = arrLength*2-1; i >= startInd; i--)
    {
        arr[i + 1] = arr[i];
    }
}

   
    
int addSquares(double * arr, int arrLength)
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