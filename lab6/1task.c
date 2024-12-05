#include <stdio.h>
#include "utils.h"
#include "validators.h"

void swap(int * a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int findMin(int * arr, int size, int startEl)
{
    int min = arr[startEl];
    int ind = startEl;
    for (int i = startEl; i < size; i++)
    {
        if(arr[i] < min) {
            min = arr[i];
            ind = i;
        };
    }
    return ind;
}

void selectionSort(int * arr, int arrLength)
{
    int fstEl = 0;
    for (int i = 0; i < arrLength; i++)
    {
        int min = arr[0];
        for (int j = i; j < arrLength; j++)
        {
            swap(&arr[findMin(arr, arrLength, j)], &arr[j]);
        }

    }
}

int main()
{
    int arrLen = getAwesomeValidatedIntInput("Input array length: ", 1, 500);
    int * arr = initIntArray(arrLen, sizeof(int) * arrLen);
    selectionSort(arr, arrLen);
    printIntArray(arr, arrLen);
}