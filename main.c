#include "messages.h"
#include "input_handler.h"
#include "pre_processor.h"
#include "assembler.h"

int main(int argc, char *argv[])
{
    checkArgs(argc, argv);

    if(strcmp(argv[1], "-p")==0)
    {
        preProcessor(argv[2]);
    } 
    else if(strcmp(argv[1], "-o")==0)
    {
        assembler(argv[2]);
    }

    return 0;
}
