#include "file_handler.h"

FILE* readFile(char *filePath)
{
	FILE* pFile;

	pFile = fopen(filePath, "r");
	if (pFile == NULL) openFileErrorMessage();

	return pFile;
}

void writeFile(char *filePath)
{
	FILE* pFile;
	char *ext, *newfilePath;
	char *test = "teste";

	if(strcmp(getExtFile(filePath), "asm")==0) 
	{
		pFile = fopen(strcat(getNameFile(filePath),".pre"), "w");
	} 
	else pFile = fopen(strcat(getNameFile(filePath),".obj"), "w");

	fputs(test, pFile);

	fclose(pFile);

	return;
}
