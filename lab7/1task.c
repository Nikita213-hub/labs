#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main()
{
    int maxWordLen = 0, maxWordInd = 0;
    int currWordLen = 0, currWordInd = 0;
    int strLength = 0;
    int strIndex = 0;
    char * str = NULL;
    char a;
    bool isDivided = false;
    while (1)
    {
        if((a = getchar()) == '\n')
        {
            
            if(currWordLen > maxWordLen)
            {
                maxWordLen = currWordLen;
                maxWordInd = currWordInd;
            }
            break;
        }
        strLength++;
        str = realloc(str, strLength * sizeof(char));
        if(a == ' ' && !isDivided)
        {
            if(strIndex > 0) {

                if(currWordLen > maxWordLen)
                {
                    maxWordLen = currWordLen;
                    maxWordInd = currWordInd;
                }
                isDivided = true;
                str[strIndex++] = a;
                currWordInd = strIndex;
                currWordLen = 0;
            }
        } else if (a == ' ' && isDivided) {
            continue;
        } else {
            currWordLen++;
            isDivided = false;
            str[strIndex++] = a;
        }
    }
    
    for (int i = maxWordInd; i < maxWordInd + maxWordLen; i++)
    {
        putchar(str[i]);
    }
    
}