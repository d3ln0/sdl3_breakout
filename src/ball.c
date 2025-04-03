#include "ball.h"
#include "SDL3/SDL_scancode.h"
#include "SDL3/SDL_stdinc.h"

Position ball_position = {WINDOW_WIDTH/2, WINDOW_HEIGHT/2};
int ball_diameter=20;
// SDL_FRect sprite_portion = {3, 3, 198, 18};

static SDL_Texture *ball_texture;
static int movement_speed = 100;
static float movement_angle = (45.0f/180)*SDL_PI_F;
static bool ismoving = false;

// static SpriteSize sprite_size = {15, 18};

static void cleanup() {
  if(ball_texture){
    SDL_DestroyTexture(ball_texture);
  }
}

static void handle_event() {}

static void update(float delta_time) {
  //handle keyboard
  const _Bool *keyboard_state = SDL_GetKeyboardState(NULL);

  if (keyboard_state[SDL_SCANCODE_SPACE]) {
    ismoving=true;
  }

  //move
  float ddist = delta_time * movement_speed;

  if(ismoving){
    ball_position.x += ddist/SDL_cos(movement_angle);
    ball_position.y += ddist/SDL_sin(movement_angle);
  }
}

static void render(SDL_Renderer *renderer) {
  SDL_FRect paddle_rect = {paddle_position.x, paddle_position.y, ball_diameter, ball_diameter};

  SDL_FRect ball_rect = {ball_position.x, ball_position.y, ball_diameter, ball_diameter};
  SDL_RenderTexture(renderer, ball_texture, NULL, &ball_rect);
}

void init_ball(SDL_Renderer *renderer) {
  const char path[] = "./assets/ball.png";
  ball_texture = IMG_LoadTexture(renderer, path);
  Entity paddle = {.name = "paddle",
                   .update = update,
                   .cleanup = cleanup,
                   .handle_event = handle_event,
                   .render = render};

  create_entity(paddle);
}