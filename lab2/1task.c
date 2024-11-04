#include <stdio.h>

int main()
{ 
    double a;
    int tries = 10;
    while(tries > 0)
    {
        printf("Insert any number: ");
        if(scanf("%lf", &a) == 1)
        {
            break;
        }
        printf("Insert correct value(int) \n");
        while(getchar() != '\n') break;
        tries--;       
    }
    if(tries <= 0) 
    {
        printf("Reached max tries");
        return 1;
    }
    
    double sum = 0;
    double counter = 1;
    do{
        sum += 1/counter;
        counter++;
    } while(sum < a);
    printf("The minimal number is %lf", --counter);
    return 0;
}