#include <stdlib.h>
#include <stdio.h>
#include "validators.h"
#include "intQueue.h"

IntQueue* NewIntQueue(int maxLen) {
    if (maxLen < 1) {
        printf("Incorrect max len");
        return NULL;
    }
    IntQueue* newQueue = malloc(sizeof(IntQueue));
    newQueue->Head = NULL;
    newQueue->Back = NULL;
    newQueue->Maxlen = maxLen;
    newQueue->Len = 0;
    return newQueue;
}

void EnqueueInt(IntQueue* q, int v) {
    if(q->Len >= q->Maxlen) return;
    
    IntNode* newNode = malloc(sizeof(IntNode));
    newNode->Val = v;
    newNode->Next = NULL;

    if(q->Len < 1) {
        q->Head = newNode;
        q->Back = newNode;
    } else {
        q->Back->Next = newNode;
        q->Back = newNode;
    }
    q->Len++;
}

IntNode* DequeueInt(IntQueue* q) {
    if (q->Len < 1) return NULL;
    
    IntNode* head = q->Head;
    if (head->Next) {
        q->Head = head->Next;
    } else {
        q->Head = NULL;
        q->Back = NULL;
    }
    q->Len--;
    return head;
}

void PrintIntQueue(IntQueue* q) {
    IntNode* curr = q->Head;
    printf("Queue: ");
    while(curr != NULL) {
        printf("%d, ", curr->Val);
        curr = curr->Next;
    }
    printf("\n");
}

void FreeIntQueue(IntQueue* q) {
    IntNode* curr = q->Head;
    while(curr != NULL) {
        IntNode* tmp = curr->Next;
        free(curr);
        curr = tmp;
    }
    free(q);
}

void FillIntQueue(IntQueue* q) {
    int len = q->Maxlen;
    int counter = 0;
    while(len > 0) {
        int num = getValidatedIntInput("Enter integer value: ");
        EnqueueInt(q, num);
        
        if(++counter > 3) {
            printf("Front element: %d\n", q->Head->Val);
        }
        len--;
    }
}

int sumIntQueue(IntQueue* q) {
    if (!q || q->Len == 0) return 0;
    
    int total = 0;
    IntNode* current = q->Head;
    
    while (current != NULL) {
        total += current->Val;
        current = current->Next;
    }
    
    return total;
}