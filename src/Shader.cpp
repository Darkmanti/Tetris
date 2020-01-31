// NOTE: Temporable file for test and other
#include "Shader.h"

void ShaderCompileErrors(u32 shader, const char* type)
{
	// NOTE: TO DO this check errors
	// NOTE: type need?
	i32 success;
	char infolog[1024];
	if (strcmp(type ,"PROGRAM") != 0)
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infolog);
			Outf("%s\n%s\n", type, infolog);
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infolog);
			Outf("%s\n%s\n", type, infolog);
		}
	}
}

bool CreateShader(u32& program, const char* vertexPath, const char* fragmentPath, const char* geometryPath)
{
	DWORD read;

	HANDLE vertexFile = CreateFile(vertexPath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
	LARGE_INTEGER vertexSize;
	GetFileSizeEx(vertexFile, &vertexSize);
	LPVOID vertexCode = malloc(vertexSize.QuadPart + 1);
	if (!ReadFile(vertexFile, vertexCode, vertexSize.QuadPart, &read, NULL))
	{
		Out("Error to read vertex:: !!!!TO DO this ERROR CODE!!!!\0");
		return false;
	}
	CloseHandle(vertexFile);
	((char*)vertexCode)[vertexSize.QuadPart] = '\0';

	HANDLE fragmentFile = CreateFile(fragmentPath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
	LARGE_INTEGER fragmentSize;
	GetFileSizeEx(fragmentFile, &fragmentSize);
	LPVOID fragmentCode = malloc(fragmentSize.QuadPart + 1);
	if (!ReadFile(fragmentFile, fragmentCode, fragmentSize.QuadPart, &read, NULL))
	{
		Out("Error to read fragment:: !!!!TO DO this ERROR CODE!!!!\0");
		return false;
	}
	CloseHandle(fragmentFile);
	((char*)fragmentCode)[fragmentSize.QuadPart] = '\0';

	u32 vertex, fragment;

	vertex = glCreateShader(GL_VERTEX_SHADER);
	const char* vCode = (const char*)vertexCode;
	glShaderSource(vertex, 1, &vCode, NULL);
	glCompileShader(vertex);
	ShaderCompileErrors(vertex, "VERTEX");

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fCode = (const char*)fragmentCode;
	glShaderSource(fragment, 1, &fCode, NULL);
	glCompileShader(fragment);
	ShaderCompileErrors(fragment, "FRAGMENT");

	program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	ShaderCompileErrors(program, "PROGRAM");

	glDeleteShader(vertex);
	glDeleteShader(fragment);
	free(vertexCode);
	free(fragmentCode);

	return true;
}