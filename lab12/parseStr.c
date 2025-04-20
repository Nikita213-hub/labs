#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "intQueue.h"
#include "validators.h"


char * getString() {
    char * str = malloc(sizeof(char) * 256);
    fgets(str, 256, stdin);
    str[strcspn(str, "\n")] = '\0'; 
    return str;
}

int isNum(char * el) {
    int isNum = 1;
    while(*el) {
        if(isdigit(*el)) {
            el++;
            continue;
        }
        isNum = 0;
        break;
    }
    return isNum;
}

IntQueue * extractNumsFromStr(char * str) {
    if (!str) return NULL;
    int num_count = 0;
    int in_number = 0;
    const char* p = str;
    while (*p) {
        if (isdigit(*p)) {
            if (!in_number) {
                num_count++;
                in_number = 1;
            }
        } else {
            in_number = 0;
        }
        p++;
    }
    IntQueue* q = NewIntQueue(num_count);
    if (!q) return NULL;

    p = str;
    in_number = 0;
    const char* num_start = NULL;

    while (*p) {
        if (isdigit(*p)) {
            if (!in_number) {
                num_start = p;
                in_number = 1;
            }
        } else {
            if (in_number) {
                int len = p - num_start;
                char* num_str = malloc(len + 1);
                memcpy(num_str, num_start, len);
                num_str[len] = '\0';
                EnqueueInt(q, atoi(num_str));
                free(num_str);
                in_number = 0;
            }
        }
        p++;
    }
    if (in_number) {
        int len = p - num_start;
        char* num_str = malloc(len + 1);
        memcpy(num_str, num_start, len);
        num_str[len] = '\0';
        EnqueueInt(q, atoi(num_str));
        free(num_str);
    }
    return q;
}