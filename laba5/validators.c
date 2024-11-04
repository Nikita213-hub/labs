#include <stdio.h>
#include <ctype.h>

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

char getValidatedCharInput(const char *message, char validChars[], int validCharsLength)
{
    if(validCharsLength < 2) return 'M';
    char input;
    while (1) 
    {
        printf("%s", message);
        if (scanf(" %c", &input) == 1) 
        {
            input = toupper(input);  
            for (int i = 0; i < validCharsLength; i++) 
            {
                if (input == toupper(validChars[i])) 
                {
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