#include <stdlib.h>
#include <stdio.h>
#include "validators.h"
#include "queue.h"



Queue * NewQueue(int maxLen) {
    if (maxLen < 1) {
        printf("Incorrect max len");
        return NULL;
    }
    Queue *newQueue = malloc(sizeof(Queue));
    newQueue->Head = NULL;
    newQueue->Back = NULL;
    newQueue->Maxlen = maxLen;
    newQueue->Len = 0;
    return newQueue;
}

void Enqueue(Queue * q, char v) {
    if(q->Len >= q->Maxlen) return;
    Node * newNode = malloc(sizeof(Node));
    newNode->Val = v;
    newNode->Next = NULL;
    if(q->Len < 1) {
        q->Head = newNode;
        q->Back = newNode;
        q->Len++;
        return;
    } 
    q->Back->Next = newNode;
    q->Back = newNode;
    q->Len++;
}

Node * Dequeu(Queue *q) {
    if (q->Len < 1) return NULL;
    Node * head = q->Head;
    if (head->Next) {
        q->Head = head->Next;
        q->Len--;
        return head;
    }
    q->Head = NULL;
    q->Back = NULL;
    q->Len--;
    return head;
}

void PrintQueue(Queue * q) {
    int len = q->Len;
    Node * curr = q->Head;
    while(len > 0) {
        printf("%c", curr->Val);
        curr=curr->Next;
        len--;
    }
    printf("\n");
}

void FreeQueue(Queue * q) {
    Node * curr = q->Head;
    while(curr != NULL) {
        Node *tmp = curr->Next;
        free(curr);
        curr=tmp;
    }
    free(q);
}

void FillQueue(Queue * q) {
    int len = q->Maxlen;
    int counter = 0;
    while(len > 0) {
        Enqueue(q, getValidatedCharInputE("Input any char value: ", NULL, 0));
        if(++counter > 3) {
            printf("The left symbol: %c\n", q->Head->Val);
        }
        len--;
    }
}