#ifndef PARSE_STRING
#define PARSE_STRING
char * getString();
int isNum(char * el);
IntQueue * extractNumsFromStr(char * str);
void freeSplittedStr(char ** splitted);
#endif