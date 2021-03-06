#pragma once

const WCHAR* GetLocEnumString(unsigned int number)
{
	switch(number)
	{
		case 0: { return L"locEnum_Tetris"; } break;
		case 1: { return L"locEnum_Singleplayer"; } break;
		case 2: { return L"locEnum_Multiplayer"; } break;
		case 3: { return L"locEnum_Settings"; } break;
		case 4: { return L"locEnum_Exit"; } break;
		default: { return L"ERROR: desired string not found"; } break;
	}
}                                        