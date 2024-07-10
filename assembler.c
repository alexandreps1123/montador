#include <ctype.h>
#include "assembler.h"

void assembler(char *filePath)
{
    FILE *pFile;
    pFile = openFile(filePath);
    
    Text text;
    createText(&text);

    int PC = 1;
    int countLine = 1;

    Line lineContent;

    while (fgets(lineContent.line, MAX_LINE_LENGTH, pFile) != NULL)
    {
        parser(lineContent.line, countLine,  " :,\n");

        countLine++;
    }

    writeFile(filePath, &text);

    fclose(pFile);
    return;
}

void parser(char *line, int countLine, char *delimiter) 
{
    char *pch, *formatedLine = malloc(strlen(line));

    strcpy(formatedLine, line);
    pch = strtok(formatedLine, delimiter);
    while (pch != NULL)
    {
        if (isNotValidFirstCharacter(pch)!=0) 
        {
            parserErrorMessage(countLine);
        }
        pch = strtok(NULL, delimiter);
    }

    return;
}

int isNotValidFirstCharacter(char *lineContent)
{
    return !(lineContent[0] == '_' || isalpha(lineContent[0]));
}

