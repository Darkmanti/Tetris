#include "OpenGLLoader.h"

static const char* funcNames[OPENGL_FUNC_COUNT] =
{
	// 1.0
	"glCullFace",
	"glFrontFace",
	"glHint",
	"glLineWidth",
	"glPointSize",
	"glPolygonMode",
	"glScissor",
	"glTexParameterf",
	"glTexParameterfv",
	"glTexParameteri",
	"glTexParameteriv",
	"glTexImage1D",
	"glTexImage2D",
	"glDrawBuffer",
	"glClear",
	"glClearColor",
	"glClearStencil",
	"glClearDepth",
	"glStencilMask",
	"glColorMask",
	"glDepthMask",
	"glDisable",
	"glEnable",
	"glFinish",
	"glFlush",
	"glBlendFunc",
	"glLogicOp",
	"glStencilFunc",
	"glStencilOp",
	"glDepthFunc",
	"glPixelStoref",
	"glPixelStorei",
	"glReadBuffer",
	"glReadPixels",
	"glGetBooleanv",
	"glGetDoublev",
	"glGetError",
	"glGetFloatv",
	"glGetIntegerv",
	"glGetString",
	"glGetTexImage",
	"glGetTexParameterfv",
	"glGetTexParameteriv",
	"glGetTexLevelParameterfv",
	"glGetTexLevelParameteriv",
	"glIsEnabled",
	"glDepthRange",
	"glViewport",
	// 1.1
	"glDrawArrays",
	"glDrawElements",
	"glGetPointerv",
	"glPolygonOffset",
	"glCopyTexImage1D",
	"glCopyTexImage2D",
	"glCopyTexSubImage1D",
	"glCopyTexSubImage2D",
	"glTexSubImage1D",
	"glTexSubImage2D",
	"glBindTexture",
	"glDeleteTextures",
	"glGenTextures",
	"glIsTexture",
	// 1.2
	"glDrawRangeElements",
	"glTexImage3D",
	"glTexSubImage3D",
	"glCopyTexSubImage3D",
	//1.3
	"glActiveTexture",
	"glSampleCoverage",
	"glCompressedTexImage3D",
	"glCompressedTexImage2D",
	"glCompressedTexImage1D",
	"glCompressedTexSubImage3D",
	"glCompressedTexSubImage2D",
	"glCompressedTexSubImage1D",
	"glGetCompressedTexImage",
	// 1.4
	"glBlendFuncSeparate",
	"glMultiDrawArrays",
	"glMultiDrawElements",
	"glPointParameterf",
	"glPointParameterfv",
	"glPointParameteri",
	"glPointParameteriv",
	"glBlendColor",
	"glBlendEquation",
	// 1.5
	"glGenQueries",
	"glDeleteQueries",
	"glIsQuery",
	"glBeginQuery",
	"glEndQuery",
	"glGetQueryiv",
	"glGetQueryObjectiv",
	"glGetQueryObjectuiv",
	"glBindBuffer",
	"glDeleteBuffers",
	"glGenBuffers",
	"glIsBuffer",
	"glBufferData",
	"glBufferSubData",
	"glGetBufferSubData",
	"glMapBuffer",
	"glUnmapBuffer",
	"glGetBufferParameteriv",
	"glGetBufferPointerv",
	// 2.0
	"glBlendEquationSeparate",
	"glDrawBuffers",
	"glStencilOpSeparate",
	"glStencilFuncSeparate",
	"glStencilMaskSeparate",
	"glAttachShader",
	"glBindAttribLocation",
	"glCompileShader",
	"glCreateProgram",
	"glCreateShader",
	"glDeleteProgram",
	"glDeleteShader",
	"glDetachShader",
	"glDisableVertexAttribArray",
	"glEnableVertexAttribArray",
	"glGetActiveAttrib",
	"glGetActiveUniform",
	"glGetAttachedShaders",
	"glGetAttribLocation",
	"glGetProgramiv",
	"glGetProgramInfoLog",
	"glGetShaderiv",
	"glGetShaderInfoLog",
	"glGetShaderSource",
	"glGetUniformLocation",
	"glGetUniformfv",
	"glGetUniformiv",
	"glGetVertexAttribdv",
	"glGetVertexAttribfv",
	"glGetVertexAttribiv",
	"glGetVertexAttribPointerv",
	"glIsProgram",
	"glIsShader",
	"glLinkProgram",
	"glShaderSource",
	"glUseProgram",
	"glUniform1f",
	"glUniform2f",
	"glUniform3f",
	"glUniform4f",
	"glUniform1i",
	"glUniform2i",
	"glUniform3i",
	"glUniform4i",
	"glUniform1fv",
	"glUniform2fv",
	"glUniform3fv",
	"glUniform4fv",
	"glUniform1iv",
	"glUniform2iv",
	"glUniform3iv",
	"glUniform4iv",
	"glUniformMatrix2fv",
	"glUniformMatrix3fv",
	"glUniformMatrix4fv",
	"glValidateProgram",
	"glVertexAttrib1d",
	"glVertexAttrib1dv",
	"glVertexAttrib1f",
	"glVertexAttrib1fv",
	"glVertexAttrib1s",
	"glVertexAttrib1sv",
	"glVertexAttrib2d",
	"glVertexAttrib2dv",
	"glVertexAttrib2f",
	"glVertexAttrib2fv",
	"glVertexAttrib2s",
	"glVertexAttrib2sv",
	"glVertexAttrib3d",
	"glVertexAttrib3dv",
	"glVertexAttrib3f",
	"glVertexAttrib3fv",
	"glVertexAttrib3s",
	"glVertexAttrib3sv",
	"glVertexAttrib4Nbv",
	"glVertexAttrib4Niv",
	"glVertexAttrib4Nsv",
	"glVertexAttrib4Nub",
	"glVertexAttrib4Nubv",
	"glVertexAttrib4Nuiv",
	"glVertexAttrib4Nusv",
	"glVertexAttrib4bv",
	"glVertexAttrib4d",
	"glVertexAttrib4dv",
	"glVertexAttrib4f",
	"glVertexAttrib4fv",
	"glVertexAttrib4iv",
	"glVertexAttrib4s",
	"glVertexAttrib4sv",
	"glVertexAttrib4ubv",
	"glVertexAttrib4uiv",
	"glVertexAttrib4usv",
	"glVertexAttribPointer",
	// 2.1
	"glUniformMatrix2x3fv",
	"glUniformMatrix3x2fv",
	"glUniformMatrix2x4fv",
	"glUniformMatrix4x2fv",
	"glUniformMatrix3x4fv",
	"glUniformMatrix4x3fv",
	// 3.0
	"glColorMaski",
	"glGetBooleani_v",
	"glGetIntegeri_v",
	"glEnablei",
	"glDisablei",
	"glIsEnabledi",
	"glBeginTransformFeedback",
	"glEndTransformFeedback",
	"glBindBufferRange",
	"glBindBufferBase",
	"glTransformFeedbackVaryings",
	"glGetTransformFeedbackVarying",
	"glClampColor",
	"glBeginConditionalRender",
	"glEndConditionalRender",
	"glVertexAttribIPointer",
	"glGetVertexAttribIiv",
	"glGetVertexAttribIuiv",
	"glVertexAttribI1i",
	"glVertexAttribI2i",
	"glVertexAttribI3i",
	"glVertexAttribI4i",
	"glVertexAttribI1ui",
	"glVertexAttribI2ui",
	"glVertexAttribI3ui",
	"glVertexAttribI4ui",
	"glVertexAttribI1iv",
	"glVertexAttribI2iv",
	"glVertexAttribI3iv",
	"glVertexAttribI4iv",
	"glVertexAttribI1uiv",
	"glVertexAttribI2uiv",
	"glVertexAttribI3uiv",
	"glVertexAttribI4uiv",
	"glVertexAttribI4bv",
	"glVertexAttribI4sv",
	"glVertexAttribI4ubv",
	"glVertexAttribI4usv",
	"glGetUniformuiv",
	"glBindFragDataLocation",
	"glGetFragDataLocation",
	"glUniform1ui",
	"glUniform2ui",
	"glUniform3ui",
	"glUniform4ui",
	"glUniform1uiv",
	"glUniform2uiv",
	"glUniform3uiv",
	"glUniform4uiv",
	"glTexParameterIiv",
	"glTexParameterIuiv",
	"glGetTexParameterIiv",
	"glGetTexParameterIuiv",
	"glClearBufferiv",
	"glClearBufferuiv",
	"glClearBufferfv",
	"glClearBufferfi",
	"glGetStringi",
	"glIsRenderbuffer",
	"glBindRenderbuffer",
	"glDeleteRenderbuffers",
	"glGenRenderbuffers",
	"glRenderbufferStorage",
	"glGetRenderbufferParameteriv",
	"glIsFramebuffer",
	"glBindFramebuffer",
	"glDeleteFramebuffers",
	"glGenFramebuffers",
	"glCheckFramebufferStatus",
	"glFramebufferTexture1D",
	"glFramebufferTexture2D",
	"glFramebufferTexture3D",
	"glFramebufferRenderbuffer",
	"glGetFramebufferAttachmentParameteriv",
	"glGenerateMipmap",
	"glBlitFramebuffer",
	"glRenderbufferStorageMultisample",
	"glFramebufferTextureLayer",
	"glMapBufferRange",
	"glFlushMappedBufferRange",
	"glBindVertexArray",
	"glDeleteVertexArrays",
	"glGenVertexArrays",
	"glIsVertexArray",
	// 3.1
	"glDrawArraysInstanced",
	"glDrawElementsInstanced",
	"glTexBuffer",
	"glPrimitiveRestartIndex",
	"glCopyBufferSubData",
	"glGetUniformIndices",
	"glGetActiveUniformsiv",
	"glGetActiveUniformName",
	"glGetUniformBlockIndex",
	"glGetActiveUniformBlockiv",
	"glGetActiveUniformBlockName",
	"glUniformBlockBinding",
	// 3.2
	"glDrawElementsBaseVertex",
	"glDrawRangeElementsBaseVertex",
	"glDrawElementsInstancedBaseVertex",
	"glMultiDrawElementsBaseVertex",
	"glProvokingVertex",
	"glFenceSync",
	"glIsSync",
	"glDeleteSync",
	"glClientWaitSync",
	"glWaitSync",
	"glGetInteger64v",
	"glGetSynciv",
	"glGetInteger64i_v",
	"glGetBufferParameteri64v",
	"glFramebufferTexture",
	"glTexImage2DMultisample",
	"glTexImage3DMultisample",
	"glGetMultisamplefv",
	"glSampleMaski",
	// 3.3
	"glBindFragDataLocationIndexed",
	"glGetFragDataIndex",
	"glGenSamplers",
	"glDeleteSamplers",
	"glIsSampler",
	"glBindSampler",
	"glSamplerParameteri",
	"glSamplerParameteriv",
	"glSamplerParameterf",
	"glSamplerParameterfv",
	"glSamplerParameterIiv",
	"glSamplerParameterIuiv",
	"glGetSamplerParameteriv",
	"glGetSamplerParameterIiv",
	"glGetSamplerParameterfv",
	"glGetSamplerParameterIuiv",
	"glQueryCounter",
	"glGetQueryObjecti64v",
	"glGetQueryObjectui64v",
	"glVertexAttribDivisor",
	"glVertexAttribP1ui",
	"glVertexAttribP1uiv",
	"glVertexAttribP2ui",
	"glVertexAttribP2uiv",
	"glVertexAttribP3ui",
	"glVertexAttribP3uiv",
	"glVertexAttribP4ui",
	"glVertexAttribP4uiv"
#if 0
	"glGetSubroutineUniformLocation",
	"glGetSubroutineIndex",
	"glGetActiveSubroutineUniformiv",
	"glGetActiveSubroutineUniformName",
	"glGetActiveSubroutineName",
	"glUniformSubroutinesuiv",
	"glGetUniformSubroutineuiv",
	"glGetProgramStageiv",

	"glTexStorage3D",
	"glCreateBuffers",
	"glNamedBufferData",
	"glMapNamedBuffer",
	"glUnmapNamedBuffer"
#endif
};

