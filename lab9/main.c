#include <stdio.h>
#include "validators.c"
#include "util.c"
#define MAX_NUMBERS 100

void fillFileWithNums(FILE * fp) {
    printf("Enter natural numbers (end with -1)\n");
    int num;
    while (1) 
    {
        num = getValidatedIntInput("Insert integer value: ");
        if (num == -1) {
            break;
        }
        fprintf(fp, "%d ", num);
        // num += '0';
        // fwrite(&num, sizeof(char), 2, fp);
    }
}

double findAvgFromFile(FILE * fp) {
    double avg = 0;
    fseek(fp, 0, SEEK_SET);
    double numCount = 0;
    int temp;
    while (fscanf(fp, "%d", &temp)) {
        avg += temp;
        numCount++;
    }
    avg /= numCount;
    return avg;
}

void printFileContent(FILE * fp) {
    fseek(fp, 0, SEEK_SET);
    int temp;
    while (fscanf(fp, "%d", &temp)) {
        printf("%d ", temp);
    }
    printf("\n");
}


void swapEls(FILE *fp) {
    int numbers[MAX_NUMBERS];
    int count = 0, temp;
    
    rewind(fp);
    while (fscanf(fp, "%d", &temp)) {
        numbers[count++] = temp;
    }
    
    if (count < 2) return; 
    
    int first = numbers[0];
    numbers[0] = numbers[count-1];
    numbers[count-1] = first;

    rewind(fp);
    for (int i = 0; i < count; i++) {
        fprintf(fp, i == 0 ? "%d" : " %d", numbers[i]);
    }
}

int main(int argc, char * argv[]) {
    char* fileName = getFileNameFromCmdArgs(argc, argv);
    FILE * fp = fopen(fileName, "w+");

    if (fp == NULL) {
        printf("Error occured when opening file\n");
        return;
    }

    fillFileWithNums(fp);
    fclose(fp);
    
    fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("Error occured when opening file\n");
        return;
    }
    printf("AVG of nums in the file = %.2lf\n", findAvgFromFile(fp));
    fclose(fp);


    fp = fopen(fileName, "r+");
    if (fp == NULL) {
        printf("Error occured when opening file\n");
        return;
    }
    swapEls(fp);
    fclose(fp);

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error occured when opening file\n");
        return;
    }
    printf("Res file content:\n");
    printFileContent(fp);
    fclose(fp);

    printf("\n");    

    return 0;
}