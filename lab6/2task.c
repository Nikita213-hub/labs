#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "validators.h"
void initMatrix(int *** matrix, int countOfRows, int countOfCols, int * rowsLensArr, char initMode)
{
    *matrix = malloc(sizeof(int*) * countOfRows);
    for (int i = 0; i < countOfRows; i++)
    {
        (*matrix)[i] = malloc(sizeof(int) * countOfCols);
        rowsLensArr[i] = countOfCols;
        if(toupper(initMode) == 'M')
        {
            for (int j = 0; j < countOfCols; j++)
            {
                char message[30];
                sprintf(message, "Insert value of matrix[%d][%d]: ", i, j);
                (*matrix)[i][j] = getAwesomeValidatedIntInput(message, -100, 100);
            }
        }
        else
        {
            for (int j = 0; j < countOfCols; j++)
            {
                (*matrix)[i][j] = rand() % 201-101;
            }
        }        
        
    }
    
}

void freeMatrix(int ** matrix, int countOfRows)
{
    for (int i = 0; i < countOfRows; i++)
    {
        free(matrix[i]);
    } 
    free(matrix);
}

void printMatrix(int ** matrix, int countOfRows, int * rowsLensArr)
{
    for (int i = 0; i < countOfRows; i++) {
        for (int j = 0; j < rowsLensArr[i]; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
}


void swap(int * a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void shellSortMatrix(int *** matrix, int countOfRows, int CountOfCols)
{
    int * rowsSums = malloc(countOfRows * sizeof(int));
    for (int i = 0; i < countOfRows; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < CountOfCols; j++)
        {
            if(j % 2 == 0)
            {
                rowSum += (*matrix)[i][j];
            }
        }
        rowsSums[i] = rowSum;
    }
    
    int gap = countOfRows / 2;
    while (gap > 0) {
        for (int i = 0; i < countOfRows - gap; i++) {
            for (int j = i + gap; j < countOfRows; j++) {
                if (rowsSums[i] < rowsSums[j]) {

                    for (int k = 0; k < CountOfCols; k++) {
                        swap(&(*matrix)[i][k], &(*matrix)[j][k]);
                    }

                    swap(&rowsSums[i], &rowsSums[j]);
                }
            }
        }
        gap /= 2;
    }
}

int main()
{
    srand(time(NULL));
    int countOfRows = getAwesomeValidatedIntInput("Input count of rows: ", 1, 100);
    int countOfCols = getAwesomeValidatedIntInput("Input count of cols: ", 1, 100);
    char validChars[2] = {'M', 'R'};
    char initMode = getValidatedCharInput("Choose initialization type manual (M) or with random values (R): ", validChars, 2);
    int rowsLensArr[countOfRows];
    int ** matrix;
    initMatrix(&matrix, countOfRows, countOfCols, rowsLensArr, initMode);
    printf("ur matrix: \n");
    printMatrix(matrix, countOfRows, rowsLensArr);
    shellSortMatrix(&matrix, countOfRows, countOfCols);
    printf("matrix after sorting: \n");
    printMatrix(matrix, countOfRows, rowsLensArr);
}