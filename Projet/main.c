#include "settings.h"
#include "levelScene.h"
#include "levelCanvas.h"

void ErrorExit(const char* message);

int main(int argc, char** argv) {

	SDL_version compiled;
	SDL_VERSION(&compiled);
	printf("SDL version: %d.%d.%d\n", compiled.major, compiled.minor, compiled.patch);

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		ErrorExit("SDL_Init");

	SDL_Window *window = SDL_CreateWindow("Projet", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	if (!window)
		ErrorExit("Create window");

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_RenderSetLogicalSize(renderer, LOGICAL_WIDTH, LOGICAL_HEIGHT);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	if (!renderer)
		ErrorExit("Create renderer");

	if (SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255) != 0)
		ErrorExit("Set background");

	//Efface le rendu a l'ecran
	SDL_RenderClear(renderer);

	//Affiche le rendu a l'ecran
	SDL_RenderPresent(renderer);

	SDL_Event event;

	bool running = true;

	LevelScene* levelScene = NULL;

	while (running) {
		levelScene = LevelScene_New(renderer);

		LevelScene_Init(levelScene);

		while (true)
		{
			bool quitLoop = LevelScene_Update(levelScene);

			if (quitLoop)
				break;

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);

			LevelScene_Render(levelScene);

			SDL_RenderPresent(renderer);
		}

		if (levelScene->input->quitPressed)
			break;

		LevelScene_Destroy(levelScene);
		levelScene = NULL;
	}

	//SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}

void ErrorExit(const char* message) {
	SDL_Log("ERROR - %s : %s\n", message, SDL_GetError());
	printf("ERROR - %s : %s\n", message, SDL_GetError());
	SDL_Quit();
	assert(false);
	abort();
	exit(EXIT_FAILURE);
}