#include "input_handler.h"
#include "consts.h"

void checkArgs(int argc, char *argv[])
{
    if(argc==2) validateInput(argv[1]);
    else if(argc==3) validateInputs(argv[1], argv[2]);
    else invalidOptionMessage();
}

void validateInput(char *flag)
{
    if (strcmp(flag, "-help")==0) helpMessage();

    invalidOptionMessage();
}

void validateInputs(char *flag, char *filePath)
{
    char *extension;

    if (strcmp(flag, "-p")!=0 && strcmp(flag, "-o")!=0)
    {
        invalidOptionMessage();
    }

    extension = getExtFile(filePath);
    validateFlagAndFileExtension(flag, extension);
}

char* getExtFile(char *filePath)
{
    int tokenNumbers = 0;
    char *pch, *extension, temp[MAX_TOKEN_LENGTH];
    
    strcpy(temp, filePath);
    pch = strtok(temp, ".");

    while (pch != NULL)
    {
        tokenNumbers++;
        if(tokenNumbers == 2) extension = pch;

        pch = strtok(NULL, ".");
    }

    if(tokenNumbers!=2) invalidExtensionMessage();
    
    return extension;
}

char* getNameFile(char *filePath)
{
    char *temp;

    temp = filePath;
    return strtok(temp, ".");
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
