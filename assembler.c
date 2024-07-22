#include <ctype.h>
#include "assembler.h"

void assembler(char *filePath)
{
    MEMORIA memoria[MAX_MEMORIA];
    TABELA_SIMBOLOS tabelaSimbolos[MAX_MEMORIA];

    FILE *pFile;
    pFile = openFile(filePath);

    Line lineContent;

    Text text;
    createText(&text);

    int PC = 0;
    int countLine = 1;
    int countToken = 0;
    int countTokenPerline = 0;
    int countSimbol = 0;
    int isConst = 0;
    char subString[MAX_TOKEN_LENGTH];

    while (fgets(lineContent.line, MAX_LINE_LENGTH, pFile) != NULL)
    {
        char *pch;

        pch = strtok(lineContent.line, " ,\n");

        while (pch != NULL)
        {
            clearString(memoria[countToken].token, MAX_TOKEN_LENGTH);

            // printf("%d  %s\n", isLabelDefinition(pch), pch);
            if (isLabelDefinition(pch))
            {
                parser(pch, countLine);

                clearString(tabelaSimbolos[countSimbol].simbolo, MAX_TOKEN_LENGTH);
                strcpy(tabelaSimbolos[countSimbol].simbolo, pch);
                tabelaSimbolos[countSimbol].def = 1;
                tabelaSimbolos[countSimbol].valor = PC;
                
                countSimbol++;

                pch = strtok(NULL, " ,\n");

                continue;
            }

            if (isConst == 1)
            {
                strcpy(memoria[countToken].token, pch);

                pch = strtok(NULL, " ,\n");
                countTokenPerline++;
                countToken++;
                PC++;
                isConst = 0;

                continue;
            }

            // verifica opcode
            if (strcmp(tokenToOPCODE(pch), "99") != 0)
            {
                strcpy(memoria[countToken].token, pch);
                // printf("%d  %s\n", PC, pch);
            }
            // se const pula pro proximo token
            else if (strcmp(pch, "CONST") == 0)
            {
                pch = strtok(NULL, " ,\n");
                countTokenPerline++;
                isConst = 1;
                continue;
            }
            // se n encontrou opcode/diretiva na primeira posicao da linha, ou depois de uma decalacao de label
            else if (countTokenPerline == 0)
            {
                opcodeInvalidErrorMessage(countLine);
            }
            else
            {
                parser(pch, countLine);

                clearString(tabelaSimbolos[countSimbol].simbolo, MAX_TOKEN_LENGTH);
                strcpy(memoria[countToken].token, pch);
                strcpy(tabelaSimbolos[countSimbol].simbolo, pch);
                tabelaSimbolos[countSimbol].def = 0;
                tabelaSimbolos[countSimbol].valor = PC;
                
                countSimbol++;

                // pch = strtok(NULL, " ,\n");

                // continue;
            }

            // printf("%d  %s\n", PC, pch);

            pch = strtok(NULL, " ,\n");
            countTokenPerline++;
            countToken++;
            PC++;
        }

        countTokenPerline = 0;
        countLine++;

        // label is defined?
        // if (isLabelDefinition(lineContent.line) == 1) {
        //     parser(lineContent.line, countLine,  ":");
        //     printf("%d\n", countLine);
        // }

        // countLine++;
    }

    for (int i = 0; i < countToken; i++)
    {
        clearString(lineContent.line, MAX_LINE_LENGTH);
        for (int j = 0; j < countSimbol; j++)
        {
            clearString(subString, MAX_TOKEN_LENGTH);
            char* pch = strstr(tabelaSimbolos[j].simbolo, memoria[i].token);

            if(tabelaSimbolos[j].def==1 && pch!=NULL)
            {
                int address = tabelaSimbolos[j].valor;

                for (int k = 0; k < countSimbol; k++)
                {
                    if(strcmp(tabelaSimbolos[k].simbolo, memoria[i].token)==0)
                    {
                        char str[20];

                        // int to string
                        sprintf(str, "%d", address);

                        strcpy(memoria[tabelaSimbolos[k].valor].token, str);
                    }
                }
            }
        }

        // put data into
        strcpy(lineContent.line, memoria[i].token);
        // printf("%d %s\n", i, memoria[i].token);
        enqueue(&text, &lineContent);
    }

    // printf("\n\ntabela de simbolos\n");
    // for (int i = 0; i < countSimbol; i++)
    // {
    //     // if(strcmp(memoria[countLine].token, "\n") != 0) {
    //     printf("%s\n", tabelaSimbolos[i].simbolo);
    //     printf("%d\n", tabelaSimbolos[i].def);
    //     printf("%d\n", tabelaSimbolos[i].valor);
    //     // }
    // }

    writeFile(filePath, &text);

    fclose(pFile);
    return;
}

