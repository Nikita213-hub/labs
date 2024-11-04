#include <stdio.h>
#include "utils.h"
#include "validators.h"

int sumOfSomeEls(int countOfRows, int countOfCols, int arr[countOfRows][countOfCols]);

int main()
{

    int countOfRows = getValidatedIntInput("Input count of rows(1 to 100): ", 1, 100);
    int countOfCols = getValidatedIntInput("Input count of columns(1 to 100): ", 1, 100); 
    int matrix[countOfRows][countOfCols];    
    char validChars[] = {'M', 'R'};
    char initMode = getValidatedCharInput("Choose type of matrix initialization manual(M) or with random values(R): ", validChars, 2);
    fulfillMatrix(countOfRows, countOfCols, matrix, initMode);
    printArray(countOfRows, countOfCols, matrix);
    printf("sum = %d", sumOfSomeEls(countOfRows, countOfCols, matrix));
    return 0;
}

int sumOfSomeEls(int countOfRows, int countOfCols, int arr[countOfRows][countOfCols])
{
    int sumOfEls = 0;
    int startInd = 0;
    int endInd = countOfCols - 1;
    for (int i = countOfRows -1; i >= 0; i--)
    {
        for (int j = startInd; j < endInd + 1; j++)
        {
            sumOfEls += arr[i][j];
            if(startInd > endInd)
            {
                return sumOfEls;
            }
        }
        startInd++;
        endInd--;
    }
    return sumOfEls;
}