#pragma once

#include "stb_truetype.h"

struct Font
{
	stbtt_bakedchar* cdata;
	i32 widthBitMap;
	i32 heightBitMap;
	i32 firstChar;
	i32 glyphs;
	u32 shader;
	u32 fontBitMap;
};

Font InitFont(u32 shader, i32 heightFont, i32 glyphs, const char* fileName, i32 firstChar, i32 width, i32 height)
{
	Font font = {};

	DWORD read;
	HANDLE file = CreateFile(fileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
	LARGE_INTEGER fileSize;
	GetFileSizeEx(file, &fileSize);
	u8* ttf_buffer = (u8*)malloc(fileSize.QuadPart + 1);
	ReadFile(file, ttf_buffer, fileSize.QuadPart, &read, NULL);
	CloseHandle(file);
	ttf_buffer[fileSize.QuadPart] = '\0';

	u8* tempBitmap = (u8*)malloc(width * height);
	stbtt_bakedchar* cdata = (stbtt_bakedchar*)malloc(glyphs * sizeof(stbtt_bakedchar));

	stbtt_BakeFontBitmap(ttf_buffer, 0, heightFont, tempBitmap, width, height, firstChar, glyphs, cdata);
	// can free ttf_buffer at this point
	glGenTextures(1, &font.fontBitMap);
	glBindTexture(GL_TEXTURE_2D, font.fontBitMap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, tempBitmap);
	// can free temp_bitmap at this point
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);

	font.cdata = cdata;
	font.firstChar = firstChar;
	font.shader = shader;
	font.heightBitMap = height;
	font.widthBitMap = width;
	font.glyphs = glyphs;

	// delete!!!

	return font;
}

void DeleteFont(Font font)
{
	free(font.cdata);
}

void PrintFont(Font font, f32 x, f32 y, const WCHAR* string, v3 color, m4 projection)
{
	while (*string)
	{
		if (*string >= font.firstChar && *string < font.glyphs)
		{
			stbtt_aligned_quad q;
			stbtt_GetBakedQuad(font.cdata, font.widthBitMap, font.heightBitMap, 
				*string - font.firstChar, &x, &y, &q, 1);

			GLfloat vertices[] = {
				q.x0, -q.y0, 0.0f, q.s0, q.t0,
				q.x1, -q.y0, 0.0f, q.s1, q.t0,
				q.x1, -q.y1, 0.0f, q.s1, q.t1,
				q.x1, -q.y1, 0.0f, q.s1, q.t1,
				q.x0, -q.y1, 0.0f, q.s0, q.t1,
				q.x0, -q.y0, 0.0f, q.s0, q.t0
			};

			GLuint VAO, VBO;
			glGenVertexArrays(1, &VAO);
			glBindVertexArray(VAO);
			glGenBuffers(1, &VBO);

			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(f32), (void*)0);
			glEnableVertexAttribArray(0);

			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(f32), (void*)(sizeof(f32) * 3));
			glEnableVertexAttribArray(1);

			glUseProgram(font.shader);
			glBindTexture(GL_TEXTURE_2D, font.fontBitMap);

			m4 model = Translate(Identity4(), V3(0.0f, 5.0f, 0.0f));
			model = Scale(model, V3(0.2f, 0.2f, 0.2f));

			glUniformMatrix4fv(glGetUniformLocation(font.shader, "model"), 1, GL_FALSE, model.data);
			glUniformMatrix4fv(glGetUniformLocation(font.shader, "projection"), 1, GL_FALSE, projection.data);
			glUniform3f(glGetUniformLocation(font.shader, "fontColor"), color.r, color.g, color.b);

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR);
			glDrawArrays(GL_TRIANGLES, 0, 6);
			glBindVertexArray(0);
			glDisable(GL_BLEND);

			glDeleteVertexArrays(1, &VAO);
			glDeleteBuffers(1, &VBO);
		}
		string++;
	}
}