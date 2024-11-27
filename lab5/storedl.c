#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "validators.h"

void removeElFromArray(int **newArr, int ** arr, int k, int countOfRows, int * rowLensArr);
void initTwoDemArr(int ** ptrsArr, int countOfRows, int * rowsLensArr);
void printTwoDemArr(int ** ptrsArr, int countOfRows, int * rowsLensArr);
void freeTwoDemArr(int ** ptrsArr, int countOfRows);

int main()
{
    int countOfRows = getValidatedIntInput("Insert count of rows: ", 0, 100);
    int * ptrsArr[countOfRows];
    int rowsLensArr[countOfRows];

    initTwoDemArr(ptrsArr, countOfRows, rowsLensArr);
    printf("Your two dimensional array: \n");
    printTwoDemArr(ptrsArr, countOfRows, rowsLensArr);

    int * newPtrsArr[countOfRows];
    removeElFromArray(newPtrsArr, ptrsArr, 2, countOfRows, rowsLensArr);
    printf("New two dimensional array: \n");
    printTwoDemArr(ptrsArr, countOfRows, rowsLensArr);
    
    freeTwoDemArr(ptrsArr, countOfRows);
    freeTwoDemArr(newPtrsArr, countOfRows);
    
    return 0;
}

void removeElFromArray(int ** newArr, int ** arr, int k, int countOfRows, int * rowLensArr)
{
    for (int  i = 0; i < countOfRows; i++)
    {
        int elementsToCopy;
        if(rowLensArr[i] < k)
        {
            elementsToCopy = rowLensArr[i];
        }
        else
        {
            elementsToCopy = k;
            rowLensArr[i] = k;
        }
        newArr[i] = malloc(sizeof(int) * elementsToCopy);
        memcpy(newArr[i], arr[i], sizeof(int) * elementsToCopy);
    }
}

void freeTwoDemArr(int ** ptrsArr, int countOfRows)
{
    for (int i = 0; i < countOfRows; i++)
    {
        free(ptrsArr[i]);
    }      
}

void printTwoDemArr(int ** ptrsArr, int countOfRows, int * rowsLensArr)
{
    for (int i = 0; i < countOfRows; i++)
    {
        for (int j = 0; j < rowsLensArr[i]; j++)
        {
            printf("%d\t", ptrsArr[i][j]);
        }
        printf("\n"); 
    }    
}

void initTwoDemArr(int ** ptrsArr, int countOfRows, int * rowsLensArr)
{
    for (int i = 0; i < countOfRows; i++)
    {
        printf("Insert values for row #%d \n", i);
        int countOfEls = 0;
        ptrsArr[i] = malloc(sizeof(int*));
        int input;
        while (1)
        {
            input = getValidatedIntInput("Input any int val: ", -1, 100);
            countOfEls++;
            ptrsArr[i] = realloc(ptrsArr[i], sizeof(int) * (countOfEls));
            if (ptrsArr[i] == NULL) {
                printf("Reallocation Failed\n");
                exit(0);
            }
            ptrsArr[i][countOfEls - 1] = input;
            if(input == -1) break;
        }
        
        rowsLensArr[i] = countOfEls;
            
    }
}
