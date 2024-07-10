#include "pre_processor.h"

void preProcessor(char *filePath)
{
    FILE *pFile;
    pFile = openFile(filePath);
    
    Text text;
    createText(&text);
        
    Line lineContent;
    char line[MAX_LINE_LENGTH];

    int countPureLabel = 0;

    int ifAction = 1;

    int countEqu = 0;
    EQU equ[MAX_EQU_DECLARATION];

    clearString(lineContent.line, MAX_LINE_LENGTH);
    clearString(line, MAX_LINE_LENGTH);

    while (fgets(lineContent.line, MAX_LINE_LENGTH, pFile) != NULL)
    {
        removeComments(lineContent.line);
        removeUnnecessaryCharacters(lineContent.line);
        toUpperCase(lineContent.line);
            
        if (validInitialCharacter(lineContent.line))
        {
            if (isLabel(lineContent.line) == 1 && isPureLabel(lineContent.line) == 1)
            {
                countPureLabel++;
                strcat(line, lineContent.line);
            }
            else
            {
                for (int i = 0; i < countEqu; i++)
                {
                    changeForEQUValue(lineContent.line, equ[i]);
                }
                
                if (countPureLabel != 0)
                {
                    countPureLabel = 0;
                    strcat(line, lineContent.line);
                    strcpy(lineContent.line, line);
                    clearString(line, MAX_LINE_LENGTH);
                }

                if (isEQU(lineContent.line))
                {
                    int countToken = 0;
                    char *pch;

                    pch = strtok(lineContent.line, ":");

                    strcpy(equ[countEqu].label, pch);

                    while (pch != NULL)
                    {
                        if (countToken == 2)
                            strcpy(equ[countEqu].value, pch);

                        pch = strtok(NULL, " ");
                        countToken++;
                    }

                    countEqu++;

                    clearString(lineContent.line, MAX_LINE_LENGTH);

                    continue;
                }

                if (isIF(lineContent.line)) {
                    ifAction = getIfValue(lineContent.line);
                    continue;
                }

                if(ifAction == 0) {
                    ifAction = 1;
                    continue;
                }
                else enqueue(&text, &lineContent);
            }
        }

        clearString(lineContent.line, MAX_LINE_LENGTH);
    }

    writeFile(filePath, &text);

    fclose(pFile);
    return;
}

void removeComments(char *lineContent)
{
    strtok(lineContent, ";");
    return;
}

void removeUnnecessaryCharacters(char *lineContent)
{
    char *pch, *formatedLine = malloc(strlen(lineContent));

    // ' '	(0x20)	space (SPC)
    // '\t'	(0x09)	horizontal tab (TAB)
    // '\n'	(0x0a)	newline (LF)
    // '\v'	(0x0b)	vertical tab (VT)
    // '\f'	(0x0c)	feed (FF)
    // '\r'	(0x0d)	carriage return (CR)
    pch = strtok(lineContent, " \t\n\r\v\f\r");
    while (pch != NULL)
    {
        strcat(formatedLine, pch);
        strcat(formatedLine, " ");
        pch = strtok(NULL, " \t\n\r\v\f\r");
    }

    clearString(lineContent, MAX_LINE_LENGTH);
    strcpy(lineContent, formatedLine);

    return;
}

void toUpperCase(char *lineContent)
{
    int i = 0;
    while (i < strlen(lineContent))
    {
        lineContent[i] = toupper(lineContent[i]);
        i++;
    }

    return;
}

int validInitialCharacter(char *lineContent)
{
    return !(lineContent[0] == '\n' || lineContent[0] == ';' || lineContent[0] == '\0');
}

int isPureLabel(char *lineContent)
{
    int countToken = 0;
    char *pch, *formatedLine = malloc(strlen(lineContent));

    pch = strtok(lineContent, ":");
    while (pch != NULL)
    {
        if (countToken == 0)
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

    clearString(lineContent, MAX_LINE_LENGTH);
    strcpy(lineContent, formatedLine);

    return countToken;
}

int isEQU(char *lineContent)
{
    char *pch;
    pch = strstr(lineContent, "EQU");

    if (pch != NULL) return 1;

    return 0;
}

void changeForEQUValue(char *lineContent, EQU equ)
{
    char *pch;

    pch = strstr(lineContent, equ.label);
    if (pch != NULL) strncpy(pch, equ.value, MAX_TOKEN_LENGTH);
    return;
}

int isIF(char *lineContent)
{
    char *pch;
    pch = strstr(lineContent, "IF");

    if (pch != NULL) return 1;

    return 0;
}

int getIfValue(char *lineContent)
{
    char *pch, *formatedLine = malloc(strlen(lineContent));

    pch = strtok(lineContent, " ");
    pch = strtok(NULL, " \n");
    strcat(formatedLine, pch);

    return atoi(formatedLine);
}
