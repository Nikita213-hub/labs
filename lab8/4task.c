#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("d.bin", "wb");
    int num;
    printf("Insert numbers(any negative to stop)\n");
    while (1) {
        if (scanf("%d", &num) != 1 || num <= 0) break;
        fwrite(&num, sizeof(int), 1, file);
    }
    fclose(file);

    file = fopen("d.bin", "rb+");
    fseek(file, 0, SEEK_END);
    int count = ftell(file) / sizeof(int);
    rewind(file);

    for (int i = 0; i < count; i++) {
        int current;
        fseek(file, i * sizeof(int), SEEK_SET);
        fread(&current, sizeof(int), 1, file);
        
        int duplicate = 0;
        for (int j = 0; j < i; j++) {
            int previous;
            fseek(file, j * sizeof(int), SEEK_SET);
            fread(&previous, sizeof(int), 1, file);
            if (previous == current) {
                duplicate = 1;
                break;
            }
        }

        if (duplicate) {
            fseek(file, i * sizeof(int), SEEK_SET);
            int zero = 0;
            fwrite(&zero, sizeof(int), 1, file);
        }
    }
    int temp;
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < count; i++) {
        fread(&temp, sizeof(int), 1, file);
        printf("%d ", temp);
    }
    fclose(file);
    return 0;
}