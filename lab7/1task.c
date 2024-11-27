#include <stdio.h>

void findLongestWord(const char *str, char *longestWord) {
    int maxLength = 0, currentLength = 0;
    int start = 0, end = 0, i = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\n') {
            currentLength++;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
                start = i - currentLength;
                end = i;
            }
            currentLength = 0;
        }
        i++;
    }

    // Check the last word
    if (currentLength > maxLength) {
        maxLength = currentLength;
        start = i - currentLength;
        end = i;
    }

    // Copy the longest word
    for (i = start; i < end; i++) {
        longestWord[i - start] = str[i];
    }
    longestWord[end - start] = '\0';
}

int main() {
    char str[] = "Это пример строки с разными словами";
    char longestWord[100];
    findLongestWord(str, longestWord);
    printf("Самое длинное слово: %s\n", longestWord);
    return 0;
}
