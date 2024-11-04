#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "validators.h"
#define ARR_SIZE 100

void combineArrays(int * risingArr, int * decreasingArr, int risingArrSize, int decreasingArrSize, int * resArr);

int main()
{
    srand(time(NULL));
    int increasingArr[ARR_SIZE];
    int decreasingArr[ARR_SIZE];
    char initMode;
    char validModes[] = {'M', 'R'};
    int customSize;
    int customSize2;
    printf("Increasing array initialization \n");
    customSize = getValidatedIntInput("How many elements u need to be in the array(int): ", 1, 100);
    initMode = getValidatedCharInput("", validModes, 1);
    initializeIntArray(initMode, increasingArr, customSize);
    printf("Decreasing array initialization \n");
    customSize2 = getValidatedIntInput("How many elements u need to be in the array(int): ", 1, 100);
    initMode = getValidatedCharInput("", validModes, 1);
    initializeIntArray(initMode, decreasingArr, customSize2);
    printf("INCREASING ARRAY: ");
    printIntArray(increasingArr, customSize);
    printf("DECREASING ARRAY: ");
    printIntArray(decreasingArr, customSize2);
    int resArr[customSize + customSize2];
    combineArrays(increasingArr, decreasingArr, customSize, customSize2, resArr);
    printf("RESULT ARRAY:  \n");
    for (int i = 0; i < customSize + customSize2; i++)
    {
        printf("%d ", resArr[i]);
    }
    
    return 0;
}

void combineArrays(int * risingArr, int * decreasingArr, int risingArrSize, int decreasingArrSize, int * resArr)
{
    int resArrSize = risingArrSize + decreasingArrSize;
    int ind = resArrSize - 1;
    int risCurrInd = risingArrSize - 1;
    int decreasCurrInd = 0;

    while (risCurrInd >= 0 && decreasCurrInd < decreasingArrSize)
    {   
        
        int max1 = risingArr[risCurrInd];
        int max2 = decreasingArr[decreasCurrInd];
        
        if (max1 > max2)
        {
            resArr[ind--] = max1;
            risCurrInd--;
        }
        else if(max1 < max2)
        {
            resArr[ind--] = max2;
            decreasCurrInd++;
        }
        else
        {
            resArr[ind--] = risingArr[risCurrInd--];
            resArr[ind--] = decreasingArr[decreasCurrInd++];
        }
    }
    while (risCurrInd >= 0)
    {
        resArr[ind--] = risingArr[risCurrInd--];
    }

    while (decreasCurrInd < decreasingArrSize)
    {
        resArr[ind--] = decreasingArr[decreasCurrInd++];
    }
}