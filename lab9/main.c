#include <stdio.h>
#include "validators.c"
#include "util.c"


void fillFileWithNums(FILE * fp) {
    printf("Enter natural numbers (end with -1)\n");
    int num;
    while (1) 
    {
        num = getValidatedIntInput("Insert integer value: ");
        if (num == -1) {
            break;
        }
        num += '0';
        fwrite(&num, sizeof(char), 1, fp);
    }
}

double findAvgFromFile(FILE * fp) {
    double avg = 0;
    fseek(fp, 0, SEEK_END);
    int numCount = ftell(fp) / sizeof(char);
    fseek(fp, 0, SEEK_SET);
    char temp;
    for (int i = 0; i < numCount; i++) {
        fread(&temp, sizeof(char), 1, fp);
        int num = temp-'0';
        avg+=num;
    }
    avg /= numCount;
    return avg;
}

void printFileContent(FILE * fp) {
    fseek(fp, 0, SEEK_END);
    int numCount = ftell(fp) / sizeof(char);
    fseek(fp, 0, SEEK_SET);
    char temp;
    for (int i = 0; i < numCount; i++) {
        fread(&temp, sizeof(char), 1, fp);
        printf("%c ", temp);
    }

}

void swapEls(FILE * fp) {

    char temp;
    char temp1;

    fseek(fp, 0, SEEK_SET);
    fread(&temp, sizeof(char), 1, fp);
    fseek(fp, -1*sizeof(char), SEEK_END);
    fread(&temp1, sizeof(char), 1, fp);

    fseek(fp, -1*sizeof(char), SEEK_END);
    fwrite(&temp, sizeof(char), 1, fp);

    fseek(fp, 0, SEEK_SET);
    fwrite(&temp1, sizeof(char), 1, fp);
    
}


int main(int argc, char * argv[]) {
    char* fileName = getFileNameFromCmdArgs(argc, argv);
    FILE * fp = fopen(fileName, "w+");

    fillFileWithNums(fp);
    fclose(fp);
    
    fp = fopen(fileName, "r");
    printf("AVG of nums in the file = %.2lf\n", findAvgFromFile(fp));
    fclose(fp);

    fp = fopen(fileName, "r+");
    swapEls(fp);
    fclose(fp);

    fp = fopen(fileName, "r");
    printf("Res file content:\n");
    printFileContent(fp);
    fclose(fp);

    printf("\n");    

    return 0;
}