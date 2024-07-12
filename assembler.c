#include <ctype.h>
#include "assembler.h"


void assembler(char *filePath)
{
    MEMORIA memoria[MAX_MEMORIA];

    FILE *pFile;
    pFile = openFile(filePath);
    
    Text text;
    createText(&text);

    int PC = 0;
    int countLine = 1;
    int countToken = 0;
    int countTokenPerline = 0;
    int isConst = 0;

    Line lineContent;

    while (fgets(lineContent.line, MAX_LINE_LENGTH, pFile) != NULL)
    {
        char *pch;
    
        pch = strtok(lineContent.line, " ,\n");

        while (pch != NULL)
        {
            clearString(memoria[countToken].token, MAX_TOKEN_LENGTH);
            
            if(isLabelDefinition(pch)) 
            {
                // TODO: resolver na tabela de simbolos
                parser(pch, countLine);
                pch = strtok(NULL, " ,\n");
                continue;
            }

            if(isConst==1) 
            {
                isConst = 0;
                printf("%d  %s\n", PC, pch);
            }

            if (strcmp(tokenToOPCODE(pch), "99") != 0) 
            {
                printf("%d  %s\n", PC, pch);
            }
            else if(strcmp(pch, "CONST")==0) 
            {
                pch = strtok(NULL, " ,\n");
                countTokenPerline++;
                isConst = 1;
                continue;
            }
            else if(countTokenPerline==0)
            {
                opcodeInvalidErrorMessage(countLine);
            }

            strcpy(memoria[countToken].token, pch);
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
        // if(strcmp(memoria[countLine].token, "\n") != 0) {
            printf("%s\n", memoria[i].token);
        // }
    }

    writeFile(filePath, &text);

    fclose(pFile);
    return;
}

void parser(char *token, int countLine) 
{
    if (isNotValidFirstCharacter(token)!=0) 
    {
        parserErrorMessage(countLine);
    }

    return;
}

int isNotValidFirstCharacter(char *lineContent)
{
    return !(lineContent[0] == '_' || isalpha(lineContent[0]));
}

int isOPCODE(char* token) {
    return strcmp(token, "SPACE") || strcmp(token, "ADD") || strcmp(token, "SUB") || strcmp(token, "MUL") ||
            strcmp(token, "DIV") || strcmp(token, "JMP") || strcmp(token, "JMPN") || strcmp(token, "JMPP") || 
            strcmp(token, "JMPZ") || strcmp(token, "COPY") || strcmp(token, "LOAD") || strcmp(token, "STORE") ||
            strcmp(token, "INPUT") || strcmp(token, "OUTPUT") || strcmp(token, "STOP");
}

char* tokenToOPCODE(char* token) {
    if(strcmp(token, "SPACE")==0) 
    {
        return strcpy(token, SPACE);
    }
    else if(strcmp(token, "ADD")==0) 
    {
        return strcpy(token, ADD);
    }
    else if(strcmp(token, "SUB")==0) 
    {
        return strcpy(token, SUB);
    }
    else if(strcmp(token, "MUL")==0) 
    {
        return strcpy(token, MUL);
    }
    else if(strcmp(token, "DIV")==0) 
    {
        return strcpy(token, DIV);
    }
    else if(strcmp(token, "JMP")==0) 
    {
        return strcpy(token, JMP);
    }
    else if(strcmp(token, "JMPN")==0) 
    {
        return strcpy(token, JMPN);
    }
    else if(strcmp(token, "JMPP")==0) 
    {
        return strcpy(token, JMPP);
    }
    else if(strcmp(token, "JMPZ")==0) 
    {
        return strcpy(token, JMPZ);
    }
    else if(strcmp(token, "COPY")==0) 
    {
        return strcpy(token, COPY);
    }
    else if(strcmp(token, "LOAD")==0) 
    {
        return strcpy(token, LOAD);
    }
    else if(strcmp(token, "STORE")==0) 
    {
        return strcpy(token, STORE);
    }
    else if(strcmp(token, "INPUT")==0) 
    {
        return strcpy(token, INPUT);
    }
    else if(strcmp(token, "OUTPUT")==0) 
    {
        return strcpy(token, OUTPUT);
    }
    else if(strcmp(token, "STOP")==0) 
    {
        return strcpy(token, STOP);
    }

    return "99";
}

int isDigitOrXDigit(char *token) {
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