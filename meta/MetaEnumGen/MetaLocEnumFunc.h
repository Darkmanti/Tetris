#pragma once

char* GetLocEnumString(unsigned int number)
{
	switch(number)
	{
		case 0: { return (char*)"locEnum_Tetris"; } break;
		case 1: { return (char*)"locEnum_Singleplayer"; } break;
		case 2: { return (char*)"locEnum_Multiplayer"; } break;
		case 3: { return (char*)"locEnum_Settings"; } break;
		case 4: { return (char*)"locEnum_Exit"; } break;
		default: { return (char*)"ERROR: desired string not found"; } break;
	}
}           