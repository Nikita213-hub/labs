#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "validators.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp;
    const char *fileName = argv[1];
    int num;
    
    fp = fopen(fileName, "wb");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return 1;
    }
    
    printf("Enter numbers (end with -1)\n");
    while (1) {
        num = getValidatedIntInput("Insert integer value: ");
        if (num == -1) break;
        fwrite(&num, sizeof(int), 1, fp);
    }
    fclose(fp);

    fp = fopen(fileName, "rb+");
    if (fp == NULL) {
        perror("Error opening file for reading/updating");
        return 1;
    }
    
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

    fseek(fp, 0, SEEK_SET);
    int temp;
    printf("File contents: ");
    for (int i = 0; i < count; i++) {
        fread(&temp, sizeof(int), 1, fp);
        printf("%d ", temp);
    }
    printf("\n");
    
    fclose(fp);
    return 0;
}