#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>

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
    // char buffer[500];
    // int currLen = 0;
    // int cursor = 0;
    printf("%s", message);
    // while (1) 
    // {
    //     long long input;
    //     int cursor = 0;
    //     char c;
    //     // printf("%s", message);
    //     if (input >= min && input <= max) 
    //     {
    //         return input;
    //     } 
    //     else 
    //     {
    //         printf("Invalid input. Please enter an integer between %d and %d.\n", min, max);
    //         while (getchar() != '\n'); 
    //     }
    // }
    int input = 0;
    char c;
    int cursor = 0;
    while ((c = _getch()) != '\r' && c != EOF)
    {
            if(c >= '0' && c <= '9')
            {
                input = input * 10 + (c-'0');
                putch(c);
                cursor++;
            }
            if(c == '\b')
            {
                if(cursor > 0)
                {
                    printf("\b \b");
                    input /= 10;
                    cursor--;
                }
            }
            // if (c == 0 || c == 224)
            // {
            //     c = _getch();
            //     if (c == 75)
            //     {
            //         if (cursor > 0)
            //         {
            //             cursor--;
            //             printf("\b");
            //         }
            //     }
            //     else if (c == 77)
            //     {
            //         if (cursor < currLen)
            //         {
            //             printf("%c", buffer[cursor]); // Move cursor right visually
            //             cursor++;
            //         }
            //     }
            // }
    }
    if(input > min && input < max)
    {
        return input;
    }

    printf("\n");
        
    // while ((c = _getch()) != '\r')
    // {
    //     if(c >= '0' && c <= '9')
    //     {
    //         input = input * 10 + (c-'0');
    //         putch(c);
    //         cursor++;
    //     }
    //     if(c == '\b')
    //     {
    //         if(cursor > 0)
    //         {
    //             printf("\b \b");
    //             input /= 10;
    //             cursor--;
    //         }
    //     }
    //     // if (c == 0 || c == 224)
    //     // {
    //     //     c = _getch();
    //     //     if (c == 75)
    //     //     {
    //     //         if (cursor > 0)
    //     //         {
    //     //             cursor--;
    //     //             printf("\b");
    //     //         }
    //     //     }
    //     //     else if (c == 77)
    //     //     {
    //     //         if (cursor < currLen)
    //     //         {
    //     //             printf("%c", buffer[cursor]); // Move cursor right visually
    //     //             cursor++;
    //     //         }
    //     //     }
    //     // }
    // }
    // if (input > min && input < max)
    // {
    //     return input;
    // }
    
    // printf("\n");
    // printf("%lld", input);
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