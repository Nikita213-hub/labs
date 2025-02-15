#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("a.bin", "wb");
    int num, divisor, count = 0;
    printf("Enter numbers (end with -1): ");
    while (scanf("%d", &num) == 1 && num != -1) 
    {
        fwrite(&num, sizeof(int), 1, fp);
    }
    fclose(fp);

    return 0;
}