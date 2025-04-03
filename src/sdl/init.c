#include "init.h"

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
  AppState *state = SDL_malloc(sizeof(AppState));
  *appstate = state;

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("Error Initializing SDL: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  state->window = SDL_CreateWindow("SDL3 Game", WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  if (!state->window) {
    SDL_Log("Error creating window: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  state->renderer = SDL_CreateRenderer(state->window, NULL);
  if (!state->renderer) {
    SDL_Log("Error creating window: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  init_paddle(state->renderer);
  init_ball(state->renderer);

  // SDL_SetRenderLogicalPresentation(state->renderer, 320, 180,
                                  //  SDL_LOGICAL_PRESENTATION_LETTERBOX);

  return SDL_APP_CONTINUE;
}