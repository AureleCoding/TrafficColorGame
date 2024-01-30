#include "Road.h"
#include "LevelScene.h"
#include "Time.h"
#include "Assets.h"

Road* Road_New(LevelScene* scene) {
    Road* self = (Road*)calloc(1, sizeof(Road));
    AssertNew(self);

    self->scene = scene;
    int carCount = 10;

    self->chooseCar = 0;

    self->carCount = carCount;

    self->cars = (Car*)calloc(carCount, sizeof(Car));
    AssertNew(self->cars);

    return self;
}

void Road_Destroy(Road* self) {
    if (!self) return;
    free(self->cars);
    free(self);
}

void Road_Init(Road* self) {
    LevelScene* scene = self->scene;
    Assets* assets = getAssets(scene);
    SDL_Color colors[] = { assets->color.blue, assets->color.red, assets->color.green };

    for (int i = 0; i < self->carCount; ++i) {
        self->cars[i].carPos.w = 50;
        self->cars[i].carPos.h = 40;
        self->cars[i].carPos.x -= i * (self->cars->carPos.w + 10);
        self->cars[i].carPos.y = WINDOW_HEIGHT/2 - self->cars->carPos.h/2;
        self->cars[i].carSpeed = 200;
        self->cars[i].carColor = colors[rand() % 3];
    }
}

void Road_Update(Road* self) {
    LevelScene* scene = self->scene;
    Time* time = getTime(scene);
    Input *input = LevelScene_getInput(scene);

    if (self->cars[0].carPos.x < WINDOW_WIDTH/5)
    {
        for (int i = 0; i < self->carCount; ++i) {
            self->cars[i].carSpeed = 200;
        }

        printf("Avance\n");
    }
    else {
        
        for (int i = 0; i < self->carCount; ++i) {
            self->cars[i].carSpeed = 0;
        }        
        
        printf("Stop\n");
    }

    if (input->rightPressed)
    {
        self->cars[self->chooseCar].carSpeed = 200;
    }

    for (int i = 0; i < self->carCount; ++i) {
        self->cars[i].carPos.x += self->cars[i].carSpeed * Time_getDeltaTime(time);
    }

}

void Road_Render(Road* self) {
    LevelScene* scene = self->scene;
    SDL_Renderer* renderer = LevelScene_getRenderer(scene);

    SDL_Rect road = { 0, WINDOW_HEIGHT / 2 - 50, WINDOW_WIDTH, 100 };
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_RenderFillRect(renderer, &road);

    for (int i = 0; i < self->carCount; ++i) {
        SDL_Rect car = { (int)self->cars[i].carPos.x, (int)self->cars[i].carPos.y, (int)self->cars[i].carPos.w, (int)self->cars[i].carPos.h };
        SDL_SetRenderDrawColor(renderer, self->cars[i].carColor.r, self->cars[i].carColor.g, self->cars[i].carColor.b, 255);
        SDL_RenderFillRect(renderer, &car);
    }
}