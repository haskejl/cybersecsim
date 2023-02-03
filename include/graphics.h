#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void add_rect_to_scene(SDL_Rect* rect);
void clear_scene();
void draw_scene();
int init_gfx();
void shutdown_gfx();

#endif
