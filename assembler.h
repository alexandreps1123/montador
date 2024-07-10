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

void assembler(char *filePath);
void parser(char *line, int countLine, char *delimiter);
int isNotValidFirstCharacter(char *lineContent);
int isLabel(char *lineContent);

#endif /* __ASSEMBLER__ */
