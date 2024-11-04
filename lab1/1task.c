#include <stdio.h>
#include <math.h>
int main()
{
//  b - 1st term of the geometric progression
//  q - denominator of the geometric progression
//  n - count of terms in geometric progression 
    int n;
    double b, q;
    printf("Insert 3 values: first term of geometric progression, denominator, count of terms: ");
    scanf("%lf %lf %d", &b, &q, &n);
    if(n < 0)
    {
        printf("Count of terms cannot be negative \n");
        return 1;
    }
    if (q == 1) 
    {
        printf("The sum of the geometric progression is: %lf\n", b * n);
        return 0;
    }
    double sum;
    sum = b*(1-pow(q, n))/(1-q);    
    printf("\n the sum of the geometric progression is %lf \n", sum);
    return 0;
}
