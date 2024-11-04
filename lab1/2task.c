#include <stdio.h>

int main()
{
    double firtArg, sndArg, thrdArg;
    // double args[3];
    printf("Insert 3 values: ");
    scanf("%lf %lf %lf", &firtArg, &sndArg, &thrdArg);
    int isThereReciprocal = (firtArg + sndArg == 0) || (firtArg + thrdArg == 0) || (sndArg + thrdArg == 0);
    // for(int i = 0; i < 3; i++)
    // {
    //     for(int j = i + 1; j < 3; j++)
    //     {
    //         if(args[i] + args[j] == 0)
    //         {
    //             isThereReciprocal = 1;
    //         }
    //     }
    // }
    if(isThereReciprocal)
    {
        printf("Among the given 3 nums there is at list 1 reciprocal \n");
    }
    else {
        printf("There is no reciprocal");
    }
    return 0;
}