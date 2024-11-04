#include <stdio.h>
// 3. Найти в матрице первую строку, все элементы которой упорядочены по возрастанию.
// Изменить упорядоченность элементов этой строки на обратную.
#include <stdio.h>
#include "validators.h"
#include "utils.h"

int isRowRising(int countOfRows,int countOfcols, int arr[countOfRows][countOfcols]);
void reverseRow(int countOfCols, int rowNumber, int arr[countOfCols][countOfCols]);
int main()
{
    int countOfRows = getValidatedIntInput("Input count of rows(1 to 100): ", 1, 100);
    int countOfCols = getValidatedIntInput("Input count of columns(1 to 100): ", 1, 100); 
    int matrix[countOfRows][countOfCols];
    char validChars[] = {'M', 'R'};
    char initMode = getValidatedCharInput("Choose type of matrix initialization manual(M) or with random values(R): ", validChars, 2);
    fulfillMatrix(countOfRows, countOfCols, matrix, initMode);
    // printf("isRowRising = %d", isRowRising(countOfRows, countOfCols, matrix));
    reverseRow(countOfCols, isRowRising(countOfRows, countOfCols, matrix), matrix);
    printArray(countOfRows, countOfCols, matrix);
    return 0;
}

int isRowRising(int countOfCols, int countOfRows, int arr[countOfRows][countOfCols])
{
    for (int i = 0; i < countOfRows; i++)
    {
        int isRowRising = 1;
        for (int j = 0; j < countOfCols - 1; j++)
        {
            if(arr[i][j] >= arr[i][j+1])
            {
                isRowRising = 0;
            }
        }
        if(isRowRising) return i;
    }
 
}

void reverseRow(int countOfCols, int rowNumber, int arr[countOfCols][countOfCols])
{
    for (int i = 0; i < countOfCols / 2; i++)
    {
        int temp = arr[rowNumber][i];
        arr[rowNumber][i] = arr[rowNumber][countOfCols - 1 - i];
        arr[rowNumber][countOfCols - 1 - i] = temp;
    }
}