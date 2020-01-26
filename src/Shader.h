// NOTE: Temporable file for test and other
#pragma once

void ShaderCompileErrors(u32 shader, const char* type);
bool CreateShader(u32& program, const char* vertexPath, const char* fragmentPath, const char* geometryPath);