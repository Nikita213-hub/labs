#ifndef VALIDATORS_H
#define VALIDATORS_H
int getValidatedIntInput(const char *prompt, int min, int max);
char getValidatedCharInput(const char *prompt, char validChars[], int validCharsLength);
double getValidatedDoubleInput(const char *prompt);
int getAwesomeValidatedIntInput(const char *message, int min, int max);
void handleIntInput(int *num, int range[2], char *message, ...);
#endif