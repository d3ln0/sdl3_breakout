#include "paddle.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "SDL3_image/SDL_image.h"
#include "sdl/common.h"

Position paddle_position = {WINDOW_WIDTH/2-PADDLE_WIDTH/2, WINDOW_HEIGHT-2*PADDLE_HEIGHT};
SDL_FRect sprite_portion = {3, 3, 198, 18};

static SDL_Texture *paddle_texture;
static int movement_speed = 100;

static SpriteSize sprite_size = {15, 18};

static void cleanup() {
  if(paddle_texture){
    SDL_DestroyTexture(paddle_texture);
  }
}

static void handle_event() {}

static void update(float delta_time) {
  const _Bool *keyboard_state = SDL_GetKeyboardState(NULL);

  if (keyboard_state[SDL_SCANCODE_D]) {
    paddle_position.x += movement_speed * delta_time;
  }
  if (keyboard_state[SDL_SCANCODE_A]) {
    paddle_position.x -= movement_speed * delta_time;
  }
}

static void render(SDL_Renderer *renderer) {
  SDL_FRect paddle_rect = {paddle_position.x, paddle_position.y, PADDLE_WIDTH, PADDLE_HEIGHT};

  SDL_RenderTexture(renderer, paddle_texture, &sprite_portion, &paddle_rect);
}

void init_paddle(SDL_Renderer *renderer) {
  const char path[] = "./assets/paddle.png";
  paddle_texture = IMG_LoadTexture(renderer, path);
  Entity paddle = {.name = "paddle",
                   .update = update,
                   .cleanup = cleanup,
                   .handle_event = handle_event,
                   .render = render};

  create_entity(paddle);
}