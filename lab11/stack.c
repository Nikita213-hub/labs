#include <stdio.h>
#include <stdlib.h>
#include "validators.h"

typedef struct Node {
    int Val;
    struct Node *Next;
    struct Node *Prev;
} Node;

typedef struct {
    int Len;
    int MaxLen;
    Node* Head;
}Stack;

typedef enum {
    INCREASING = 0,
    DECREASING,
    CHAOTIC,
} fillingType;

Stack * newStack() {
    Node * head = malloc(sizeof(Node));
    Stack * stack = malloc(sizeof(Stack));
    stack->Head = head;
    stack->Head->Prev = NULL;
    stack->Len = 0;
    stack->MaxLen = getValidatedIntInput("Input max len of stack: ");
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
    if(stack->Len >= stack->MaxLen) {
        printf("Error: U have reached max len of stack\n");
        return;
    }
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
    free(temp);
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
    switch (ft)
    {
    case INCREASING:
        for(int i = 0; i < stack->MaxLen; i++) {
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
        for(int i = 0; i < stack->MaxLen; i++) {
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
        for(int i = 0; i < stack->MaxLen; i++) {
            int val = getValidatedIntInput("Insert int value: ");
            Push(val, stack);
        }
        break;
    default:
        break;
    }
}