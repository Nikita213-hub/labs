#include <stdio.h>
#include <string.h>

void getFileName(char * str) {
    fgets(str, 252, stdin);
    str[strcspn(str, "\n")] = '\0'; 
    
    int len = strlen(str);
    if (len < 4 || strncmp(str + len - 4, ".bin", 4) != 0) {
        strcat(str, ".bin");
    }
}