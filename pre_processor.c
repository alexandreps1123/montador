#include "pre_processor.h"

void preProcessor(FILE *pFile) 
{
    char lineContent[80];

    while (fgets(lineContent , 80 , pFile) != NULL) {
        removeComments(lineContent);
        removeUnnecessaryCharacters(lineContent);
        toUpperCase(lineContent);

        // TODO: verify if is a label
        if (validCharacter(lineContent)) {
            // TODO: write content line in a data structure
            printf("%s\n", lineContent);
        }
    }
    // TODO: write in a file pre processed data
    
    return;
}

void removeComments(char *lineContent) 
{
    strtok(lineContent, ";");
    return;
}

void removeUnnecessaryCharacters(char *lineContent)
{
    char *formatedLine = malloc(strlen(lineContent)); 
    char *pch, *temp = lineContent;

    pch = strtok(temp, " \t");
    while (pch != NULL)
    {
        strcat(formatedLine, pch);
        strcat(formatedLine, " ");
        pch = strtok(NULL, " \t");
    }

    strcpy(lineContent, formatedLine);

    return;
}

void toUpperCase(char *lineContent) 
{
    int i=0;
    while (i < strlen(lineContent))
    {
        lineContent[i] = toupper(lineContent[i]);
        i++;
    }

    return;
}

int validCharacter(char *lineContent) 
{
    return !(lineContent[0] == '\n' || lineContent[0] == ';');
}

// int isFlag(char *lineContent) 
// {
//     int i = 0;
//     while()
//     return !(lineContent[0] == '\n' || lineContent[0] == ';');
// }
