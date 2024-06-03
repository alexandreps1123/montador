#ifndef __ASSEMBLER__
#define __ASSEMBLER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "queue.h"
#include "messages.h"

void assembler(FILE *pFile);
void parser(char *line, int countLine, char *delimiter);
int isNotValidFirstCharacter(char *lineContent);

#endif /* __ASSEMBLER__ */
