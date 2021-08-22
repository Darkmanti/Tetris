#include "Interface.h"

void InitInterfaceRenderer(rendererInterface* rendInt)
{
	f32 vertices[] = {
		0.0f, 0.0f, 0.0f,  0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,  1.0f, 1.0f,
		1.0f, 1.0f, 0.0f,  1.0f, 1.0f,
		0.0f, 1.0f, 0.0f,  0.0f, 1.0f,
		0.0f, 0.0f, 0.0f,  0.0f, 0.0f
	};

	glGenBuffers(1, &rendInt->VBO);
	glGenVertexArrays(1, &rendInt->VAO);

	glBindVertexArray(rendInt->VAO);

	glBindBuffer(GL_ARRAY_BUFFER, rendInt->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(f32), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(f32), (void*)(sizeof(f32) * 3));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	CreateShader(rendInt->fontShader, "../res/Shaders/fontShader.vs", "../res/Shaders/fontShader.fs", "");
	CreateShader(rendInt->objectShader, "../res/Shaders/Interfaceshader.vs", "../res/Shaders/Interfaceshader.fs", "");
	rendInt->orthoProjection = Orthographic(0.0f, settings.MainWindowWidth, 0.0f, settings.MainWindowHeight, -1.0f, 1.0f);
	// default Font
	rendInt->interfaceFont = InitFont(rendInt->fontShader, 120, 65536, "../res/Fonts/OpenSans-Semibold.ttf", 32, 2048, 2048);
}

u32 LoadImageTexture(const char* path)
{
	int w = 0, h = 0, nrComp = 0;
	u8* image = NULL;

	u32 result = 0;

	image = loaders::LoadImageU8(path, &w, &h, &nrComp, NULL);
	image = stbi_load(path, &w, &h, &nrComp, NULL);

	glGenTextures(1, &result);
	glBindTexture(GL_TEXTURE_2D, result);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

	free(image);

	return result;
}

screenInterface InitScreenInterface(u32 maxSize)
{
	screenInterface scrInt = {};
	scrInt.sizeRender = 0;
	scrInt.renderGroup = (entityRenderBlock*)malloc(sizeof(entityRenderBlock) * maxSize);
	memset(scrInt.renderGroup, 0, sizeof(entityRenderBlock) * maxSize);
	return scrInt;
}

void PushScreenInterface(screenInterface* scrInt, v3 pos, v3 scale, u32 texture, i32 text)
{
	scrInt->renderGroup[scrInt->sizeRender].pos = pos;
	scrInt->renderGroup[scrInt->sizeRender].scale = scale;
	scrInt->renderGroup[scrInt->sizeRender].texture = texture;

	if (text >= 0)
	{
		// text init
	}
	scrInt->sizeRender++;
}

void DrawScreenInterface(rendererInterface* rendInt, screenInterface* scrInt)
{
	glUseProgram(rendInt->objectShader);
	glBindVertexArray(rendInt->VAO);

	i32 modelLoc = glGetUniformLocation(rendInt->objectShader, "model");
	i32 projectionLoc = glGetUniformLocation(rendInt->objectShader, "projection");
	u32 texture = 0;

	PrintFont(rendInt->interfaceFont, 200, 400, L"What???", V3(255, 0, 0), rendInt->orthoProjection, rendInt->orthoProjection);

	for (u32 i = 0; i < scrInt->sizeRender; i++)
	{
		if (scrInt->renderGroup[i].texture != texture)
		{
			texture = scrInt->renderGroup[i].texture;
			glBindTexture(GL_TEXTURE_2D, texture);
		}

		m4 model = Translate(Identity4(), scrInt->renderGroup[i].pos);
		model = Scale(model, scrInt->renderGroup[i].scale);

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model.data);
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, rendInt->orthoProjection.data);

		glDrawArrays(GL_TRIANGLES, 0, 6);
	}
	glBindVertexArray(0);
}