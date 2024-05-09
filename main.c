#include "messages.h"
#include "input_handler.h"
#include "file_handler.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *pFile;

    checkArgs(argc, argv);

    if(strcmp(argv[1], "-p")==0)
    {

        pFile = openFile(argv[2]);
        // preProcessor();

        writeFile(argv[2]);

        fclose(pFile);
    } 
    else if(strcmp(argv[1], "-o")==0)
    {
        pFile = openFile(argv[2]);

        // assembler();

        writeFile(argv[2]);

        fclose(pFile);
    }

    return 0;
}
