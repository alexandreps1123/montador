#include "messages.h"
#include <stdio.h>
#include <stdlib.h>

void helpMessage()
{
    printf(
        "Uso: ./montador [options] arquivo...\n"
        "Options:\n"
        "\t-help\t\t\tApresenta esta tela.\n"
        "\t-p <file>.asm\t\tGera um arquivo pre-processado <file>.pre\n"
        "\t-o <file>.pre\t\tGera o arquivo objeto <file>.obj\n");
    exit(0);
}

void invalidOptionMessage()
{
    printf("Option invalida.\n");
    exit(1);
}

void invalidExtensionMessage()
{
    printf("Extensao invalida.\n");
    exit(1);
}