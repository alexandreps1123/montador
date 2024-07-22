#include "pre_processor.h"

void clearString(char *lineContent, int length)
{
    int i = 0;
    while (i < length)
    {
        lineContent[i] = '\0';
        i++;
    }
}

int isLabelDefinition(char *lineContent)
{
    int i = 0;

    while (i < MAX_LINE_LENGTH)
    {
        if (lineContent[i] == ':') return 1;

        i++;
    }

    return 0;
}

