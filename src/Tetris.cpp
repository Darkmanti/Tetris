#include "Tetris.h"

void Tetris()
{
	InitSettingsFunc();
	InitMainMenuInterface(&mMenu);

	while (true)
	{
		if (PeekMessage(&msg, hMainWnd, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			if (msg.message == WM_MOUSEMOVE)
			{
				settings.cursorPos.x = (int)(short)LOWORD(msg.lParam);
				settings.cursorPos.y = settings.MainWindowHeight - (int)(short)HIWORD(msg.lParam);
				//Outf("%i    %i\n", settings.cursorPos.x, settings.cursorPos.y);
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			//Outf("%i\n", msg.message);
		}

		Control();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		DrawMainMenuInterface(&mMenu);

		SwapBuffers(hDC);
	}
}

bool KeyPressed(int key)
{
	if (GetAsyncKeyState(key) && !KeyState[key])
	{
		KeyState[key] = true;
		return true;
	}
	return false;
}

bool KeyReleased(int key)
{
	if (!GetAsyncKeyState(key) && KeyState[key])
	{
		KeyState[key] = false;
		return true;
	}
	return false;
}

bool KeyDown(int key)
{
	if (GetAsyncKeyState(key))
		return true;
	else
		return false;
}

void Control()
{
	// Each KeyPressed corresponds KeyReleased

	// perhaps add check for render window Rect
	if (KeyPressed(VK_LBUTTON))
	{
		Outf("%i    %i\n", settings.cursorPos.x, settings.cursorPos.y);
	}

	if (KeyPressed(VK_LEFT))
	{
		con::Out("LEFT press\n");
		glClearColor(0.0f, 0.7f, 0.0f, 1.0f);
	}

	if (KeyPressed(VK_RIGHT))
	{
		con::Out("RIGHT press\n");
		glClearColor(0.0f, 0.0f, 0.7f, 1.0f);
	}

	if (KeyPressed(VK_UP))
	{
		Outf("UP ONE PRESSSSSSSSSSSSSSSSSED\n");
		glClearColor(0.0f, 0.5f, 0.0f, 1.0f);
	}

	if (KeyReleased(VK_LEFT)){}
	if (KeyReleased(VK_RIGHT)) {}
	if (KeyReleased(VK_UP)) {}
	if (KeyReleased(VK_LBUTTON)) {}

	/*for (int i = 0; i < 256; i++)
	{
		KeyReleased(i);
	}*/

	if (KeyDown(VK_UP))
	{
		con::Out("UP down\n");
	}
}