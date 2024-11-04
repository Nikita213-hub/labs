#include <stdio.h>
#include <math.h>

int main()
{
    double squareSide, radius;
    printf("Insert radius of a circle and side of a square: ");
    scanf("%lf %lf", &radius, &squareSide);

    if (radius <= 0 || squareSide <= 0) {
        printf("Both values must be positive.\n");
        return 1;
    }

    double diameter = 2 * radius;
    double diagonal = squareSide * sqrt(2);

    if (diameter <= squareSide) 
    {
        printf("The circle will fit in the square.\n");
    } 
    else 
    {
        printf("The circle will NOT fit in the square.\n");
    }

    if (diagonal <= diameter) 
    {
        printf("The square will fit in the circle.\n");
    } 
    else 
    {
        printf("The square will NOT fit in the circle.\n");
    }
    return 0;
}