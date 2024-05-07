#include "messages.h"
#include "handle_input.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    checkArgs(argc, argv);

    printf("Passou\n");

    return 0;
}

void readFile(char flag[], char fileName[])
{
    // char str[] = fileName;
    char *pch;
    pch = strtok(fileName, ".");
    while (pch != NULL)
    {
        printf("%s\n", pch);
        pch = strtok(NULL, ".");
    }
    
}
