#pragma once

#include "ImageLoader.h"
#include "FontLoader.h"
#include "Shader.h"

u32 iShader;
u32 iFontShader;
Font Ifont = {};
m4 orthoProjection;

// TO DO mem padding
struct IEntity
{
	f32 x;
	f32 y;
	f32 scale;

	bool haveText;
	bool clickable;

	u32 VAO;
	u32 VBO;

	u32 diffuseTexture;
	u32 text;
};

struct IOneScreen
{

};

struct MainMenu
{
	u32 VBO;
	u32 VAO;
	u32 texture;
	u32 shader;
	m4 projection;

	Font font;
};

void InitInterface()
{
	CreateShader(iShader, "../res/Shaders/Interfaceshader.vs", "../res/Shaders/Interfaceshader.fs", "");
	CreateShader(iFontShader, "../res/Shaders/fontShader.vs", "../res/Shaders/fontShader.fs", "");
	Ifont = InitFont(iFontShader, 120, 65536, "../res/Fonts/OpenSans-Semibold.ttf", 32, 2048, 2048);
	orthoProjection = Orthographic(0.0f, settings.MainWindowWidth, 0.0f, settings.MainWindowHeight, -100.0f, 100.0f);
}

IEntity RegisterIEntity(f32 x, f32 y, f32 scale , const char* pathDiffuse = NULL, bool haveText = false, u32 text = NULL)
{
	IEntity iEntity = {};
	iEntity.x = x;
	iEntity.y = y;
	iEntity.scale = scale;

	if (pathDiffuse)
	{
		int w, h, nrComp;
		u8* image = NULL;

		image = loaders::LoadImageU8("../res/Interface/container.bmp", &w, &h, &nrComp, NULL);

		glGenTextures(1, &iEntity.diffuseTexture);
		glBindTexture(GL_TEXTURE_2D, iEntity.diffuseTexture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);

		free(image);
	}

	if (haveText)
	{
		iEntity.haveText = true;
		iEntity.text = text;
	}

	f32 vertices[] = {
		0.0f, 0.0f, 0.0f,  0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,  1.0f, 1.0f,
		1.0f, 1.0f, 0.0f,  1.0f, 1.0f,
		0.0f, 1.0f, 0.0f,  0.0f, 1.0f,
		0.0f, 0.0f, 0.0f,  0.0f, 0.0f
	};

	glGenBuffers(1, &iEntity.VBO);
	glGenVertexArrays(1, &iEntity.VAO);

	glBindVertexArray(iEntity.VAO);

	glBindBuffer(GL_ARRAY_BUFFER, iEntity.VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(f32), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(f32), (void*)(sizeof(f32) * 3));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	return iEntity;
};

void DrawIEntity(IEntity entity)
{
	glUseProgram(iShader);

	m4 model = Translate(Identity4(), V3(entity.x, entity.y, 0.0f));
	model = Scale(model, V3(entity.scale, entity.scale, 0.0f));
	glUniformMatrix4fv(glGetUniformLocation(iShader, "model"), 1, GL_FALSE, model.data);
	glUniformMatrix4fv(glGetUniformLocation(iShader, "projection"), 1, GL_FALSE, orthoProjection.data);

	glBindTexture(GL_TEXTURE_2D, entity.diffuseTexture);
	glBindVertexArray(entity.VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void DeleteIEntity(IEntity* iEntity)
{
	glDeleteVertexArrays(1, &iEntity->VAO);
	glDeleteBuffers(1, &iEntity->VBO);
	glDeleteTextures(1, &iEntity->diffuseTexture);
}

void InitMainMenuInterface(MainMenu* mMenu);

void DrawMainMenuInterface(MainMenu* mMenu);