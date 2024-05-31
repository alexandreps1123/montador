#include "file_handler.h"

FILE* openFile(char *filePath)
{
	FILE* pFile;

	pFile = fopen(filePath, "r");
	if (pFile == NULL) openFileErrorMessage();

	return pFile;
}

void writeFile(char *filePath, Text *text)
{
	FILE* pFile;
	Line line;

	if(strcmp(getExtFile(filePath), "asm")==0) 
	{
		pFile = fopen(strcat(getNameFile(filePath),".pre"), "w");
	} 
	else pFile = fopen(strcat(getNameFile(filePath),".obj"), "w");

	while (isEmpty(text) != 1)
	{
		line = *(printHead(text));
		fputs(line.line, pFile);
		fputs("\n", pFile);

		dequeue(text);
	}

	fclose(pFile);

	return;
}
