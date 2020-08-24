#pragma once

#include "ImageLoader.h"
#include "FontLoader.h"
#include "Shader.h"

/*  ������ ������� ������� ����������
	� ������� ���� ������� � ����������� ����� ����������
	������ ��� ��� ���: ������ ��� ���� ����������
	����� ������� ���� �������� � ����� ������ ��������� ���� ������� � �� � ��� ������ ������
	�� ��� � ����� ��� ������ �������� ��������, ������� � �� � ��
	
	�� � ������ ����� �������� ���������, ��� ������� ������
	�� ���� ������ ��� �������� ����, ������ ��� ����� ����, � ���� ��� ���������, �� ������
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