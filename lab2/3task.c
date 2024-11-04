#include <stdio.h>

int main()
{
    double a, b;
    int tries = 10;
    while(tries > 0)
    {
        printf("Insert A(number) and B(number): ");
        if(scanf("%lf %lf", &a, &b) == 2)
        {
            break;
        }
        printf("Insert correct value \n");
        while(getchar() != '\n') break;
        tries--;       
    }
    if(tries <= 0) 
    {
        printf("Reached max tries");
        return 1;
    }
    if(a < 0 || b < 0)
    {
        printf("Both A and B must be > 0");
        return 1;
    }
    if(a < b)
    {
        printf("A must be > B \n");
        return 1;
    }
    int counter = 0;
    for (double i = b; i <= a; i+=b)
    {
        counter++;  
    }
    printf("The total b in a is: %d", counter);
    return 0;
}