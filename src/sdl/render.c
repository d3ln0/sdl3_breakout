#include "render.h"
#include "SDL3/SDL_render.h"

void app_render(void *appstate) {
  AppState *state = (AppState *)appstate;

  SDL_SetRenderDrawColor(state->renderer, 255, 255, 255, 255);
  SDL_RenderClear(state->renderer);

  ENTITIES_RUN_OPTIONAL(render, state->renderer)

  SDL_RenderPresent(state->renderer);
}