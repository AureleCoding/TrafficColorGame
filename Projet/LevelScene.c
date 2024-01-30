/*
  Copyright (c) JOBLET AURELE GAUTIER-GRALL MAXENCE.
*/

#include "levelScene.h"

LevelScene* LevelScene_New(SDL_Renderer *renderer) {
	LevelScene *self = (LevelScene*)calloc(1, sizeof(LevelScene));
	AssertNew(self);

	self->renderer = renderer;
	self->canvas = LevelCanvas_New(self);
	self->assets = Assets_New(renderer);
	self->input = Input_New();
	self->road = Road_New(self);

	return self;
}

void LevelScene_Destroy(LevelScene* self) {
	if (!self) return;

	Input_Destroy(self->input);
	LevelCanvas_Destroy(self->canvas);
	Road_Destroy(self->road);
	
	free(self);
}

void LevelScene_Init(LevelScene* self) {
	Road_Init(self->road);
}

bool LevelScene_Update(LevelScene* self) {
	Input_Update(self->input);
	LevelCanvas_Update(self->canvas);
	Road_Update(self->road);

	return self->input->quitPressed;
}

void LevelScene_Render(LevelScene* self) {
	SDL_Rect rect = { 10, 10, 10, 10 };
	SDL_SetRenderDrawColor(self->renderer, 255, 255, 0, 255);
	SDL_RenderFillRect(self->renderer, &rect);

	Road_Render(self->road);
}