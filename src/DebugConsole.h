#pragma once
#include <windows.h>

#define USE_NAMESPACE_CON

#define ASSERT(expr, ...) do { if (!(expr)) {LogAssert(__FILE__, __func__, __LINE__, #expr, __VA_ARGS__); __debugbreak();}} while(false)

#define invalid_default() default:{ASSERT(false);}

namespace con
{
	HANDLE debugConsole = NULL;

	void* ReadFileToBuffer(const char* fileName);
	void* ReadFileToBuffer(const char* fileName, PLARGE_INTEGER fileSize);
	void FreeBufferFromFile(u8* buffer);
	void FreeBufferFromFile(char* buffer);
	void FreeBufferFromFile(void* buffer);

	bool InitParam(const char* CmdLine);

	void SetConColor(int color);
	void SetConFontColorRed();
	void SetConFontColorWhite();

	void SetConLangRussia();
	void SetConLangDefault();

	void Out(const char* string);
	void Out(const char ch);
	void Out(int value);
	void Out(unsigned int value);
	void Out(short value);
	void Out(unsigned short value);
	void Out(long long value);
	void Out(unsigned long long value);
	void Out(float value);
	void Out(double value);

	void Outf(const char* string, ...);

	inline void LogAssert(const char* file, const char* func, u32 line, const char* assertStr, ...);
}

#if defined(USE_NAMESPACE_CON)
using namespace con;
#endif