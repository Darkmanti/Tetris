#define STB_IMAGE_IMPLEMENTATION
#define STB_TRUETYPE_IMPLEMENTATION

#include <winsock2.h>
#include <windows.h>
#include <stdarg.h>
#include "glcorearb.h"
#include "wgl.h"
#include "wglext.h"
#include "Math.h"
#include "OpenGLLoader.h"
#include "DebugConsole.h"
#include "Settings.h"
#include "Tetris.h"

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

HWND hMainWnd = {};
MSG msg = {};

int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//Disable windows app scaling
	SetProcessDPIAware();

	con::InitParam(lpCmdLine);
	con::Out("RABOTAET CONSOL\n");

	con::Outf("privet parametri: %i, %s\n", 20, "rubley");

	InitSettingsFunc();

	HICON icon = (HICON)LoadImage(NULL, TEXT("../res/icon.ico"), IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
	if (!icon)
	{
		con::SetConColor(FOREGROUND_RED);
		con::Out("error loading icon\n");
		con::SetConColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}

	WNDCLASSEX MainWindowClass = {};
	MainWindowClass.cbSize = sizeof(WNDCLASSEX);
	MainWindowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	MainWindowClass.lpfnWndProc = MainWndProc;
	MainWindowClass.hInstance = hInstance;
	MainWindowClass.hIcon = icon;
	MainWindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	MainWindowClass.lpszClassName = "MainTetrisWindow";
	MainWindowClass.hIconSm = icon;

	if (!RegisterClassEx(&MainWindowClass))
	{
		MessageBox(NULL, "error to creae a class", "error", MB_OK);
		return NULL;
	}

	hMainWnd = CreateWindow(
		MainWindowClass.lpszClassName, // name windows class
		"Tetris", // name window
		WS_OVERLAPPEDWINDOW, // The style
		CW_USEDEFAULT, // position window on x axis //CW_USEDEFAULT
		CW_USEDEFAULT, // position window on y axis //CW_USEDEFAULT
		1920, // width window //CW_USEDEFAULT
		1080, // height window
		NULL, // A handle to the parent or owner window
		NULL, // A handle to a menu
		hInstance, // A handle to the instance
		NULL); // ????????????????????

	if (!hMainWnd)
	{
		MessageBox(NULL, "error to create a window", "error", MB_OK);
		return NULL;
	}

	ShowWindow(hMainWnd, nCmdShow);
	UpdateWindow(hMainWnd);

	// Create Context OpenGL
	CreateContextOpenGL(hMainWnd);

	// Load OpenGL functions
	funcTable = LoadOpenGLFunctions();

	// Start the game process
	Tetris();

	DeleteContextOpenGL(hMainWnd);
	return msg.wParam;
}

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_DESTROY:
		{
			PostQuitMessage(NULL);
		} break;
		case WM_KEYDOWN:
		{
			switch (wParam)
			{
				case VK_ESCAPE:
				{
					PostQuitMessage(NULL);
				} break;
			}
		} break;
		case WM_MOVE:
		{
			// x and y coord position of window
			Outf("%i   %i\n", (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam));
		} break;
		case WM_SIZE:
		{
			// something
		} break;
		default:
		{
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
		} break;
	}
	return NULL;
}