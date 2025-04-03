#include "ball.h"

Position ball_position = {WINDOW_WIDTH/2, WINDOW_HEIGHT/2};
int ball_diameter=20;
// SDL_FRect sprite_portion = {3, 3, 198, 18};

static SDL_Texture *ball_texture;
static int movement_speed = 100;

// static SpriteSize sprite_size = {15, 18};

static void cleanup() {
  if(ball_texture){
    SDL_DestroyTexture(ball_texture);
  }
}

static void handle_event() {}

static void update(float delta_time) {
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