#ifndef STR_QUEUE_H
#define STR_QUEUE_H
typedef struct IntNode {
    int Val;
    struct IntNode* Next;
} IntNode;
typedef struct {
    int Maxlen;
    int Len;
    struct IntNode* Head;
    struct IntNode* Back;
} IntQueue;
IntQueue* NewIntQueue(int maxLen);
void EnqueueInt(IntQueue* q, int v);
IntNode* DequeuInt(IntQueue* q);
void PrintIntQueue(IntQueue* q);
void FreeIntQueue(IntQueue* q);
void FillIntQueue(IntQueue* q);
int sumIntQueue(IntQueue* q);
#endif