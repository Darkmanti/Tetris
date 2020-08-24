#pragma once
#include "DebugConsole.h"

struct SettingsTagStruct
{
	RECT RealWindowSize = {};
	i32 MainWindowWidth = 800;
	i32 MainWindowHeight = 600;
	f32 AspectRatioWidth = 4;
	f32 AspectRatioHeight = 3;
	i32 FullScreen = 0;

	MONITORINFOEXW monitorInfo = {};

	u16 locale = 0;
	WCHAR** locArray = NULL;

	POINT cursorPos = {};
};

SettingsTagStruct settings = {};

void SetSettingConsole(const u8* value)
{
	if ((value[0] == '1') && (debugConsole == NULL))
	{
		AllocConsole();
		//can use to bind new console
		//freopen("CONOUT$", "w", stdout);
		debugConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTitle("Tetris_Console");
	}
}

// add checking for errors
void SetSettingWidth(const u8* value)
{
	settings.MainWindowWidth = atoi((const char*)value);
}

void SetSettingWidth(const i32 value)
{
	settings.MainWindowWidth = value;
}

void SetSettingHeight(const u8* value)
{
	settings.MainWindowHeight = atoi((const char*)value);
}

void SetSettingHeight(const i32 value)
{
	settings.MainWindowHeight = value;
}

void SetSettingAspectRation(const u8* value)
{
	settings.AspectRatioWidth = atoi((const char*)value);
	settings.AspectRatioHeight = atoi((strchr((const char*)value, '/'))+1);
}

// https://devblogs.microsoft.com/oldnewthing/20100412-00/?p=14353
// FullScreen
void SetSettingFullScreen(const u8* value)
{
	DWORD dwStyle = GetWindowLong(hMainWnd, GWL_STYLE);

	if (value[0] == '0')
	{
		settings.RealWindowSize.left = 0;
		settings.RealWindowSize.top = 0;
		settings.RealWindowSize.right = settings.MainWindowWidth;
		settings.RealWindowSize.bottom = settings.MainWindowHeight;
		AdjustWindowRectEx(&settings.RealWindowSize, dwStyle, NULL, NULL);

		SetWindowLong(hMainWnd, GWL_STYLE,
			dwStyle | WS_OVERLAPPEDWINDOW);

		SetWindowPos(hMainWnd, NULL, 0, 0,
			Abs((i32)settings.RealWindowSize.left) + Abs((i32)settings.RealWindowSize.right),
			Abs((i32)settings.RealWindowSize.top) + Abs((i32)settings.RealWindowSize.bottom),
			SWP_NOMOVE | SWP_NOZORDER |
			SWP_NOOWNERZORDER | SWP_FRAMECHANGED);

		glViewport(0, 0, settings.MainWindowWidth, settings.MainWindowHeight);
		settings.FullScreen = 0;
	}
	else if (value[0] == '1')
	{
		// TO DO with AdjustWindowRectEx
		SetWindowLong(hMainWnd, GWL_STYLE,
			dwStyle & ~WS_OVERLAPPEDWINDOW);
		SetWindowPos(hMainWnd, HWND_TOP,
			settings.monitorInfo.rcMonitor.left, settings.monitorInfo.rcMonitor.top,
			settings.monitorInfo.rcMonitor.right - settings.monitorInfo.rcMonitor.left,
			settings.monitorInfo.rcMonitor.bottom - settings.monitorInfo.rcMonitor.top,
			SWP_NOOWNERZORDER | SWP_FRAMECHANGED);

		glViewport(0, 0, settings.monitorInfo.rcMonitor.right - settings.monitorInfo.rcMonitor.left, 
			settings.monitorInfo.rcMonitor.bottom - settings.monitorInfo.rcMonitor.top);
		settings.FullScreen = 1;
	}
	else if (value[0] == '2')
	{
		settings.FullScreen = 2;
	}
}

void LockCursorInWindow()
{
	WINDOWPLACEMENT wndPlace = {};
	wndPlace.length = sizeof(WINDOWPLACEMENT);
	GetWindowPlacement(hMainWnd, &wndPlace);
	i32 smallBorder = (wndPlace.rcNormalPosition.right - settings.MainWindowWidth - wndPlace.rcNormalPosition.left) / 2;
	i32 bigBorder = wndPlace.rcNormalPosition.bottom - settings.MainWindowHeight - wndPlace.rcNormalPosition.top - smallBorder;
	wndPlace.rcNormalPosition.left = wndPlace.rcNormalPosition.left + smallBorder;
	wndPlace.rcNormalPosition.top = wndPlace.rcNormalPosition.top + bigBorder;
	wndPlace.rcNormalPosition.right = wndPlace.rcNormalPosition.right - smallBorder;
	wndPlace.rcNormalPosition.bottom = wndPlace.rcNormalPosition.bottom - smallBorder;
	ClipCursor(&wndPlace.rcNormalPosition);
}

void SetSettingLocalisation(const u8* value)
{
	FreeLocalisationBuffer(settings.locArray);
	settings.locArray = InitLanguageThroughTextValue(value);
}

void ReCalcOrthoProjection(m4* ortho)
{
	*ortho = Orthographic(0.0f, settings.MainWindowWidth, 0.0f, settings.MainWindowHeight, -100.0f, 100.0f);
	Outf("%i    %i\n", settings.MainWindowWidth, settings.MainWindowHeight);
}

void SetSetting(const u8* setting, const u8* value)
{
	if (memcmp(setting, (u8*)"Console", 8) == 0)
	{
		SetSettingConsole(value);
	}
	if (memcmp(setting, (u8*)"MainWindowWidth", 16) == 0)
	{
		SetSettingWidth(value);
	}
	if (memcmp(setting, (u8*)"MainWindowHeight", 17) == 0)
	{
		SetSettingHeight(value);
	}
	if (memcmp(setting, (u8*)"AspectRatio", 12) == 0)
	{
		SetSettingAspectRation(value);
	}
	if (memcmp(setting, (u8*)"FullScreen", 11) == 0)
	{
		SetSettingFullScreen(value);
	}
	if (memcmp(setting, (u8*)"Localisation", 13) == 0)
	{
		SetSettingLocalisation(value);
	}
}

void InitSettingsFunc()
{
	const u16 sizeofSetting = 64;
	const u16 sizeofValue = 64;

	LARGE_INTEGER fileSize;
	u8* buffer = (u8*)ReadFileToBuffer("../res/settings.ini", &fileSize);

	u32 i = 0, c = 0;
	u8 setting[sizeofSetting];
	u8 value[sizeofValue];

	// Need move to anther place
	settings.monitorInfo.cbSize = sizeof(MONITORINFOEXW);
	GetMonitorInfoW(MonitorFromWindow(hMainWnd, MONITOR_DEFAULTTOPRIMARY), &settings.monitorInfo);

	// parsing ini file
	while (i < fileSize.QuadPart)
	{
		c = 0;
		memset(setting, 0, sizeofSetting);
		memset(value, 0, sizeofValue);

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

		while ((buffer[i] != '\n') && (i < fileSize.QuadPart))
			i++;
		i++;
		
	}

	FreeBufferFromFile(buffer);
}
