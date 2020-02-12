#pragma once
#include <windows.h>

//#define USE_NAMESPACE_LOADERS

namespace loaders
{
	void DefineType()
	{

	}

	u8* LoadBMPU8(u8* buffer, int* x, int* y, int* comp, int* reqComp)
	{
		BITMAPFILEHEADER header = {};
		memcpy(&header.bfType, buffer, 2);
		memcpy(&header.bfSize, buffer + 2, 4);
		memcpy(&header.bfOffBits, buffer + 10, 4);

		DWORD infoHeaderSize = 0;
		memcpy(&infoHeaderSize, buffer + 14, 4);

		BITMAPCOREHEADER BMPCOREHEADER = {};
		BITMAPINFOHEADER BMPINFOHEADER = {};
		BITMAPV4HEADER BMPV4HEADER = {};
		BITMAPV5HEADER BMPV5HEADER = {};

		u8* result = NULL;

		if (infoHeaderSize == 12)
		{
			memcpy(&BMPCOREHEADER.bcSize, buffer + 14, 4);
			memcpy(&BMPCOREHEADER.bcWidth, buffer + 18, 2);
			memcpy(&BMPCOREHEADER.bcHeight, buffer + 20, 2);
			memcpy(&BMPCOREHEADER.bcPlanes, buffer + 22, 2);
			memcpy(&BMPCOREHEADER.bcBitCount, buffer + 24, 2);
		}
		else if (infoHeaderSize == 40)
		{
			memcpy(&BMPINFOHEADER.biSize, buffer + 14, 4);
			memcpy(&BMPINFOHEADER.biWidth, buffer + 18, 4);
			memcpy(&BMPINFOHEADER.biHeight, buffer + 22, 4);
			memcpy(&BMPINFOHEADER.biPlanes, buffer + 26, 2);
			memcpy(&BMPINFOHEADER.biBitCount, buffer + 28, 2);
			memcpy(&BMPINFOHEADER.biCompression, buffer + 30, 4);
			memcpy(&BMPINFOHEADER.biSizeImage, buffer + 34, 4);
			memcpy(&BMPINFOHEADER.biXPelsPerMeter, buffer + 38, 4);
			memcpy(&BMPINFOHEADER.biYPelsPerMeter, buffer + 42, 4);
			memcpy(&BMPINFOHEADER.biClrUsed, buffer + 46, 4);
			memcpy(&BMPINFOHEADER.biClrImportant, buffer + 50, 4);
		}
		else if (infoHeaderSize == 108)
		{
			memcpy(&BMPV4HEADER.bV4Size, buffer + 14, 4);
			memcpy(&BMPV4HEADER.bV4Width, buffer + 18, 4);
			memcpy(&BMPV4HEADER.bV4Height, buffer + 22, 4);
			memcpy(&BMPV4HEADER.bV4Planes, buffer + 26, 2);
			memcpy(&BMPV4HEADER.bV4BitCount, buffer + 28, 2);
			memcpy(&BMPV4HEADER.bV4V4Compression, buffer + 30, 4);
			memcpy(&BMPV4HEADER.bV4SizeImage, buffer + 34, 4);
			memcpy(&BMPV4HEADER.bV4XPelsPerMeter, buffer + 38, 4);
			memcpy(&BMPV4HEADER.bV4YPelsPerMeter, buffer + 42, 4);
			memcpy(&BMPV4HEADER.bV4ClrUsed, buffer + 46, 4);
			memcpy(&BMPV4HEADER.bV4ClrImportant, buffer + 50, 4);
			memcpy(&BMPV4HEADER.bV4RedMask, buffer + 54, 4);
			memcpy(&BMPV4HEADER.bV4GreenMask, buffer + 58, 4);
			memcpy(&BMPV4HEADER.bV4BlueMask, buffer + 62, 4);
			memcpy(&BMPV4HEADER.bV4AlphaMask, buffer + 66, 4);
			memcpy(&BMPV4HEADER.bV4CSType, buffer + 70, 4);
			memcpy(&BMPV4HEADER.bV4Endpoints, buffer + 74, 36);
			memcpy(&BMPV4HEADER.bV4GammaRed, buffer + 110, 4);
			memcpy(&BMPV4HEADER.bV4GammaGreen, buffer + 114, 4);
			memcpy(&BMPV4HEADER.bV4GammaBlue, buffer + 118, 4);
		}
		else if (infoHeaderSize == 124)
		{
			memcpy(&BMPV5HEADER.bV5Size, buffer + 14, 4);
			memcpy(&BMPV5HEADER.bV5Width, buffer + 18, 4);
			memcpy(&BMPV5HEADER.bV5Height, buffer + 22, 4);
			memcpy(&BMPV5HEADER.bV5Planes, buffer + 26, 2);
			memcpy(&BMPV5HEADER.bV5BitCount, buffer + 28, 2);
			memcpy(&BMPV5HEADER.bV5Compression, buffer + 30, 4);
			memcpy(&BMPV5HEADER.bV5SizeImage, buffer + 34, 4);
			memcpy(&BMPV5HEADER.bV5XPelsPerMeter, buffer + 38, 4);
			memcpy(&BMPV5HEADER.bV5YPelsPerMeter, buffer + 42, 4);
			memcpy(&BMPV5HEADER.bV5ClrUsed, buffer + 46, 4);
			memcpy(&BMPV5HEADER.bV5ClrImportant, buffer + 50, 4);
			memcpy(&BMPV5HEADER.bV5RedMask, buffer + 54, 4);
			memcpy(&BMPV5HEADER.bV5GreenMask, buffer + 58, 4);
			memcpy(&BMPV5HEADER.bV5BlueMask, buffer + 62, 4);
			memcpy(&BMPV5HEADER.bV5AlphaMask, buffer + 66, 4);
			memcpy(&BMPV5HEADER.bV5CSType, buffer + 70, 4);
			memcpy(&BMPV5HEADER.bV5Endpoints, buffer + 74, 36);
			memcpy(&BMPV5HEADER.bV5GammaRed, buffer + 110, 4);
			memcpy(&BMPV5HEADER.bV5GammaGreen, buffer + 114, 4);
			memcpy(&BMPV5HEADER.bV5GammaBlue, buffer + 118, 4);
			memcpy(&BMPV5HEADER.bV5Intent, buffer + 122, 4);
			memcpy(&BMPV5HEADER.bV5ProfileData, buffer + 126, 4);
			memcpy(&BMPV5HEADER.bV5ProfileSize, buffer + 130, 4);
			memcpy(&BMPV5HEADER.bV5Reserved, buffer + 134, 4);
		}

		if (infoHeaderSize == 12)
		{
			Outf("Error this BMP info == 12 bytes unsupported\n");
			return 0;
		}
		else if (infoHeaderSize == 40)
		{
			*x = (int)BMPINFOHEADER.biWidth;
			*y = (int)BMPINFOHEADER.biHeight;
			*comp = (int)(BMPINFOHEADER.biBitCount / 8);

			if (BMPINFOHEADER.biBitCount == 24)
			{
				result = (u8*)malloc(BMPINFOHEADER.biSizeImage);
				RGBTRIPLE* mask = (RGBTRIPLE*)(buffer + header.bfOffBits);
				for (int i = 0; i < BMPINFOHEADER.biWidth * BMPINFOHEADER.biHeight; i++)
				{
					result[i * 3] = mask[i].rgbtRed;
					result[(i * 3) + 1] = mask[i].rgbtGreen;
					result[(i * 3) + 2] = mask[i].rgbtBlue;
				}
				
			}

		}
		else if (infoHeaderSize == 108)
		{
			Outf("Error this BMP info == 108 bytes unsupported\n");
			return 0;
		}
		else if (infoHeaderSize == 124)
		{
			Outf("Error this BMP info == 124 bytes unsupported\n");
			return 0;
		}

		return result;
	}

	u8* LoadImageU8(const char* fileName, int* x, int* y, int* comp, int* reqComp)
	{
		DWORD read;

		HANDLE file = CreateFile(fileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
		LARGE_INTEGER sizeFile;
		GetFileSizeEx(file, &sizeFile);

		LPVOID buffer = malloc(sizeFile.QuadPart);
		if (!ReadFile(file, buffer, sizeFile.QuadPart, &read, NULL))
		{
			Out("Error to read image :: !!!!TO DO this ERROR CODE!!!!\0");
			return 0;
		}

		CloseHandle(file);

		u8* charBuffer = (u8*)buffer;

		WORD BMPType = 0;
		memcpy(&BMPType, charBuffer, 2);

		u8* result;

		if (BMPType == 0x4D42)
		{
			result = LoadBMPU8(charBuffer, x, y, comp, reqComp);
		}
		else
		{
			Outf("Error this file [%s] is not BMP\n", fileName);
			return 0;
		}

		free(buffer);

		return result;
	}
}

#if defined(USE_NAMESPACE_LOADERS)
using namespace loaders;
#endif