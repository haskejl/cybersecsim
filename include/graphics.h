#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "entity.h"

void add_entity_to_scene(struct EntityNode* en);
void add_rect_to_scene(SDL_Rect* rect, int r, int g, int b, int a);
void add_text_to_scene(const char* str, SDL_Rect* rect);
void clear_scene();
void draw_scene();
int init_gfx();
void shutdown_gfx();

#endif