GLFuncTable LoadOpenGLFunctions()
{
	GLFuncTable result = {};

	HMODULE glLibHandle = {};

	for (UINT32 i = 0; i < OPENGL_FUNC_COUNT; i++)
	{
		result.func[i] = wglGetProcAddress(funcNames[i]);

		if  (result.func[i] == (void*)0 || 
			(result.func[i] == (void*)1) || 
			(result.func[i] == (void*)2) ||
			(result.func[i] == (void*)3) ||
			(result.func[i] == (void*)-1))
		{
			if (!glLibHandle)
			{
				glLibHandle = LoadLibraryA("opengl32.dll");
			}
			if (glLibHandle)
			{
				result.func[i] = GetProcAddress(glLibHandle, funcNames[i]);
			}
			else
			{
				con::Out("Error. failed to load opengl32.dll\n");
			}

			if (!result.func[i])
			{
				con::Out("Error. failed to load ");
				con::Out(funcNames[i]);
				con::Out('\n');
			}
		}
	}

	return result;
}

void CreateContextOpenGL(HWND hWNDToDC)
{
	PIXELFORMATDESCRIPTOR pfd;
	int format;
	hDC = GetDC(hWNDToDC);

	memset(&pfd, 0, sizeof(pfd));
	pfd.nSize = sizeof(pfd);

	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24; // 16 maybe
	format = ChoosePixelFormat(hDC, &pfd);

	if (!format || !SetPixelFormat(hDC, format, &pfd))
	{
		con::Out("Setting pixel format fail ");
		con::Out((unsigned long long)GetLastError());
		con::Out("\n");
	}

	HGLRC hRCTemp = wglCreateContext(hDC);

	if (!hRCTemp || !wglMakeCurrent(hDC, hRCTemp))
	{
		con::Out("Ñreating temp render context fail ");
		con::Out((unsigned long long)GetLastError());
		con::Out("\n");
	}

	PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");

	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(hRCTemp);

	if (!wglCreateContextAttribsARB)
	{
		con::Out("wglCreateContextAttribsARB fail ");
		con::Out((unsigned long long)GetLastError());
		con::Out("\n");
	}

	int attribs[] =
	{
		WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
		WGL_CONTEXT_MINOR_VERSION_ARB, 3,
		WGL_CONTEXT_FLAGS_ARB,         WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
		WGL_CONTEXT_PROFILE_MASK_ARB,  WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
		0
	};

	hRC = wglCreateContextAttribsARB(hDC, 0, attribs);

	if (!hRC || !wglMakeCurrent(hDC, hRC))
	{
		con::Out("Creating render context fail ");
		con::Out((unsigned long long)GetLastError());
		con::Out("\n");
	}
}

void DeleteContextOpenGL(HWND hWNDToDC)
{
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(hRC);
	ReleaseDC(hWNDToDC, hDC);
}