void parser(char *token, int countLine)
{
    if (isNotValidFirstCharacter(token) != 0)
    {
        parserErrorMessage(countLine);
    }

    return;
}

int isNotValidFirstCharacter(char *lineContent)
{
    return !(lineContent[0] == '_' || isalpha(lineContent[0]));
}

int isOPCODE(char *token)
{
    return strcmp(token, "SPACE") || strcmp(token, "ADD") || strcmp(token, "SUB") || strcmp(token, "MUL") ||
           strcmp(token, "DIV") || strcmp(token, "JMP") || strcmp(token, "JMPN") || strcmp(token, "JMPP") ||
           strcmp(token, "JMPZ") || strcmp(token, "COPY") || strcmp(token, "LOAD") || strcmp(token, "STORE") ||
           strcmp(token, "INPUT") || strcmp(token, "OUTPUT") || strcmp(token, "STOP");
}

char *tokenToOPCODE(char *token)
{
    if (strcmp(token, "SPACE") == 0)
    {
        return strcpy(token, SPACE);
    }
    else if (strcmp(token, "ADD") == 0)
    {
        return strcpy(token, ADD);
    }
    else if (strcmp(token, "SUB") == 0)
    {
        return strcpy(token, SUB);
    }
    else if (strcmp(token, "MUL") == 0)
    {
        return strcpy(token, MUL);
    }
    else if (strcmp(token, "DIV") == 0)
    {
        return strcpy(token, DIV);
    }
    else if (strcmp(token, "JMP") == 0)
    {
        return strcpy(token, JMP);
    }
    else if (strcmp(token, "JMPN") == 0)
    {
        return strcpy(token, JMPN);
    }
    else if (strcmp(token, "JMPP") == 0)
    {
        return strcpy(token, JMPP);
    }
    else if (strcmp(token, "JMPZ") == 0)
    {
        return strcpy(token, JMPZ);
    }
    else if (strcmp(token, "COPY") == 0)
    {
        return strcpy(token, COPY);
    }
    else if (strcmp(token, "LOAD") == 0)
    {
        return strcpy(token, LOAD);
    }
    else if (strcmp(token, "STORE") == 0)
    {
        return strcpy(token, STORE);
    }
    else if (strcmp(token, "INPUT") == 0)
    {
        return strcpy(token, INPUT);
    }
    else if (strcmp(token, "OUTPUT") == 0)
    {
        return strcpy(token, OUTPUT);
    }
    else if (strcmp(token, "STOP") == 0)
    {
        return strcpy(token, STOP);
    }

    return "99";
}

void storeInSimbolTable() {

}

int isDigitOrXDigit(char *token)
{
    int checkDigit = 0;
    int checkXDigit = 0;

    for (int i = 0; strlen(token) > i; i++)
    {
        if (!isdigit(token[i]))
        {
            checkDigit++;
        }
        if (!isxdigit(token[i]))
        {
            checkXDigit++;
        }
    }

    return checkDigit == 0 || checkXDigit == 0;
}
