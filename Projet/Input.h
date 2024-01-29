#pragma once

#include "Settings.h"

typedef struct Input {
	SDL_Scancode keyCodes[4];

	bool quitPressed;

	bool upPressed;

	bool leftPressed;
	
	bool downPressed;
	
	bool rightPressed;
}
Input;

Input* Input_New();

void Input_Destroy(Input* self);

void Input_Update(Input* self);