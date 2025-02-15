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

    fp = fopen("a.bin", "rb");
    fseek(fp, 0, SEEK_END);
    int count = ftell(fp) / sizeof(int);
    fseek(fp, 0, SEEK_END);
    int temp;
    printf("Numbers from file: \n");
    for (int i = 0; i < count; i++) {
        fread(&temp, sizeof(int), 1, fp);
        printf("%d ", temp);
    }

    return 0;
}