#include <stdio.h>
#include <stdlib.h>
#include "validators.h"
#include "stack.h"

Stack * newStack() {
    Node * head = malloc(sizeof(Node));
    Stack * stack = malloc(sizeof(Stack));
    stack->Head = head;
    stack->Head->Prev = NULL;
    stack->Len = 0;
    return stack;
}

void freeStack(Stack * stack) {
    Node * el = stack->Head;
    while(el != NULL) {
        el = el->Prev;
        free(el);
    }
    free(stack);
    return;
}

void Push(int val, Stack * stack) {
    Node * newNode = malloc(sizeof(Node));
    newNode->Val = val;
    Node *temp = stack->Head;
    stack->Head = newNode;
    stack->Head->Prev = temp;
    stack->Len++;
}

Node * Pop(Stack * stack) {
    if(stack->Head->Prev == NULL) {
        return NULL;
    }
    Node*temp = stack->Head;
    stack->Head = stack->Head->Prev;
    stack->Head->Next = NULL;
    stack->Len--;
    return temp;
}

void PrintStack(Stack * stack) {
    Node*temp = stack->Head;
    while(temp->Prev) {
        printf("%d\n", temp->Val);
        temp = temp->Prev;
    }
}

void FillStack(Stack * stack) {
    int ftInt = getValidatedIntInput("Choose stack type:\n 0 - increasing,\n 1 - decreasing,\n 2 - chaotic\nEnter num: ");
    fillingType ft = ftInt;
    int count = getValidatedIntInput("How many elements do you want to add? ");
    switch (ft)
    {
    case INCREASING:
        for(int i = 0; i < count; i++) {
            int val = getValidatedIntInput("Insert int value: ");
            if(val < stack->Head->Val && stack->Len > 0) {
                printf("Error: Each value must be bigger than th prev one\n");
                i--;
                continue;
            }
            Push(val, stack);
        }
        break;
    case DECREASING:
        for(int i = 0; i < count; i++) {
            int val = getValidatedIntInput("Insert int value: ");
            if(val > stack->Head->Val && stack->Len > 0) {
                printf("Error: Each value must be smaller than th prev one\n");
                i--;
                continue;
            }
            Push(val, stack);
        }
        break;
    case CHAOTIC:
        for(int i = 0; i < count; i++) {
            int val = getValidatedIntInput("Insert int value: ");
            Push(val, stack);
        }
        break;
    default:
        break;
    }
}

int sumStack(Stack * stack) {
    Node*temp = Pop(stack);
    int sum = 0;
    while(temp != NULL) {
        sum+=temp->Val;
        printf("Val summed: %d\n", temp->Val);
        free(temp);
        temp = Pop(stack);
    }
    return sum;
}

Stack * mergeStacks(Stack * s1, Stack * s2) {
    Stack * result = newStack();
    Stack * tempStack = newStack();

    // Merge s1 and s2 into tempStack in reverse sorted order
    while (s1->Len > 0 && s2->Len > 0) {
        if (s1->Head->Val >= s2->Head->Val) {
            Push(s1->Head->Val, tempStack);
            Node *v = Pop(s1);
            free(v);
        } else {
            Push(s2->Head->Val, tempStack);
            Node *v = Pop(s2);
            free(v);
        }
    }

    // Add remaining elements from s1 or s2
    while (s1->Len > 0) {
        Push(s1->Head->Val, tempStack);
        Pop(s1);
    }
    while (s2->Len > 0) {
        Push(s2->Head->Val, tempStack);
        Pop(s2);
    }

    // Reverse tempStack into result to get correct order
    while (tempStack->Len > 0) {
        Push(tempStack->Head->Val, result);
        Pop(tempStack);
    }

    freeStack(tempStack);
    return result;
}