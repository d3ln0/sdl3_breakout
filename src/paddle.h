#pragma once

#include "SDL3/SDL_render.h"
#include "entity.h"
#include "sdl/common.h"

typedef struct {
  float x, y;
} Position;

typedef struct {
  float w, h;
} SpriteSize;

extern Position paddle_position;

void init_paddle(SDL_Renderer *renderer);