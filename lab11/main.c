#include <stdio.h>
#include <stdlib.h>
#include "validators.h"
#include "stack.h"
#include "textStack.h"
#include "RPNalg.h"
#include "util.h"
#include "txtReaderWriter.h"
#include "Errors.h"
#include "RPN.h"


int main() {
    char validChars[3] = {'1', '2', '3'};
    char choice = getValidatedCharInput("Choose the task:\n 1 - first task,\n 2 - second task,\n 3 - third task\n ", validChars, 3);
    switch (choice)
    {
    case '1':
        Stack * stack = newStack();
        FillStack(stack);
        printf("Sum of stack els = %d\n", sumStack(stack));
        freeStack(stack);
        break;
    case '2':
        Stack * stacks1 = newStack();
        FillStack(stacks1);
        Stack * stacks2 = newStack();
        FillStack(stacks2);
        Stack * mergedStack = mergeStacks(stacks1, stacks2);
        PrintStack(mergedStack);
        break;
    case '3':
        char* exprFileName = malloc(sizeof(char)*256);
        char* resFileName = malloc(sizeof(char)*256);
        printf("Insert expressions file name: ");
        getFileName(exprFileName);
        printf("\n");
        printf("Insert res file name: ");
        getFileName(resFileName);
        FILE * fpExpr= fopen(exprFileName, "r");
        FILE * fpRes= fopen(resFileName, "w+");
        if (fpExpr == NULL || fpRes == NULL) {
            printf("Error occured when opening file\n");
            return 1;
        }
        
        processExpressions(fpExpr, fpRes);

        free(resFileName);
        free(exprFileName);
        fclose(fpExpr);
        fclose(fpRes);
        break;
    default:
        printf("Error: incorect choice");
        break;
    }
}