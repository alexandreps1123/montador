#ifndef __PRE_PROCESSOR__
#define __PRE_PROCESSOR__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct EQU
{
    char label[80];
    char value[80];
} EQU;

void preProcessor(FILE *pFile);
void clearString(char *lineContent, int lenght);
void removeComments(char *lineContent);
void removeUnnecessaryCharacters(char *lineContent);
void toUpperCase(char *lineContent);
int validInitialCharacter(char *lineContent);
int isLabel(char *lineContent);
int isPureLabel(char *lineContent);
int isEQU(char *lineContent);
void changeForEQUValue(char *lineContent, EQU equ);
int isIF(char *lineContent);
int getIfValue(char *lineContent);

#endif /* __PRE_PROCESSOR__ */
