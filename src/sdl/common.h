#pragma once

#include "../entity.h"
#include <SDL3/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct AppState {
  SDL_Window *window;
  SDL_Renderer *renderer;
  float last_tick;
  float current_tick;
  float delta_time;
} AppState;