#include "DebugConsole.h"

namespace con
{
	bool InitParam(const char* CmdLine)
	{
		char param[8][16] = {};
		int count = 0;
		int j = 0;
		int length = strlen(CmdLine);

		for (int i = 0; i < length; i++)
		{
			if (CmdLine[i] != ' ')
			{
				param[count][j] = CmdLine[i];
				j++;
			}
			else
			{
				count++;
				j = 0;
			}
		}
		count++;

		for (int i = 0; i < count; i++)
		{
			if (strcmp(param[i], "-cmd") == 0 && debugConsole == NULL)
			{
				AllocConsole();
				debugConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTitle("Tetris_Console");
			}
		}

		return true;
	}

	void SetConColor(int color)
	{
		SetConsoleTextAttribute(debugConsole, color);
	}

	// russian language
	void SetConLangRussia()
	{
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
	}
	// default language
	void SetConLangDefault()
	{
		SetConsoleOutputCP(866);
		SetConsoleCP(866);
	}

	void Out(const char* string)
	{
		WriteConsole(debugConsole, string, strlen(string), NULL, NULL);
	}

	void Out(const char ch)
	{
		char string[1] = {};
		string[0] = ch;
		WriteConsole(debugConsole, string, 1, NULL, NULL);
	}

	void Out(int value)
	{
		char string[11];
		_itoa(value, string, 10);
		WriteConsole(debugConsole, string, strlen(string), NULL, NULL);
	}

	void Out(unsigned int value)
	{
		char string[10];
		_itoa(value, string, 10);
		WriteConsole(debugConsole, string, strlen(string), NULL, NULL);
	}

	void Out(short value)
	{
		char string[6];
		_itoa(value, string, 10);
		WriteConsole(debugConsole, string, strlen(string), NULL, NULL);
	}

	void Out(unsigned short value)
	{
		char string[5];
		_itoa(value, string, 10);
		WriteConsole(debugConsole, string, strlen(string), NULL, NULL);
	}

	void Out(long long value)
	{
		char string[21];
		_i64toa(value, string, 10);
		WriteConsole(debugConsole, string, strlen(string), NULL, NULL);
	}

	void Out(unsigned long long value)
	{
		char string[20];
		_ui64toa(value, string, 10);
		WriteConsole(debugConsole, string, strlen(string), NULL, NULL);
	}

	void Out(float value)
	{
		int numDigit = 6;
		float temp = value;
		while (temp > 1)
		{
			temp /= 10;
			numDigit += 1;
		}
		char string[14];
		_gcvt(value, numDigit, string);
		WriteConsole(debugConsole, string, strlen(string), NULL, NULL);
	}

	void Out(double value)
	{
		int numDigit = 6;
		double temp = value;
		while (temp > 1)
		{
			temp /= 10;
			numDigit += 1;
		}
		char string[24];
		_gcvt(value, numDigit, string);
		WriteConsole(debugConsole, string, strlen(string), NULL, NULL);
	}

	void Outf(const char* string, ...)
	{
		char result[1024];
		char temp[256];
		memset(result, NULL, 1024);
		memset(temp, NULL, 256);

		va_list args;
		va_start(args, string);

		int i = 0;
		while (i < strlen(string))
		{
			if (string[i] == '%')
			{
				switch (string[i + 1])
				{
				case 's':
				{
					strcpy(temp, va_arg(args, char*));
					strcat(result, temp);
					break;
				}
				case 'i':
				{
					_itoa(va_arg(args, int), temp, 10);
					strcat(result, temp);
					break;
				}
				case 'f':
				{
					float value = va_arg(args, double);
					int numDigit = 6;
					float tempValue = value;
					while (tempValue > 1)
					{
						tempValue /= 10;
						numDigit += 1;
					}
					_gcvt(value, numDigit, temp);
					strcat(result, temp);
					break;
				}
				case 'm':
				{
					switch (string[i + 2])
					{
					case '2':
					{
						m2 value = va_arg(args, m2);
						value = Transpose(value);
						for (int i = 0; i < 4; i++)
						{
							int numDigit = 6;
							float tempValue = value.data[i];
							while (tempValue > 1)
							{
								tempValue /= 10;
								numDigit += 1;
							}
							_gcvt(value.data[i], numDigit, temp);

							if (i == 1)
								strcat(temp, "\n");
							else
								strcat(temp, " ");

							strcat(result, temp);
						}
						break;
					}
					case '3':
					{
						m3 value = va_arg(args, m3);
						value = Transpose(value);
						for (int i = 0; i < 9; i++)
						{
							int numDigit = 6;
							float tempValue = value.data[i];
							while (tempValue > 1)
							{
								tempValue /= 10;
								numDigit += 1;
							}
							_gcvt(value.data[i], numDigit, temp);

							if (i == 2 || i == 5)
								strcat(temp, "\n");
							else
								strcat(temp, " ");

							strcat(result, temp);
						}
						break;
					}
					case '4':
					{
						m4 value = va_arg(args, m4);
						value = Transpose(value);
						for (int i = 0; i < 16; i++)
						{
							int numDigit = 6;
							float tempValue = value.data[i];
							while (tempValue > 1)
							{
								tempValue /= 10;
								numDigit += 1;
							}
							_gcvt(value.data[i], numDigit, temp);

							if (i == 3 || i == 7 || i == 11)
								strcat(temp, "\n");
							else
								strcat(temp, " ");

							strcat(result, temp);
						}
						break;
					}
					default:{}
					}
					i = i + 1;
					break;
				}
				case 'v':
				{
					switch (string[i + 2])
					{
					case '2':
					{
						v2 value = va_arg(args, v2);
						for (int i = 0; i < 2; i++)
						{
							int numDigit = 6;
							float tempValue = value.data[i];
							while (tempValue > 1)
							{
								tempValue /= 10;
								numDigit += 1;
							}
							_gcvt(value.data[i], numDigit, temp);
							if (i != 1)
								strcat(temp, " ");
							strcat(result, temp);
						}
						break;
					}
					case '3':
					{
						v3 value = va_arg(args, v3);
						for (int i = 0; i < 3; i++)
						{
							int numDigit = 6;
							float tempValue = value.data[i];
							while (tempValue > 1)
							{
								tempValue /= 10;
								numDigit += 1;
							}
							_gcvt(value.data[i], numDigit, temp);
							if (i != 2)
								strcat(temp, " ");
							strcat(result, temp);
						}
						break;
					}
					case '4':
					{
						v4 value = va_arg(args, v4);
						for (int i = 0; i < 4; i++)
						{
							int numDigit = 6;
							float tempValue = value.data[i];
							while (tempValue > 1)
							{
								tempValue /= 10;
								numDigit += 1;
							}
							_gcvt(value.data[i], numDigit, temp);
							if (i != 3)
								strcat(temp, " ");
							strcat(result, temp);
						}
						break;
					}
					}
					i = i + 1;
					break;
				}
				default:{}
				}
					i = i + 2;
			}
			else
			{
				result[strlen(result)] = string[i];
				i++;
			}
		}
		WriteConsole(debugConsole, result, strlen(result), NULL, NULL);
	}
}