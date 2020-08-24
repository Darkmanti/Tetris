#pragma once

#include "ImageLoader.h"
#include "FontLoader.h"
#include "Shader.h"

/*  Кароче простая система интерфейса
	я вызываю одну функцию и регистрирую кусок интерфейса
	говорю мол что это: кнопка или тупо картиночка
	после функция сама выбирает в какой массив добавлять этот элемент и чё с ним делать дальше
	всё что я делаю это просто указываю текстуру, размеры и тд и тп
	
	ну и кароче таких массивов несколько, для каждого экрана
	то есть массив для главного меню, массив для самой игры, и типо они свапаются, всё просто
*/

struct rendererInterface
{
	u32 fontShader;
	u32 objectShader;
	u32 VAO;
	u32 VBO;
	m4 orthoProjection;
	Font interfaceFont;
};

struct entityRenderBlock
{
	v3 pos;
	v3 scale;
	u32 texture;
};

struct screenInterface
{
	u32 sizeRender;
	entityRenderBlock* renderGroup;
};

void InitInterfaceRenderer(rendererInterface* rendInt);

u32 LoadImageTexture(const char* path);

screenInterface InitScreenInterface(u32 maxSize);

void PushScreenInterface(screenInterface* scrInt, v3 pos, v3 scale, u32 texture, i32 text);

void DrawScreenInterface(rendererInterface* rendInt, screenInterface* scrInt);