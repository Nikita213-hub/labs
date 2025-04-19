#ifndef QUEUE_H
#define QUEUE_H
typedef struct Node{
    char Val;
    struct Node *Next;
}Node;

typedef struct {
    int Maxlen;
    int Len;
    struct Node *Head;
    struct Node *Back;
}Queue;

Queue * NewQueue(int maxLen);
void Enqueue(Queue * q, char v);
Node * Dequeu(Queue *q);
void PrintQueue(Queue * q);
void FreeQueue(Queue * q);
void FillQueue(Queue * q);
#endif