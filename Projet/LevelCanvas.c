#include "LevelCanvas.h"
#include "LevelScene.h"

LevelCanvas* LevelCanvas_New(LevelScene *scene) {
	LevelCanvas* self = (LevelCanvas*)calloc(1, sizeof(LevelCanvas));
	AssertNew(self);

	return self;
}

void LevelCanvas_Destroy(LevelCanvas* self) {
	if (!self) return;
	free(self);
}

void LevelCanvas_Update(LevelCanvas* self) {

}

void LevelCanvas_Render(LevelCanvas* self) {

}