#ifndef __ASSEMBLER__
#define __ASSEMBLER__

#include "queue.h"
#include "messages.h"
#include "file_handler.h"
#include "assembler.h"
#include "consts.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MEMORIA
{
    char token[MAX_TOKEN_LENGTH];
} MEMORIA;

typedef struct TABELA_SIMBOLOS
{
    char simbolo[MAX_TOKEN_LENGTH];
    int valor;
    int def;
} TABELA_SIMBOLOS;

typedef struct OPERACAO
{
    char* value;
    int expectedOperators;
} OPERACAO;

void assembler(char *filePath);
void parser(char *token, int countLine);
int isNotValidFirstCharacter(char *lineContent);
int isDigitOrXDigit(char *token);
char* tokenToOPCODE(char* token);
int isOPCODE(char* token);
int invalidCharacter(char *lineContent);

#endif /* __ASSEMBLER__ */
