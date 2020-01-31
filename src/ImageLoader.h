#pragma once

void DefineType()
{

}

u8* LoadImageU8(const char* filename, int* x, int* y, int* comp, bool AutoType)
{
	if (AutoType)
		DefineType();

	return 0;
}