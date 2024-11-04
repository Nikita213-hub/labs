#include <stdio.h>

int main()
{
    double n;
    int tries = 10;
    while(tries > 0)
    {
        printf("Insert n > 1: ");
        if(scanf("%lf", &n) == 1)
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
    if(n < 1)
    {
        printf("Insert value > 1 \n");
        return 1;
    }
    double sum = 0;
    double mult = (n >= 3) ? 1 : 0;
    for (double i = 3; i <= n; i += 3) 
    {
        sum += i;
        mult *= i;
    }
    printf("sum = %lf mult = %lf", sum, mult);    
    
    return 0;
}