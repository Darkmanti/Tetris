#pragma once
#include "WSNetwork.h"
#include "OpenGLLoader.h"
#include "Interface.h"

bool KeyState[256] = {};

bool KeyPressed(int key);
bool KeyReleased(int key);

bool KeyDown(int key);

void Tetris();

void Control();