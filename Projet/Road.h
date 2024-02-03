#pragma once

#include "Settings.h"
#include "Input.h"

typedef struct LevelScene LevelScene;

typedef enum CarState
{
    CAR_MOVING,

	CAR_STOPPED,

	CAR_CRASHED,

	CAR_FINISHED
} CarState;

typedef struct CarPos
{
	float x;
	float y;
	int w;
	int h;
} CarPos;

typedef struct Car {
	CarState state;

	int carId;
	
	int carSpeed;
	
	SDL_Color carColor;

	CarPos carPos;
} Car;

typedef struct Road
{
	LevelScene* scene;

	Car* cars;

	int carCount;

	Input* input;

	int firstCar;

	bool firstCarMoving;
} Road;

Road *Road_New(LevelScene *scene);

void Road_Destroy(Road *self);

void Road_Init(Road *self);

void Road_Update(Road *self);

void Road_Render(Road *self);