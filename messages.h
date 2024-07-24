#ifndef __MESSAGES__
#define __MESSAGES__

#include <stdio.h>
#include <stdlib.h>

void helpMessage();
void invalidOptionMessage();
void invalidExtensionMessage();
void openFileErrorMessage();
void parserErrorMessage(int countLine);
void opcodeInvalidErrorMessage(int countLine);
void doubleLabelSameLineErrorMessage(int countLine);
void incorrectArgumentNumbersErrorMessage(int countLine, int desireTokenPerline, char* firstToken, int countTokenPerline);

#endif /* __MESSAGES__ */
