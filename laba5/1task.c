#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "validators.h"

int addSquares(int * arr, int arrLength);

int main()
{
    // int indOfEl = 0;
    // int length = 0;
    // int capacity = 5;
    // int *ptr = malloc(sizeof(int) * capacity);
    // while (indOfEl <= 10)
    // {
    //     if(length > capacity)
    //     {
    //         ptr = realloc(ptr, sizeof(int) * 2 * capacity);
    //     }
    //     printf("hui #%d: ", indOfEl);
    //     scanf("%d", &ptr[indOfEl]);
    //     length++;
    //     indOfEl++;
    // }
    // printf("%d", indOfEl);
    // printf("%d", ptr[indOfEl - 1]);
    // return 0;    
    int arrLength = getValidatedIntInput("Insert array length from 1 to 100: ", 1, 100);
    int arrSize = sizeof(int) *  2*arrLength;
    int *arr = initIntArray(arrLength, arrSize);
    printIntArray(arr, arrLength * 2);
    addSquares(arr, arrLength);
    printIntArray(arr, arrLength * 2);
    free(arr);
}                       


void shiftArray(int * arr, int arrLength)
{
    for (int i = arrLength - 1; i >= 0; i--)
    {
        arr[i + arrLength] = arr[i];
    }
}
    
   
    
int addSquares(int * arr, int arrLength)
{
    int temp = arr[0];
    shiftArray(arr, arrLength);
    for (int i = 0; i < arrLength * 2; i+=2)
    {
        arr[i + 1] = arr[i] * arr[i];
    } 
}

// [1, 4, 3]
// [1, 1, 4, 3]
// [1, 1, 4, 4, 3]
// [1, 1, 4, 16, 3]
// [1, 1, 4, 16, 3, 3]
// [1, 1, 4, 16, 3, 9]