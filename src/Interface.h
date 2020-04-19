#pragma once

#include "ImageLoader.h"
#include "FontLoader.h"

struct MenuElement
{
	u32 element;

	u16 x0, y0;
	u16 x1, y1;
};

struct MainMenu
{
	u32 VBO;
	u32 VAO;
	u32 texture;
	u32 shader;
	m4 projection;
	m4 view;

	Font font;
};

void InitMainMenuInterface(MainMenu* mMenu);

void DrawMainMenuInterface(MainMenu* mMenu);