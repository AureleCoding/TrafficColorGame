#pragma once

#include "Settings.h"

typedef struct Color {
    SDL_Color red;

    SDL_Color green;

    SDL_Color blue;
}Color;

typedef struct Assets {
    Color color;
} Assets;

Assets* Assets_New(SDL_Renderer* renderer);

void Assets_Destroy(Assets* self);

void loadColor(SDL_Color* color, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

void loadTexture(SDL_Renderer* renderer, SDL_Texture** texture, const char* path);