#include <stdio.h>
#include "util.h"
#include "validators.h"

int main() {
    FILE *fp;
    char fileName[256];
    printf("Enter bin file's name:\n");
    getFileName(fileName);

    fp = fopen(fileName, "wb");
    int divisor;
    printf("Enter numbers (end with -1)\n");
    int num;
    while (1) 
    {
        num = getValidatedIntInput("Insert integer value: ");
        if (num == -1) {
            break;
        }
        fwrite(&num, sizeof(int), 1, fp);
    }
    fclose(fp);
    
    divisor = getValidatedIntInput("Enter divisor: ");

    fp = fopen(fileName, "rb");
    int count = 0;
    if (!fp) return 1;
    while (fread(&num, sizeof(int), 1, fp) == 1)
    {
        if (num % divisor == 0) count++;
    }

    
    fclose(fp);

    printf("Count: %d\n", count);
    return 0;
}