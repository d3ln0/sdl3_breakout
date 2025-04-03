#pragma once

#include "SDL3/SDL_render.h"
#include "entity.h"
#include "sdl/common.h"
#include "SDL3/SDL_rect.h"
#include "SDL3_image/SDL_image.h"

extern Position paddle_position;

void init_ball(SDL_Renderer *renderer);