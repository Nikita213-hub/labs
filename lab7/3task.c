#include <stdio.h>

// Helper function to find the length of the shortest word in a string
int shortestWordLength(const char *str) {
    int minLength = 1000, currentLength = 0, i = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ') {
            currentLength++;
        } else if (currentLength > 0) {
            if (currentLength < minLength) {
                minLength = currentLength;
            }
            currentLength = 0;
        }
        i++;
    }

    // Check the last word
    if (currentLength > 0 && currentLength < minLength) {
        minLength = currentLength;
    }

    return minLength;
}

// Hoare partition function
int partition(char arr[][100], int left, int right) {
    char pivot[100];
    for (int i = 0; arr[(left + right) / 2][i] != '\0'; i++) {
        pivot[i] = arr[(left + right) / 2][i];
    }
    pivot[(left + right) / 2] = '\0';
    int pivotShortest = shortestWordLength(pivot);

    while (left <= right) {
        while (shortestWordLength(arr[left]) < pivotShortest) left++;
        while (shortestWordLength(arr[right]) > pivotShortest) right--;
        if (left <= right) {
            // Swap left and right
            char temp[100];
            int i = 0;
            while (arr[left][i] != '\0') {
                temp[i] = arr[left][i];
                i++;
            }
            temp[i] = '\0';

            int j = 0;
            while (arr[right][j] != '\0') {
                arr[left][j] = arr[right][j];
                j++;
            }
            arr[left][j] = '\0';

            j = 0;
            while (temp[j] != '\0') {
                arr[right][j] = temp[j];
                j++;
            }
            arr[right][j] = '\0';

            left++;
            right--;
        }
    }
    return left;
}

// Recursive Hoare quicksort
void quicksort(char arr[][100], int left, int right) {
    if (left >= right) return;

    int index = partition(arr, left, right);
    quicksort(arr, left, index - 1);
    quicksort(arr, index, right);
}

int main() {
    char strings[5][100] = {
        "Это пример строки",
        "Слово короче",
        "Тест",
        "С длинными словами например таким",
        "Просто строка"
    };

    int n = 5;
    quicksort(strings, 0, n - 1);

    printf("Отсортированный массив строк:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
