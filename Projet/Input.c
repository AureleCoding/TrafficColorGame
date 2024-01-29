#include "Input.h"
#include "Settings.h"

Input *Input_New() {
    Input* self = (Input*)calloc(1, sizeof(Input));
    AssertNew(self);

    self->keyCodes[0] = SDL_SCANCODE_W;
    self->keyCodes[1] = SDL_SCANCODE_A;
    self->keyCodes[2] = SDL_SCANCODE_S;
    self->keyCodes[3] = SDL_SCANCODE_D;

	return self;
}

void Input_Destroy(Input* self) {
	if (!self) return;
	free(self);
}

void Input_Update(Input* self) {
    self->quitPressed = false;
    self->upPressed = false;
    self->leftPressed = false;
    self->downPressed = false;
    self->rightPressed = false;

    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            self->quitPressed = true;
            break;

        case SDL_KEYDOWN:
            if (event.key.repeat)
                break;

            switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE:
                self->quitPressed = true;
                break;

            default:
                break;
            }
            break;

        default:
            break;
        }
    }

    const Uint8* state = SDL_GetKeyboardState(NULL);

    for (int i = 0; i < 4; i++) {
        if (state[self->keyCodes[i]]) {
            if (i == 0)
                self->upPressed = true;
            else if (i == 1)
                self->leftPressed = true;
            else if (i == 2)
                self->downPressed = true;
            else if (i == 3)
                self->rightPressed = true;
        }
    }
}
