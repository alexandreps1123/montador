#ifndef __PRE_PROCESSOR__
#define __PRE_PROCESSOR__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void preProcessor(FILE *pFile);
void clearString(lineContent);
void removeComments(char *lineContent);
void removeUnnecessaryCharacters(char *lineContent);
void toUpperCase(char *lineContent);
int validInitialCharacter(char *lineContent);
int isLabel(char *lineContent);
int isPureLabel(char *lineContent);

#endif /* __PRE_PROCESSOR__ */
