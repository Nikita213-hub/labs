#include <stdio.h>
#include "util.h"
#include "validators.h"


#define BUFFER_SIZE 4096 

void swapBlocks(FILE *fp, int posA, int posB, int chunkLen) {
    if (posA == posB || chunkLen <= 0) return;

    int bufferA[BUFFER_SIZE];
    int bufferB[BUFFER_SIZE];
    int remaining = chunkLen;

    while (remaining > 0) {
        int chunk = (remaining > BUFFER_SIZE) ? BUFFER_SIZE : remaining;
        

        fseek(fp, posA * sizeof(int), SEEK_SET);
        fread(bufferA, 1, chunk * sizeof(int), fp);
        

        fseek(fp, posB * sizeof(int), SEEK_SET);
        fread(bufferB, 1, chunk * sizeof(int), fp);
        
 
        fseek(fp, posA * sizeof(int), SEEK_SET);
        fwrite(bufferB, 1, chunk * sizeof(int), fp);
        
        fseek(fp, posB * sizeof(int), SEEK_SET);
        fwrite(bufferA, 1, chunk * sizeof(int), fp);

        posA += chunk;
        posB += chunk;
        remaining -= chunk;
    }
}

void cyclicShift(FILE *fp, int rotdist) {

    fseek(fp, 0, SEEK_END);
    int intsCount = ftell(fp) / sizeof(int);
    fseek(fp, 0, SEEK_SET);

    if (rotdist == 0 || rotdist == intsCount) return;
 
    rotdist %= intsCount;

    int a = rotdist;
    int bl = intsCount - rotdist;
    int br = rotdist;

    while (a != bl) {
        if (a > bl) {
            swapBlocks(fp, br - a, br, bl); 
            a -= bl;
        } else {
            swapBlocks(fp, br - a, br + bl - a, a);
            bl -= a;
        }
    }
    swapBlocks(fp, br - a, br, a);
}

int main() {
    FILE *fp;
    char fileName[256];
    printf("Enter bin file's name:\n");
    getFileName(fileName);

    fp = fopen(fileName, "wb");
    int numbersCount = 0;
    int num;
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

    int rShiftVal = getValidatedIntInput("Enter k(shift value): ");
    int lShift = numbersCount-rShiftVal;

    fp = fopen(fileName, "rb+");
    int temp;
    cyclicShift(fp, lShift);
    fseek(fp, 0, SEEK_SET);
    for (int i = 0; i < numbersCount; i++) { 
        fread(&temp, sizeof(int), 1, fp);
        printf("%d ", temp);
    }
    printf("\n");
    fclose(fp);
    return 0;
}