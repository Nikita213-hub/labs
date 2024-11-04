#include <stdio.h>
#include <stdlib.h>
#include "validators.h"

void printArray(int countOfRows, int countOfCols, int arr[countOfRows][countOfCols])
{
    for (int i = 0; i < countOfRows; i++)
    {
        for (int j = 0; j < countOfCols; j++)
        {
            printf(" %d ", arr[i][j]);
        }
        printf("\n");   
    }
}


void fulfillMatrix(int countOfRows, int countOfCols, int arr[countOfRows][countOfCols],char initMode)
{
    if(initMode == 'M')
    {
        for (int i = 0; i < countOfRows; i++)
        {
            for (int j = 0; j < countOfCols; j++)
            {
                char prompt[50];
                sprintf(prompt, "Insert value of [%d][%d]: ", i + 1, j + 1);
                // scanf("%d", &arr[i][j]);
                arr[i][j] = getValidatedIntInput(prompt, 1, 100);
            }
            
        }
        
    }
    else
    {
        for (int i = 0; i < countOfRows; i++)
        {
            for (int j = 0; j < countOfCols; j++)
            {
                arr[i][j] = rand() % 11;
            }
            
        }        
    }
    
}