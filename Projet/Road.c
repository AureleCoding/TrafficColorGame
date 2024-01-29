#include "Road.h"
#include "LevelScene.h"

Road* Road_New(LevelScene* scene) {
    Road* self = (Road*)calloc(1, sizeof(Road));
    AssertNew(self);

    self->scene = scene;
    int carCount = 10;

    self->carCount = carCount;

    self->cars = (Car*)calloc(carCount, sizeof(Car));
    AssertNew(self->cars);

    for (int i = 0; i < carCount; ++i) {
        self->cars[i].carColor = rand() % 256;
    }

    return self;
}

void Road_Destroy(Road* self) {
    if (!self) return;
    free(self->cars);
    free(self);
}

void Road_Init(Road* self) {
    for (int i = 0; i < self->carCount; ++i) {
        self->cars[i].carPos.x = 10 + i * 20;
        self->cars[i].carPos.y = 10;
        self->cars[i].carPos.w = 10;
        self->cars[i].carPos.h = 10;
    }
}

void Road_Update(Road* self) {
    for (int i = 0; i < self->carCount; ++i) {
        self->cars[i].carPos.x += 1;
    }
}

void Road_Render(Road* self) {
    LevelScene* scene = self->scene;
    SDL_Renderer* renderer = LevelScene_getRenderer(scene);

    for (int i = 0; i < self->carCount; ++i) {
        printf("Car %d: x: %f, y: %f, w: %f, h: %f\n", i, self->cars[i].carPos.x, self->cars[i].carPos.y, self->cars[i].carPos.w, self->cars[i].carPos.h);

        SDL_Rect rect = { (int)self->cars[i].carPos.x, (int)self->cars[i].carPos.y, (int)self->cars[i].carPos.w, (int)self->cars[i].carPos.h };
        SDL_SetRenderDrawColor(renderer, self->cars[i].carColor, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
}