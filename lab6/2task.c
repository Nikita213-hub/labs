#include <stdio.h>

void swap(int * a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int arr[5] = {5, 6, 1, 4, 3};
    int len = 5;
    int gap = len/2;
    // for (int i = 0; gap >= 1; gap/=2)
    // {
    //     for (int j = 0; j < len-gap; j+=gap)
    //     {
    //         printf("%d \n", j+gap);
    //         if(arr[j] > arr[j+gap])
    //         {
    //             swap(&arr[j], &arr[j+gap]);
    //         }
    //     }
        
    // }
    // for (int i = 0; i < len; i++)
    // {
        
    // }
    
    for (int gap = len/2; gap > 0; gap /=2)
    {
        for (int j = 0; j < len; j++)
        {
            for (int i = gap + j; i < len; i+=gap)
            {
                if(arr[i] < arr[i-gap])
                {
                    swap(&arr[i], &arr[i-gap]);
                }
            }   
        }
    }
    
    
    
    for (int i = 0; i < 5; i++)
    {
        printf(" %d ", arr[i]);
    }
}