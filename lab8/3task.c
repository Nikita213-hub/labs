#include <stdio.h>
#include "util.h"
#include "validators.h"

int main() {
    FILE *fp;
    char fileName[256];
    printf("Enter bin file's name:\n");
    getFileName(fileName);

    fp = fopen(fileName, "wb");
    int numbersCount, num = 0;
    printf("Enter numbers (end with -1)\n");
    while (1) 
    {
        num = getValidatedIntInput("Insert integer value: ");
        if (num == -1) {
            break;
        }
        fwrite(&num, sizeof(int), 1, fp);
        numbersCount++;
    }
    fclose(fp);
    

    fp = fopen(fileName, "rb+");
    printf("Insert k: ");
    int k;
    scanf("%d", &k);
    int shiftVal = 0;
    printf("NC is %d\n", 2%4);
    k%=numbersCount;
    printf("K is %d\n", k);
    if (k==0)
    {
        printf("no need\n");
    }
    int temp;
    fseek(fp, 0, SEEK_SET);
    int offset = 0;
    int originalNumbersCount = numbersCount;
    for (int i = k; i > 0; i--) {
        fseek(fp, -(i + offset) * sizeof(int), SEEK_END);
        fread(&temp, sizeof(int), 1, fp);
        printf("trace1 %d\n", temp);
        fseek(fp, 0, SEEK_END);
        fwrite(&temp, sizeof(int), 1, fp);
        offset++;
        numbersCount++;
    }
    for (int i = 0; i < originalNumbersCount-k; i++) {
        fseek(fp, -(i+offset+k+1) * sizeof(int), SEEK_END);
        fread(&temp, sizeof(int), 1, fp);
        fseek(fp, -(i+offset+1) * sizeof(int), SEEK_END);
        fwrite(&temp, sizeof(int), 1, fp);
        printf("TEMP TRACE: %d\n", temp);
    }
    // while(numbersCount > 0) {
    //     fread(&temp, sizeof(int), 1, fp);
    //     fseek(fp, -sizeof(int), SEEK_CUR);
    //     fwrite(&temp, sizeof(int), 1, fp);
    // }
    fseek(fp, 0, SEEK_SET);
    for (int i = 0; i < numbersCount; i++) {
        fread(&temp, sizeof(int), 1, fp);
        printf("%d ", temp);
    }
    printf("\n");
    fclose(fp);
    return 0;
}