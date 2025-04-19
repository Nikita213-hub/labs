#ifndef DEQUEUE_H
#define DEQUEUE_H
typedef struct DeqNode {
    char Val;
    struct DeqNode* Next;
    struct DeqNode* Prev;
} DeqNode;

typedef struct {
    int Maxlen;
    int Len;
    struct DeqNode* Head;
    struct DeqNode* Tail;
} Dequeue;

Dequeue* NewDequeue(int maxLen);
void EnqueueFront(Dequeue* dq, char v);
void EnqueueBack(Dequeue* dq, char v);
DeqNode* DequeueFront(Dequeue* dq);
DeqNode* DequeueBack(Dequeue* dq);
void PrintDequeue(Dequeue* dq);
void FreeDequeue(Dequeue* dq);
void FillDequeue(Dequeue* dq);
#endif