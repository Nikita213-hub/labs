#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "validators.h"

int main() {
    FILE *fp;
    char fileName[256];
    printf("Enter bin file's name:\n");
    getFileName(fileName);
    fp = fopen(fileName, "wb");
    int num;
    printf("Enter numbers (end with -1)\n");
    while (1) 
    {
        num = getValidatedIntInput("Insert integer value: ");
        if (num == -1) {
            break;
        }
        fwrite(&num, sizeof(int), 1, fp);
    }
    fclose(fp);

    fp = fopen(fileName, "rb+");
    fseek(fp, 0, SEEK_END);
    int count = ftell(fp) / sizeof(int);
    fseek(fp, 0, SEEK_SET);

    for (int i = 0; i < count; i++) {
        int current;
        fseek(fp, i * sizeof(int), SEEK_SET);
        fread(&current, sizeof(int), 1, fp);
        
        int duplicate = 0;
        for (int j = 0; j < i; j++) {
            int previous;
            fseek(fp, j * sizeof(int), SEEK_SET);
            fread(&previous, sizeof(int), 1, fp);
            if (previous == current) {
                duplicate = 1;
                break;
            }
        }

        if (duplicate) {
            fseek(fp, i * sizeof(int), SEEK_SET);
            int zero = 0;
            fwrite(&zero, sizeof(int), 1, fp);
        }
    }
    int temp;
    fseek(fp, 0, SEEK_SET);
    for (int i = 0; i < count; i++) {
        fread(&temp, sizeof(int), 1, fp);
        printf("%d ", temp);
    }
    fclose(fp);
    return 0;
}