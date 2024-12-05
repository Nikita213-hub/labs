#include <stdio.h>
#include <stdlib.h>
#define MAX_STR_LENGTH 100

typedef struct {
    int length;
    char * content;
} Word;

typedef struct {
    int countOfWords;
    Word * content;
} String;


String * addWordToStr(String * str, Word * word)
{
    str->content = realloc(str->content, sizeof(Word)*(str->countOfWords+1));
    str->countOfWords += 1;
    str->content[(str->countOfWords)-1] = *word;
}

int compareTwoWords(Word * w1, Word * w2)
{
    int isTheSameWord = 1;
    if(w1->length != w2->length) return 0;
    for (int i = 0; i < w1->length; i++)
    {
        if(w1->content[i] != w2->content[i]) isTheSameWord = 0;
    }
    return isTheSameWord;
}

void deleteWordFromStr(String * str, String * newStr, Word * word)
{
    int countOfWordInStr = 0;
    for (int i = 0; i < str->countOfWords; i++)
    {
        if(compareTwoWords(&str->content[i], word))
        {
            countOfWordInStr++;
        }
    }

    newStr->countOfWords = (str->countOfWords)-countOfWordInStr;
    newStr->content = realloc(newStr->content, sizeof(Word)*(newStr->countOfWords));
    int newStrInd = 0;
    for (int i = 0; i < str->countOfWords; i++)
    {
        if(compareTwoWords(&str->content[i], word))
        {
            continue;
        }
        newStr->content[newStrInd++] = str->content[i];
    }
    
    
}

void freeString(String *str) {
    if (!str || !str->content) return;
    for (int i = 0; i < str->countOfWords; i++) {
        free(str->content[i].content);
    }
    free(str->content);
    str->content = NULL;
    str->countOfWords = 0;
}

String printString(String * str)
{
    for (int i = 0; i < str->countOfWords; i++)
    {
        Word word = str->content[i];
        for (int j = 0; j < word.length; j++)
        {
            printf("%c", word.content[j]);
        }
        if(i != (str->countOfWords)-1) printf(" ");
    }
    printf("\n");
}

void inputString(String * str)
{
    int strIndex = 0;
    char inputChar;
    int isDivided = 0;
    Word currWord = {0, NULL};
    char * strD = NULL;
    while (1)
    {
        inputChar = getchar();
        if(inputChar == '\n' || inputChar == EOF)
        {
            if(currWord.length > 0)
            {
                addWordToStr(str, &currWord);
                currWord.length = 0;
                currWord.content = NULL;
                strIndex = 0;
                break;
            }
            printf("Error, u must input at least one symbol: \n");
            continue;
        }
        if(inputChar == ' ' && !isDivided)
        {
            if(strIndex > 0) {
                isDivided = 1;
                addWordToStr(str, &currWord);
                currWord.length = 0;
                currWord.content = NULL;
                strIndex = 0;
            }
        } else if (inputChar == ' ' && isDivided) {
            continue;
        } else {
            isDivided = 0;
            currWord.length += 1;
            currWord.content = realloc(currWord.content, sizeof(char)*((currWord.length)));
            currWord.content[strIndex++] = inputChar;
            //str[strIndex++] = a;
        }
    }
    
}

int main()
{
    String s0 = {0, NULL};
    String s1 = {0, NULL};
    
    printf("Input String S0: ");
    inputString(&s0);
    printf("Input String S1: ");
    inputString(&s1);

    String newStr = {0, NULL};
    deleteWordFromStr(&s0, &newStr, &s1.content[0]);
    printString(&newStr);

    freeString(&s0);
    freeString(&s1);
    freeString(&newStr);
}