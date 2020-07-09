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

	WCHAR** locArray = (WCHAR**)malloc(NUMBERSoflocEnum * sizeof(WCHAR*));

	for (u32 i = 0; i < NUMBERSoflocEnum; i++)
	{
		const WCHAR* targetString = GetLocEnumString(i);
		u16 targetStringLen = wcslen(targetString);
		WCHAR* locString = wcsstr(Wbuffer, targetString);
		if (locString == NULL)
		{
			locArray[i] = (WCHAR*)malloc((targetStringLen + 11) * sizeof(WCHAR));
			memset(locArray[i], 0, (targetStringLen + 11) * sizeof(WCHAR));
			wcscat(locArray[i], L"not_found_");
			wcscat(locArray[i], targetString);
			continue;
		}
		locString = locString + targetStringLen + 4;

		u16 length = 0;
		while (locString[length] != L'"')
			length++;

		if (length == 0)
		{
			locArray[i] = (WCHAR*)malloc((targetStringLen + 7) * sizeof(WCHAR));
			memset(locArray[i], 0, (targetStringLen + 7) * sizeof(WCHAR));
			wcscat(locArray[i], L"zero_");
			wcscat(locArray[i], targetString);
			continue;
		}

		locArray[i] = (WCHAR*)malloc((length + 1) * sizeof(WCHAR));
		memset(locArray[i], 0, (length + 1) * sizeof(WCHAR));
		memcpy(locArray[i], locString, length * sizeof(WCHAR));
	}

	free(Wbuffer);
	return locArray;
}

void FreeLocalisationBuffer(WCHAR** buffer)
{
	if (buffer != NULL)
	{
		for (u32 i = 0; i < NUMBERSoflocEnum; i++)
		{
			free(buffer[i]);
		}
		free(buffer);
	}
}

WCHAR** InitLanguageThroughTextValue(const u8* value)
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

	return locArray;
}