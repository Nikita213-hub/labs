#include <stdio.h>

void removeFirstWordOccurrence(char *s, const char *s0) {
    char firstWord[100];
    int i = 0, j = 0;

    // Extract the first word from S0
    while (s0[i] != ' ' && s0[i] != '\0') {
        firstWord[j++] = s0[i++];
    }
    firstWord[j] = '\0';

    // Find the first occurrence of the first word in S
    int k = 0, match = 0, start = -1;
    while (s[k] != '\0') {
        if (s[k] == firstWord[match]) {
            match++;
            if (match == 1) start = k;
            if (firstWord[match] == '\0') {
                break;
            }
        } else {
            match = 0;
            start = -1;
        }
        k++;
    }

    // Remove the word if found
    if (start != -1) {
        int shift = k + 1; // Position after the found word
        k = start;
        while (s[shift] != '\0') {
            s[k++] = s[shift++];
        }
        s[k] = '\0'; // Null-terminate the modified string
    }
}

int main() {
    char s[] = "Пример строки для удаления слова";
    const char s0[] = "строки дополнительные данные";
    removeFirstWordOccurrence(s, s0);
    printf("Результат: %s\n", s);
    return 0;
}
