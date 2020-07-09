#define STB_IMAGE_IMPLEMENTATION
#define STB_TRUETYPE_IMPLEMENTATION

#include <winsock2.h>
#include <windows.h>
#include <stdarg.h>

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

HWND hMainWnd = {};
MSG msg = {};

#include "glcorearb.h"
#include "wgl.h"
#include "wglext.h"
#include "Math.h"
#include "OpenGLLoader.h"
#include "DebugConsole.h"
#include "Localisation.h"
#include "Settings.h"
#include "Tetris.h"

MainMenu mMenu = {};

int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//Disable windows app scaling
	SetProcessDPIAware();

	con::InitParam(lpCmdLine);

	con::Outf("privet parametri: %i, %s\n", 20, "rubley");

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
		MessageBox(NULL, "error to create a class", "error", MB_OK);
		return NULL;
	}

	settings.RealWindowSize.left = 0;
	settings.RealWindowSize.top = 0;
	settings.RealWindowSize.right = settings.MainWindowWidth;
	settings.RealWindowSize.bottom = settings.MainWindowHeight;
	AdjustWindowRectEx(&settings.RealWindowSize, WS_OVERLAPPEDWINDOW | WS_VISIBLE, NULL, NULL);

	hMainWnd = CreateWindowEx(
		NULL,
		MainWindowClass.lpszClassName, // name windows class
		"Tetris", // name window
		WS_OVERLAPPEDWINDOW | WS_VISIBLE, // The style
		CW_USEDEFAULT, // position window on x axis //CW_USEDEFAULT
		CW_USEDEFAULT, // position window on y axis //CW_USEDEFAULT
		Abs(settings.RealWindowSize.left) + Abs(settings.RealWindowSize.right), // width window //CW_USEDEFAULT
		Abs(settings.RealWindowSize.top) + Abs(settings.RealWindowSize.bottom), // height window
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

	// Create Context OpenGL
	CreateContextOpenGL(hMainWnd);
	// TO DO load EXT Context OpenGL

	// Load OpenGL functions
	funcTable = LoadOpenGLFunctions();

	// Start the game process
	glViewport(0, 0, settings.MainWindowWidth, settings.MainWindowHeight);
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

		case WM_CLOSE:
		{
			PostQuitMessage(NULL);
		} break;

		case WM_ACTIVATEAPP:
		{

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
			//Outf("%i   %i\n", (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam));
		} break;

		case WM_SIZE:
		{
			if (((int)(short)LOWORD(lParam) != settings.MainWindowWidth) || ((int)(short)HIWORD(lParam) != settings.MainWindowHeight))
			{
				//Outf("%i   %i\n", (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam));
				SetSettingWidth((int)(short)LOWORD(lParam));
				SetSettingHeight((int)(short)HIWORD(lParam));
				SetSettingFullScreen((const u8*)"0");
				ReCalcOrthoProjection(&orthoProjection);
				ReCalcOrthoProjection(&mMenu.projection);
			}
		} break;

		case WM_CAPTURECHANGED:
		{
			Outf("WM_CAPTURECHANGED\n");
		} break;

		case WM_MOUSEACTIVATE:
		{
			Outf("WM_MOUSEACTIVATE\n");
		} break;

		case WM_MOUSEMOVE:
		{
			//Outf("%i   %i\n", (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam));
		} break;

		default:
		{
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
		} break;
	}
	return NULL;
}