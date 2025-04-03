#include <stdio.h>
#include <stdlib.h>
#include "validators.h"
#include "stack.h"
#include "textStack.h"
#include "RPNalg.h"
#include "util.h"
#include "txtReaderWriter.h"
#include "Errors.h"

int sumStack(Stack * stack) {
    Node*temp = stack->Head;
    int sum = 0;
    while(temp->Prev) {
        sum+=temp->Val;
        printf("Val summed: %d\n", temp->Val);
        temp = temp->Prev;
    }
    return sum;
}

Stack * mergeStacks(Stack * s1, Stack * s2) {
    Node * currNodeS1 = s1->Head;
    Node * currNodeS2 = s2->Head;
    Node * mergedStackHead = malloc(sizeof(Node));
    Stack * mergedStack = malloc(sizeof(Stack));
    mergedStack->Head = mergedStackHead;
    mergedStack->MaxLen = s1->Len + s2->Len;
    while(mergedStack->Len < mergedStack->MaxLen) {
        if(currNodeS1->Val <= currNodeS2->Val) {
            Push(currNodeS1->Val, mergedStack);
            currNodeS1 = currNodeS1->Prev;
            if(mergedStack->Len == mergedStack->MaxLen-1){
                Push(currNodeS2->Val, mergedStack);
            }
            continue;
        }
        Push(currNodeS2->Val, mergedStack);
        currNodeS2 = currNodeS2->Prev;
        if(mergedStack->Len == mergedStack->MaxLen-1){
                Push(currNodeS1->Val, mergedStack);
        }
    }
    return mergedStack;
}

void ptrI(char * str) {
    while(*str != '\0'){
        printf("%c", *str);
        str++;
    }
}


int main() {
    char validChars[3] = {'1', '2', '3'};
    char choice = getValidatedCharInput("Choose the task:\n 1 - first task,\n 2 - second task,\n 3 - third task\n ", validChars, 3);
    switch (choice)
    {
    case '1':
        Stack * stack = newStack();
        FillStack(stack);
        printf("Sum of stack els = %d\n", sumStack(stack));
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
        char line[1024];
        char * postfixStr = malloc(sizeof(char) * 1024);
        int currLine = 0;
        while(readLine(fpExpr, line)) {
            currLine++;
            errorsList * errors = convertInfixToPostfix(line, postfixStr, currLine);
            if (isErrors(errors)) {
                printErrors(errors);
                continue;
            }
            float t = calcWithRPN(postfixStr);
            writeLine(fpRes, t);
        }
        free(postfixStr);
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