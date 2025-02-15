#include <stdio.h>
#include "util.h"
#include "validators.h"

int main() {
    FILE *fp;
    char fileName[256];
    printf("Enter bin file's name:\n");
    getFileName(fileName);
    fp = fopen(fileName, "wb");
    printf("Enter natural numbers (end with -1)\n");
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

    fp = fopen(fileName, "rb");
    fseek(fp, 0, SEEK_END);
    int count = ftell(fp) / sizeof(int);
    fseek(fp, 0, SEEK_END);
    int temp;
    printf("Numbers from file: \n");
    fseek(fp, 0, SEEK_SET);
    for (int i = 0; i < count; i++) {
        fread(&temp, sizeof(int), 1, fp);
        printf("%d ", temp);
    }
    printf("\n");
    return 0;
}