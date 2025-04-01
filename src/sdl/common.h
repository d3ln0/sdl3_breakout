#pragma once

#include "../entity.h"
#include <SDL3/SDL.h>

typedef struct AppState {
  SDL_Window *window;
  SDL_Renderer *renderer;
  float last_tick;
  float current_tick;
  float delta_time;
} AppState;