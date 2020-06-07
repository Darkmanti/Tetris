#define _CRT_SECURE_NO_WARNINGS
#define UNICODE

#include <Windows.h>
#include <fileapi.h>

int main()
{
	DWORD read;
	HANDLE file = CreateFile(L"../../../src/Localisation.h", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
	LARGE_INTEGER fileSize;
	GetFileSizeEx(file, &fileSize);
	void* buffer = malloc(fileSize.QuadPart);
	memset(buffer, 0, fileSize.QuadPart);
	ReadFile(file, buffer, fileSize.QuadPart, &read, NULL);
	CloseHandle(file);

	char* nBuffer = strstr((char*)buffer, "enum localisationEnumerable");

	unsigned int  maxSize = 0;
	unsigned int  maxStrings = 0;
	while (nBuffer[maxSize] != ';')
	{
		if (nBuffer[maxSize] == '\n')
			maxStrings++;
		maxSize++;
	}

	unsigned int* massStringsLen = (unsigned int*)malloc(maxStrings * (sizeof(unsigned int)));
	memset(massStringsLen, 0, maxStrings * (sizeof(unsigned int)));

	char* Template = (char*)malloc(maxSize);
	memset(Template, 0, maxSize);
	char* offsetTemplate = Template;

	unsigned int stringCounter = 0;
	unsigned int i = 28;
	char* offsetBegin = NULL;
	unsigned short offsetEnd = 0;

	while (nBuffer[i] != 'l')
		i++;

	while (nBuffer[i] != ';')
	{
		if ((nBuffer[i] != ' ') && (nBuffer[i] != ',') && (nBuffer[i] > 32))
		{
			if (offsetBegin == NULL)
			{
				offsetBegin = nBuffer + i;
			}
			offsetEnd++;
		}
		else if(offsetBegin && (stringCounter <= (maxStrings - 4)))
		{
			memcpy(offsetTemplate, offsetBegin, offsetEnd);
			offsetTemplate = offsetTemplate + offsetEnd;
			massStringsLen[stringCounter] = offsetEnd;
			stringCounter++;
			offsetBegin = NULL;
			offsetEnd = 0;

			while ((nBuffer[i] != ',') && (nBuffer[i] != '}'))
				i++;
		}

		i++;
	}
	i = 0;

	char* writeTemplate = (char*)malloc(strlen(Template) + ((maxStrings - 3) * 7));
	memset(writeTemplate, 0, strlen(Template) + ((maxStrings - 3) * 7));

	offsetBegin = writeTemplate;

	for (i = 0; i < stringCounter; i++)
	{
		unsigned int offset = 0;
		for (unsigned int j = 0; j < i; j++)
			offset = offset + massStringsLen[j];

		memcpy(offsetBegin, Template + offset, massStringsLen[i]);
		offsetBegin = offsetBegin + massStringsLen[i];
		strcat(writeTemplate, " = \"\"\n");
		offsetBegin = offsetBegin + 6;
	}

	// "../../../res/Localisation/Template.txt"
	file = CreateFile(L"../../../res/Localisation/Template.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD toWrite;
	WriteFile(file, writeTemplate, strlen(Template) + ((maxStrings - 3) * 7), &toWrite, NULL);
	CloseHandle(file);

	// maybe little more than 123
	unsigned int sizeToWriteFunc = strlen(Template) + 90 + (40 * stringCounter) + 70;
	
	char* writeMetaEnumFunc = (char*)malloc(sizeToWriteFunc);
	memset(writeMetaEnumFunc, 0, sizeToWriteFunc);

	strcat(writeMetaEnumFunc, 
R"(#pragma once

char* GetLocEnumString(unsigned int number)
{
	switch(number)
	{
)");

	for (i = 0; i < stringCounter; i++)
	{
		char value[16];
		char temp[256];
		strcpy(temp, "\t\tcase ");
		_itoa(i, value, 10);
		strcat(temp, value);
		strcat(temp, ": { return (char*)\"");

		unsigned int offset = 0;
		for (unsigned int j = 0; j < i; j++)
			offset = offset + massStringsLen[j];

		char* strstrsearch = strstr(temp, "\"") + 1;
		memcpy(strstrsearch, Template + offset, massStringsLen[i]);
		memcpy(strstrsearch + massStringsLen[i], "\"; } break;\n\0", 14);
		//strcat(temp, "\"; } break;\n");
		strcat(writeMetaEnumFunc, temp);
	}

	strcat(writeMetaEnumFunc, "\t\tdefault: { return (char*)\"ERROR: desired string not found\"; } break;\n");
	strcat(writeMetaEnumFunc,
R"(	}
})");

	file = CreateFile(L"../MetaLocEnumFunc.h", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	toWrite = 0;
	WriteFile(file, writeMetaEnumFunc, sizeToWriteFunc, &toWrite, NULL);
	CloseHandle(file);

	free(buffer);
	free(massStringsLen);
	free(Template);
	free(writeTemplate);
	free(writeMetaEnumFunc);
	return 0;
}