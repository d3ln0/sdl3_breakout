#include "entity.h"
#include "SDL3/SDL_log.h"

Entity entities[MAX_ENTITIES];
int entities_count = 0;

void create_entity(Entity entity) {
  if (entities_count < MAX_ENTITIES) {
    entities[entities_count] = entity;
    entities_count++;
  } else {
    SDL_Log("Maximum number of entites reached\n");
  }
}

void delete_entity(int index) {
  if (index < 0 || index >= MAX_ENTITIES) {
    SDL_Log("index is not valid: %d\n", index);
    return;
  }

  entities[index].cleanup();

  for (int i = index; i < MAX_ENTITIES - 1; i++) {
    entities[i] = entities[i + 1];
  }

  entities_count--;
}

void swap_entities(int index1, int index2) {
  if (index1 < 0 || index1 >= MAX_ENTITIES || index2 < 0 ||
      index2 >= MAX_ENTITIES) {
    SDL_Log("Invalid indices %d and %d\n", index1, index2);
    return;
  }

  Entity temp = entities[index1];
  entities[index1] = entities[index2];
  entities[index2] = temp;
}

int find_entity(const char *name) {
  for (int i = 0; i < entities_count; i++) {
    if (strcmp(entities[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}