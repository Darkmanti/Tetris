#include "Interface.h"

// Temporable structures and functions
void InitMainMenuInterface(MainMenu* mMenu)
{
	//glEnable(GL_DEPTH_TEST);
	//glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.0f, 0.5f, 0.0f, 1.0f);

	f32 vertices[] = {
		0.0f, 0.0f, 0.0f,  0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,  1.0f, 1.0f,
		1.0f, 1.0f, 0.0f,  1.0f, 1.0f,
		0.0f, 1.0f, 0.0f,  0.0f, 1.0f,
		0.0f, 0.0f, 0.0f,  0.0f, 0.0f
	};

	glGenBuffers(1, &mMenu->VBO);
	glGenVertexArrays(1, &mMenu->VAO);

	glBindVertexArray(mMenu->VAO);

	glBindBuffer(GL_ARRAY_BUFFER, mMenu->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(f32), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(f32), (void*)(sizeof(f32) * 3));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	CreateShader(mMenu->shader, "../res/Shaders/shader.vs", "../res/Shaders/shader.fs", "");

	glUseProgram(mMenu->shader);

	// Texture =================================================================================
	int w, h, nrComp;
	u8* image = NULL;

	image = loaders::LoadImageU8("../res/Interface/container.bmp", &w, &h, &nrComp, NULL);

	glGenTextures(1, &mMenu->texture);
	glBindTexture(GL_TEXTURE_2D, mMenu->texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

	free(image);

	//fonts
	u32 tempShader;
	CreateShader(tempShader, "../res/Shaders/fontShader.vs", "../res/Shaders/fontShader.fs", "");
	mMenu->font = InitFont(tempShader, 120, 65536, "../res/Fonts/OpenSans-Semibold.ttf", 32, 2048, 2048);

	mMenu->projection = Orthographic(0.0f, settings.MainWindowWidth, 0.0f, settings.MainWindowHeight, -100.0f, 100.0f);
	//mMenu->projection = PerspectiveOpenGLRH(75, 1920, 1080, 0.1f, 100.0f);
}

void DrawMainMenuInterface(MainMenu* mMenu)
{
	glUseProgram(mMenu->shader);
	i32 modelLoc = glGetUniformLocation(mMenu->shader, "model");

	glUniformMatrix4fv(glGetUniformLocation(mMenu->shader, "projection"), 1, GL_FALSE, mMenu->projection.data);

	m4 model = Translate(Identity4(), V3(200.0f, 400.0f, 0.0f));
	model = Scale(model, V3(400.0f, 400.0f, 0.0f));
	_SYSTEMTIME time = {};
	GetLocalTime(&time);
	//model = Rotate(model, time.wMilliseconds / 4, V3(1.0f, 1.0f, 1.0f));
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model.data);

	glBindTexture(GL_TEXTURE_2D, mMenu->texture);
	glBindVertexArray(mMenu->VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);

	//model = Translate(Identity4(), V3(1000.0f, 0.0f, 0.0f));
	//model = Scale(model, V3(0.01f, 0.01f, 0.01f));
	PrintFont(mMenu->font, 200.0f, 400.0f, settings.locArray[locEnum_Tetris], V3(0.631f, 0.631f, 0.631f), mMenu->projection, model);
}