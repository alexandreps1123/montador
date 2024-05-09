#ifndef __FILE_HANDLER__
#define __FILE_HANDLER__

#include "messages.h"
#include "input_handler.h"
#include <stdio.h>
#include <string.h>

FILE* readFile(char *filePath);
void writeFile(char *filePath);

#endif /* __FILE_HANDLER__ */
