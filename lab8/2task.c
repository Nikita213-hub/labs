#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("b.bin", "wb");
    int num, divisor, count = 0;
    printf("Enter numbers (end with -1): ");
    while (scanf("%d", &num) == 1 && num != -1) 
    {
        fwrite(&num, sizeof(int), 1, fp);
    }
    fclose(fp);

    printf("Enter divisor: ");
    scanf("%d", &divisor);

    fp = fopen("b.bin", "rb");
    if (!fp) return 1;
    while (fread(&num, sizeof(int), 1, fp) == 1)
    {
        if (num % divisor == 0) count++;
    }
    fclose(fp);

    printf("Count: %d\n", count);
    return 0;
}