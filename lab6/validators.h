#ifndef VALIDATORS_H
#define VALIDATORS_H
int getValidatedIntInput(const char *prompt, int min, int max);
char getValidatedCharInput(const char *prompt, char validChars[], int validCharsLength);
double getValidatedDoubleInput(const char *prompt);
int getAwesomeValidatedIntInput(const char *message, int min, int max);
int validateIntInp(const char *message ,int min, int max);
int getAwesomeValidatedIntInput(const char *message, int min, int max);
#endif