#pragma once
#include <SDL3/SDL.h>
#define MAX_ENTITIES 100
#define MAX_NAME_LENGTH 64
#include <string.h>

#define ENTITIES_RUN_OPTIONAL(function, ...)                                   \
  for (int i = 0; i < entities_count; i++) {                                   \
    if (entities[i].function) {                                                \
      entities[i].function(__VA_ARGS__);                                       \
    }                                                                          \
  }
 
typedef struct {
  float x, y;
} Position;

typedef struct {
  float w, h;
} SpriteSize;

typedef struct {
  char name[MAX_NAME_LENGTH];
  void (*cleanup)(void);
  void (*handle_event)(SDL_Event *);
  void (*update)(float);
  void (*render)(SDL_Renderer *);
} Entity;

extern Entity entities[MAX_ENTITIES];
extern int entities_count;

void swap_entities(int index1, int index2);
void delete_entity(int index);
void create_entity(Entity entity);
int find_entity(const char *name);