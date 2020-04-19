#pragma once

enum localisationEnumerable
{
	locEnum_Tetris = 0,
	locEnum_Singleplayer,
	locEnum_Multiplayer,
	locEnum_Settings,
	locEnum_Exit,
	NUMBERSoflocEnum
};

WCHAR** ReadLocaleTextFromFile(u8* buffer, PLARGE_INTEGER fileSize)
{
	WCHAR** locArray = (WCHAR**)malloc(NUMBERSoflocEnum);

	u32 i = 0;
	u32 c = 0;

	//MultiByteToWideChar(CP_ACP, WC_SEPCHARS, buffer, )

	WCHAR* buf = (WCHAR*)buffer;

	while (i < fileSize->QuadPart)
	{
		if (buf[i] == '=')
			Outf("=\n");
		i++;
	}

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

	LARGE_INTEGER fileSize;
	u8* buffer = ReadFileToBuffer(path, &fileSize);

	ReadLocaleTextFromFile(buffer, &fileSize);

	FreeBufferFromFile(buffer);
}