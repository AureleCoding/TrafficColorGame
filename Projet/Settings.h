#pragma once

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#define FHD
//#define FULLSCREEN

#define MAX_KEY_COUNT 8

#ifdef _WIN32
#  include "SDL.h"
#  include "SDL_image.h"
#else
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_image.h>
#endif

#ifdef _MSC_VER
#  define INLINE inline
#else
#  define INLINE static inline
#endif

#ifdef _MSC_VER
#  define strdup(str) _strdup(str)
#endif

#define AssertNew(ptr) { if (ptr == NULL) { assert(false); abort(); } }

#define HD_WIDTH 1280
#define HD_HEIGHT 720
#define FHD_WIDTH 1920
#define FHD_HEIGHT 1080

#ifdef FHD
#define WINDOW_WIDTH   FHD_WIDTH
#define WINDOW_HEIGHT  FHD_HEIGHT
#define LOGICAL_WIDTH  FHD_WIDTH
#define LOGICAL_HEIGHT FHD_HEIGHT
#else
#define WINDOW_WIDTH   HD_WIDTH
#define WINDOW_HEIGHT  HD_HEIGHT
#define LOGICAL_WIDTH  HD_WIDTH
#define LOGICAL_HEIGHT HD_HEIGHT
#endif