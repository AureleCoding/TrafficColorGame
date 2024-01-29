#pragma once

#include "Settings.h"
#include "LevelCanvas.h"
#include "Road.h"
#include "Input.h"

typedef struct Cube {
    float x;
    float y;
    float w;
    float h;
} Cube;

typedef struct LevelScene
{
    SDL_Renderer* renderer;

    LevelCanvas* canvas;

    Road* road;

    Input* input;

    Cube cubes;
} LevelScene;

LevelScene *LevelScene_New(SDL_Renderer* renderer);

void LevelScene_Destroy(LevelScene *self);

void LevelScene_Init(LevelScene *self);

bool LevelScene_Update(LevelScene *self);

void LevelScene_Render(LevelScene *self);

INLINE SDL_Renderer* LevelScene_getRenderer(LevelScene* self)
{
    return self->renderer;
}

INLINE Input* LevelScene_getInput(LevelScene* self)
{
    return self->input;
}