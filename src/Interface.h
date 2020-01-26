#pragma once

#include "ImageLoader.h"
#include "FontLoader.h"

// Temporable files for test
#define STB_IMAGE_IMPLEMENTATION
#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_truetype.h"

// Temporable structures and functions
struct MainMenu
{
	u32 VBO;
	u32 VAO;
	u32 texture;
	u32 shader;
};

void InitMainMenuInterface(MainMenu* mMenu);

void DrawMainMenuInterface(MainMenu* mMenu);