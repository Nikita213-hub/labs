#include <stdio.h>
#include <stdlib.h>
#include "validators.h"
#include "stack.h"
#include "textStack.h"
#include "RPNalg.h"

// int sumStack(Stack * stack) {
//     Node*temp = stack->Head;
//     int sum = 0;
//     while(temp->Prev) {
//         sum+=temp->Val;
//         printf("Val summed: %d\n", temp->Val);
//         temp = temp->Prev;
//     }
//     return sum;
// }

// Stack * mergeStacks(Stack * s1, Stack * s2) {
//     Node * currNodeS1 = s1->Head;
//     Node * currNodeS2 = s2->Head;
//     Node * mergedStackHead = malloc(sizeof(Node));
//     Stack * mergedStack = malloc(sizeof(Stack));
//     mergedStack->Head = mergedStackHead;
//     mergedStack->MaxLen = s1->Len + s2->Len;
//     while(mergedStack->Len < mergedStack->MaxLen) {
//         if(currNodeS1->Val <= currNodeS2->Val) {
//             Push(currNodeS1->Val, mergedStack);
//             currNodeS1 = currNodeS1->Prev;
//             if(mergedStack->Len == mergedStack->MaxLen-1){
//                 Push(currNodeS2->Val, mergedStack);
//             }
//             continue;
//         }
//         Push(currNodeS2->Val, mergedStack);
//         currNodeS2 = currNodeS2->Prev;
//         if(mergedStack->Len == mergedStack->MaxLen-1){
//                 Push(currNodeS1->Val, mergedStack);
//         }
//     }
//     return mergedStack;
// }

void ptrI(char * str) {
    while(*str != '\0'){
        printf("%c", *str);
        str++;
    }
}


int main() {
    // Stack * stacks1 = newStack();
    // FillStack(stacks1);
    // Stack * stacks2 = newStack();
    // FillStack(stacks2);
    // Stack * mergedStack = mergeStacks(stacks1, stacks2);
    // PrintStack(mergedStack);
    //printf("Sum of stack els = %d\n", sumStack(stack));

    char * infixStr = "((15.5 / 2.5) + (3.6 * 2)) - (8.4 / 1.4)\0";
    char * postfixStr = malloc(sizeof(char) * 1024);
    convertInfixToPostfix(infixStr, postfixStr);
    printf("%s\n", postfixStr);
    float t = calcWithRPN(postfixStr);
    printf("%f\n", t);
}