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
    int count = 0;
    int in_token = 0;


    const char* p = str;
    while (*p) {
        if (isspace(*p)) {
            in_token = 0;
        } else {
            if (!in_token) (count)++;
            in_token = 1;
        }
        p++;
    }
    IntQueue * q = NewIntQueue(count);
    p = str;
    while (*p) {
        while (*p && isspace(*p)) p++;
        if (!*p) break;
        const char* start = p;
        while (*p && !isspace(*p)) p++;
        int len = p - start;

        char* token = malloc(sizeof(char) * (len + 1));
        if (!token) {
            return NULL;
        }
        memcpy(token, start, len);
        token[len] = '\0';
        if(isNum(token)) {
            EnqueueInt(q, atoi(token));
        }
    }
    return q;
}