#pragma once

#include "Settings.h"

typedef struct Time {
	float lastTime;

	float deltaTime;
} Time;

Time* Time_New();

void Time_Destroy(Time* self);

void Time_Update(Time* self);

float Time_getDeltaTime(Time* self);

float Time_getFPS(Time* self);

INLINE float Time_getDeltaTime(Time* self)
{
	return self->deltaTime / 1000.0f;
}

INLINE float Time_getFPS(Time* self)
{
	return 1.0f / (self->deltaTime / 1000.0f);
}