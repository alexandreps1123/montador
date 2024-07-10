#ifndef __PRE_PROCESSOR__
#define __PRE_PROCESSOR__

#include "queue.h"
#include "file_handler.h"
#include "consts.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct EQU
{
    char label[MAX_TOKEN_LENGTH];
    char value[MAX_TOKEN_LENGTH];
} EQU;

void preProcessor(char *filePath);
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
