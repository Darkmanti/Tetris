#include "Interface.h"

void InitMainMenuInterface(MainMenu* mMenu)
{
	glViewport(0, 0, 1280, 720);

	f32 vertices[] =
	{
		0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
		0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
		-0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.0f, 0.0f, 1.0f
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
	stbi_set_flip_vertically_on_load(true);
	int w, h, nrComp;
	unsigned char* image = stbi_load("../res/Interface/container.jpg", &w, &h, &nrComp, 0);

	glGenTextures(1, &mMenu->texture);
	glBindTexture(GL_TEXTURE_2D, mMenu->texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(image);
}

void DrawMainMenuInterface(MainMenu* mMenu)
{
	m4 trans = Identity4();
	trans = Rotate(trans, 0, V3(0.0f, 0.0f, 1.0f));
	trans = Scale(trans, V3(1.0f, 1.0f, 1.0f));

	glUniformMatrix4fv(glGetUniformLocation(mMenu->shader, "transform"), 1, GL_FALSE, trans.data);

	glBindTexture(GL_TEXTURE_2D, mMenu->texture);
	glBindVertexArray(mMenu->VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}