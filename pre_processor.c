#include "pre_processor.h"

const int MAX_LINE_LENGTH = 256;
const int MAX_TOKEN_LENGTH = 80;
const int MAX_EQU_DECLARATION = 20;

void preProcessor(FILE *pFile)
{
    char lineContent[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];

    int countPureLabel = 0;

    int ifAction = 1;

    int countEqu = 0;
    EQU equ[MAX_EQU_DECLARATION];

    // Queue q;

    // createQueue(&q);

    clearString(lineContent, MAX_LINE_LENGTH);
    clearString(line, MAX_LINE_LENGTH);

    while (fgets(lineContent, MAX_LINE_LENGTH, pFile) != NULL)
    {
        removeComments(lineContent);
        removeUnnecessaryCharacters(lineContent);
        toUpperCase(lineContent);

        // TODO: verify if is a label
        if (validInitialCharacter(lineContent))
        {
            if (isLabel(lineContent) == 1 && isPureLabel(lineContent) == 1)
            {
                countPureLabel++;
                strcat(line, lineContent);
            }
            else
            {
                for (int i = 0; i < countEqu; i++)
                {
                    changeForEQUValue(lineContent, equ[i]);
                }
                
                if (countPureLabel != 0)
                {
                    countPureLabel = 0;
                    strcat(line, lineContent);
                    strcpy(lineContent, line);
                    clearString(line, MAX_LINE_LENGTH);
                }

                if (isEQU(lineContent))
                {
                    int countToken = 0;
                    char *pch;

                    pch = strtok(lineContent, ":");

                    strcpy(equ[countEqu].label, pch);

                    while (pch != NULL)
                    {
                        if (countToken == 2)
                            strcpy(equ[countEqu].value, pch);

                        pch = strtok(NULL, " ");
                        countToken++;
                    }

                    countEqu++;

                    clearString(lineContent, MAX_LINE_LENGTH);

                    continue;
                }

                if (isIF(lineContent)) {
                    ifAction = getIfValue(lineContent);
                    continue;
                }

                if(ifAction == 0) {
                    ifAction = 1;
                    continue;
                }
                else printf("%s\n", lineContent);
            }
        }

        clearString(lineContent, MAX_LINE_LENGTH);
    }

    // for (size_t i = 0; i < countEqu; i++)
    // {
    //     // equ = *(printHead(&q));
    //     printf("Numero: %s\n", equ[i].label);
    //     printf("Numero: %s\n", equ[i].value);
    //     // dequeue(&q);
    //     // countEqu--;
    // }

    // TODO: write in a file pre processed data
    // clear(&q);

    return;
}

void clearString(char *lineContent, int length)
{
    int i = 0;
    while (i < length)
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
