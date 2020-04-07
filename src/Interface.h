#pragma once

// Temporable files for test
//#include "stb_image.h"

#include "ImageLoader.h"
#include "FontLoader.h"

// Temporable structures and functions
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