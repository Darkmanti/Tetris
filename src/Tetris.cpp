#include "Tetris.h"

void Tetris()
{
	MainMenu mMenu = {};
	InitMainMenuInterface(&mMenu);

	glClearColor(0.0f, 0.5f, 0.0f, 1.0f);

	while (true)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
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
	if (KeyPressed(VK_LEFT))
	{
		con::Out("LEFT press\n");
		glClearColor(0.0f, 0.7f, 0.0f, 1.0f);
		/*con::Out("you are server\n");
		InitNetSocket();
		HostServer();*/
	}

	if (KeyPressed(VK_RIGHT))
	{
		con::Out("RIGHT press\n");
		glClearColor(0.0f, 0.0f, 0.7f, 1.0f);
		/*con::Out("you are client\n");
		InitNetSocket();
		HostClient();*/
	}

	if (KeyPressed(VK_UP))
	{
		Outf("UP ONE PRESSSSSSSSSSSSSSSSSED\n");
		glClearColor(0.0f, 0.5f, 0.0f, 1.0f);
	}

	for (int i = 0; i < 256; i++)
	{
		KeyReleased(i);
	}

	if (KeyDown(VK_UP))
	{
		con::Out("UP down\n");
	}
}