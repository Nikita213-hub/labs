#include <stdlib.h>
#include <stdio.h>

// (2+3)*3+2

// stack: 
// postfix: 23+3*2+

// typedef struct {
//     float val;
//     Node * next;
// }Node;

// typedef struct {
//     Node * head;
//     int len;
// }NumsStack;

// NumsStack * newStack() {
//     NumsStack * newStack = malloc(sizeof(NumsStack));
//     newStack->head = malloc(sizeof(Node));
//     newStack->len = 0;
//     return newStack;
// }

// void push(float v, NumsStack * stack) {
//     Node * newNode = malloc(sizeof(Node));
//     newNode->val = v;
//     newNode->next = stack->head;
//     stack->head = newNode;
// }

// float pop(NumsStack * stack) {
//     Node* temp = stack->head;
//     stack->head = stack->head->next;
//     float poppedVal = temp->val;
//     free(temp);
//     return poppedVal;
// }


typedef struct Node{
    char val;
    struct Node * next;
}Node;

typedef struct {
    Node * head;
    int len;
}OpsStack;

OpsStack * newStack() {
    OpsStack * newStack = malloc(sizeof(OpsStack));
    newStack->head = malloc(sizeof(Node));
    newStack->len = 0;
    return newStack;
}

void printStack(OpsStack * stack) {
    Node * temp = stack->head;
    while(temp != NULL) {
        printf("%c", temp->val);
        temp = temp->next;        
    }
    printf("\n");
}

void pushOp(char v, OpsStack * stack) {
    Node * newOp = malloc(sizeof(Node));
    newOp->val = v;
    newOp->next = stack->head;
    if (stack->len < 1) {
        newOp->next = NULL;
    }
    stack->head = newOp;
    stack->len++;
}

char popOp(OpsStack * stack) {
    if(stack->len < 1) {
        return -1;
    }
    if (stack->head == NULL) {
        return -1;
    }
    //printStack(stack);
    // printStack(stack);
    Node * temp;
    if (stack->head->next == NULL) {
        temp = stack->head;

        char v = temp->val;
        stack->head = NULL;
        stack->len--;
        return v;
    } else {
        temp = stack->head;
        stack->head = temp->next;
        char poppedChar = temp->val;
        //free(temp);
        stack->len--;
        return poppedChar;
    }
}

int isNum(char val) {
    if (val >= '0' && val <= '9') {
        return 1;
    } else {
        return 0;
    }
}

Node * getHeadNode(OpsStack * stack) {
    return stack->head;
}


short getPrecedence(char op) {
    switch (op)
    {
    case '+':
    case '-':
        return 2;
        break;
    case '*':
    case '/':
        return 3;
        break;
    case '(':
        return 1;
        break;
    default:
        return -1;
    }
}


void convertInfixToPostfix(char * infix, char * postfix) {
    OpsStack * stack = newStack();
    int isPrevOp = 1;
    while(*infix != '\0') {
        if(*infix == ' ') {
            infix++;
            continue;
        } else if(isNum(*infix) || *infix=='.') {
            *postfix = *infix;
            postfix++;
            infix++;
            isPrevOp = 0;
        } else if (!isNum(*infix)) {
            if(isPrevOp && *infix == '-') {
                *postfix = *infix;
                postfix++;
                infix++;
                continue;
            }
            isPrevOp = 1;
            *postfix = ' ';
            postfix++;
            Node *headNode = stack->head;
            switch (*infix)
            {
            case '(':
                pushOp(*infix, stack);
                infix++;
                break;
            case ')':
                char popped;
                while ((popped = popOp(stack)) != '(') {
                    *postfix = popped;
                    postfix++;
                }
                isPrevOp = 0;
                infix++;
                break;
            default:
                while (stack->head != NULL && 
                    getPrecedence(*infix) <= getPrecedence(stack->head->val)) {
                    *postfix = popOp(stack);
                    postfix++;
                    *postfix = ' ';
                    postfix++;
                }
                pushOp(*infix, stack);
                infix++;
                break;
                // if (!headNode || getPrecedence(*infix) > getPrecedence(headNode->val)) {
                //     pushOp(*infix, stack);
                // } else {
                //     while(getPrecedence(*infix) < getPrecedence(headNode->val)) {
                //         *postfix = popOp(stack);
                //         postfix++;
                //     }
                //     continue;
                // }
                // break;
            }
            // if(*infix == '(') {
            //     pushOp(*infix, stack);
            // }
            // if(*infix == ')') {
            //     char popped = popOp(stack);
            //     while(popped != '(') {
            //         printf("%c", popped);
            //         *postfix = popped;
            //         postfix++;
            //         popped = popOp(stack);
            //     }
            //     continue;
            // } else if (!headNode || getPrecedence(*infix) > getPrecedence(headNode->val)) {
            //     pushOp(*infix, stack);
            // } else {
            //     while(getPrecedence(*infix) < getPrecedence(headNode->val)) {
            //         *postfix = popOp(stack);
            //         postfix++;
            //     }
            //     continue;
            // }
        }
        // infix++;
        // postfix++;
    }
    if(stack->len > 0) {
        while(stack->len > 0) {
            *postfix = popOp(stack);
            postfix++;
        }
    }
    *postfix='\0';
    free(stack);
}