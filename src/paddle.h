#pragma once

#include "SDL3/SDL_render.h"
#include "entity.h"
#include "sdl/common.h"

extern Position paddle_position;

void init_paddle(SDL_Renderer *renderer);