#include <stdio.h>


int Min(int x, int y)
{
    if(x < y) return x;
    else return y;
}

void main(void){
    printf("%d", Min(11, 10));
}