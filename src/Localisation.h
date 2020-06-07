#pragma once
#include "../meta/MetaEnumGen/MetaLocEnumFunc.h"

enum localisationEnumerable
{
	locEnum_Tetris = 0,
	locEnum_Singleplayer,
	locEnum_Multiplayer,
	locEnum_Settings,
	locEnum_Exit,
	NUMBERSoflocEnum
};

WCHAR** ReadLocaleTextFromFile(void* buffer, PLARGE_INTEGER bufferSize)
{
	//https://www.codeproject.com/Tips/317642/Handling-simple-text-files-in-C-Cplusplus

	i32 length = MultiByteToWideChar(CP_UTF8, NULL, (char*)buffer, bufferSize->QuadPart, NULL, NULL);
	WCHAR* Wbuffer = (WCHAR*)malloc(length * sizeof(WCHAR));
	memset(Wbuffer, 0, length * sizeof(WCHAR));
	length = MultiByteToWideChar(CP_UTF8, NULL, (char*)buffer, bufferSize->QuadPart, Wbuffer, length);

	char* proverka = GetLocEnumString(0);

	WCHAR** locArray = (WCHAR**)malloc(NUMBERSoflocEnum);
	locArray[locEnum_Tetris] = wcsstr(Wbuffer, L"locEnum_Tetris");

	free(Wbuffer);
	return locArray;
}

void FreeLocaleBuffer(WCHAR** buffer)
{
	for (u32 i = 0; i < NUMBERSoflocEnum; i++)
	{
		free(buffer[i]);
	}
	free(buffer);
}

void InitLanguageThroughTextValue(const u8* value)
{
	char path[256];
	memset(path, 0, 256);
	strcpy(path, "../res/Localisation/");
	strcat(path, (const char*)value);
	strcat(path, ".txt");

	LARGE_INTEGER bufferSize = {};
	void* buffer = ReadFileToBuffer(path, &bufferSize);

	WCHAR** locArray = ReadLocaleTextFromFile(buffer, &bufferSize);

	FreeBufferFromFile(buffer);
}