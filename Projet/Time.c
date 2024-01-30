#include "Time.h"

Time* Time_New()
{
	Time* self = (Time*)calloc(1, sizeof(Time));
	AssertNew(self);

	self->lastTime = SDL_GetTicks();
	self->deltaTime = 0.0f;

	return self;
}

void Time_Destroy(Time* self)
{
	if (!self) return;
	free(self);
}

void Time_Update(Time* self)
{
	self->deltaTime = SDL_GetTicks() - self->lastTime;
	self->lastTime = SDL_GetTicks();
}
