#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "validators.h"

void removeElFromArray(int **newArr, int **arr, int k, int countOfRows, int *rowLensArr);
void initTwoDemArr(int ***ptrsArr, int countOfRows, int *rowsLensArr);
void printTwoDemArr(int **ptrsArr, int countOfRows, int *rowsLensArr);
void freeTwoDemArr(int **ptrsArr, int countOfRows);

int main()
{
    int countOfRows = getAwesomeValidatedIntInput("Insert count of rows: ", 0, 100);
    int **ptrsArr = malloc(sizeof(int *) * countOfRows); 
    int rowsLensArr[countOfRows]; 


    initTwoDemArr(&ptrsArr, countOfRows, rowsLensArr);
    printf("ur two dimensional arr: \n");
    printTwoDemArr(ptrsArr, countOfRows, rowsLensArr);

    int **newPtrsArr = malloc(sizeof(int *) * countOfRows); 

    int k = getAwesomeValidatedIntInput("Input k value: ", 1, 100);
    removeElFromArray(newPtrsArr, ptrsArr, k, countOfRows, rowsLensArr);
    printf("new two dimensional arr: \n");
    printTwoDemArr(newPtrsArr, countOfRows, rowsLensArr);

    freeTwoDemArr(ptrsArr, countOfRows);
    freeTwoDemArr(newPtrsArr, countOfRows);

    return 0;
}

void removeElFromArray(int **newArr, int **arr, int k, int countOfRows, int *rowLensArr)
{
    for (int i = 0; i < countOfRows; i++)
    {
        int elementsToCopy;
        if (rowLensArr[i] < k)
        {
            elementsToCopy = rowLensArr[i];
        }
        else
        {
            elementsToCopy = k;
            rowLensArr[i] = k;
        }
        newArr[i] = malloc(sizeof(int) * elementsToCopy);
        // memcpy(newArr[i], arr[i], sizeof(int) * elementsToCopy);
        for (int j = 0; j < elementsToCopy; j++) {
            newArr[i][j] = arr[i][j];
        }
    }
}

void freeTwoDemArr(int **ptrsArr, int countOfRows)
{
    for (int i = 0; i < countOfRows; i++)
    {
        free(ptrsArr[i]);
    }
    free(ptrsArr);
}

void printTwoDemArr(int **ptrsArr, int countOfRows, int *rowsLensArr)
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

void initTwoDemArr(int ***ptrsArr, int countOfRows, int *rowsLensArr)
{
    for (int i = 0; i < countOfRows; i++)
    {
        printf("Insert values for row #%d \n", i);
        int countOfEls = 0;
        (*ptrsArr)[i] = malloc(sizeof(int)); 

        int input;
        while (1)
        {
            input = getAwesomeValidatedIntInput("Input any int val: ", -1, 100);
            countOfEls++;
            (*ptrsArr)[i] = realloc((*ptrsArr)[i], sizeof(int) * countOfEls);

            (*ptrsArr)[i][countOfEls - 1] = input;
            if (input == -1)
            {
                break;
            }
        }

        rowsLensArr[i] = countOfEls;
    }
}
