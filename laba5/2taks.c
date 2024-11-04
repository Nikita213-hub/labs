#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "validators.h"

int main()
{
    int countOfRows = getValidatedIntInput("Insert count of rows: ", 0, 100);
    int * ptrsArr[countOfRows];
    int rowsLensArr[countOfRows];
    for (int i = 0; i < countOfRows; i++)
    {
        printf("Insert values for row #%d \n", i);
        int countOfEls = 0;
        ptrsArr[i] = malloc(sizeof(int));
        int input;
        while (1)
        {
            input = getValidatedIntInput("Input any int val: ", 0, 100);
            countOfEls++;
            ptrsArr[i] = realloc(ptrsArr[i], sizeof(int) * (countOfEls));
            if (ptrsArr[i] == NULL) {
                printf("Reallocation Failed\n");
                exit(0);
            }
            ptrsArr[i][countOfEls - 1] = input;
            if(input == 1) break;
        }
        
        rowsLensArr[i] = countOfEls;
            
    }

    for (int i = 0; i < countOfRows; i++)
    {
        for (int j = 0; j < rowsLensArr[i]; j++)
        {
            printf(" %d ", ptrsArr[i][j]);
        }
        printf("\n"); 
        free(ptrsArr[i]);
    }
    
    
    return 0;
}































