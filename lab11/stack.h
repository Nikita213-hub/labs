#ifndef STACK_H
#define STACK_H
typedef struct Node {
    int Val;
    struct Node *Next;
    struct Node *Prev;
} Node;

typedef struct {
    int Len;
    Node* Head;
}Stack;
typedef enum {
    INCREASING = 0,
    DECREASING,
    CHAOTIC,
} fillingType;
Stack * newStack();
void Push(int val, Stack * stack);
Node * Pop(Stack * stack);
void PrintStack(Stack * stack);
void FillStack(Stack * stack);
void freeStack(Stack * stack);

int sumStack(Stack * stack);
Stack * mergeStacks(Stack * s1, Stack * s2);

#endif