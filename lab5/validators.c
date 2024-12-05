#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
int getValidatedIntInput(const char *message, int min, int max)
{
    int input;
    while (1) 
    {
        printf("%s", message);
        if (scanf("%d", &input) == 1 && input >= min && input <= max) 
        {
            return input;
        } 
        else 
        {
            printf("Invalid input. Please enter an integer between %d and %d.\n", min, max);
            while (getchar() != '\n'); 
        }
    }
}

int getAwesomeValidatedIntInput(const char *message, int min, int max)
{
    while (1)
    {
        printf("%s", message);
        int input = 0;
        char a;
        int isAnyErrorsInInput = 0;
        int valueLen = 0;
        short sign = 1;
        int rawBufferLen = 0;
        while ((a = getchar()) != '\n')
        {
            rawBufferLen++;
            if(valueLen == 0 && a == '-')
            {
                sign = -1;
                valueLen++;
                continue;
            }
            if(a < '0' || a > '9')
            {
                isAnyErrorsInInput = 1;
                // while((getchar()) != '\n');
                break;
            }
            else
            {
                if (sign == 1 && input > (INT_MAX - '0') / 10) {
                    // printf("Value overflow \n");
                    isAnyErrorsInInput = 1;
                    break;
                }
                if (sign == -1 && input < (INT_MIN + '0') / 10) {
                    // printf("Value overfplow \n");
                    isAnyErrorsInInput = 1;
                    break;
                }
                valueLen++;
                input = input * 10 + (a-'0');
            }
        }
        if(sign == -1 && valueLen == 1)
        {
            isAnyErrorsInInput = 1;
            rawBufferLen--;
        }
        if(!isAnyErrorsInInput && valueLen && (input * sign >= min && input * sign <= max))
        {
            return input * sign;
        }
        else {
            input = 0;
            printf("Incorrect input \n");
        }
        if(rawBufferLen > 0 && isAnyErrorsInInput)
        {
            while((getchar()) != '\n');
        }
    }
    
}

char getValidatedCharInput(const char *message, char validChars[], int validCharsLength)
{
    if(validCharsLength < 2) return 'M';
    char input;
    while (1) 
    {
        printf("%s", message);
        if (scanf("%c", &input) == 1) 
        {
            input = toupper(input);  
            for (int i = 0; i < validCharsLength; i++) 
            {
                if (input == toupper(validChars[i])) 
                {
                    while (getchar() != '\n');
                    return input;
                }
            }
        }
        printf("Invalid input. Please enter one of the following characters: ");
        for (int i = 0; i < validCharsLength; i++) 
        {
            printf("%c ", validChars[i]);
        }
        printf("\n");
        while (getchar() != '\n');  
    }
}

double getValidatedDoubleInput(const char *message)
{
    double input;
    while (1) 
    {
        printf("%s", message);
        if (scanf("%lf", &input) == 1) 
        {
            return input;
        } 
        else 
        {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n');
        }
    }
}