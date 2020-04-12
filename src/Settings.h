#pragma once
//#include "DebugConsole.h"

struct SettingsTagStruct
{
	i32 MainWindowHeight;
	i32 MainWindowWidth;
};

SettingsTagStruct settings = {};

void SetSetting(const u8* setting, const u8* value)
{

}

void InitSettingsFunc()
{
	DWORD read;

	HANDLE file = CreateFile("../res/settings.ini", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
	LARGE_INTEGER fileSize;
	GetFileSizeEx(file, &fileSize);
	LPVOID buffervoid = malloc(fileSize.QuadPart + 1);
	ReadFile(file, buffervoid, fileSize.QuadPart, &read, NULL);
	CloseHandle(file);

	u8* buffer = (u8*)buffervoid;

	u32 i = 0, c = 0;
	u8 setting[32];
	u8 value[32];

	// parsing ini file
	while (i < fileSize.QuadPart)
	{
		c = 0;
		memset(setting, 0, 32);
		memset(value, 0, 32);

		if (((buffer[i] >= 65) && (buffer[i] <= 90)) || ((buffer[i] >= 97) && (buffer[i] <= 122)))
		{
			while (buffer[i + c] != '=')
				c++;

			memcpy(setting, buffer + i, c);
			
			i = i + c + 1;
			c = 0;

			while ((buffer[i + c] != '\r') && (buffer[i + c] != '\n'))
				c++;

			memcpy(value, buffer + i, c);

			i = i + c;

			SetSetting(setting, value);
		}

		while (buffer[i] != '\n')
			i++;
		i++;
		
	}

	free(buffervoid);
}
