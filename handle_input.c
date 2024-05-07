#include "handle_input.h"
#include "messages.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void validateInput(char *flag);
void validateInputs(char *flag, char *fileName);
void validateFlagAndFileExtension(char *flag, char *extension);
int checkFlagExtension(char *flag, char *extension);
char* validateFileExtension(char *fileName);

void checkArgs(int argc, char *argv[])
{
    if(argc==2) validateInput(argv[1]);
    else if(argc==3) validateInputs(argv[1], argv[2]);
    else invalidOptionMessage();
}

void validateInput(char *flag)
{
    if (strcmp(flag, "-help")==0)
    {
        helpMessage();
    }

    invalidOptionMessage();
}

void validateInputs(char *flag, char *fileName)
{
    char *extension;

    if (strcmp(flag, "-p")!=0 && strcmp(flag, "-o")!=0)
    {
        invalidOptionMessage();
    }

    extension = validateFileExtension(fileName);
    validateFlagAndFileExtension(flag, extension);
}

char* validateFileExtension(char *fileName)
{
    int tokenNumbers = 0;
    char *pch, *extension;

    pch = strtok(fileName, ".");
    while (pch != NULL)
    {
        tokenNumbers++;
        if(tokenNumbers == 2) extension = pch;

        pch = strtok(NULL, ".");
    }

    if(tokenNumbers!=2) invalidExtensionMessage();
    
    return extension;
}

void validateFlagAndFileExtension(char *flag, char *extension)
{
    if(checkFlagExtension(flag, extension)==0)
    {
        invalidExtensionMessage();
    }
}

int checkFlagExtension(char *flag, char *extension)
{
    return (strcmp(flag, "-p")==0 && strcmp(extension, "asm")==0) ||
        (strcmp(flag, "-o")==0 && strcmp(extension, "pre")==0);
}
