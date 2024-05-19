#include "messages.h"
#include "input_handler.h"
#include "file_handler.h"
#include "pre_processor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Função para remover espaços em branco extras de uma linha
// void trim(char *str) {
//     int i = 0, j = -1;
//     while (str[i]) {
//         if (!isspace(str[i]) || (i > 0 && !isspace(str[i - 1]))) {
//             str[++j] = str[i];
//         }
//         i++;
//     }
//     str[++j] = '\0';
// }

// void preProcessor(char *str){

// }

// void assembler(char *str){
//     switch(){
//         case 1:
//             break;
//         default:
//             break;
//     }
// }



int main(int argc, char *argv[])
{
    FILE *pFile;

    checkArgs(argc, argv);

    if(strcmp(argv[1], "-p")==0)
    {

        pFile = openFile(argv[2]);
        preProcessor(pFile);

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
