#include "RPN.h"
#include "txtReaderWriter.h"
#include "RPNalg.h"
#include "Errors.h"
#include "textStack.h"
#include <stdio.h>
#include <stdlib.h>

void processExpressions(FILE *fpExpr, FILE *fpRes) {
    char line[1024];
    char *postfixStr = malloc(sizeof(char) * 1024);
    if (postfixStr == NULL) {
        printf("Fatal: Memory allocation for postfix string failed.\n");
        return;
    }

    int currLine = 0;
    while(readLine(fpExpr, line)) {
        currLine++;
        errorsList * errors = convertInfixToPostfix(line, postfixStr, currLine);
        if (isErrors(errors)) {
            printErrors(errors);
            writeLine(fpRes, 0.0);
            freeErrors(errors);
            continue;
        }
        
        float t = calcWithRPN(postfixStr);
        writeLine(fpRes, t);
        
        freeErrors(errors);
    }
    free(postfixStr);
} 