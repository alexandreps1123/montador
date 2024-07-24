#include "messages.h"

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

void openFileErrorMessage()
{
    printf("Erro ao abrir arquivo.\n");
    exit(1);
}

void parserErrorMessage(int countLine)
{
    printf("Erro lexico, linha: %d\n", countLine);
    return;
}

void opcodeInvalidErrorMessage(int countLine)
{
    printf("Instrucao invalida, linha: %d\n", countLine);
    return;
}

void doubleLabelSameLineErrorMessage(int countLine)
{
    printf("Rotulo dobrado, linha: %d\n", countLine);
    return;
}
