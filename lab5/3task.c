#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "utils.h"
#include "validators.h"

void initMatrix(int *** matrix, int countOfRows, int countOfCols, int * rowsLensArr, char initMode);
void printMatrix(int ** matrix, int countOfRows, int * rowsLensArr);
void deleteSomeElsFromMtrx(int *** newMatrix, int *** matrix, int countOfRows, int countOfCols, int * rowsLensArr);
void removeNegativeColumns(int ***newMatrix, int **matrix, int countOfRows, int countOfCols, int *rowLensArr);
void freeMatrix(int ** matrix, int countOfRows);

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
    int ** newMatrix;
    // deleteSomeElsFromMtrx(&newMatrix, &matrix, countOfRows, countOfCols, rowsLensArr);
    removeNegativeColumns(&newMatrix, matrix, countOfRows, countOfCols, rowsLensArr);
    printf("new matrix: \n");
    printMatrix(newMatrix, countOfRows, rowsLensArr);
    freeMatrix(matrix, countOfRows);
}

void removeNegativeColumns(int ***newMatrix, int **matrix, int countOfRows, int countOfCols, int *rowLensArr)
{
    int keepCols[countOfCols];
    for (int j = 0; j < countOfCols; j++) {
        keepCols[j] = 0;
        for (int i = 0; i < countOfRows; i++) {
            if (j < rowLensArr[i] && matrix[i][j] >= 0) {
                keepCols[j] = 1;
                break;
            }
        }
    }

    *newMatrix = malloc(sizeof(int *) * countOfRows);

    for (int i = 0; i < countOfRows; i++) {
        int newCols = 0;

        for (int j = 0; j < countOfCols; j++) {
            if (keepCols[j]) {
                newCols++;
            }
        }

        (*newMatrix)[i] = malloc(sizeof(int) * newCols);
        int currentCol = 0;
        for (int j = 0; j < countOfCols; j++) {
            if (keepCols[j]) {
                (*newMatrix)[i][currentCol++] = matrix[i][j];
            }
        }
        rowLensArr[i] = newCols;
    }
}


// void deleteSomeElsFromMtrx(int *** newMatrix, int *** matrix, int countOfRows, int countOfCols)
// {
//     *newMatrix = malloc(sizeof(int*) * countOfRows);
//     int elsToDel = 0;
//     for (int i = 0; i < countOfRows; i++)
//     {
//         (*newMatrix)[i] = malloc(sizeof(int) * (countOfCols - elsToDel));
//         memcpy((*newMatrix)[i]+elsToDel, (*matrix)[i]+elsToDel, sizeof(int)*(countOfCols-elsToDel));
//         elsToDel++;
//     }
// }


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


void deleteSomeElsFromMtrx(int ***newMatrix, int ***matrix, int countOfRows, int countOfCols, int * rowsLensArr)
{
    *newMatrix = malloc(sizeof(int*) * countOfRows);

    int elsToDel = 0;

    for (int i = 0; i < countOfRows; i++)
    {
        (*newMatrix)[i] = malloc(sizeof(int) * (countOfCols - elsToDel));
        rowsLensArr[i] -= elsToDel;
        for (int j = elsToDel; j < countOfCols; j++) 
        {
            (*newMatrix)[i][j - elsToDel] = (*matrix)[i][j]; 
        }
        elsToDel++;
    }
}