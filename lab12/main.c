#include <stdio.h>
#include <stdlib.h>
#include "validators.h"
#include "queue.h"
#include "Dequeue.h"
#include "intQueue.h"
#include "parseStr.h"

int main() {
    int taskChoice = -1;
    while((taskChoice=getValidatedIntInput("Menu: \n Insert queue - Press 1 \n Insert dequeue - Press 2 \n Parse string - Press 3 \n Exit - Press 0 \nInput number of a task: ")) != 0) {
        switch (taskChoice)
        {
        case 1:
            Queue * q = NewQueue(getValidatedIntInput("Input max len of the queue: "));
            FillQueue(q);
            PrintQueue(q);
            FreeQueue(q);
            break;
        case 2:
            Dequeue * dq = NewDequeue(getValidatedIntInput("Input max len of the dequeue: "));
            FillDequeue(dq);
            PrintDequeue(dq);
            FreeDequeue(dq);
            break;
        case 3:
            char * str = getString();
            IntQueue * iq = extractNumsFromStr(str);
            PrintIntQueue(iq);
            printf("Sum of queue's els = %d\n", sumIntQueue(iq));
            FreeIntQueue(iq);
            break;
        case 0:
            return 0;
        default:
            printf("Invalid command\n");
            break;
        }
    }
}