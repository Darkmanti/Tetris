#pragma once
#include <windows.h>

#define USE_NAMESPACE_CON

namespace con
{
	HANDLE debugConsole = NULL;

	bool InitParam(const char* CmdLine);

	void SetConColor(int color);

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
}

#if defined(USE_NAMESPACE_CON)
using namespace con;
#endif