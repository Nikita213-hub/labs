#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include "validators.h"
#include "utils.h"
#define ARRAY_SIZE 100

double sumElsOfArray(double * arr, int arrSize);
double findMax(double * arr, int arrSIze);

int main()
{
    srand(time(NULL));  
    double arr[ARRAY_SIZE];
    int customSize;
    customSize = getValidatedIntInput("How many elements u need to be in the array(int): ", 1, 100);
    char validModes[] = {'M', 'R'};
    char initMode = getValidatedCharInput("Choose the mode of array initializing (M) manual or (R) random values: ", validModes, 2);
    initializeDoubleArray(initMode, arr, customSize);
    printDoubleArray(arr, customSize);
    printf("The sum of positive elements of the array = %lf \n", sumElsOfArray(arr, customSize));
    printf("The max element of the array = %lf", findMax(arr, customSize));
    return 0;
}

double sumElsOfArray(double * arr, int arrSize)
{
    double sumOfEls = 0;
    double lastPosInd;
    for (int i = 0; i < arrSize; i++)
    {
        if(arr[i] > 0)
        {
            lastPosInd = i;
        }
    }
    for (int i = 0; i <= lastPosInd; i++)
    {
        sumOfEls += arr[i];
    }
    
    return sumOfEls;
}

double findMax(double * arr, int arrSize)
{
    double maxEl = arr[0];
    for (int i = 0; i < arrSize; i++)
    {
        if(arr[i] > maxEl)
        {
            maxEl = arr[i];
        }
    }
    return maxEl;
}