#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "validators.h"
#include "Dequeue.h"

Dequeue* NewDequeue(int maxLen) {
    if (maxLen < 1) {
        printf("Invalid maximum length\n");
        return NULL;
    }
    Dequeue* dq = malloc(sizeof(Dequeue));
    dq->Head = dq->Tail = NULL;
    dq->Maxlen = maxLen;
    dq->Len = 0;
    return dq;
}

void EnqueueHead(Dequeue* dq, char v) {
    if (dq->Len >= dq->Maxlen) return;
    
    DeqNode* newNode = malloc(sizeof(DeqNode));
    newNode->Val = v;
    newNode->Prev = NULL;
    newNode->Next = dq->Head;

    if (dq->Len == 0) {
        dq->Tail = newNode;
    } else {
        dq->Head->Prev = newNode;
    }
    dq->Head = newNode;
    dq->Len++;
}

void EnqueueBack(Dequeue* dq, char v) {
    if (dq->Len >= dq->Maxlen) return;
    
    DeqNode* newNode = malloc(sizeof(DeqNode));
    newNode->Val = v;
    newNode->Next = NULL;
    newNode->Prev = dq->Tail;

    if (dq->Len == 0) {
        dq->Head = newNode;
    } else {
        dq->Tail->Next = newNode;
    }
    dq->Tail = newNode;
    dq->Len++;
}

DeqNode* DequeueHead(Dequeue* dq) {
    if (dq->Len == 0) return NULL;
    
    DeqNode* head = dq->Head;
    dq->Head = head->Next;
    
    if (dq->Head) {
        dq->Head->Prev = NULL;
    } else {
        dq->Tail = NULL;
    }
    
    dq->Len--;
    head->Next = NULL;
    return head;
}

DeqNode* DequeueBack(Dequeue* dq) {
    if (dq->Len == 0) return NULL;
    
    DeqNode* back = dq->Tail;
    dq->Tail = back->Prev;
    
    if (dq->Tail) {
        dq->Tail->Next = NULL;
    } else {
        dq->Head = NULL;
    }
    
    dq->Len--;
    back->Prev = NULL;
    return back;
}

void PrintDequeue(Dequeue* dq) {
    DeqNode* current = dq->Head;
    while (current) {
        printf("%c ", current->Val);
        current = current->Next;
    }
    printf("\n");
}

void FreeDequeue(Dequeue* dq) {
    DeqNode* current = dq->Head;
    while (current) {
        DeqNode* temp = current;
        current = current->Next;
        free(temp);
    }
    free(dq);
}

void FillDequeue(Dequeue* dq) {
    int counter = 0;
    char input;
    
    while (1) {
        input = getValidatedCharInputE("Enter character: ", NULL, 0);
        if (input == -1) return; 
        if (counter % 2 == 0) {
            if (dq->Len >= dq->Maxlen) {
                DeqNode* removed = DequeueHead(dq); 
                free(removed);
            }
            EnqueueBack(dq, input);
        } else {
            if (dq->Len >= dq->Maxlen) {
                DeqNode* removed = DequeueBack(dq);
                free(removed);
            }
            EnqueueHead(dq, input);
        }
        printf("Deque (%d/%d): ", dq->Len, dq->Maxlen);
        PrintDequeue(dq);
        counter++;
    }
}