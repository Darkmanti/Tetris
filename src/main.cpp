#include <winsock2.h>
#include <windows.h>
#include "glcorearb.h"
#include "wgl.h"
#include "wglext.h"
#include "FolkMath.h"
#include "OpenGLLoader.h"
#include "DebugConsole.h"
#include "Tetris.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HWND hMainWnd = {};
MSG msg = {};

GLFuncTable funcTable = {};

int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	con::InitParam(lpCmdLine);
	con::Out("RABOTAET CONSOL\n");

	con::Outf("privet parametri: %i, %s", 20, "rubley\n");

	HICON icon = (HICON)LoadImage(NULL, TEXT("../res/icon.ico"), IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
	if (!icon)
	{
		con::SetConColor(FOREGROUND_RED);
		con::Out("error loading icon\n");
		con::SetConColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}

	WNDCLASSEX windowClass = {};
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = WndProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = hInstance;
	windowClass.hIcon = icon;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = "MainTetrisWindow";
	windowClass.hIconSm = icon;

	if (!RegisterClassEx(&windowClass))
	{
		MessageBox(NULL, "error to creae a class", "error", MB_OK);
		return NULL;
	}

	hMainWnd = CreateWindow(windowClass.lpszClassName,
		"Tetris", // им€ окна
		WS_OVERLAPPEDWINDOW, // режимы отображени€ окошка
		CW_USEDEFAULT, // положение окна по оси х //CW_USEDEFAULT
		CW_USEDEFAULT, // позици€ окна по оси у //CW_USEDEFAULT
		1280, // ширина окошка //CW_USEDEFAULT
		720, // высота окна
		NULL, // дескриптор родительского окошка
		NULL, // дескриптор меню
		hInstance, // дескриптор экземпл€ра приложени€
		NULL); // ничего не передаЄм из WndProc

	if (!hMainWnd)
	{
		MessageBox(NULL, "error to create a window", "error", MB_OK);
		return NULL;
	}

	ShowWindow(hMainWnd, nCmdShow);
	UpdateWindow(hMainWnd);

	CreateContextOpenGL(hMainWnd);

	// Load OpenGL functions
	funcTable = LoadOpenGLFunctions();

	// Start the game process
	Tetris();

	DeleteContextOpenGL(hMainWnd);
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(NULL);
		break;
	case WM_KEYDOWN:
		/*switch (wParam)
		{
		case VK_LEFT:
			con::Out("left\n");
			break;
		case VK_RIGHT:
			con::Out("right\n");
			break;
		case VK_DOWN:
			con::Out("down\n");
			break;
		case VK_UP:
			con::Out("up\n");
			break;
		default:
			con::Out("non char\n");
			break;
		}*/
	case WM_MOVE:
		// x and y coord position of window
		//Outf("%i   %i\n", (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam));
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return NULL;
}