#pragma once
#include "Settings.h"

typedef struct LevelScene LevelScene;

typedef struct LevelCanvas
{
	LevelScene *scene;
} LevelCanvas;


// crer le Canvas 
LevelCanvas* LevelCanvas_New(LevelScene* scene);

// detruire le Canvas
void LevelCanvas_Destroy(LevelCanvas* self);

// mettre a jour le Canvas
void LevelCanvas_Update(LevelCanvas* self);

// afficher le Canvas
void LevelCanvas_Render(LevelCanvas* self);