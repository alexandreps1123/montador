#include "pre_processor.h"

const int MAX_LINE_LENGTH = 256;

void preProcessor(FILE *pFile) 
{
    char lineContent[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int countPureLabel = 0;

    clearString(lineContent);
    clearString(line);

    while (fgets(lineContent , MAX_LINE_LENGTH, pFile) != NULL) 
    {
        removeComments(lineContent);
        removeUnnecessaryCharacters(lineContent);
        toUpperCase(lineContent);

        // TODO: verify if is a label
        if (validInitialCharacter(lineContent)) {
            if(isLabel(lineContent) == 1 && isPureLabel(lineContent) == 1) 
            {
                countPureLabel++;
                strcat(line, lineContent);
            }
            else 
            {
                if(countPureLabel != 0) 
                {
                    countPureLabel = 0;
                    strcat(line, lineContent);
                    strcpy(lineContent, line);
                    clearString(line);
                }

                printf("%s\n", lineContent);
            }
        }

        clearString(lineContent);
    }
    // TODO: write in a file pre processed data
    
    return;
}

void clearString(char lineContent[MAX_LINE_LENGTH]) {
    int i = 0;
    while (i < MAX_LINE_LENGTH)
    {
        lineContent[i] = '\0';
        i++;
    }
    
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

    // ' '	(0x20)	space (SPC)
    // '\t'	(0x09)	horizontal tab (TAB)
    // '\n'	(0x0a)	newline (LF)
    // '\v'	(0x0b)	vertical tab (VT)
    // '\f'	(0x0c)	feed (FF)
    // '\r'	(0x0d)	carriage return (CR)
    pch = strtok(temp, " \t\n\r\v\f\r");
    while (pch != NULL)
    {
        strcat(formatedLine, pch);
        strcat(formatedLine, " ");
        pch = strtok(NULL, " \t\n\r\v\f\r");
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

int validInitialCharacter(char *lineContent) 
{
    return !(lineContent[0] == '\n' || lineContent[0] == ';' || lineContent[0] == NULL);
}

int isLabel(char *lineContent) 
{
    int i = 0;
    while (i < MAX_LINE_LENGTH)
    {
        if (lineContent[i] == ':') return 1;
        i++;
    }

    return 0;
}

int isPureLabel(char *lineContent)
{
    int countToken = 0;
    char *formatedLine = malloc(strlen(lineContent)); 
    char *pch;

    // ' '	(0x20)	space (SPC)
    // '\t'	(0x09)	horizontal tab (TAB)
    // '\n'	(0x0a)	newline (LF)
    // '\v'	(0x0b)	vertical tab (VT)
    // '\f'	(0x0c)	feed (FF)
    // '\r'	(0x0d)	carriage return (CR)
    pch = strtok(lineContent, ":");
    while (pch != NULL)
    {
        if(countToken == 0) 
        {
            strcat(formatedLine, pch);
            strcat(formatedLine, ": ");
        }
        else
        {
            strcat(formatedLine, pch);
            strcat(formatedLine, " ");
        }
        pch = strtok(NULL, " \t\n\r\v\f\r");
        countToken++;
    }

    clearString(lineContent);
    strcpy(lineContent, formatedLine);

    return countToken;
}
