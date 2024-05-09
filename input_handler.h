#ifndef __INPUT_HANDLER__
#define __INPUT_HANDLER__

#include "messages.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void checkArgs(int argc, char *argv[]);
void validateInput(char *flag);
void validateInputs(char *flag, char *filePath);
char* getExtFile(char *filePath);
char* getNameFile(char *filePath);
void validateFlagAndFileExtension(char *flag, char *extension);
int checkFlagExtension(char *flag, char *extension);

#endif /* __INPUT_HANDLER__ */
