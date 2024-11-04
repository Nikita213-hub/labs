#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "utils.h"
#include "validators.h"
#define MATRIX_ORDER 6
int findSumOfMinEvenRowEls(int arr[MATRIX_ORDER][MATRIX_ORDER], int matrixOrder);
int findSumOfMaxOddRowEls(int arr[MATRIX_ORDER][MATRIX_ORDER], int matrixOrder);

int main()
{
    srand(time(NULL)); 
    int matrix[MATRIX_ORDER][MATRIX_ORDER];
    char initMode;
    char validChars[] = {'M', 'R'};
    initMode = getValidatedCharInput("Choose the mode of matrix initializing (M) manual or (R) random values: ", validChars, 2);
    fulfillMatrix(MATRIX_ORDER, MATRIX_ORDER, matrix, initMode);
    printArray(MATRIX_ORDER, MATRIX_ORDER, matrix);
    printf("Sum of smallest els in even rows = %d \n", findSumOfMinEvenRowEls(matrix, MATRIX_ORDER));
    printf("Sum of max els in odd rows = %d \n", findSumOfMaxOddRowEls(matrix, MATRIX_ORDER));
    return 0;
}

int findSumOfMinEvenRowEls(int arr[MATRIX_ORDER][MATRIX_ORDER], int matrixOrder)
{
    int sum = 0;
    for (int i = 0; i < matrixOrder; i+=2)
    {
        int fewestEl = arr[i][0];
        for (int j = 0; j < matrixOrder; j++)
        {
            if(arr[i][0] > arr[i][j])
            {
                fewestEl = arr[i][j];
            }
        }
        sum += fewestEl;
        
    }
    return sum;
    
}

int findSumOfMaxOddRowEls(int arr[MATRIX_ORDER][MATRIX_ORDER], int matrixOrder)
{
    int sum = 0;
    for (int i = 1; i < matrixOrder; i+=2)
    {
        int maxEl = arr[i][0];
        for (int j = 0; j < matrixOrder; j++)
        {
            if(maxEl < arr[i][j])
            {
                maxEl = arr[i][j];
            }
        }
        sum += maxEl;
        
    }
    return sum;
    
}
