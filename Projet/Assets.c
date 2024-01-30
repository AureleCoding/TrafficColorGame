#include "Assets.h"

void loadColor(SDL_Color* color, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	color->r = r;
	color->g = g;
	color->b = b;
	color->a = a;
}

void loadTexture(SDL_Renderer* renderer, SDL_Texture** texture, const char* path)
{
	SDL_Surface* surface = IMG_Load(path);
	if (!surface)
	{
		printf("Error: %s\n", IMG_GetError());
		return;
	}

	*texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (!*texture)
	{
		printf("Error: %s\n", SDL_GetError());
		return;
	}

	SDL_FreeSurface(surface);
}

//void loadFont(TTF_Font** font, const char* path, int size)
//{
//	*font = TTF_OpenFont(path, size);
//	if (!*font)
//	{
//		printf("Error: %s\n", TTF_GetError());
//		return;
//	}
//}


Assets* Assets_New(SDL_Renderer* renderer)
{
	Assets* self = (Assets*)calloc(1, sizeof(Assets));
	AssertNew(self);

	loadColor(&self->color.red , 255, 0, 0, 255);
	loadColor(&self->color.green, 0, 255, 0, 255);
	loadColor(&self->color.blue, 0, 0, 255, 255);

	return self;
}

void Assets_Destroy(Assets* self)
{
	if (!self) return;
	free(self);
}