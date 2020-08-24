#include "Tetris.h"

void Tetris()
{
	glClearColor(0.0f, 0.7f, 0.0f, 1.0f);

	u32 newTexture = LoadImageTexture("../res/Interface/button.png");

	screenInterface mainMenu = InitScreenInterface(5);
	PushScreenInterface(&mainMenu, V3(0.0f, 240.0f, 0.0f), V3(150.0f, 50.0f, 0.0f), newTexture, -1);
	PushScreenInterface(&mainMenu, V3(0.0f, 180.0f, 0.0f), V3(150.0f, 50.0f, 0.0f), newTexture, -1);
	PushScreenInterface(&mainMenu, V3(0.0f, 120.0f, 0.0f), V3(150.0f, 50.0f, 0.0f), newTexture, -1);
	PushScreenInterface(&mainMenu, V3(0.0f, 60.0f, 0.0f), V3(150.0f, 50.0f, 0.0f), newTexture, -1);
	PushScreenInterface(&mainMenu, V3(0.0f, 0.0f, 0.0f), V3(150.0f, 50.0f, 0.0f), newTexture, -1);

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
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

		DrawScreenInterface(&rendInt, &mainMenu);

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

	if (KeyDown(VK_UP))
	{
		con::Out("UP down\n");
	}
}