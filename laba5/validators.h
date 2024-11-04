#ifndef VALIDATORS_H
#define VALIDATORS_H
int getValidatedIntInput(const char *prompt, int min, int max);
char getValidatedCharInput(const char *prompt, char validChars[], int validCharsLength);
double getValidatedDoubleInput(const char *prompt);
#endif