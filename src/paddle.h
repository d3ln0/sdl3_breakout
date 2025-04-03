#pragma once

#include "SDL3/SDL_render.h"
#include "entity.h"
#include "sdl/common.h"

#define PADDLE_WIDTH 200
#define PADDLE_HEIGHT 20

extern Position paddle_position;

void init_paddle(SDL_Renderer *renderer);