#ifndef STACK_H
#define STACK_H
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
    DEFAULT = 0,
    INCREASING,
    DECREASING,
} fillingType;
Stack * newStack();
void Push(int val, Stack * stack);
Node * Pop(Stack * stack);
void PrintStack(Stack * stack);
void FillStack(Stack * stack);
void freeStack(Stack * stack);
#endif